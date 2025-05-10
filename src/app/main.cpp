#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickItem>
#include "../core/CoreController.h"
#include "../modules/MusicPlayer/MusicController.h"
#include "../modules/Navigation/NavigationController.h"
#include "../modules/Settings/SettingsController.h"
#include "../modules/VehicleInfo/VehicleInfoController.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    // 创建控制器实例

    CoreController coreController;
	MusicController musicController;
    NavigationController navigationController;
	SettingsController settingsController;
	VehicleInfoController vehicleInfoController;

	// 初始化系统
    coreController.initialize();

	// 启动车辆信息监控
	vehicleInfoController.startMonitoring();

	// 注册 QML 类型
    //当你有自定义的 C++ 类型，需要暴露给 QML 使用时才用它。
    // qmlRegisterType<QQuickItem>("MainPage", 1, 0, "Main");
	qmlRegisterType<QQuickItem>("MusicPlayer", 1, 0, "MusicView");
	qmlRegisterType<QQuickItem>("Settings", 1, 0, "SettingsView");
	qmlRegisterType<QQuickItem>("VehicleInfo", 1, 0, "VehicleInfoView");
	qmlRegisterType<QQuickItem>("Navigation", 1, 0, "NavigationView");

	QQmlApplicationEngine engine;

	// 注册控制器到 QML 上下文
    engine.rootContext()->setContextProperty("coreController", &coreController);
    engine.rootContext()->setContextProperty("musicController", &musicController);
    engine.rootContext()->setContextProperty("navigationController", &navigationController);
    engine.rootContext()->setContextProperty("settingsController", &settingsController);
    engine.rootContext()->setContextProperty("vehicleInfoController", &vehicleInfoController);

    qDebug()<<"start scanning";

    // QObject::connect(
    //     &engine,
    //     &QQmlApplicationEngine::objectCreationFailed,
    //     &app,
    //     []() { QCoreApplication::exit(-1); },
    //     Qt::QueuedConnection);
    // engine.loadFromModule("MainPage", "Main");
    // engine.load(QUrl("qrc:/MainPage/Main.qml"));

    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl) QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);


    qDebug()<<"end";

    // const QUrl url(u"qrc:/MainPage/Main.qml"_qs);
    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                  &app, [url](QObject *obj, const QUrl &objUrl) {
    //     if (!obj && url == objUrl)
    //         QCoreApplication::exit(-1);
    // }, Qt::QueuedConnection);
    // engine.load(url);

	return app.exec();
}
