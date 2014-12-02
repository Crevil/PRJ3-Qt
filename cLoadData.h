#ifndef CLOADDATA_H
#define CLOADDATA_H

#include <QObject>
#include <QTimer>
#define GETDATATIMEOUT 2    // in sec

class cLoadData : public QObject
{
    Q_OBJECT
public:
    explicit cLoadData(QObject *parent = 0);
    ~cLoadData();

signals:

public slots:
    void getData();
};

#endif // CLOADDATA_H
