#include "viewerwidget.h"

ViewerWidget::ViewerWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    scene->addText("Test");

    this->setScene(scene);
}

void ViewerWidget::openComic(Comic comic)
{
    qDebug() << "Gonna open this comic: " << comic.getName();

    QStringList fileInfo = comic.getPagesList();

    foreach (QString file, fileInfo)
    {
        qDebug() << "   ~> Page: " << file;
    }

    scene->setBackgroundBrush(QPixmap(fileInfo[0]));
}
