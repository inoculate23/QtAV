#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace QtAV {
class AVPlayer;
class AVClock;
class VideoRenderer;
}

class QTimeEdit;
class QVBoxLayout;
class QLabel;
class QPushButton;
class Button;
class Slider;
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setRenderer(QtAV::VideoRenderer* renderer);
    void play(const QString& name);

public slots:
    void openFile();
    void togglePlayPause();

signals:
    void ready();

private slots:
    void processPendingActions();
    void initPlayer();
    void setupUi();
    void onStartPlay();
    void onStopPlay();
    void onPaused(bool p);
    void seekToMSec(int msec);
    void seek();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void timerEvent(QTimerEvent *);

private:
    bool mIsReady, mHasPendingPlay;
    int mTimerId;
    QVBoxLayout *mpPlayerLayout;

    QWidget *mpControl;
    QLabel *mpCurrent, *mpDuration;
    QLabel *mpTitle;
    Slider *mpTimeSlider;//, *mpVolumeSlider;
    Button *mpPlayPauseBtn, *mpStopBtn, *mpForwardBtn, *mpBackwardBtn;
    Button *mpOpenBtn;

    QtAV::AVClock *mpClock;
    QtAV::AVPlayer *mpPlayer;
    QtAV::VideoRenderer *mpRenderer, *mpTempRenderer;
    QString mFile;
    QPixmap mPlayPixmap;
    QPixmap mPausePixmap;
};

#endif // MAINWINDOW_H
