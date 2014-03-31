#include <QtGui/QApplication>
#include "mainthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString configPath = "./";
    if (a.arguments().contains("-c"))
    {
        int const index = a.arguments().indexOf("-c");
        if (a.arguments().count() <= index + 1)
        {
            //        printUsage();
            return 1;
        }

        configPath = a.arguments()[index + 1];
        if (configPath.right(1) != "/")
        {
            configPath += "/";
        }
    }

    MainThread mainthread(a.thread(),configPath);

    return a.exec();
}
