#include "VehicleInfoController.h"
#include <QDebug>
#include <QRandomGenerator>

VehicleInfoController::VehicleInfoController(QObject *parent)
    : QObject(parent)
    , m_speed(0.0)
    , m_fuelLevel(100.0)
    , m_engineTemp(90.0)
    , m_odometer(0)
{
    connect(&m_updateTimer, &QTimer::timeout, this, &VehicleInfoController::updateVehicleInfo);
}

VehicleInfoController::~VehicleInfoController()
{
    stopMonitoring();
}

double VehicleInfoController::speed() const
{
    return m_speed;
}

double VehicleInfoController::fuelLevel() const
{
    return m_fuelLevel;
}

double VehicleInfoController::engineTemp() const
{
    return m_engineTemp;
}

int VehicleInfoController::odometer() const
{
    return m_odometer;
}

void VehicleInfoController::startMonitoring()
{
    m_updateTimer.start(1000); // 每秒更新一次
}

void VehicleInfoController::stopMonitoring()
{
    m_updateTimer.stop();
}

void VehicleInfoController::updateVehicleInfo()
{
    // 模拟车辆数据更新
    // 在实际应用中，这些数据应该从车辆传感器获取
    double newSpeed = static_cast<double>(QRandomGenerator::global()->bounded(0, 200)); // 使用整数范围
    double newFuelLevel = m_fuelLevel - 0.1;
    double newEngineTemp = 90.0 + (static_cast<double>(QRandomGenerator::global()->bounded(-50, 50)) / 10.0); // 使用整数范围并除以10
    int newOdometer = m_odometer + static_cast<int>(newSpeed / 3600.0); // 假设速度单位为 km/h

    // 检查警告条件
    if (newFuelLevel < 20.0) {
        emit warning("Low fuel level!");
    }
    if (newEngineTemp > 100.0) {
        emit warning("High engine temperature!");
    }

    // 更新并发出信号
    if (newSpeed != m_speed) {
        m_speed = newSpeed;
        emit speedChanged(m_speed);
    }

    if (newFuelLevel != m_fuelLevel) {
        m_fuelLevel = newFuelLevel;
        emit fuelLevelChanged(m_fuelLevel);
    }

    if (newEngineTemp != m_engineTemp) {
        m_engineTemp = newEngineTemp;
        emit engineTempChanged(m_engineTemp);
    }

    if (newOdometer != m_odometer) {
        m_odometer = newOdometer;
        emit odometerChanged(m_odometer);
    }
} 