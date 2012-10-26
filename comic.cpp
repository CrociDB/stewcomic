#include "comic.h"

Comic::Comic(QDir &comicDir)
{
    loadComic(comicDir);
}

void Comic::loadComic(QDir &comicDir)
{
    dir = new QDir(comicDir);
    name = dir->dirName();
}

QStringList Comic::getPagesList()
{
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.gif";

    QStringList retList;

    foreach (QString file, dir->entryList(filters, QDir::Files, QDir::Name))
    {
        retList << dir->absoluteFilePath(file);
    }

    return retList;
}

QString Comic::getName()
{
    return name;
}
