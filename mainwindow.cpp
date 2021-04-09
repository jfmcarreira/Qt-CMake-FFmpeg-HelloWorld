#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cFmtCtx = NULL;
}

bool MainWindow::parseArgs( int argc, char* argv[] )
{
  if ( argc > 1 )
  {
    m_filename = argv[1];

    /* open input file, and allocate format context */
    if (avformat_open_input(&m_cFmtCtx, m_filename.c_str(), NULL, NULL) < 0) {
      fprintf(stderr, "Could not open source file %s\n", m_filename.c_str());
      exit(1);
    }

    /* retrieve stream information */
    if (avformat_find_stream_info(m_cFmtCtx, NULL) < 0) {
      fprintf(stderr, "Could not find stream information\n");
      exit(1);
    }

    /* dump input information to stderr */
    av_dump_format(m_cFmtCtx, 0, m_filename.c_str(), 0);

  }
  return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
