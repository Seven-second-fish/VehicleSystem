#include "MusicController.h"
#include <QDebug>
#include <QDir>

MusicController::MusicController(QObject *parent)
	: QObject(parent)
	, m_player(new QMediaPlayer(this))
	, m_audioOutput(new QAudioOutput(this))
	, m_isPlaying(false)
	, m_volume(50)
	, m_currentIndex(-1)
{
	m_player->setAudioOutput(m_audioOutput);
	m_audioOutput->setVolume(m_volume / 100.0);

	connect(m_player, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status) {
		if (status == QMediaPlayer::EndOfMedia) {
			next();
		}
	});
}

MusicController::~MusicController()
{
	stop();
}

QString MusicController::currentSong() const
{
	return m_currentSong;
}

bool MusicController::isPlaying() const
{
	return m_isPlaying;
}

int MusicController::volume() const
{
	return m_volume;
}

void MusicController::play()
{
	if (m_player->playbackState() != QMediaPlayer::PlayingState) {
		m_player->play();
		m_isPlaying = true;
		emit playingStateChanged(m_isPlaying);
	}
}

void MusicController::pause()
{
	if (m_player->playbackState() == QMediaPlayer::PlayingState) {
		m_player->pause();
		m_isPlaying = false;
		emit playingStateChanged(m_isPlaying);
	}
}

void MusicController::stop()
{
	m_player->stop();
	m_isPlaying = false;
	emit playingStateChanged(m_isPlaying);
}

void MusicController::next()
{
	if (m_playlist.isEmpty()) return;
	
	m_currentIndex = (m_currentIndex + 1) % m_playlist.size();
	m_player->setSource(m_playlist[m_currentIndex]);
	updateCurrentSong();
	if (m_isPlaying) {
		play();
	}
}

void MusicController::previous()
{
	if (m_playlist.isEmpty()) return;
	
	m_currentIndex = (m_currentIndex - 1 + m_playlist.size()) % m_playlist.size();
	m_player->setSource(m_playlist[m_currentIndex]);
	updateCurrentSong();
	if (m_isPlaying) {
		play();
	}
}

void MusicController::setVolume(int volume)
{
	if (volume != m_volume) {
		m_volume = qBound(0, volume, 100);
		m_audioOutput->setVolume(m_volume / 100.0);
		emit volumeChanged(m_volume);
	}
}

void MusicController::loadPlaylist(const QString &path)
{
	QDir dir(path);
	QStringList filters;
	filters << "*.mp3" << "*.wav" << "*.ogg";
	QStringList files = dir.entryList(filters, QDir::Files);

	m_playlist.clear();
	for (const QString &file : files) {
		m_playlist.append(QUrl::fromLocalFile(dir.filePath(file)));
	}

	if (!m_playlist.isEmpty()) {
		m_currentIndex = 0;
		m_player->setSource(m_playlist[m_currentIndex]);
		updateCurrentSong();
	}
}

void MusicController::updateCurrentSong()
{
	if (m_currentIndex >= 0 && m_currentIndex < m_playlist.size()) {
		QString newSong = m_playlist[m_currentIndex].fileName();
		if (newSong != m_currentSong) {
			m_currentSong = newSong;
			emit currentSongChanged(m_currentSong);
		}
	}
}
