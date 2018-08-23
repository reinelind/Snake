#include "Game.h"
#include <QApplication>
#include "debuglog.h"

void myDebugOutput(QtMsgType type,const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)

    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt+= QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt += QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt += QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt += QString("Fatal: %1").arg(msg);
        abort();
    }

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
