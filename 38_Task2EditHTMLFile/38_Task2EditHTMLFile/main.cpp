/*Задача 2. Создайте приложение, в котором окно делится на две половины. В левой половине можно редактировать HTML-документ, а в правой — видеть результат WebView.*/
#include <QtGui/QtGui>
#include <QApplication>
#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <qfiledialog.h>
#include <qfuture.h>
#include <QtConcurrent/QtConcurrent>

void writeHtml(QString fileEdit, QWebEngineView *webView)
{
    webView->setHtml(fileEdit);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto* browWindow = new QWidget;
    auto* webView = new QWebEngineView;
    auto* fileEdit = new QPlainTextEdit;
    auto* hbox = new QHBoxLayout(browWindow);
    QString fileName;
    QFile file("HTMLFile.html");
    QSizePolicy policyEdit(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSizePolicy policyWeb(QSizePolicy::Preferred, QSizePolicy::Preferred);

    file.open(QFile::ReadWrite);
    //text edit    
    policyEdit.setHorizontalStretch(1);
    policyEdit.setVerticalStretch(0);
    fileEdit->setSizePolicy(policyEdit);
    hbox->addWidget(fileEdit);
    //web view    
    policyWeb.setHorizontalStretch(1);
    policyWeb.setVerticalStretch(0);
    webView->setSizePolicy(policyWeb);
    hbox->addWidget(webView);

    fileEdit->setPlainText(file.readAll());
    webView->setHtml(fileEdit->toPlainText());

    QObject::connect(fileEdit, &QPlainTextEdit::cursorPositionChanged, [webView, fileEdit]
    {
        webView->setHtml(fileEdit->toPlainText());
    });

    browWindow->show();
    file.close();
    return a.exec();
}
