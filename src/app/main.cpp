#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickItem>
#include "../modules/Core/CoreController.h"
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

    // engine.addImportPath(QCoreApplication::applicationDirPath() + "/../lib/qml");

    engine.loadFromModule("MainPage", "Main");

    if (engine.rootObjects().isEmpty()) {
        qWarning() << "QML module MainPage.Main failed to load!";
        return -1;
    }

    // const QUrl url(u"qrc:/main.qml"_qs);
    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                  &app, [url](QObject *obj, const QUrl &objUrl) {
    //     if (!obj && url == objUrl)
    //         QCoreApplication::exit(-1);
    // }, Qt::QueuedConnection);
    // engine.load(url);

	return app.exec();
}
