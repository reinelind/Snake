#include "Game.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QtCore/QMessageLogger>
#include <QtCore/QMessageLogContext>
#include <QtCore/QtMessageHandler>
#include <QtCore/QDebug>
#include <QtCore/QtGlobal>

void myDebugOutput(QtMsgType type,const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)

    QString txt;

    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(myDebugOutput);
    Game::Instance().run();
    return a.exec();
}
