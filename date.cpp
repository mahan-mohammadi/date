// Date.cpp
#include "Date.h"
#include <iostream>

using namespace std;

// Helper function to calculate days in a month (simplified)

    int daysInMonth(int month, int year) {
        if (month == 2) return 28; // No leap year support
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        return 31;
    }


// Static member function
Months Date::dayToMonth(Date d) {
    return static_cast<Months>(d.month);
}

// Constructors
Date::Date(Months m, int d, int y) : year(y), mode(TEXT) {
    month = m;
    int maxDays = daysInMonth(m, y);
    day = (d >= 1 && d <= maxDays) ? d : 1;
}

Date::Date(int m, int d, int y) : year(y), mode(MMDDYY) {
    month = (m >= 1 && m <= MONTHS_PER_YEAR) ? m : 1;
    int maxDays = daysInMonth(month, y);
    day = (d >= 1 && d <= maxDays) ? d : 1;
}

Date::Date(int dayOfYear, int y) : year(y), mode(DDDYYYY) {
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int m = 1;
    while (dayOfYear > monthDays[m - 1]) {
        dayOfYear -= monthDays[m - 1];
        m++;
    }
    month = m;
    day = dayOfYear;
}

Date::Date() : day(1), month(1), year(1970), mode(MMDDYY) {}

// Destructor
Date::~Date() {}

// Setters
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setMonth(Months m) { month = m; }
void Date::setYear(int y) { year = y; }

// Getters
int Date::getYear() const { return year; }
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }

// Mode control
void Date::setMode(Mode m) { mode = m; }
int Date::getMode() const { return mode; }

// Print functions
void Date::print() const {
    switch (mode) {
    case DDDYYYY: print0(); break;
    case MMDDYY: print1(); break;
    case TEXT: print2(); break;
    }
}

void Date::print0() const {
    cout << day << "-" << month << "-" << year;
}

void Date::print1() const {
    cout << month << "/" << day << "/" << year % 100;
}

void Date::print2() const {
    cout << static_cast<Months>(month) << " " << day << ", " << year;
}