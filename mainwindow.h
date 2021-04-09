#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QMainWindow>

extern "C" {
  #include <libavformat/avformat.h>
  #include <libavutil/avutil.h>
  #include <libavutil/imgutils.h>
  #include <libavutil/samplefmt.h>
  #include <libswscale/swscale.h>
}

namespace Ui {
class MainWindow;
}

struct AVFormatContext;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool parseArgs( int argc, char* argv[] );

private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    AVFormatContext* m_cFmtCtx;
    std::string m_filename;
};

#endif // MAINWINDOW_H
