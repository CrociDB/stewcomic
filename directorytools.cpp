#include "directorytools.h"

QDir &DirectoryTools::dir()
{
    return *base_directory;
}


DirectoryTools::DirectoryTools()
{
    initBaseDirectory();
}

void DirectoryTools::initBaseDirectory()
{
    base_directory = new QDir(QDir::homePath());
    if (!base_directory->exists(APP_DIR))
    {
        base_directory->mkdir(APP_DIR);
    }

    base_directory->cd(APP_DIR);
}

