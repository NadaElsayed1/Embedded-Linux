#include "cppsignalsender.h"

cppSignalSender::cppSignalSender(QObject *parent)
    : QObject{parent}, m_value(0)
{
    m_timer = new QTimer (this);
    connect(m_timer, &QTimer::timeout,[=]{
        ++m_value;
        emit cppToQML(QString::number(m_value));
    });
    m_timer->start(1000);
}
