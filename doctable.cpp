#include "doctable.h"


DocTable::DocTable(int iddoc, QWidget *parent) :
    QWidget(parent)
{
    this->iddoc = iddoc;
    controls = new QWidget();
    close_button = new QPushButton("НАЗАД");
    table = new QTableView();
    model = new QSqlQueryModel();
    pmodel = new MyProxyModelForDoc();
    row_height = table->verticalHeader()->fontMetrics().height() + 2;

    pmodel->setSourceModel(model);
    table->setModel(pmodel);

    set_columns_names();
    custom_table();
    set_layout();
    connects();
    fill(iddoc);
}

inline void DocTable::connects(){
    QObject::connect(this->close_button, SIGNAL(clicked()),
                     this, SLOT(close_slot()));
}

void DocTable::custom_table(){
    table->verticalHeader()->hide();
    table->horizontalHeader()->setMovable(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->verticalHeader()->setDefaultSectionSize(row_height);
    table->horizontalHeader()->setHighlightSections(false);
    table->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    table->setAlternatingRowColors(true);
}

void DocTable::rename_columns(){
    for(int i = 0; i < pmodel->columnCount(); i++){
        if(columns[pmodel->headerData(i, Qt::Horizontal).toString()] != "")
            pmodel->setHeaderData(i, Qt::Horizontal, columns[pmodel->headerData(i, Qt::Horizontal).toString()]);
    }
}


inline void DocTable::set_layout(){
    // только кнопка закрыть
    QHBoxLayout *hlt = new QHBoxLayout();
    hlt->addWidget(close_button);
    controls->setLayout(hlt);
    resize();
    QVBoxLayout *vlt = new QVBoxLayout();
    vlt->addWidget(controls);
    vlt->addWidget(table);

    this->setLayout(vlt);
}

void DocTable::resize(){
    close_button->adjustSize();
    close_button->setFixedHeight(close_button->fontMetrics().height()+5);
    controls->setFixedSize(close_button->width(), close_button->height()+10);
    table->verticalHeader()->setDefaultSectionSize(table->verticalHeader()->fontMetrics().height() + 2);
    table->resizeColumnsToContents();
    row_height = table->verticalHeader()->fontMetrics().height() + 2;
    table->horizontalHeader()->resizeSection(1, row_height*1.5);
}

inline void DocTable::set_columns_names(){
    columns["mdate"] = "Дата";
    columns["myear"] = "Год";
    columns["pod"] = "Г";
    columns["tovmark"] = "Тов. марка";
    columns["fost"] = "Кол-во";
    columns["storage"] = "Склад";
    columns["board"] = "Стеллаж.";
    columns["plase"] = "Полка";
    columns["box"] = "Ящик";
    columns["notes"] = "Доп.парам.";
    columns["primmen"] = "Примечание";
    columns["tovcat"] = "Категория";
    columns["nu"] = "Норм.уп.";
    columns["except"] = "Приёмка";
    columns["idtov"] = "id";
    columns["prise"] = "Цена";
}

void DocTable::fill(int iddoc){
    QString query = "SELECT idtov,pod,tovmark,fost,prise,storage,board,plase,box,myear,nu,primmen,except,tovcat,notes FROM chek WHERE idlist = '" + QString::number(iddoc) + "' ORDER BY numt";
    model->setQuery(query);
    rename_columns();
    //table->hideColumn(0);
    table->resizeColumnsToContents();
    table->horizontalHeader()->resizeSection(1, row_height*1.5);
}

void DocTable::fill_slot(int id){
    this->fill(id);
}

void DocTable::close_slot(){
    emit(close_signal());
}
