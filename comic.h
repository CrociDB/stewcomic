#ifndef COMIC_H
#define COMIC_H

#include <QFileInfo>
#include <QFileInfoList>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QtDebug>

#include "directorytools.h"

class Comic
{
private:
    QString name;
    QDir *dir;

    int currentPage;
public:
    Comic(QDir& comicDir);

    void loadComic(QDir& comicDir);
    QStringList getPagesList();
    QString getName();
};

#endif // COMIC_H
