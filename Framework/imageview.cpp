#include <QPainter>

#include "imageview.h"

ImageView::ImageView(QWidget *parent) :
    QWidget(parent),
    m_pImage(nullptr)
{
}

void ImageView::setImage(const QImage *pImage)
{
    if(pImage == nullptr)
        return;

    if(m_pImage == nullptr)
    {
        m_pImage = new QImage(pImage->width(), pImage->height(), pImage->format());
    }

    memcpy(m_pImage->bits(), pImage->bits(), pImage->byteCount());
    update();
}

void ImageView::setImage(const QImage &image)
{
    setImage(&image);
}

void ImageView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    if(m_pImage == nullptr)
        return;
    QPainter painter(this);
    painter.drawImage(rect(), *m_pImage, QRect(QPoint(0, 0), m_pImage->size()));
}