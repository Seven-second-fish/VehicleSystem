#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "modules/Core/CoreController.h"
#include "modules/MusicPlayer/MusicController.h"
#include "modules/Navigation/NavigationController.h"
#include "modules/Settings/SettingsController.h"
#include "modules/VehicleInfo/VehicleInfoController.h"

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

	QQmlApplicationEngine engine;

	// 注册控制器到 QML 上下文
	engine.rootContext()->setContextProperty("coreController", &coreController);
	engine.rootContext()->setContextProperty("musicController", &musicController);
	engine.rootContext()->setContextProperty("navigationController", &navigationController);
	engine.rootContext()->setContextProperty("settingsController", &settingsController);
	engine.rootContext()->setContextProperty("vehicleInfoController", &vehicleInfoController);

	const QUrl url(u"qrc:/main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
