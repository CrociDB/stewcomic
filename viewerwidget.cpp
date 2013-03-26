#include "viewerwidget.h"

ViewerWidget::ViewerWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();

    this->setScene(scene);

    currentPage = NULL;

    this->autoFillBackground();
    this->setDragMode(QGraphicsView::ScrollHandDrag);
}

void ViewerWidget::openComic(Comic comic)
{
    qDebug() << "Gonna open this comic: " << comic.getName();

    fileInfo = comic.getPagesList();

    foreach (QString file, fileInfo)
    {
        qDebug() << "   ~> Page: " << file;
    }

    currentPage = new ComicPage();
    scene->addItem(currentPage);

    currentPageNumber = 0;
    currentPage->loadFile(fileInfo[currentPageNumber]);
}

void ViewerWidget::nextPage()
{
    currentPageNumber = currentPageNumber == fileInfo.size() - 1 ? currentPageNumber : currentPageNumber + 1;

    scene->removeItem(currentPage);
    delete currentPage;
    currentPage = new ComicPage();
    currentPage->loadFile(fileInfo[currentPageNumber]);
    scene->addItem(currentPage);

    QScrollBar *y = this->verticalScrollBar();
    y->setValue(0);
}

void ViewerWidget::previousPage()
{
    currentPageNumber = currentPageNumber == 0 ? currentPageNumber : currentPageNumber - 1;

    scene->removeItem(currentPage);
    delete currentPage;
    currentPage = new ComicPage();
    currentPage->loadFile(fileInfo[currentPageNumber]);
    scene->addItem(currentPage);

    QScrollBar *y = this->verticalScrollBar();
    y->setValue(0);
}

void ViewerWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right)
    {
        nextPage();
    }
    else if (event->key() == Qt::Key_Left)
    {
        previousPage();
    }
    else if (event->key() == Qt::Key_Down)
    {
        QScrollBar *y = this->verticalScrollBar();
        y->setValue(y->value() + 20);
    }
    else if (event->key() == Qt::Key_Up)
    {
        QScrollBar *y = this->verticalScrollBar();
        y->setValue(y->value() - 20);
    }
    else if (event->key() == Qt::Key_Equal)
    {
        zoomIn();
    }
    else if (event->key() == Qt::Key_Minus)
    {
        zoomOut();
    }
}

void ViewerWidget::zoomIn()
{
    scale(1.1, 1.1);
}

void ViewerWidget::zoomOut()
{
    scale(0.9, 0.9);
}
