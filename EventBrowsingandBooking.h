/*#ifndef EVENTBROWSINGANDBOOKING_H
#define EVENTBROWSINGANDBOOKING_H

#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "BookingConfirmation.h"
#include "BookingHistory.h"
#include "Event.h"
#include <vector>

namespace Ui{
class EventBrowsingandBooking;
}

class EventBrowsingandBooking : public QDialog
{
    Q_OBJECT

public:
    explicit EventBrowsingandBooking( QWidget *parent = nullptr);
    ~EventBrowsingandBooking();

    void loadEventsFromFile();
    // vector<Event> saveToFile(const std::vector<Event>& events, const QString& filePath);
    void saveToFile(const std::vector<Event>& events, const QString& filePath);
    QString title;
    QString description;
    QString date;
    QString location;
    double ticketPrice;
    int availableSeats;
    void searchEventsByKeyword(const QString& keyword);
    vector<Event>event;


private slots:
    void on_bookEventButton_clicked();

    void on_bookingHistoryButton_clicked();

    void on_selectCategory_activated(int index);

    void on_searchEvents_textChanged(const QString &arg1);

    void on_searchEvents_textEdited(const QString &arg1);

    void on_searchEvents_returnPressed();

    void on_ENTERPUSH_BUTTON_clicked();

private:
    Ui::EventBrowsingandBooking *ui;
    QTableWidget *eventTable;
    BookingHistory *bookingHistoryWindow = nullptr;
    BookingConfirmation *bookingConfirmation;

};

#endif // EVENTBROWSINGANDBOOKING_H*/

#ifndef EVENTBROWSINGANDBOOKING_H
#define EVENTBROWSINGANDBOOKING_H

#include <QDialog>
#include <QTableWidget>
#include <QString>

namespace Ui {
class EventBrowsingandBooking;
}

class EventBrowsingandBooking : public QDialog
{
    Q_OBJECT

public:
    explicit EventBrowsingandBooking(QWidget *parent = nullptr);
    ~EventBrowsingandBooking();

private slots:
    void on_searchTextChanged(const QString &searchQuery);

public:
    Ui::EventBrowsingandBooking *ui;
    QTableWidget *eventTable;
    void loadEventsFromFile();
};

#endif // EVENTBROWSINGANDBOOKING_H