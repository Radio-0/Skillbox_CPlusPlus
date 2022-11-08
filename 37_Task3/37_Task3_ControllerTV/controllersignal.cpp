#include "controllersignal.h"

controllerSignal::controllerSignal(QObject *parent) : QObject{parent}
{

}
/*void controllerSignal::cppSlot(const QString &msg)
{
    QObject* numb1 = this->parent()->findChild<QObject*>("numb1");
    //QObject* numb2 = this->parent()->findChild<QObject*>("numb2");
    //QObject* numb3 = this->parent()->findChild<QObject*>("numb3");
    QObject* canal = this->parent()->findChild<QObject*>("canal");
    bool click = false;
    //click = numb1->property("onClicked").toBool();

    //QString str1 = (numb1->property("onClicked")).toString();
    //canal->setProperty("text", msg + str1);
    //int a = str1.toInt();
    //QString res = QString::number(a);
    //canal->setProperty("text", res);
}*/
void controllerSignal::clickSlot()
{
    QObject* canal = this->parent()->findChild<QObject*>("canal");
    canal->setProperty("text", "0");
}
