#ifndef CORECONTROLLER_H
#define CORECONTROLLER_H

#include <QObject>
#include <QString>

class CoreController : public QObject
{
    Q_OBJECT

public:
    explicit CoreController(QObject *parent = nullptr);
    ~CoreController();

    Q_INVOKABLE void initialize();
    Q_INVOKABLE void shutdown();

signals:
    void systemInitialized();
    void systemShutdown();

private:
    bool m_initialized;
};

#endif // CORECONTROLLER_H 