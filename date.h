#pragma once
// Date.h
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

// Enum for months
enum Months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
    SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

// Enum for display modes
enum Mode {
    DDDYYYY, MMDDYY, TEXT
};

// Date class declaration
class Date {
private:
    int day;
    int month;
    int year;
    static const int MONTHS_PER_YEAR = 12;
    static const int DAYS_PER_MONTH = 30;
    Mode mode;

    static Months dayToMonth(Date);

public:
    // Constructors
    Date(int dayOfYear, int year);
    Date(int month, int day, int year);
    Date(Months month, int day, int year);
    Date();

    // Destructor
    ~Date();

    // Setters
    void setDay(int);
    void setMonth(int);
    void setMonth(Months);
    void setYear(int);

    // Getters
    int getYear() const;
    int getDay() const;
    int getMonth() const;

    // Mode control
    void setMode(Mode);
    int getMode() const;

    // Print functions
    void print() const;
    void print0() const;
    void print1() const;
    void print2() const;
};

#endif // DATE_H