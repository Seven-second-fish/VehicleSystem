#include "CoreController.h"

CoreController::CoreController(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
{
}

CoreController::~CoreController()
{
    if (m_initialized) {
        shutdown();
    }
}

void CoreController::initialize()
{
    if (!m_initialized) {
        // 初始化系统核心功能
        m_initialized = true;
        emit systemInitialized();
    }
}

void CoreController::shutdown()
{
    if (m_initialized) {
        // 关闭系统核心功能
        m_initialized = false;
        emit systemShutdown();
    }
} 