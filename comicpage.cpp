#include "comicpage.h"

ComicPage::ComicPage()
{
    loaded = false;
}

void ComicPage::loadFile(QString filename)
{
    QPixmap pix(filename);
    imageBrush = new QBrush(pix);

    rect.setX(0);
    rect.setY(0);
    rect.setWidth(pix.width());
    rect.setHeight(pix.height());

    loaded = true;

    update(rect);
}

QRectF ComicPage::boundingRect() const
{
    return rect;
}

void ComicPage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!loaded) return;

    painter->fillRect(rect, *imageBrush);
}
