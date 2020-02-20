#ifndef WEBHOOK_H
#define WEBHOOK_H

#include <QObject>
#include <QtNetwork>
#include <qtconcurrentrun.h>
#include <QThread>

QString static url;

class Webhook : public QObject
{
    Q_OBJECT
public:
    explicit Webhook(QString urlC)
    {
        url = urlC;
    }

    void sendMsg(QString msg)
    {
        QFuture<void> f1 = QtConcurrent::run(printMsg, msg);
    }

private:
    static void printMsg(QString msg)
    {
        QNetworkRequest req(url);
        QNetworkAccessManager nam;
        QByteArray json = "{"
                          "\"content\" : \"" + msg.toUtf8() + "\""
                          "}";
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
        QNetworkReply *reply = nam.post(req, json);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
    }
    static void printFullMsg(QByteArray json)
    {
        QNetworkRequest req(url);
        QNetworkAccessManager nam;
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
        QNetworkReply *reply = nam.post(req, json);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
    }
};

#endif // WEBHOOK_H
