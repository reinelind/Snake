#ifndef DEBUGLOG_H
#define DEBUGLOG_H
//#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QtCore/QMessageLogger>
#include <QtCore/QMessageLogContext>
#include <QtCore/QtMessageHandler>
#include <QtCore/QDebug>
#include <QtCore/QtGlobal>

void myDebugOutput(QtMsgType type,const QMessageLogContext &context ,const char &msg);
#endif // DEBUGLOG_H
