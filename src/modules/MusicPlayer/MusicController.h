#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

class MusicController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString currentSong READ currentSong NOTIFY currentSongChanged)
	Q_PROPERTY(bool isPlaying READ isPlaying NOTIFY playingStateChanged)
	Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
	explicit MusicController(QObject *parent = nullptr);
	~MusicController();

	QString currentSong() const;
	bool isPlaying() const;
	int volume() const;

public slots:
	void play();
	void pause();
	void stop();
	void next();
	void previous();
	void setVolume(int volume);
	void loadPlaylist(const QString &path);
    void updateCurrentSong();

signals:
	void currentSongChanged(const QString &song);
	void playingStateChanged(bool isPlaying);
	void volumeChanged(int volume);

private:
	QMediaPlayer *m_player;
	QAudioOutput *m_audioOutput;
	QString m_currentSong;
	bool m_isPlaying;
	int m_volume;
	QList<QUrl> m_playlist;
	int m_currentIndex;
};

#endif // MUSICCONTROLLER_H
