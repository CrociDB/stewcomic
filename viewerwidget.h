#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QtOpenGL/QGLWidget>

class ViewerWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    
signals:
    
public slots:
    
};

#endif // VIEWERWIDGET_H
