// DMMLogger - A logging software for digital multimeters
// Copyright 2013 Sergey Sharybin. All rights reserved.
//
// Author: sergey.vfx@gmail.com (Sergey Sharybin)

#ifndef UI_MAIN_H_
#define UI_MAIN_H_

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QTableWidget>
#include <QTimer>
#include <QWidget>

#include "dmm/dmm.h"
#include "dmm/trigger.h"

#include "ui/graph_widget.h"
#include "ui/reader_thread.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(void);
  ~MainWindow(void);

 public slots:
  void ToggleConnection(bool connect);
  void HandleTimer(void);

 private:
  QWidget *CreateCentralWidget(void);
  void ConnectToDMM(void);
  void DisconnectFromDMM(void);
  void UpdateDisplay(const DMMState &state);
  void UpdateGraph(void);
  void LogState(const DMMState &state);

  DMM *dmm_;
  Trigger *trigger_;
  ReaderThread *reader_thread_;

  QLabel *value_display_label_;
  GraphWidget *graph_display_;
  QTableWidget *values_table_;
  QTimer timer_;
  QPixmap graph_pixmap_;
};
#endif