#include "itemproperty.h"
ItemProperty::ItemProperty(QString _text)
    :m_text(_text)
{
    m_priority="无";
    m_isRepeated=m_isFinished=false;
}

QString ItemProperty::getText() const
{
    return m_text;
}
QString ItemProperty::getPriority() const
{
    return m_priority;
}

QDate ItemProperty::getExpirationTime() const
{
    return m_expirationTime;
}

bool ItemProperty::getIsRepeated() const
{
    return m_isRepeated;
}

QDate ItemProperty::getReminderTime() const
{
    return m_reminderTime;
}

bool ItemProperty::getIsFinished() const
{
    return m_isFinished;
}

//QTreeWidgetItem *ItemProperty::getItem()
//{
//    return m_item;
//}

QTreeWidgetItem *ItemProperty::createItem()//每次返回item都会创建新item指针
{
    QString str=toString();
    QTreeWidgetItem* item=new NItem(QStringList()<<str,this);
    if(m_isFinished==false)
        item->setCheckState(0,Qt::Unchecked);
    else
        item->setCheckState(0,Qt::Checked);
    //    m_item=item;
    return item;
}

void ItemProperty::setText(QString _text)
{
    m_text=_text;
}

void ItemProperty::setPriority(QString _priority)
{
    m_priority=_priority;
}

void ItemProperty::setExpirationTime(QDate _expirationTime)
{
    m_expirationTime=_expirationTime;
}

void ItemProperty::setIsRepeated(bool _isRepeated)
{
    m_isRepeated=_isRepeated;
}

void ItemProperty::setReminderTime(QDate _reminderTime)
{
    m_reminderTime=_reminderTime;
}

void ItemProperty::setIsFinished(bool _isFinished)
{
    m_isFinished=_isFinished;
}

QString ItemProperty::toString()
{

    QString str=m_text+"\n";
    if(m_expirationTime.toString("yyyy-MM-dd").length()>0)
        str+=m_expirationTime.toString("yyyy-MM-dd")+"   |   ";
    else
        str+="我的待办   |   ";
    for(int index=0;index<4;index++){
        if(p[index]==m_priority)
        {
            str+="优先级:"+p[index]+"   |   ";
            break;
        }
    }

    str+=(m_isRepeated==true?"可重复":"不重复");
    return str;
}



