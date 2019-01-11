#ifndef USBCAMERA_H
#define USBCAMERA_H

#include <QObject>
#include <QVideoFrame>

#include "video_global.h"

class QCamera;
class QVideoProbe;
class QCameraImageCapture;

class VIDEOSHARED_EXPORT USBCamera : public QObject
{
    Q_OBJECT
public:
    explicit USBCamera(QObject *parent = nullptr);

public slots:
    void start();

signals:
    void sigImage(const QImage &img);

private slots:
    void detectBarcodes(QVideoFrame frame);

private:
    QImage imageFromVideoFrame(const QVideoFrame& buffer) const;
    void setCameraProp();

private:
    QCamera *m_pCamera;
    QVideoProbe *m_pVideoProbe;
};

#endif // USBCAMERA_H
