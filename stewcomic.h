#ifndef STEWCOMIC_H
#define STEWCOMIC_H

#define __MACOS__

#include <QMainWindow>

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
};

#endif // STEWCOMIC_H
