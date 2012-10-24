#ifndef DIRECTORYTOOLS_H
#define DIRECTORYTOOLS_H

#define APP_DIR         ".stewcomic"

#include <QDir>

class DirectoryTools
{
private:
    QDir *base_directory;

    void initBaseDirectory();

public:
    DirectoryTools();

    QDir& dir();
};

#endif // DIRECTORYTOOLS_H
