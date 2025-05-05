#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>
#include <QString>
#include <QGeoCoordinate>

class NavigationController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentLocation READ currentLocation NOTIFY currentLocationChanged)
    Q_PROPERTY(QString destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(bool isNavigating READ isNavigating NOTIFY navigatingStateChanged)

public:
    explicit NavigationController(QObject *parent = nullptr);
    ~NavigationController();

    QString currentLocation() const;
    QString destination() const;
    bool isNavigating() const;

public slots:
    void startNavigation();
    void stopNavigation();
    void setDestination(const QString &destination);
    void updateCurrentLocation(const QGeoCoordinate &location);
    void calculateRoute();

signals:
    void currentLocationChanged(const QString &location);
    void destinationChanged(const QString &destination);
    void navigatingStateChanged(bool isNavigating);
    void routeCalculated(const QString &route);
    void navigationError(const QString &error);

private:
    QString m_currentLocation;
    QString m_destination;
    bool m_isNavigating;
    QGeoCoordinate m_currentCoordinate;
};

#endif // NAVIGATIONCONTROLLER_H 