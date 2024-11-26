#include "loginforuser.h"
#include "ui_loginforuser.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <cstdlib>
#include <map>
#include "EventBrowsingandBooking.h"
#include <vector>
#include "Event.h"

login::login(std::map<QString, QString> username_and_password, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
    , userDatabase(std::move(username_and_password)) // Initialize userDatabase
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_returnbackpushbutton_clicked()
{
    hide();
    mainwindow *mainwindowWindow = new mainwindow(this);
    mainwindowWindow->show();
}

void login::on_signupushbutton_clicked()
{
    QMessageBox::information(this, "Signup", "Signup functionality not yet implemented.");
}

void login::on_enterpsuhbutton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString email =  ui->email->text();

    // Check if the username and password match
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
        hide();
        //vector<Event>vec;
         EventBrowsingandBooking *object = new EventBrowsingandBooking(this);
        // to take what inside the file of events that the admin can update
        object->loadEventsFromFile();
        object->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again.");
    }
}
