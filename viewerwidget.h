#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtDebug>

#include <comic.h>

class ViewerWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = 0);

    void openComic(Comic comic);
protected:
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;
};

#endif // VIEWERWIDGET_H
