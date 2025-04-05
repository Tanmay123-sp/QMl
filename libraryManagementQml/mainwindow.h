#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMap>
#include<QString>
#include <QStringList>
using namespace std;

    class MainWindow : public QObject
    {
        Q_OBJECT
    public:
        explicit MainWindow(QObject *parent = nullptr);

    // ~MainWindow();

    Q_INVOKABLE QStringList getBooksList() const;
    Q_INVOKABLE QString getBookCount(QString bookName);
    Q_INVOKABLE void updateBooks(QString bookName, int Quantity);

private:

    QMap<QString,pair<int,QMap<QString,int>>> bookMap;
    QMap<QString,bool>categoryMap;

    void count_Books();
    // void updateTotalBooks();
    //void EachBookQty();
};
#endif // MAINWINDOW_H
