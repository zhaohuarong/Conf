#include <QBuffer>
#include <QPainter>
//#include <QCoreApplication>
#include <QVideoProbe>
#include <QDebug>
#include <QCamera>
#include <QImage>
#include <QCameraImageCapture>

#include "usbcamera.h"

USBCamera::USBCamera(QObject *parent) :
    QObject(parent),
    m_pCamera(nullptr),
    m_pVideoProbe(nullptr)
{
    m_pCamera = new QCamera(this);
    m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
    setCameraProp();

    m_pVideoProbe = new QVideoProbe(this);

    if(m_pVideoProbe->setSource(m_pCamera))
    {
        connect(m_pVideoProbe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(detectBarcodes(QVideoFrame)));
    }
}

void USBCamera::start()
{
    m_pCamera->start();
}

void USBCamera::detectBarcodes(QVideoFrame frame)
{
    //qDebug() << "frame" << frame.size();
    QImage img = imageFromVideoFrame(frame);
    emit sigImage(img);
    //memcpy(m_pImage->bits(), img.bits(), static_cast<size_t>(img.sizeInBytes()));
    //update();
    //m_nFramePerSecond ++;
    ///////////////////// test size
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    img.save(&buffer, "jpg", 50);
    QByteArray arry;
    arry.append(buffer.data());
    qDebug() << "size:" << frame.size() << "buffer size:" << arry.size();
    buffer.reset();
    buffer.close();
    ///////////////////// test size
	//qApp->processEvents();
}

QImage USBCamera::imageFromVideoFrame(const QVideoFrame& buffer) const
{
    QImage img;
    QVideoFrame frame(buffer);  // make a copy we can call map (non-const) on
    frame.map(QAbstractVideoBuffer::ReadOnly);
    QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(
                frame.pixelFormat());
    // BUT the frame.pixelFormat() is QVideoFrame::Format_Jpeg, and this is
    // mapped to QImage::Format_Invalid by
    // QVideoFrame::imageFormatFromPixelFormat
    if (imageFormat != QImage::Format_Invalid) {
        img = QImage(frame.bits(),
                     frame.width(),
                     frame.height(),
                     // frame.bytesPerLine(),
                     imageFormat);
    } else {
        // e.g. JPEG
        int nbytes = frame.mappedBytes();
        img = QImage::fromData(frame.bits(), nbytes);
    }
    frame.unmap();
    return img;
}

void USBCamera::setCameraProp()
{
    QCameraViewfinderSettings set;
    QSize size(1280, 720);
    set.setResolution(size);
    //setGeometry(0, 0, size.width(), size.height());
    m_pCamera->setViewfinderSettings(set);
}
