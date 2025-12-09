#pragma once

#include <iostream>

const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 1970;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

class Date {
private:
  int d;
  int m;
  int y;

  int GetDaysInFeb(int year) const;

  int GetDaysInMonth(int month, int year) const;

  int GetDaysInYear(int year) const;

  bool IsCorrectDate() const;

  int DaysPassedToMonth(int month, int year) const;

  void SetFormDays(int inp_days);

public:
  Date(int day, int month, int year);

  int GetDay() const { return d; }

  int GetMonth() const { return m; }

  int GetYear() const { return y; }

  Date operator+(int k) const {
    Date result(*this);
    result.SetFormDays(result.GetDay() + k);
    return result;
  }

  Date operator-(int k) const {
    Date result(*this);
    result.SetFormDays(result.GetDay() - k);
    return result;
  }

  int operator-(const Date &order) const { return GetDay() - order.GetDay(); }
};
