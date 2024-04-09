#include "../lib/QHotkey/QHotkey/QHotkey"
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QPalette>
#include <QSettings>
#include <QStyleFactory>

void set_dark() {
  qApp->setStyle(QStyleFactory::create("Fusion"));
  QPalette darkPalette;
  QColor darkColor = QColor(45, 45, 45);
  QColor disabledColor = QColor(127, 127, 127);
  darkPalette.setColor(QPalette::Window, darkColor);
  darkPalette.setColor(QPalette::WindowText, Qt::white);
  qApp->setPalette(darkPalette);
  QFile f(":qdarkstyle/dark/darkstyle.qss");
  if (!f.exists()) {
    printf("Unable to set stylesheet, file not found\n");
  } else {
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    qApp->setStyleSheet(ts.readAll());
  }
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow w;
  w.show();

#ifdef Q_OS_WIN
  QSettings settings(
      "HKEY_CURRENT_"
      "USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
      QSettings::NativeFormat);
  if (settings.value("AppsUseLightTheme") == 0)
    set_dark();
#else
  QPalette palette = app.palette();
  // 检查当前颜色主题是深色还是浅色
  if (palette.color(QPalette::Window).value() < 128) {
    set_dark();
    qDebug() << "dark mode";
  } else {
    qDebug() << "light mode";
  }
#endif

  QHotkey hotkey(QKeySequence("Ctrl+LEFT"), true, &app);
  qDebug() << "Is segistered:" << hotkey.isRegistered();
  QObject::connect(&hotkey, &QHotkey::activated, &w,
                   &MainWindow::change_visibility);

  return app.exec();
}
