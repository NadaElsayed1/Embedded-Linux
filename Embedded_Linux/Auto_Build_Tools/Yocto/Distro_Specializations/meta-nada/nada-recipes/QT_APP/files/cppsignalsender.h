#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class cppSignalSender : public QObject
{
    Q_OBJECT
public:
    explicit cppSignalSender(QObject *parent = nullptr);
    int m_value;
    QTimer *m_timer;

signals:

    void cppToQML(QString value);
};

#endif // CPPSIGNALSENDER_H
