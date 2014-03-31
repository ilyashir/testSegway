#include "mainthread.h"

MainThread::MainThread(QThread *guiThread, QString configPath) :
    brick(*guiThread, configPath),
    mspeed(0),
    mleftEnc(0),
    mrightEnc(0)
{
    qDebug() << "Check";

    connect(brick.keys(), SIGNAL(buttonPressed(int,int)), this, SLOT(getButton(int,int)));

}

MainThread::~MainThread()
{
    taskTimer.stop();
    brick.motor("M1")->powerOff(); //obsolete
    brick.motor("JM3")->powerOff(); //obsolete
    brick.encoder("JB4")->reset(); //left encoder
    brick.encoder("JB3")->reset(); //right encoder
}

void MainThread::getButton(int code, int value)
{
    if (value != 1)
      return;

    switch (code) {
    case 28:
        qDebug()<<"press Enter";
        buttonPressed();
        break;
    case 105:
        mspeed += 10;
        qDebug()<<"speed: " << mspeed;
        brick.motor("M1")->setPower(mspeed);
        brick.motor("JM3")->setPower(-mspeed);
        break;
    case 106:
        mspeed -= 10;
        qDebug()<<"speed: " << mspeed;
        brick.motor("M1")->setPower(mspeed);
        brick.motor("JM3")->setPower(-mspeed);
        break;
    case 139:
        qDebug()<<"press Esc";
        taskTimer.stop();

        brick.motor("M1")->powerOff(); //right motor
        brick.motor("JM3")->powerOff(); //left motor

        brick.encoder("JB4")->reset(); //left encoder
        brick.encoder("JB3")->reset(); //right encoder

        break;
    default:
        qDebug()<<"no key" << code;
        break;
    }
}

void MainThread::buttonPressed(){

    connect(&taskTimer, SIGNAL(timeout()), this, SLOT(goThread()));
    taskTimer.start(5);
}

void MainThread::goThread()
{
    mleftEnc = -brick.encoder("JB4")->read();
    mrightEnc = brick.encoder("JB3")->read();
    qDebug() << "enc read" << mleftEnc << " " << mrightEnc;
}


