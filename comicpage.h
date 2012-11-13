#ifndef PAGE_H
#define PAGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>

class ComicPage : public QGraphicsItem
{
public:
    ComicPage();
    
    void loadFile(QString filename);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QBrush *imageBrush;
    QRectF rect;
    bool loaded;

signals:
    
public slots:
    
};

#endif // PAGE_H
