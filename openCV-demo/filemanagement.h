#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QTimer>

#define INTERVAL_FOR_SLIDES_MSEC 1000

class FileManagement : public QObject
{
    Q_OBJECT
public:
    QString currentPicturePath;

    explicit FileManagement(QObject *parent = 0);
private:
    QString currentFolderPath;
    QDir currentDir;
    QFileInfoList fileList;
    QStringList formatFilter;
    int currentPicIndex;

    QTimer myTimer;

    void setCurrentPicturePath(QString newPath);

signals:
    void oncurrentPictureChanged();

public slots:    
    void playPics();
    void pausePics();
    void showNextPic();
    void showPreviousPic();
    void loadFile();
};

#endif // FILEMANAGEMENT_H
