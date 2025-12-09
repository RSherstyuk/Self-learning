#include "Date.h"

int Date::GetDaysInFeb(int year) const {
  if ((!year % 4) and (year % 100) || !(year % 400)) {
    return 29;
  }
  return 28;
}

int Date::GetDaysInMonth(int month, int year) const {
  switch (month) {
  case 2:
    return GetDaysInFeb(year);
  case 1:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  default:
    return 30;
  }
}

int Date::GetDaysInYear(int year) const {
  return DAYS_IN_YEAR_WITHOUT_FEB + GetDaysInFeb(year);
}

bool Date::IsCorrectDate() const {
  return GetMonth() <= 12 && GetDay() <= 31 && GetMonth() >= 1;
}

Date::Date(int day, int month, int year) : d{day}, m{month}, y{year} {
  if (!IsCorrectDate()) {
    d = DEFAULT_DATE_DAY;
    m = DEFAULT_DATE_MONTH;
    y = DEFAULT_DATE_YEAR;
  }
};
