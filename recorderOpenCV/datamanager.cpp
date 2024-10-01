#include "datamanager.h"
#include<QFile>
#include<QDebug>
#include<QDir>
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

bool dataManager::saveFile(const QByteArray &data, const QString &fileName)
{
    // Define the directory to save recorded files
    QString directoryPath = "C:/QML Projects/recorderOpenCV/recordedFiles/";
    QDir dir(directoryPath);

    // Ensure the directory exists; create if it does not.
    if (!dir.exists()) {
        if (!dir.mkpath(directoryPath)) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return false;
        }
    }

    // Construct the full file path
    QString filePath = directoryPath + fileName;

    // Determine if the file is audio or video based on the file extension
    QString fileExtension = QFileInfo(fileName).suffix().toLower();
    if (fileExtension == "mp4" || fileExtension == "avi" || fileExtension == "mkv" ||
        fileExtension == "m4a" || fileExtension == "mp3" || fileExtension == "wav")
    {
        // Create and open the file for writing
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            // Write the data to the file
            if (file.write(data) == -1) { // Check if writing failed
                qDebug() << "Failed to write data to file:" << filePath;
                return false;
            }
            file.close();
            qDebug() << "File saved successfully:" << filePath;

            // Emit a signal or update your ListView to refresh and show the new file
            emit fileSaved(filePath); // You can define a signal like this for updating the UI
            return true;
        } else {
            qDebug() << "Failed to open file for writing:" << filePath;
            return false;
        }
    } else {
        qDebug() << "Unsupported file type:" << fileExtension;
        return false;
    }
}
