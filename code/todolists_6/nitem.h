#ifndef NITEM_H
#define NITEM_H
#include <QString>
#include <QtWidgets/QTreeWidget>

class ItemProperty;

class NItem:public QTreeWidgetItem{//继承treeitem,能够返回指向属性类型的指针
  public:
    ItemProperty* itemP;
    NItem(const QStringList &strings,ItemProperty* _itemP);
};
#endif // NITEM_H
