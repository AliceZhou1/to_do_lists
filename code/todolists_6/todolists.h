#ifndef TODOLISTS_H
#define TODOLISTS_H
#include<utility>
#include <QWidget>
#include <QtWidgets/QTreeWidget>
#include <vector>
#include <QDate>
#include <QDateEdit>
#include <QMenu>
#include "itemproperty.h"
namespace Ui {
class ToDoLists;
}

class ToDoLists : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoLists(QWidget *parent = 0);
    ~ToDoLists();
private slots:
    void onEditEntered();//输入栏回车
    void onRefreshClicked();//点击刷新
    void onPushButtonMenuClicked();//我的首页按钮、我的待办按钮
    void onChildItemClicked(QTreeWidgetItem* item);//点击表项
    void onPushButtonCloseClicked();//关闭按钮
    void onPushButtonOkClicked();//确定按钮
    void onPushButtonCancelClicked();//取消按钮
    void updateWidget1(QTreeWidget* widget);//更新容器内容到widget1中
    void updateWidget2(QTreeWidget* widget);//更新容器内容到widget1中
    void sortFunc(QAction* act);//排序
private:
    Ui::ToDoLists *ui;
    std::vector<ItemProperty> m_toDoItems;//使用QVector存储需要TBDEvents重载=才能深拷贝，这里使用stl vector
    QTreeWidgetItem* m_widgetItem[5];//存储未安排，未来七天,以后,未完成,已完成5个item
    ItemProperty* m_curProperty;//当前属性页展示的属性
    QAction* m_actionSort[3];
    void setWidgitStyle();//设置窗体样式
    void connectSlots();//连接槽函数
    void initTopLevelItems();//初始化三个树节点并隐藏
//    void refreshWidget(QTreeWidget* widget);
    void removeAllTopItems(QTreeWidget* widget);//析构treewidget下所有父节点(无孩子)
    void removeAllChildren(QTreeWidgetItem* item);//析构treewidget下所有父节点的子节点
    ItemProperty* getProperty(QTreeWidgetItem* item);//在vector中寻找property
    void showPropertyBox(ItemProperty* itemP);
    void setRightTime(QDateEdit* dateEdit,QDate date);
    static bool comparePriority(const ItemProperty &i1,const ItemProperty &i2);//按优先级排序
    static bool compareExpiration(const ItemProperty &i1,const ItemProperty &i2);//按到期时间排序

};

#endif // TODOLISTS_H
