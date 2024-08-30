#include "datamanager.h"
#include<QFile>
#include<QDebug>

dataManager::dataManager(QObject *parent)
    : QObject{parent}
{}

bool dataManager::deleteFile(const QString &filePath)
{
    QFile file(filePath);
    if(file.exists()){
        if(file.remove()){
            qDebug()<<"File deleted successfully:"<<filePath;
            return true;
        }else{
            qDebug()<<"failed to delete file:"<<filePath;
            return false;
        }
    }else{
        qDebug()<<"file does not exist:"<<filePath;
        return false;
    }
}
