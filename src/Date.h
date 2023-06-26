#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <ctime>

class Date {
private:
    std::chrono::system_clock::time_point tp;
    int day, month, year;

public:
    Date();
    Date(int day, int month, int year);
    ~Date();
    static int daysBetween(const Date& d1, const Date& d2);
    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void print() const;
};

#endif // DATE_H
