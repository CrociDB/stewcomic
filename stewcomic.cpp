#include "stewcomic.h"
#include "ui_stewcomic.h"
#include "viewerwidget.h"

stewcomic::stewcomic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stewcomic)
{
    ui->setupUi(this);

    ui->tabWidget->clear();
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

    ViewerWidget *view = new ViewerWidget(ui->tabWidget);
    view->openComic(Comic(fe.getDir()));
    ui->tabWidget->addTab(view, fileName.mid(fileName.lastIndexOf("/")+1, fileName.length()).mid(0, 20));
}
