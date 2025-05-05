#include "NavigationController.h"
#include <QDebug>

NavigationController::NavigationController(QObject *parent)
    : QObject(parent)
    , m_isNavigating(false)
{
}

NavigationController::~NavigationController()
{
    if (m_isNavigating) {
        stopNavigation();
    }
}

QString NavigationController::currentLocation() const
{
    return m_currentLocation;
}

QString NavigationController::destination() const
{
    return m_destination;
}

bool NavigationController::isNavigating() const
{
    return m_isNavigating;
}

void NavigationController::startNavigation()
{
    if (!m_isNavigating && !m_destination.isEmpty()) {
        m_isNavigating = true;
        emit navigatingStateChanged(m_isNavigating);
        calculateRoute();
    }
}

void NavigationController::stopNavigation()
{
    if (m_isNavigating) {
        m_isNavigating = false;
        emit navigatingStateChanged(m_isNavigating);
    }
}

void NavigationController::setDestination(const QString &destination)
{
    if (destination != m_destination) {
        m_destination = destination;
        emit destinationChanged(m_destination);
    }
}

void NavigationController::updateCurrentLocation(const QGeoCoordinate &location)
{
    m_currentCoordinate = location;
    // 这里可以添加地理编码逻辑，将坐标转换为地址
    QString newLocation = QString("%1, %2").arg(location.latitude()).arg(location.longitude());
    if (newLocation != m_currentLocation) {
        m_currentLocation = newLocation;
        emit currentLocationChanged(m_currentLocation);
    }
}

void NavigationController::calculateRoute()
{
    if (m_destination.isEmpty()) {
        emit navigationError("No destination set");
        return;
    }

    // 这里添加实际的路由计算逻辑
    // 示例实现
    QString route = QString("Route from %1 to %2").arg(m_currentLocation).arg(m_destination);
    emit routeCalculated(route);
} 