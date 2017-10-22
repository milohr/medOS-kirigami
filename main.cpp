#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include "./3rdparty/kirigami/src/kirigamiplugin.h"
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

#ifdef Q_OS_ANDROID
    KirigamiPlugin::getInstance().registerTypes();
#endif

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        qDebug()<<"engine.load is empty";
        return -1;
    }else
    {
        qDebug()<<"engine.load is not empty";
    }

    return app.exec();
}
