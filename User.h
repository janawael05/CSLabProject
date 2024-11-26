#ifndef USER_H
#define USER_H

#include <QString>
#include <QMap>
#include <QVector>

using namespace std;

class User {
public:
    // Constructor to initialize User with name, email, and password
    User(QString name, QString email, QString password);

    // Getter for user name
    QString getName() const;

    // Getter for user email
    QString getEmail() const;

    // Check if entered password matches the stored password
    bool checkPassword(const QString& password) const;

    // Book an event by event date (no longer by event name)
    void bookEvent(QString eventDate);
    // Display all booked events
    void viewBookings() const;

    // Static method to access the user database
    static QMap<QString, QString>& getUserDatabase();
    //void getUserDatabase();
    static void saveUsersToFile(const QMap<QString, QString> userDatabase, const std::string& filepath);


    // Static method to validate user credentials (username & password)
    static bool validateCredentials(const QString& username, const QString& password);

private:
    QString name;  // User's name
    QString email; // User's email
    QString password;  // User's password
    QVector<QString> bookedEvents;  // List of events the user has booked (now using event date)
};

#endif // USER_H
