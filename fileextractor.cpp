#include "fileextractor.h"

QDir& FileExtractor::createDir(QDir &dir)
{
    QDir *extractDir = new QDir(dir);

    if (!extractDir->exists(treatedName))
    {
        extractDir->mkdir(treatedName);
    }
    extractDir->cd(treatedName);

    return *extractDir;
}

QString FileExtractor::treatName()
{
    QString newDirName(fileName);
    newDirName.remove(QRegExp("[^\\]*[\\]"));
    newDirName.remove(QRegExp("[^/]*[/]"));
    newDirName.remove(QRegExp("[ #@!$]|[.].*"));

    return newDirName;
}

void FileExtractor::extractFile()
{
    fex_t *fex;
    FileExtractor::fexError(fex_open(&fex, fileName.toLocal8Bit().data()));

    int file_counter = 0;
    while (!fex_done(fex))
    {
        QString filename;

        if (fex_has_extension(fex_name(fex), ".jpg") || fex_has_extension(fex_name(fex), ".jpeg"))
        {
            filename = ".jpg";
            treatedName = treatName();
            extractedDir = createDir(dir);
        }
        else if (fex_has_extension(fex_name(fex), ".gif"))
        {
            filename = ".gif";
        }
        else if (fex_has_extension(fex_name(fex), ".png"))
        {
            filename = ".png";
        }

        QString num;
        num.sprintf("%06d", file_counter++);
        filename.prepend(num);
        filename.prepend("/");
        filename.prepend(extractedDir.absolutePath());

        fex_stat(fex);
        int data_size = fex_size(fex);
        char *data_content = (char*) malloc(data_size);
        fex_read(fex, data_content, data_size);

        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QDataStream stream(&file);
        stream.writeRawData(data_content, data_size);
        file.close();

        fex_next(fex);
    }

    fex_close(fex);
}

QDir &FileExtractor::getDir()
{
    return extractedDir;
}

void FileExtractor::fexError(fex_err_t err)
{
    if ( err != NULL )
    {
        QString errDesc(fex_err_str(err));
        qDebug() << "FEX ERROR: " << errDesc;
        exit(-1);
    }
}

FileExtractor::FileExtractor(QString filename, QDir& dir)
{
    fileName = filename;
    treatedName = treatName();
    extractedDir = createDir(dir);
}
