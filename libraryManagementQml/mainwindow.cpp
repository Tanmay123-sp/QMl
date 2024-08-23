#include "mainwindow.h"
#include<QString>
#include<QComboBox>
// #include<QWidget>
// #include<QComboBox>

    MainWindow::MainWindow(QObject *parent)
        : QObject(parent)
    {
        bookMap = {
            {"C++", {2, {{"Sagar", 1}}}},
            {"Java", {3, {{"Nilesh", 2}}}},
            {"Python", {2, {{"Hari", 1}}}},
            {"Linux", {4, {{"Mahesh", 1}}}},
            {"Novel", {4, {{"Manish", 1}}}}
        };

        categoryMap = {
            {"C++", 1},
            {"Java", 1},
            {"Python", 1},
            {"Linux", 1},
            {"Novel", 0}
        };

        // count_Books();
        getBooksList();
        // getBookCount();
    }

    QStringList MainWindow::getBooksList() const
    {
        // QStringList booksList;
        for (const auto &it : bookMap) {
            // QString bookInfo = it.first + " - " + QString::number(it.second.first);
            // booksList.append(bookInfo);
            // QString countBook =
            qDebug() << bookMap.keys();
        }
        // qDebug()<<bookMap.keys();
        return bookMap.keys();
    }

    QString MainWindow::getBookCount(QString bookName)
    {
        if (bookMap.find(bookName) != bookMap.end()) {
            return QString::number(bookMap[bookName].first);
        }
        return "0";
    }

    void MainWindow::updateBooks(QString bookName, int Quantity) {
        if (bookMap.find(bookName) != bookMap.end()) {
            bookMap[bookName].first += Quantity;
        } else {
            // If the book does not exist, add it with the given Quantity
            bookMap[bookName] = std::make_pair(Quantity, QMap<QString, int>());
        }
    }


// void MainWindow::update_1(QString name,int count,bool selectCat){
//     // bookMap[name].first += count;
//     // add_Books();
//     MainWindow:: count_Books();
// }

// void MainWindow::update_2(QString name,int count){
//     // bookMap[name].first += count;
//     // add_Books();
//     MainWindow:: count_Books();
// }

// void MainWindow :: count_Books(){
//     int total_books =0;
//     for(auto &count : bookMap){
//         total_books += count.second.first;
//     }
    // ui->lineEdit->setText(QString :: number(total_books));
// }
