#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QObject {
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr)
    {};

signals:
    void workFinished();

public slots:
    void doWork()
    {

    }

};

#endif // WORKER_H
