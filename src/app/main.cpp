#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
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

	QQmlApplicationEngine engine;

	// 注册控制器到 QML 上下文
	engine.rootContext()->setContextProperty("coreController", &coreController);
	engine.rootContext()->setContextProperty("musicController", &musicController);
	engine.rootContext()->setContextProperty("navigationController", &navigationController);
	engine.rootContext()->setContextProperty("settingsController", &settingsController);
	engine.rootContext()->setContextProperty("vehicleInfoController", &vehicleInfoController);

    qDebug()<<"start scanning";

    // 添加 QML 导入路径
    engine.addImportPath(QCoreApplication::applicationDirPath() + "/../lib/qml");
    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");

    // 尝试加载 QML 文件
    const QUrl url(QStringLiteral("qrc:/MainPage/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        qWarning() << "QML module MainPage.Main failed to load!";
        return -1;
    }

	return app.exec();
}
