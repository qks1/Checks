#include "mtable.h"


MTable::MTable(QWidget *parent)
    : QWidget(parent)
{
    // создаём все кнопки и поя ввода даты, который для удобства размещения поместим на специальный виджет controls
    controls = new QWidget();
    from_label = new QLabel("С:");
    to_label = new QLabel("По:");
    type_label = new QLabel("Тип:");
    from_date = new QDateEdit();
    to_date = new QDateEdit;
    docnum = new QRadioButton("номер");
    client = new QRadioButton("клиент");
    textline = new QLineEdit();
    reset_text = new QPushButton("X");
    type_box = new QComboBox();
    remove_dates = new QCheckBox("ВЫКЛ.");
    refresh_button = new QPushButton("ОБНОВИТЬ");
    table = new QTableView();
    model = new QSqlQueryModel();
    pmodel = new MyProxyModel();

    docnum->setChecked(true);
    reset_text->setToolTip("Сброс фильтра");
    refresh_button->setToolTip("Обновить список документов");

    // сохраним высоту строки, потом она нам понадобится, чтобы по неё калибровать ширину некоторых столбцов
    row_height = table->verticalHeader()->fontMetrics().height() + 2;

    //hidden - показываем или нет скрытые типы документов. По умолчанию - нет.
    hidden = false;
    // фильтр по типу документов. Пока пуст.
    filter = 0;

    // связываем модели и представления
    pmodel->setSourceModel(model);
    table->setModel(pmodel);

    // воплощаем всё в реальность
    set_columns_names();
    fill_checkbox();
    custom_dates();
    custom_table();
    set_layout();
    connects();
    fill();

}

inline void MTable::connects(){
    // смена даты
    QObject::connect(this->from_date, SIGNAL(dateChanged(QDate)), SLOT(date_changed(QDate)));
    QObject::connect(this->to_date, SIGNAL(dateChanged(QDate)), SLOT(date_changed(QDate)));

    // комбобокс с документами
    QObject::connect(this->type_box, SIGNAL(activated(QString)), SLOT(combobox_used(QString)));

    // чекбокс "выкл."
    QObject::connect(this->remove_dates, SIGNAL(clicked(bool)), SLOT(disactivate_dates(bool)));

    // кнопка "Обновить"
    QObject::connect(this->refresh_button, SIGNAL(clicked()), SLOT(refresh()));

    // двойной щелчок по строке - вызов документа
    QObject::connect(this->table, SIGNAL(doubleClicked(QModelIndex)), SLOT(double_click(QModelIndex)));

    // щелчок по ячейке
    QObject::connect(this->table, SIGNAL(clicked(QModelIndex)), SLOT(click(QModelIndex)));

    // нажатие на радиокнопку
    QObject::connect(this->docnum, SIGNAL(clicked()), SLOT(clear_textline()));
    QObject::connect(this->client, SIGNAL(clicked()), SLOT(clear_textline()));

    // ввод текста
    QObject::connect(this->textline, SIGNAL(textChanged(QString)), SLOT(text_changed_slot(QString)));

    // сброс текстового фильтра
    QObject::connect(this->reset_text, SIGNAL(clicked()), SLOT(reset_textfilter()));
}

inline void MTable::custom_dates(){
    // по умолчанию устанавливаем в оба поля выбора даты сегодняшнее число
    QDate date = QDate::currentDate();
    from_date->setDate(date);
    to_date->setDate(date);

    // активируем выпадающий календарь
    from_date->setCalendarPopup(true);
    to_date->setCalendarPopup(true);
    from_date->calendarWidget()->setFirstDayOfWeek(Qt::Monday);
    to_date->calendarWidget()->setFirstDayOfWeek(Qt::Monday);
}

void MTable::custom_table(){
    // приводим таблицу к нужному виду: скрываем заголовок, делаем выбор целой строки, запрещаем редактирование,
    // ставим высоту строки по умолчанию, раскрашиваем через строчку, отменяем выделение заголовков жирным
    table->verticalHeader()->hide();
    //table->horizontalHeader()->setMovable(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->verticalHeader()->setDefaultSectionSize(row_height);
    table->horizontalHeader()->setHighlightSections(false);
    table->setAlternatingRowColors(true);
    // это в принципе не нужно: по щелчку правой кнопкой на выдавать контекстного меню
    table->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
}

inline void MTable::set_layout(){
    // все элементы управления запихнём в виджет
    QHBoxLayout *hlt = new QHBoxLayout();
    hlt->addWidget(from_label);
    hlt->addWidget(from_date);
    hlt->addWidget(to_label);
    hlt->addWidget(to_date);
    hlt->addWidget(remove_dates);
    hlt->addSpacing(20);
    hlt->addWidget(type_label);
    hlt->addWidget(type_box);
    // дальше - две радиокнопки, текстовое поле и кнопка сброса
    // радиокнопки в вертикальном лайауте
    QVBoxLayout *rblt = new QVBoxLayout();
    rblt->addWidget(docnum);
    rblt->addWidget(client);
    hlt->addLayout(rblt);
    hlt->addWidget(textline);
    hlt->addWidget(reset_text);
    hlt->addSpacing(20);
    // и кнопка обновить
    hlt->addWidget(refresh_button);
    resize();
    controls->setLayout(hlt);

    // виджет и таблицу пихаем в лайаут
    QVBoxLayout *vlt = new QVBoxLayout();
    vlt->addWidget(controls);
    vlt->addWidget(table);

    this->setLayout(vlt);
}

void MTable::resize(){
    // на радиокнопки ставим маленький шрифт
    QSettings settings("erk", "Checks");
    settings.beginGroup("FONTS");
    int font_size = settings.value("system_size").toInt();
    QString font_family = settings.value("system_family").toString();
    settings.endGroup();
    QFont small_font;
    small_font.setFamily(font_family);
    small_font.setPointSize(font_size-1);
    docnum->setFont(small_font);
    client->setFont(small_font);

    from_label->adjustSize();
    from_date->adjustSize();
    to_label->adjustSize();
    to_date->adjustSize();
    remove_dates->adjustSize();
    type_label->adjustSize();
    type_box->adjustSize();
    docnum->adjustSize();
    client->adjustSize();
    textline->setFixedWidth(font_size * 15);
    reset_text->setFixedSize(font_size+15, font_size+15);
    refresh_button->adjustSize();
    int total_width = from_label->width() + from_date->width() + to_label->width() + to_date->width() + remove_dates->width() + type_label->width() +
            type_box->width() + client->width() + textline->width() + reset_text->width() + refresh_button->width() + 115;
    int total_height = docnum->height()*2 + 15;
    controls->setFixedSize(total_width, total_height);
    table->verticalHeader()->setDefaultSectionSize(table->verticalHeader()->fontMetrics().height() + 2);
    table->resizeColumnsToContents();
    row_height = table->verticalHeader()->fontMetrics().height() + 2;
    table->horizontalHeader()->resizeSection(1, row_height*1.5);
    table->horizontalHeader()->resizeSection(2, row_height*1.5);
    table->horizontalHeader()->resizeSection(3, row_height*1.5);
}

inline void MTable::set_columns_names(){
    columns["mdate"] = "Дата";
    columns["mtime"] = "Время";
    columns["doc"] = "Документ";
    columns["numdoc"] = "Номер";
    columns["klient"] = "Клиент";
    columns["gg"] = "гот.";
    columns["pp"] = "опл.";
    columns["im"] = "спис.";
    columns["vidan"] = "выд.";
    columns["prim"] = "Примечание";
    columns["prim_k"] = "Для кого";
    columns["id"] = "id";
    columns["fullprise"] = "Цена";
}

void MTable::rename_columns(){
    // переименовываем столбцы, беря названия из columns
    for(int i = 0; i < pmodel->columnCount(); i++){
        if(columns[pmodel->headerData(i, Qt::Horizontal).toString()] != "")
            pmodel->setHeaderData(i, Qt::Horizontal, columns[pmodel->headerData(i, Qt::Horizontal).toString()]);
    }
}

// заполнение таблицы
void MTable::fill(){
    // устанавливаем фильтры (по дате и типу документов, по тексту), формируем запрос
    QString begin = "", end = "";
    QString docs = (hidden ? " > 0" : " < 20");     // >0 - это просто так
    QString query = "SELECT id,pp,gg,vidan,doc,numdoc,DATE_FORMAT(mdate, '%d.%m.%Y') as mdate,mtime,klient,fullprise,prim FROM listdoc WHERE ";
    QString order_by_numdoc = "";
    bool last_text = false;
    if(!remove_dates->isChecked()){
        begin = from_date->date().toString("yyyy-MM-dd");
        end = to_date->date().toString("yyyy-MM-dd");
        query += "mdate >= '" + begin + "' AND mdate <= '" + end + "' AND ";
    }
    if(textline->text() != ""){
        // фильтр по тексту
        // если фильтруем по номеру документа
        if(this->docnum->isChecked()){
            query += " numdoc >= " + textline->text() + " AND ";
            order_by_numdoc = " numdoc ASC, ";
        }
        else if(this->client->isChecked()){
            query += " klient LIKE '%" + textline->text() + "%' AND ";
        }
        last_text = true;
    }
    query += " g1 " + docs + " AND im != '3' " + (filter == 0 ? "" : (" AND g1 = " + QString::number(filter))) + " ORDER BY " + order_by_numdoc + " mdate DESC, mtime DESC";
    model->setQuery(query);
    if(model->rowCount() == 0 && last_text){
        delete_last_symbol();
        return;
    }
    // переименовываем столбцы
    rename_columns();
    // скрываем столбец id
    table->hideColumn(0);
    // подбираем ширину столбцов
    table->resizeColumnsToContents();
    table->horizontalHeader()->resizeSection(1, row_height*1.5);
    table->horizontalHeader()->resizeSection(2, row_height*1.5);
    table->horizontalHeader()->resizeSection(3, row_height*1.5);
}

// обрабатываем нажатие Ctrl+Q
void MTable::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Q:
        if(event->modifiers() && Qt::ControlModifier){
            switch_hidden();
        }
        break;
    default:
        QWidget::keyReleaseEvent(event);
    }
}

void MTable::fill_checkbox(){
    type_box->clear();
    type_box->addItem("");
    type_box->addItem("Чек");
    type_box->addItem("Счёт");
    type_box->addItem("Заявка");
    type_box->addItem("Накладная");
    if(hidden){
        type_box->addItem("Р-отгрузка");
        type_box->addItem("Б-отгрузка");
        type_box->addItem("М-отгрузка");
    }
}

void MTable::date_changed(QDate date){
    fill();
}

void MTable::disactivate_dates(bool b){
    this->from_date->setEnabled(!b);
    this->to_date->setEnabled(!b);
    fill();
}

void MTable::switch_hidden(){
    hidden = !hidden;
    fill_checkbox();
    fill();
}

void MTable::combobox_used(QString str){
    if(str == "Счёт")
        filter = 2;
    else if(str == "Заявка")
        filter = 5;
    else if(str == "Накладная")
        filter = 7;
    else if(str == "Чек")
        filter = 1;
    else if(str == "Р-отгрузка")
        filter = 21;
    else if(str == "Б-отгрузка")
        filter = 22;
    else if(str == "М-отгрузка")
        filter = 20;
    else
        filter = 0;
    fill();
}

void MTable::delete_last_symbol(){
    if(this->textline->text() != ""){
        this->textline->setText(this->textline->text().remove(this->textline->text().size()-1, 1));
        fill();
    }
}

void MTable::refresh(){
    fill();
}

void MTable::double_click(QModelIndex mi){
    int id = pmodel->data(pmodel->index(mi.row(),0), Qt::DisplayRole).toInt();
    emit(show_doc_signal(id));
}

void MTable::click(QModelIndex mi){
    // column = 1 - оплата, set = 3
    // column = 2 - готовность, set = 1
    // column = 3 - выдача, set = 2
    if(mi.column() != 1 && mi.column() != 2 && mi.column() !=3)
        return;
    else{
        int data = model->data(mi, Qt::DisplayRole).toInt();
        int id = model->data(model->index(mi.row(),0), Qt::DisplayRole).toInt();
        QString docname = model->data(model->index(mi.row(),4), Qt::DisplayRole).toString();
        QString docnum = model->data(model->index(mi.row(),5), Qt::DisplayRole).toString();
        QString docdate = model->data(model->index(mi.row(),6), Qt::DisplayRole).toString();
        QString doc = QString("%1 №%2 от %3").arg(docname, docnum, docdate);
        QString question, query;
        if(mi.column() == 1){
            // в зависимости от того, стоит или нет галка, предлагаем соответствующее действие
            if(data == 3){
                question = "Снять отметку об оплате с документа " + doc + "?";
                query = "UPDATE listdoc SET pp=0 WHERE id=" + QString::number(id);
            }
            else if(data == 0){
                question = "Установить отметку об оплате в документе " + doc + "?";
                query = "UPDATE listdoc SET pp=3 WHERE id=" + QString::number(id);
            }
        }
        else if(mi.column() == 2){
            // в зависимости от того, стоит или нет галка, предлагаем соответствующее действие
            if(data == 1){
                question = "Снять отметку о готовности с документа " + doc + "?";
                query = "UPDATE listdoc SET gg=0 WHERE id=" + QString::number(id);
            }
            else if(data == 0){
                question = "Установить отметку о готовности в документе " + doc + "?";
                query = "UPDATE listdoc SET gg=1 WHERE id=" + QString::number(id);
            }
        }
        if(mi.column() == 3){
            // в зависимости от того, стоит или нет галка, предлагаем соответствующее действие
            if(data == 2){
                question = "Снять отметку о выдаче с документа " + doc + "?";
                query = "UPDATE listdoc SET vidan=0 WHERE id=" + QString::number(id);
            }
            else if(data == 0){
                question = "Установить отметку о выдаче в документе " + doc + "?";
                query = "UPDATE listdoc SET vidan=2 WHERE id=" + QString::number(id);
            }
        }
        if(QMessageBox::warning(this->table, "Вы уверены?", question) == QMessageBox::Ok){
            QSqlQuery q(query);
            if(!q.exec()){
                QMessageBox::warning(this->table, "Не получается", "Ошибка:\n" + q.lastError().text());
                return;
            }
            this->refresh();
        }
    }
}

void MTable::text_changed_slot(QString text){
    // реакция на изменение текста в текстовом поле
    fill();
}

void MTable::clear_textline(){
    // реакция на нажатие радиокнопки
    this->textline->clear();
    textline->setFocus(Qt::TabFocusReason);
}


void MTable::reset_textfilter(){
    // реакция на нажатие кнопки "сброс фильтра"
    this->textline->clear();
    fill();
}
