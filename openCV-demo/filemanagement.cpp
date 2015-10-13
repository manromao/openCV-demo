#include "filemanagement.h"
#include <QDebug>

FileManagement::FileManagement(QObject *parent) : QObject(parent)
{
    formatFilter = (QStringList()
                    << "*.jpg"
                    << "*.png"
                    << "*.jpeg");

    currentPicturePath = "openCV.png";
    currentFolderPath = QDir::currentPath();
    currentDir.setPath(currentFolderPath);
    fileList = currentDir.entryInfoList(formatFilter);
    currentPicIndex = 0;


}

// Private
void FileManagement::setCurrentPicturePath(QString newPath){
    currentPicturePath = newPath;
    oncurrentPictureChanged(); // Send signal to update image
}

// Slots
void FileManagement::playPics(){
    myTimer.setInterval(INTERVAL_FOR_SLIDES_MSEC);
    connect (&myTimer, &QTimer::timeout,this,&FileManagement::showNextPic);
    myTimer.start();
}

void FileManagement::pausePics(){
    myTimer.stop();
}

void FileManagement::showNextPic(){
    int nextPicIndex = currentPicIndex+1;

    if(nextPicIndex <= fileList.length() ){     // If there are still pics
        currentPicIndex = nextPicIndex;
        setCurrentPicturePath(fileList.at(nextPicIndex).absoluteFilePath());
    }
    else{
        qDebug() << "End of list";
        myTimer.stop();
    }



}

void FileManagement::showPreviousPic(){
    int prevPicIndex = currentPicIndex-1;

    if(prevPicIndex >= 0 ){     // If not the first picture
        currentPicIndex = prevPicIndex;
        setCurrentPicturePath(fileList.at(prevPicIndex).absoluteFilePath());
    }
    else{
         qDebug() << "Start of list";
        myTimer.stop();
    }



}

void FileManagement::loadFile(){
    // Open file browser
    QString QFileName = QFileDialog::getOpenFileName();

    QFileInfo myInfo(QFileName);

    // Update directory
    currentDir = myInfo.dir();

    // Update File list
    fileList = currentDir.entryInfoList(formatFilter,, QDir::Time);

    //Update list index
    currentPicIndex = fileList.indexOf(myInfo);

    // Update picture path
    setCurrentPicturePath(QFileName);

}
