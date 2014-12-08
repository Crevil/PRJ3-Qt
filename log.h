#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QVector>

class log
{
public:
    log();
    ~log();

    int saveLog( QVector<QString> log );
    int getLog( QVector<QVector<QString> > * log );
    int getLatest( QVector< QString > * log);

private:
    QVector<QVector<QString> > * log_;
    QVector<QString> * latest_;
};

#endif // LOG_H
