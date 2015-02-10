#ifndef EXAMPLES_H
#define EXAMPLES_H

#include "cgo.h"
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QStandardItemModel>
#include <QCompleter>

using namespace std;

namespace Ui {
class Examples;
}

class Examples : public QMainWindow
{
    Q_OBJECT

public:
    explicit Examples(QWidget *parent = 0);
    ~Examples();

public:
    Cgo *cgo;
    QTimer *timer;
    QStringList *history;

public:
    void appendHistory(const QString&);
    void sendDisplay(const char *);
    int setCgo(Cgo*);

protected:
    bool eventFilter(QObject *obj, QEvent *ev);

private slots:
    void sendCommand();
    void sendMessage();

private slots:
    void on_quit_triggered();
    void on_clear_triggered();
    void on_connect_triggered();
    void on_help_triggered();
    void on_disconn_triggered();
    void on_network_triggered();
    void on_member_triggered();
    void on_save_triggered();

private:
    Ui::Examples *ui;

};

#endif // EXAMPLES_H
