#pragma once

#include <QObject>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <trikControl/brick.h>
using namespace trikControl;

class MainThread : public QWidget
{
    Q_OBJECT
public:
    explicit MainThread(QThread *guiThread, QString configPath);
    ~MainThread();

protected:
    void buttonPressed();

private slots:
    void getButton(int code, int value);
    void goThread();

private:
    Brick brick;
    QTimer taskTimer;

    int mleftEnc;
    int mrightEnc;

    int mspeed;
};

