#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QDir>

class fileManagement : public QObject
{
    Q_OBJECT
public:
    explicit fileManagement(QObject *parent = 0);

signals:

public slots:
};

#endif // FILEMANAGEMENT_H
