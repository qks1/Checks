#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "mtable.h"
#include "doctable.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(bool, QSqlDatabase);

private:
    QSettings *settings;
    QSqlDatabase base;
    MTable *docs_list;
    DocTable *doc;
    QStackedWidget *mwidget;
    QAction *quit_action;
    QAction *settings_action;
    bool is_connect;

    void create_central_widget();
    void create_menu();
    void create_actions();



signals:
    void exit_signal();
    void reset_signal();


private slots:
    void send_exit();
    void send_settings();
    void signal_from_list(int);
    void doc_closed();
    void reload_base();
};

#endif // MAINWINDOW_H
