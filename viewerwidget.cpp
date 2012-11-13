#include "viewerwidget.h"

ViewerWidget::ViewerWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();

    this->setScene(scene);

    currentPage = NULL;

    this->autoFillBackground();
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
}

void ViewerWidget::previousPage()
{
    currentPageNumber = currentPageNumber == 0 ? currentPageNumber : currentPageNumber - 1;

    scene->removeItem(currentPage);
    delete currentPage;
    currentPage = new ComicPage();
    currentPage->loadFile(fileInfo[currentPageNumber]);
    scene->addItem(currentPage);
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
}
