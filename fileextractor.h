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
    static QDir& createDir(QString filename, QDir &dir);
    static void fexError(fex_err_t err);

public:
    FileExtractor();

    static void extractFile(QString filename, QDir& dir);
};

#endif // FILEEXTRACTOR_H
