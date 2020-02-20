# DiscordWebhook

Simple Discord's webhook integration.
Coded in C++ and Qt.
Two functions are available :
- sendMsg(QString msg) : it prints a simple message on your pre-configured webhook.
- sendFullMsg(QByteArray json) : it allows you to use every possibilities of Discord's webhook. I recommand reading [this](https://gist.github.com/Birdie0/78ee79402a4301b1faf412ab5f1cdcf9).

Webhook's message are sent in another thread. If this need to be blocking, considerer changing
```cpp
void sendMsg(QString msg)
{
    QFuture<void> f1 = QtConcurrent::run(printMsg, msg);
}

void sendFullMsg(QByteArray json)
{
    QFuture<void> f1 = QtConcurrent::run(printFullMsg, json);
}
```
to
```cpp
void sendMsg(QString msg)
{
    printMsg(msg);
}

void sendFullMsg(QByteArray json)
{
    printFullMsg(json);
}
```
