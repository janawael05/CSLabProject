#include "loginforadmins.h"
#include "AdminDashboard.h"
#include "ui_loginforadmins.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <cstdlib>
#include <map>
#include "EventBrowsingandBooking.h"

loginforadmins::loginforadmins(std::map<QString, QString> username_and_password, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginforadmins)
    // , username_and_passowrdadmin(std::move(username_and_password)) // Corrected variable name
{
    ui->setupUi(this);
    userDatabaseadmin = username_and_password;
}

loginforadmins::~loginforadmins()
{
    delete ui;
}
void loginforadmins::on_returnbackpushbutton_clicked()
{
    // Hide the current login window
    hide();

    // Retrieve the map of users and pass it back to the main window
    mainwindow *mainWin = new mainwindow(this);
    mainWin->show();
}

void loginforadmins::on_signupushbutton_clicked()
{
    QMessageBox::information(this, "Signup", "Signup functionality not yet implemented.");
}

void loginforadmins::on_enterpsuhbutton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    // Check if the username and password match
    if (userDatabaseadmin.find(username) != userDatabaseadmin.end() && userDatabaseadmin[username] == password) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
        hide();
        AdminDashboard *object = new AdminDashboard(this);
        object->loadEventsFromFile();
        object->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again.");
    }
}
