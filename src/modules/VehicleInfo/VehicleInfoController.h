#ifndef VEHICLEINFOCONTROLLER_H
#define VEHICLEINFOCONTROLLER_H

#include <QObject>
#include <QString>
#include <QTimer>

class VehicleInfoController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(double fuelLevel READ fuelLevel NOTIFY fuelLevelChanged)
    Q_PROPERTY(double engineTemp READ engineTemp NOTIFY engineTempChanged)
    Q_PROPERTY(int odometer READ odometer NOTIFY odometerChanged)

public:
    explicit VehicleInfoController(QObject *parent = nullptr);
    ~VehicleInfoController();

    double speed() const;
    double fuelLevel() const;
    double engineTemp() const;
    int odometer() const;

public slots:
    void startMonitoring();
    void stopMonitoring();
    void updateVehicleInfo();

signals:
    void speedChanged(double speed);
    void fuelLevelChanged(double level);
    void engineTempChanged(double temp);
    void odometerChanged(int distance);
    void warning(const QString &message);

private:
    QTimer m_updateTimer;
    double m_speed;
    double m_fuelLevel;
    double m_engineTemp;
    int m_odometer;
};

#endif // VEHICLEINFOCONTROLLER_H 