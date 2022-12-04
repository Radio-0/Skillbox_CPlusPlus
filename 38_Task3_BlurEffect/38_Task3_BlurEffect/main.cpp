#include <QtWidgets/QApplication>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <qsizepolicy.h>
#include <QFileDialog>
#include <QPixmap>
#include <qgraphicsscene.h>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QtConcurrent/QtConcurrent>
#include <QtGui/QtGui>
#include <QDir>

#include <iostream>

/*QImage blurImage(QImage source, int blurRadius)
{
    if (source.isNull())
        return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    auto* blur = new QGraphicsBlurEffect;
    QImage result(source.size(), QImage::Format_ARGB32);
    QPainter painter(&result);
    item.setPixmap(QPixmap::fromImage(source));
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    result.fill(Qt::transparent);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}

void processSingleImage(QString sourceFile, int blurRadius)
{
    auto blured = blurImage(QImage(sourceFile), blurRadius);
    blured.save(sourceFile + "blur");
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto* blurWindow = new QWidget;
    auto* vbox = new QVBoxLayout(blurWindow);
    auto* imageLabel = new QLabel;
    auto* sliderBlur = new QSlider(Qt::Horizontal, blurWindow);
    auto* pushOpen = new QPushButton("Open");
    QPixmap filePix;
    auto* blur = new QGraphicsBlurEffect;

    QSizePolicy policyImage(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSizePolicy policySlider(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy policyButton(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //label
    imageLabel->setMinimumSize(640, 480);
    policyImage.setHorizontalStretch(1);
    policyImage.setVerticalStretch(0);
    imageLabel->setSizePolicy(policyImage);
    vbox->addWidget(imageLabel);
    //slider
    sliderBlur->setMinimum(0);
    sliderBlur->setMaximum(10);
    policySlider.setHorizontalStretch(0);
    policySlider.setVerticalStretch(1);
    sliderBlur->setSizePolicy(policySlider);
    vbox->addWidget(sliderBlur);    
    //button
    policyButton.setHorizontalStretch(0);
    policyButton.setVerticalStretch(1);
    pushOpen->setSizePolicy(policyButton);
    vbox->addWidget(pushOpen);

    //QString filePath;

    QObject::connect(pushOpen, &QPushButton::clicked, [&filePix, imageLabel, sliderBlur, blur]
    {
        filePix = QFileDialog::getOpenFileName(nullptr, "Open image", ".\\", "Image file *.jpg");
        imageLabel->setPixmap(filePix.scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio));
        QObject::connect(sliderBlur, &QSlider::valueChanged, [&sliderBlur, imageLabel, filePix, blur](int newValue)
        {
            blur->setBlurRadius(newValue);
            imageLabel->setGraphicsEffect(blur);
            //processSingleImage(filePath, newValue);
            //filePix.save("Rocket_blur2.jpg");
        });
    });

    blurWindow->show();
    return a.exec();
}

