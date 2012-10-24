#ifndef STEWCOMIC_H
#define STEWCOMIC_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include "directorytools.h"
#include "fileextractor.h"

namespace Ui {
class stewcomic;
}

class stewcomic : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit stewcomic(QWidget *parent = 0);
    ~stewcomic();
    
private:
    Ui::stewcomic *ui;
    DirectoryTools dir_tool;

private slots:
    void on_actionOpen_triggered();
};

#endif // STEWCOMIC_H
