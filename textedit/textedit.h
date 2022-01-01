#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileInfo>
#include <QFileSystemModel>

#include "ui_textedit.h"
#include "repo.h"

// forward declaration
class QAction;

class Textedit : public QMainWindow {
  Q_OBJECT

 public:
  Textedit(QWidget *parent = Q_NULLPTR);
  ~Textedit();

  // File operations
  void openFile();
  void openFile(const QModelIndex &index);
  void openFile(QString path);
  void openDir();
  void saveFile();
  void newFile();

  // git 
  void gitInit();

 private:
  Ui::TexteditClass ui;
  QString path;
  QString cwd;
  QFileInfo info;
  QFileSystemModel modelDir;
  gitnote::Repo repo;

  // check if file path is default
  bool isFileDefault;
};
