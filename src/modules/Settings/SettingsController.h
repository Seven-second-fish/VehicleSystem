#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QObject>
#include <QSettings>
#include <QString>

class SettingsController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString theme READ theme WRITE setTheme NOTIFY themeChanged)
    Q_PROPERTY(int brightness READ brightness WRITE setBrightness NOTIFY brightnessChanged)
    Q_PROPERTY(bool darkMode READ darkMode WRITE setDarkMode NOTIFY darkModeChanged)

public:
    explicit SettingsController(QObject *parent = nullptr);
    ~SettingsController();

    QString theme() const;
    int brightness() const;
    bool darkMode() const;

public slots:
    void setTheme(const QString &theme);
    void setBrightness(int brightness);
    void setDarkMode(bool enabled);
    void saveSettings();
    void loadSettings();
    void resetToDefaults();

signals:
    void themeChanged(const QString &theme);
    void brightnessChanged(int brightness);
    void darkModeChanged(bool enabled);
    void settingsSaved();
    void settingsLoaded();
    void settingsReset();

private:
    QSettings m_settings;
    QString m_theme;
    int m_brightness;
    bool m_darkMode;
};

#endif // SETTINGSCONTROLLER_H 