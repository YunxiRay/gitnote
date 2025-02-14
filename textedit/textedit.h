#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileInfo>
#include <QFileSystemModel>
#include <QTextCodec>

#include "ui_textedit.h"
#include "repo.h"
#include "dialoggitstatus.h"
#include"dialoggitremote.h"
#include "dialogauthssl.h"

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
  void startDialogGitStatus();
  void startDialogGitRemote();
  void gitPush();
  void gitFetch();
  void gitPull();

  // help
  void about();

 private:
  Ui::TexteditClass ui;

  // File System
  QString path;
  QString cwd;
  QFileInfo info;
  QFileSystemModel modelDir;

  //git
  gitnote::Repo repo;
  DialogGitStatus *gitStatus;
  DialogGitRemote *gitRemote;

  // check if file path is default
  bool isFileDefault;
  // check if git repo is opened. 
  bool isGitOpened = false;
};
