#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QColor>
#include <QPixmap>

class MyProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MyProxyModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;    
};

class MyProxyModelForDoc : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MyProxyModelForDoc(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MYPROXYMODEL_H
