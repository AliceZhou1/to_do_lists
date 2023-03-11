#ifndef ITEMPROPERTY_H
#define ITEMPROPERTY_H
#include <QString>
#include <QtWidgets/QTreeWidget>
#include <QDate>
#include <QDateEdit>
#include "nitem.h"

static QString p[4]={"高","中","低","无"};
//ToBeDoneEvents 属性类型
class ItemProperty{
 public:
    ItemProperty(QString _text);
    QString getText() const;
    QString getPriority() const;
    QDate getExpirationTime() const;
    bool getIsRepeated() const;
    QDate getReminderTime() const;
    bool getIsFinished() const;
//    QTreeWidgetItem* getItem();
    QTreeWidgetItem* createItem();//根据属性返回item
    void setText(QString _text);
    void setPriority(QString _Priority);
    void setExpirationTime(QDate _expirationTime);
    void setIsRepeated(bool _isRepeated);
    void setReminderTime(QDate _reminderTime);
    void setIsFinished(bool _isFinished);
    QString toString();//设置item在widget显示的文本，为两行显示


 private:
//    QTreeWidgetItem* m_item;//当前属性对象在widget中的指针
    QString m_text;//正文
    QString m_priority;//优先级
    QDate m_expirationTime;//到期时间
    bool m_isRepeated;//是否重复
    bool m_isFinished;//是否已完成
    QDate m_reminderTime;//提醒时间
    setRightTime();
};


#endif//ITEMPROPERTY_H
