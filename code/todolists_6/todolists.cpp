#include "todolists.h"
#include "ui_todolists.h"
#include <QDebug>

ToDoLists::ToDoLists(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToDoLists)
{
    ui->setupUi(this);
    setWidgitStyle();
    connectSlots();
    initTopLevelItems();
}

ToDoLists::~ToDoLists()
{
    delete ui;
}

void ToDoLists::onEditEntered()
{
    QLineEdit* edit=static_cast<QLineEdit*>(sender());
    QString str=edit->text();
    edit->clear();
    ItemProperty itemP(str);
    m_toDoItems.push_back(itemP);//vector添加元素后会改变首地址，因此不能在没刷新的地方使用temp对象的属性指针
    QTreeWidgetItem* item=m_toDoItems.back().createItem();//注意不能使用临时变量itemP创建
    if(edit==ui->lineEdit_newToDo){
        ui->treeWidget_temp->addTopLevelItem(item);
    }else if(edit==ui->lineEdit_page2_newToDo)
    {
        ui->treeWidget_page2_temp->addTopLevelItem(item);
    }
}

void ToDoLists::onRefreshClicked()//刷新时将容器中数据同步到widget上
{
    QPushButton* btn=static_cast<QPushButton*>(sender());
    QTreeWidget* widget=nullptr;
    QTreeWidget* widget_temp=nullptr;
    if(btn==ui->pushButton_refresh){
        widget=ui->treeWidget;
        widget_temp=ui->treeWidget_temp;
    }else if(btn==ui->pushButton_page2_refresh){
        widget=ui->treeWidget_page2;
        widget_temp=ui->treeWidget_page2_temp;
    }
    if(widget==ui->treeWidget)
        updateWidget1(widget);
    else if(widget==ui->treeWidget_page2)
        updateWidget2(widget);
    removeAllTopItems(widget_temp);
}

void ToDoLists::onPushButtonMenuClicked()
{
    QPushButton* btn=static_cast<QPushButton*>(sender());
    if(btn==ui->pushButton_home)
        ui->stackedWidget->setCurrentIndex(0);
    if(btn==ui->pushButton_list)
        ui->stackedWidget->setCurrentIndex(1);
}

void ToDoLists::onChildItemClicked(QTreeWidgetItem *item)
{
    bool checkState;//获取item的勾选属性
    if(item->checkState(0)==Qt::Unchecked)
        checkState=false;
    else
        checkState=true;
    ItemProperty* itemP=getProperty(item);
    if(itemP->getIsFinished()==checkState)//勾选属性无变化,说明没有点击复选框
        showPropertyBox(itemP);
    else
    {
        itemP->setIsFinished(checkState);
    }
}

void ToDoLists::onPushButtonCloseClicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void ToDoLists::onPushButtonOkClicked()
{
    QString text=ui->lineEdit_text->text();
    int index=ui->comboBox_priority->currentIndex();
    QDate expTime=ui->dateEdit_expiration->date();
    QDate remTime=ui->dateEdit_reminder->date();
    m_curProperty->setText(text);
    m_curProperty->setPriority(p[index]);
    m_curProperty->setExpirationTime(expTime);
    m_curProperty->setReminderTime(remTime);
    m_curProperty=nullptr;
    ui->stackedWidget_2->setCurrentIndex(1);
    updateWidget1(ui->treeWidget);
    updateWidget2(ui->treeWidget_page2);
}

void ToDoLists::onPushButtonCancelClicked()
{
    showPropertyBox(m_curProperty);
}

void ToDoLists::updateWidget1(QTreeWidget *widget)
{
    //先全部清空widget，再根据vector重新写入
    for(int i=0;i<3;i++)
    {
        removeAllChildren(m_widgetItem[i]);
    }

    for(auto it=m_toDoItems.begin();it!=m_toDoItems.end();++it){
        QTreeWidgetItem* item=it->createItem();
        QDate date=it->getExpirationTime();
        int dif=QDate::currentDate().daysTo(date);
        if(dif<=0)
            m_widgetItem[0]->addChild(item);
        else if(dif>7)
            m_widgetItem[2]->addChild(item);
        else
            m_widgetItem[1]->addChild(item);
    }
    for(int i=0;i<3;i++){
        if(m_widgetItem[i]->childCount()==0)
            m_widgetItem[i]->setHidden(true);
        else
            m_widgetItem[i]->setHidden(false);
    }

}

void ToDoLists::updateWidget2(QTreeWidget *widget)
{
    //先全部清空widget，再根据vector重新写入
    for(int i=3;i<5;i++)
    {
        removeAllChildren(m_widgetItem[i]);
    }
    for(auto it=m_toDoItems.begin();it!=m_toDoItems.end();++it){
        QTreeWidgetItem* item=it->createItem();
        if(it->getIsFinished()==true)
        {
            m_widgetItem[4]->addChild(item);
        }else{
            m_widgetItem[3]->addChild(item);
        }
    }
    for(int i=3;i<5;i++){
        if(m_widgetItem[i]->childCount()==0)
            m_widgetItem[i]->setHidden(true);
        else
            m_widgetItem[i]->setHidden(false);
    }
    m_widgetItem[3]->setExpanded(true);
    m_widgetItem[4]->setExpanded(false);
}

void ToDoLists::sortFunc(QAction *act)
{
    std::vector<ItemProperty> temp(m_toDoItems);
    if(act->text()=="按优先级")
    {
        std::sort(m_toDoItems.begin(),m_toDoItems.end(),comparePriority);
    }else if(act->text()=="按到期时间")
    {
        std::sort(m_toDoItems.begin(),m_toDoItems.end(),compareExpiration);
    }

    updateWidget2(ui->treeWidget_page2);
    m_toDoItems.assign(temp.begin(),temp.end());
}


void ToDoLists::setWidgitStyle()
{
    ui->horizontalLayout->setStretch(1,3);
    ui->horizontalLayout->setStretch(2,1);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(1);

    QMenu *menu = new QMenu(this);
    ui->pushButton_page2_sort->setMenu(menu);
    m_actionSort[0] = menu->addAction("按创建时间");
    m_actionSort[1] = menu->addAction("按优先级");
    m_actionSort[2] = menu->addAction("按到期时间");

    QActionGroup *grp = new QActionGroup(this);
    grp->addAction(m_actionSort[0]);
    grp->addAction(m_actionSort[1]);
    grp->addAction(m_actionSort[2]);
    //action menu连接排序
    connect(grp, SIGNAL(triggered(QAction*)),this, SLOT(sortFunc(QAction*)));
    m_actionSort[0]->setCheckable(true);
    m_actionSort[1]->setCheckable(true);
    m_actionSort[2]->setCheckable(true);
    m_actionSort[0]->setChecked(true);
}

void ToDoLists::connectSlots()
{
    //lineEdit槽连接
    connect(ui->lineEdit_newToDo,&QLineEdit::returnPressed,this,onEditEntered);
    connect(ui->lineEdit_page2_newToDo,&QLineEdit::returnPressed,this,onEditEntered);
    //按钮槽连接
    connect(ui->pushButton_refresh,&QPushButton::clicked,this,onRefreshClicked);
    connect(ui->pushButton_page2_refresh,&QPushButton::clicked,this,onRefreshClicked);
    connect(ui->pushButton_home,&QPushButton::clicked,this,onPushButtonMenuClicked);
    connect(ui->pushButton_list,&QPushButton::clicked,this,onPushButtonMenuClicked);
    connect(ui->pushButton_close,&QPushButton::clicked,this,onPushButtonCloseClicked);
    connect(ui->pushButton_ok,&QPushButton::clicked,this,onPushButtonOkClicked);
    connect(ui->pushButton_cancel,&QPushButton::clicked,this,onPushButtonCancelClicked);
    //item点击槽，连接的是widget对象
    connect(ui->treeWidget,&QTreeWidget::itemClicked,this,onChildItemClicked);
    connect(ui->treeWidget_page2,&QTreeWidget::itemClicked,this,onChildItemClicked);
}

void ToDoLists::initTopLevelItems()
{
    m_widgetItem[0]=new QTreeWidgetItem(ui->treeWidget,QStringList()<<"未安排");
    m_widgetItem[1]=new QTreeWidgetItem(ui->treeWidget,QStringList()<<"未来七天");
    m_widgetItem[2]=new QTreeWidgetItem(ui->treeWidget,QStringList()<<"以后");
    m_widgetItem[3]=new QTreeWidgetItem(ui->treeWidget_page2,QStringList()<<"未完成");
    m_widgetItem[4]=new QTreeWidgetItem(ui->treeWidget_page2,QStringList()<<"已完成");
    m_widgetItem[0]->setHidden(true);
    m_widgetItem[1]->setHidden(true);
    m_widgetItem[2]->setHidden(true);
    m_widgetItem[3]->setHidden(true);
    m_widgetItem[4]->setHidden(true);
    m_curProperty=nullptr;
}


void ToDoLists::removeAllTopItems(QTreeWidget *widget)
{
    QTreeWidgetItem* item;
    int count=widget->topLevelItemCount();
    while (count--) {
        item=widget->takeTopLevelItem(0);
        delete item;
    }
}

void ToDoLists::removeAllChildren(QTreeWidgetItem *item)
{
    QTreeWidgetItem* child;
    int count=item->childCount();
    while (count--) {
        child=item->takeChild(0);
        delete child;
    }
}

ItemProperty *ToDoLists::getProperty(QTreeWidgetItem *item)
{
    if(item)
    {
        NItem* nitem=static_cast<NItem*>(item);
        return nitem->itemP;
    }
    return nullptr;
}

void ToDoLists::showPropertyBox(ItemProperty *itemP)
{
    m_curProperty=itemP;
    ui->stackedWidget_2->setCurrentIndex(0);
    QString text=itemP->getText();
    QString priority=itemP->getPriority();
    int index;
    for(index=0;index<4;index++){
        if(p[index]==priority)
            break;
    }
    QDate expTime=itemP->getExpirationTime();
    QDate remTime=itemP->getReminderTime();
    ui->lineEdit_text->setText(text);
    ui->comboBox_priority->setCurrentIndex(index);
    setRightTime(ui->dateEdit_expiration,expTime);
    setRightTime(ui->dateEdit_reminder,remTime);
}

void ToDoLists::setRightTime(QDateEdit *dateEdit, QDate date)
{
    //如果是默认值就设置成当前时间，如果已经设置了就显示设置好的时间
    if(date.toString("yyyy-MM-dd").length()==0)
        date=QDate::currentDate();
    dateEdit->setDate(date);
}

bool ToDoLists::comparePriority(const ItemProperty &i1, const ItemProperty &i2)
{
    int index1,index2;
    for(index1=0;index1<4;index1++){
        if(p[index1]==i1.getPriority())
            break;
    }
    for(index2=0;index2<4;index2++){
        if(p[index2]==i2.getPriority())
            break;
    }
    return index1<index2;

}

bool ToDoLists::compareExpiration(const ItemProperty &i1, const ItemProperty &i2)
{
    return i1.getExpirationTime()<i2.getExpirationTime();
}
