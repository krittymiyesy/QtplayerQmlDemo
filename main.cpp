#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qtavplayer/AVDefine.h"
#include "qtavplayer/AVPlayer.h"
#include "qtavplayer/AVOutput.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<AVDefine>("qtavplayer", 1, 0, "AVDefine");
    qmlRegisterType<AVPlayer>("qtavplayer", 1, 0, "AVPlayer");
    qmlRegisterType<AVOutput>("qtavplayer", 1, 0, "AVOutput");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
