#ifndef TABLE_H
#define TABLE_H

#include <QtGui>
#include <QtSql>
#include "myproxymodel.h"


class MTable : public QWidget
{
    Q_OBJECT
    
public:
    MTable(QWidget *parent = 0);

    void fill();
    void resize();

protected:


private:
    // элементы формы
    QLabel *from_label;
    QLabel *to_label;
    QLabel *type_label;
    QDateEdit *from_date;
    QDateEdit *to_date;
    QComboBox *type_box;
    QCheckBox *remove_dates;
    QPushButton *refresh_button;
    QRadioButton *docnum;
    QRadioButton *client;
    QLineEdit *textline;
    QPushButton *reset_text;
    QWidget *controls;
    QTableView *table;
    QSqlQueryModel *model;
    MyProxyModel *pmodel;
    QMap<QString, QString> columns;
    int row_height;

    void custom_table();
    void rename_columns();

    bool hidden;
    int filter;

    inline void set_layout();
    inline void connects();
    inline void set_columns_names();

    inline void custom_dates();
    void fill_checkbox();
    void delete_last_symbol();

    void keyReleaseEvent(QKeyEvent *);

signals:
    void show_doc_signal(int);

private slots:
    void date_changed(QDate);
    void disactivate_dates(bool);
    void switch_hidden();
    void combobox_used(QString);
    void refresh();
    void double_click(QModelIndex);
    void click(QModelIndex);
    void text_changed_slot(QString);
    void clear_textline();
    void reset_textfilter();
};


#endif // TABLE_H
