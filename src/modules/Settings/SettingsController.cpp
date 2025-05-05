#include "SettingsController.h"
#include <QDebug>

SettingsController::SettingsController(QObject *parent)
    : QObject(parent)
    , m_settings("VehicleSystem", "Settings")
    , m_theme("default")
    , m_brightness(100)
    , m_darkMode(false)
{
    loadSettings();
}

SettingsController::~SettingsController()
{
    saveSettings();
}

QString SettingsController::theme() const
{
    return m_theme;
}

int SettingsController::brightness() const
{
    return m_brightness;
}

bool SettingsController::darkMode() const
{
    return m_darkMode;
}

void SettingsController::setTheme(const QString &theme)
{
    if (theme != m_theme) {
        m_theme = theme;
        emit themeChanged(m_theme);
    }
}

void SettingsController::setBrightness(int brightness)
{
    if (brightness != m_brightness) {
        m_brightness = qBound(0, brightness, 100);
        emit brightnessChanged(m_brightness);
    }
}

void SettingsController::setDarkMode(bool enabled)
{
    if (enabled != m_darkMode) {
        m_darkMode = enabled;
        emit darkModeChanged(m_darkMode);
    }
}

void SettingsController::saveSettings()
{
    m_settings.setValue("theme", m_theme);
    m_settings.setValue("brightness", m_brightness);
    m_settings.setValue("darkMode", m_darkMode);
    m_settings.sync();
    emit settingsSaved();
}

void SettingsController::loadSettings()
{
    m_theme = m_settings.value("theme", "default").toString();
    m_brightness = m_settings.value("brightness", 100).toInt();
    m_darkMode = m_settings.value("darkMode", false).toBool();
    emit settingsLoaded();
}

void SettingsController::resetToDefaults()
{
    m_theme = "default";
    m_brightness = 100;
    m_darkMode = false;
    
    emit themeChanged(m_theme);
    emit brightnessChanged(m_brightness);
    emit darkModeChanged(m_darkMode);
    emit settingsReset();
    
    saveSettings();
} 