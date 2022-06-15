#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class settingswidget;
}

class settingswidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingswidget(QWidget *parent = nullptr);
    ~settingswidget();
    QButtonGroup *buttongroup,*buttongroup2;

private:
    Ui::settingswidget *ui;

signals:
    void ok(int,int,QString,QString);
};

#endif // SETTINGSWIDGET_H
