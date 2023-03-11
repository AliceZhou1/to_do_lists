#include "nitem.h"

NItem::NItem(const QStringList &strings,ItemProperty* _itemP)
    :QTreeWidgetItem(strings),itemP(_itemP)
{

}
