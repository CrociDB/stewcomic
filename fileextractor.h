#ifndef FILEEXTRACTOR_H
#define FILEEXTRACTOR_H

#include <QString>
#include <QDir>
#include <QDebug>
#include <QRegExp>

#include <fex/fex.h>

#include "exceptions/ioexception.h"

class FileExtractor
{
private:
    QString fileName;
    QString treatedName;
    QDir extractedDir;

    QDir& createDir(QDir &dir);
    void fexError(fex_err_t err);
    QString treatName();


public:
    FileExtractor(QString filename, QDir &dir);

    void extractFile();
    QDir& getDir();
};

#endif // FILEEXTRACTOR_H
