#ifndef LOGINFORUSER_H
#define LOGINFORUSER_H

#include <QDialog>
#include <map>
#include <QString>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(std::map<QString, QString> username_and_password, QWidget *parent = nullptr);
    ~login();
    std::map<QString , QString>username_and_passowrdadmin;


private slots:
    void on_returnbackpushbutton_clicked();
    void on_signupushbutton_clicked();
    void on_enterpsuhbutton_clicked();

private:
    Ui::login *ui;
    std::map<QString, QString> userDatabase; // Store the map passed to the constructor
};

#endif // LOGINFORUSER_H
