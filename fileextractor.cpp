#include "fileextractor.h"

QDir& FileExtractor::createDir(QString filename, QDir &dir)
{
    QDir *extractDir = new QDir(dir);

    QString newDirName(filename);
    newDirName.remove(QRegExp("[^\\]*[\\]"));
    newDirName.remove(QRegExp("[^/]*[/]"));
    newDirName.remove(QRegExp("[ #@!$]|[.].*"));

    if (!extractDir->exists(newDirName))
    {
        extractDir->mkdir(newDirName);
    }
    extractDir->cd(newDirName);

    return *extractDir;
}

void FileExtractor::extractFile(QString filename, QDir &dir)
{
    if (filename == NULL) return;

    QFile testFile(filename);
    if (!testFile.exists()) return;

    QDir newDir = FileExtractor::createDir(filename, dir);

    fex_t *fex;
    FileExtractor::fexError(fex_open(&fex, filename.toLocal8Bit().data()));

    int file_counter = 0;
    while (!fex_done(fex))
    {
        QString filename;

        if (fex_has_extension(fex_name(fex), ".jpg") || fex_has_extension(fex_name(fex), ".jpeg"))
        {
            filename = ".jpg";
        }
        else if (fex_has_extension(fex_name(fex), ".gif"))
        {
            filename = ".gif";
        }
        else if (fex_has_extension(fex_name(fex), ".png"))
        {
            filename = ".png";
        }

        filename.prepend(QString::number(file_counter++));
        filename.prepend("/");
        filename.prepend(newDir.absolutePath());

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

void FileExtractor::fexError(fex_err_t err)
{
    if ( err != NULL )
    {
        QString errDesc(fex_err_str(err));
        qDebug() << "FEX ERROR: " << errDesc;
        throw new Exception(errDesc, FEX_ERROR);
    }
}


FileExtractor::FileExtractor()
{
}
