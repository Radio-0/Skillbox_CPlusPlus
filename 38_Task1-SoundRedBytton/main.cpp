#include <QtGui/QtGui>
#include <QApplication>
#include <qpushbutton.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <QPaintEvent>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaContent>
#include <QVBoxLayout>
#include <QFileDialog>
#include <iostream>
using namespace std;

class ImageButton : public QPushButton
{
    Q_OBJECT
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
public:
    ImageButton() = default;
    ImageButton(QWidget* parent)
    {
        setParent(parent);
        setToolTip("Stop");
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        mButtonUpPixmap = QPixmap("..\\38_Task1-SoundRedBytton\\up.bmp");
        mButtonDownPixmap = QPixmap("..\\38_Task1-SoundRedBytton\\down.bmp");
        mCurrentButtonPixmap = mButtonUpPixmap;
        setGeometry(mCurrentButtonPixmap.rect());
        connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
    }
    void paintEvent(QPaintEvent* e) override
    {
        QPainter p(this);
        p.drawPixmap(e->rect(), mCurrentButtonPixmap);
    }
    void keyPressEvent(QKeyEvent* e) override
    {
        setDown();
    }
public slots:
    void setUp()
    {
        mCurrentButtonPixmap = mButtonUpPixmap;
        update();
    }
    void setDown()
    {
        mCurrentButtonPixmap = mButtonDownPixmap;
        update();
        QTimer::singleShot(100, this, &ImageButton::setUp);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget buttonWindow;
    QVBoxLayout vbox(&buttonWindow);
    ImageButton redButton(nullptr);
    auto *player = new QMediaPlayer(&buttonWindow);
    QString filePathSound;
    redButton.setFixedSize(200,200);
    buttonWindow.setFixedSize(150,150);
    buttonWindow.move(1000,400);
    vbox.addWidget(&redButton);
    QObject::connect(&redButton, &QPushButton::clicked, [&filePathSound, player]
    {
        cout << "click\n";
        player->setMedia(QUrl::fromLocalFile("..\\38_Task1-SoundRedBytton\\click.mp3"));
        player->setVolume(75);
        player->play();
    });
    buttonWindow.show();
    return a.exec();
}

#include <main.moc>

