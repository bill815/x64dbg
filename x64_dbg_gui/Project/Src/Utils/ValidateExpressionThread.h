#ifndef VALIDATEEXPRESSIONTHREAD_H
#define VALIDATEEXPRESSIONTHREAD_H

#include <QThread>
#include <QMutex>
#include "NewTypes.h"

class ValidateExpressionThread : public QThread
{
    Q_OBJECT
public:
    ValidateExpressionThread(QObject* parent = 0);
    void start(QString initialValue = QString());
    void stop();

signals:
    void expressionChanged(bool validExpression, bool validPointer, int_t value);

public slots:
    void textChanged(QString text);

private:
    QMutex mExpressionMutex;
    QString mExpressionText;
    bool mExpressionChanged;
    volatile bool mStopThread;

    void run();
};

#endif // VALIDATEEXPRESSIONTHREAD_H
