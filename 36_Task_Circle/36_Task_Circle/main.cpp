//#include "_Task_Circle.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <qslider.h>
#include <QVBoxLayout>
#include <qpixmap.h>
#include <qsizepolicy.h>
#include <QPainter>
#include <QPaintEvent>
#include <qpushbutton.h>
#include <QGridLayout>

class ColorfulCircle:public QPushButton
{
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
public:
    ColorfulCircle() = default;
    ColorfulCircle(QWidget* parent)
    {
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        mGreenCircle = QPixmap("./green.png");
        mYellowCircle = QPixmap("./yellow.png");
        mRedCircle = QPixmap("./red.png");
        mCurrentCircle = mGreenCircle;
        setGeometry(mCurrentCircle.rect());
    }
    void paintEvent(QPaintEvent* e) override
    {
        QPainter p(this);
        p.drawPixmap(e->rect(), mCurrentCircle);
    }
    QSize sizeHint() const
    {
        return QSize(100, 100);
    }
public slots:
    void setGreen() //0-33
    {
        mCurrentCircle = mGreenCircle;
        update();
    }
    void setYellow() //33-66
    {  
        mCurrentCircle = mYellowCircle;
        update();
    }
    void setRed() //66-100
    {  
        mCurrentCircle = mRedCircle;
        update();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* window = new QWidget;
    auto* layout = new QGridLayout(window);
    auto* slider = new QSlider(Qt::Horizontal, window);
    ColorfulCircle circle(nullptr);

    slider->setMinimum(0);
    slider->setMaximum(100);
    circle.setFixedSize(300, 300);

    layout->addWidget(&circle,0,0);
    layout->addWidget(slider, 1,0);
    
    QObject::connect(slider, &QSlider::valueChanged, [&slider, &circle](int newValue)
    {
            if (newValue <= 33)
                circle.setGreen();
            else if (newValue > 33 && newValue <= 66)
                circle.setYellow();
            else if (newValue > 66)
                circle.setRed();
    });

    window->resize(300, 400);
    window->move(1000, 500);
    window->show();
    return a.exec();
}
