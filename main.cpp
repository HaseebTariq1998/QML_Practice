#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtConcurrent>
#include <personmodel.h>
#include <QQmlContext>
#include <worker.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    PersonModel p;

    engine.rootContext()->setContextProperty("Person_Q",&p);

    int  count =0;


    QtConcurrent:QtConcurrent::run([&](){

            for( int i = 0; i< 100000; i++)
            {
                count++;
                QThread::sleep(100000);
            }

        });



        QThread* thread = new QThread;
        Worker* worker = new Worker();

        worker->moveToThread(thread);

        QObject::connect(thread, &QThread::started, worker, &Worker::doWork);
        QObject::connect(worker, &Worker::workFinished, thread, &QThread::quit);

        thread->start();


    return app.exec();
}
