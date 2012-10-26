#include "stewcomic.h"
#include "ui_stewcomic.h"

stewcomic::stewcomic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stewcomic)
{
    ui->setupUi(this);
}

stewcomic::~stewcomic()
{
    delete ui;
}

void stewcomic::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QDir::homePath(), "Comics (*.cbz *.cbr)");

    QFile testFile(fileName);
    if (!testFile.exists()) return;

    FileExtractor fe(fileName, dir_tool.dir());
    fe.extractFile();

    ViewerWidget *widget = this->findChild<ViewerWidget*>("widget");
    widget->openComic(Comic(fe.getDir()));
}
