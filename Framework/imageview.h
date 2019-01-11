#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QWidget>

#include "framework_global.h"

class QImage;

class FRAMEWORKSHARED_EXPORT ImageView : public QWidget
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = nullptr);

public slots:
    void setImage(const QImage *pImage);
    void setImage(const QImage &image);

protected:
    void paintEvent(QPaintEvent *e);

private:
    QImage *m_pImage;
};

#endif // IMAGEVIEW_H
