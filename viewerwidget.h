#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QtWebKit>

class ViewerWidget : public QWebView
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = 0);

protected:
    
signals:
    
public slots:

};

#endif // VIEWERWIDGET_H
