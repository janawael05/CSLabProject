#ifndef LOGINFORADMINS_H
#define LOGINFORADMINS_H

#include <QDialog>
#include <map>
#include <QString>

namespace Ui {
class loginforadmins;
}

class loginforadmins : public QDialog
{
    Q_OBJECT

public:
    explicit loginforadmins(std::map<QString, QString> username_and_password, QWidget *parent = nullptr);
    ~loginforadmins();

private slots:
    void on_returnbackpushbutton_clicked();
    void on_signupushbutton_clicked();
    void on_enterpsuhbutton_clicked();

private:
    Ui::loginforadmins *ui;
    std::map<QString, QString> userDatabaseadmin; // Corrected member variable name
};

#endif // LOGINFORADMINS_H
