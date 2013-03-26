#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QGraphicsView>
#include <QScrollBar>
#include <QGraphicsScene>
#include <QtDebug>
#include <QKeyEvent>

#include <comic.h>

#include "comicpage.h"

class ViewerWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = 0);

    void openComic(Comic comic);
    void nextPage();
    void previousPage();

protected:
    void keyPressEvent(QKeyEvent *event);
    void zoomIn();
    void zoomOut();
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;

    QStringList fileInfo;

    int currentPageNumber;
    ComicPage *currentPage;
};

#endif // VIEWERWIDGET_H
