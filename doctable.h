#ifndef DOCTABLE_H
#define DOCTABLE_H

#include <QtGui>
#include <QtSql>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QTableView>
#include "myproxymodel.h"

class DocTable : public QWidget
{
    Q_OBJECT
public:
    explicit DocTable(int iddoc, QWidget *parent = 0);
    void resize();

private:
    QPushButton *close_button;
    MyProxyModelForDoc *pmodel;
    void fill(int id);
    inline void set_layout();
    inline void connects();
    inline void set_columns_names();
    QWidget *controls;
    QTableView *table;
    QSqlQueryModel *model;
    QMap<QString, QString> columns;
    int row_height;
    void custom_table();
    int iddoc;
    void rename_columns();
    
signals:
    void close_signal();

private slots:
    void close_slot();
    
public slots:
    void fill_slot(int);
};

#endif // DOCTABLE_H
