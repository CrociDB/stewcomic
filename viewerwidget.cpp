#include "viewerwidget.h"

ViewerWidget::ViewerWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void ViewerWidget::initializeGL()
{
}

void ViewerWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ViewerWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
