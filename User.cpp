#include "User.h"
#include <QDebug>
#include <fstream>
#include <QMessageBox>
using namespace std;
// Constructor to initialize User with name, email, and password
User::User(QString name, QString email, QString password)
    : name(name), email(email), password(password) {}

// Getter for user name
QString User::getName() const {
    return name;
}

// Getter for user email
QString User::getEmail() const {
    return email;
}

// Check if entered password matches the stored password
bool User::checkPassword(const QString& inputPassword) const {
    return inputPassword == password;  // Return true if passwords match
}


// Display all booked events
void User::viewBookings() const {
    // Loop through the list of booked events and log each one
    for (const QString& event : bookedEvents) {
        qDebug() << "Booked Event on: " << event;  // Output the event date
    }
}

// Static method to access the user database
// QMap<QString, QString>& User::getUserDatabase() {
//     static QMap<QString, QString> userDatabase;  // Static map to store user credentials (username -> password)
//     if (userDatabase.isEmpty()) {
//         // Initialize the user database with some dummy users
//         userDatabase["Ahmed"] = "1234";
//         userDatabase["Jana"] = "2345";
//         userDatabase["Noor"] = "3456";
//     }
//     return userDatabase;  // Return the static user database
// }
 QMap<QString, QString>& User::getUserDatabase() {
//void User::getUserDatabase() {
    static QMap<QString, QString> userDatabase;
    if (userDatabase.isEmpty()) {
        userDatabase["Ahmed"] = "1234";
        userDatabase["Jana"] = "2345";
        userDatabase["Noor"] = "3456";
    }
    return userDatabase;
}
// void User::saveUsersToFile(const QMap<QString, QString> userDatabase, const string& filepath) {
//     // Open the file in truncation mode to clear its contents
//     ofstream outFile(filepath);
//     if (!outFile.is_open()) {
//         QMessageBox::warning(nullptr, "File Error", "Failed to open the file for saving.");
//         return;
//     }

//     // Write each user from the map into the file
//     // for (const auto& person : userDatabase) {
//     //     outFile << person.first.to << person.second;
//     // }
//     for (auto it = userDatabase.begin(); it != userDatabase.end(); ++it) {
//         outFile << it.key().toStdString() << " " << it.value().toStdString() << "\n";
//     }
//     outFile.close(); // Ensure the file is properly closed
//     QMessageBox::information(nullptr, "Save Successful", "Events have been saved successfully.");
// }
// // Static method to validate user credentials (username & password)
// bool User::validateCredentials(const QString& username, const QString& password) {
//     QMap<QString, QString>& userDatabase = getUserDatabase();  // Get the user database
//     return userDatabase.contains(username) && userDatabase[username] == password;  // Check if username exists and password matches
// }
