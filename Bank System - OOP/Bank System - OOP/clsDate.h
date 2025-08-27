#pragma once
#pragma warning(disable :4996)

#include <iostream>
#include <iomanip>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
	short _Year;
	short _Month;
	short _Day;

	enum enCompareDates {
		Before = -1, Equal = 0, After = 1
	};

public:

	clsDate() {
	
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;

	}

	clsDate(string sDate) {
		vector <string> vDate = clsString::Split(sDate, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day,short Month,short Year) {
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}

	clsDate(short DayOrderInYear,short Year) {

		clsDate Date1 = GetDateFromDayOrderInAYear(DayOrderInYear, Year);
		this->_Year = Date1._Year;
		this->_Month = Date1._Month;
		this->_Day = Date1._Day;
	}

	void Print() {

		cout << DateToString() << endl;
	}

	void SetYear(short Year) {
		this->_Year = Year;
	}

	short GetYear() {
		return _Year;
	}

	void SetMonth(short Month) {
		this->_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}

	void SetDay(short Day) {
		this->_Day = Day;
	}

	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	static bool IsValidDate(clsDate Date) {

		if (Date._Day > NumberOfDaysInMonth(Date._Month, Date._Year) || Date._Month > 12)
			return false;
		else
			return true;

	}

	bool IsValid() {
		return IsValidDate(*this);
	}

	static bool IsLeapYear(short Year) {

		return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
	}

	bool IsLeapYear() {
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year) {
		return IsLeapYear(Year) ? 366 : 365;

	}

	short NumberOfDaysInYear() {
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year) {
		return NumberOfDaysInYear(Year) * 24;
	}
	short NumberOfHoursInYear() {
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year) {
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear() {
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year) {
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear() {
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year) {
		if (Month > 12 || Month < 1)
			return 0;

		short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

	}

	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Year, short Month) {
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	short NumberOfHoursInMonth() {
		return NumberOfHoursInMonth(_Year, _Month);
	}

	static int NumberOfMinutesInMonth(short Year, short Month) {
		return NumberOfHoursInMonth(Year, Month) * 60;
	}

	int NumberOfMinutesInMonth() {
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecondsInMonth(short Year, short Month) {
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInMonth() {
		return NumberOfSecondsInMonth(_Year,_Month);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year) {

		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date) {
		return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}

	short DayOfWeekOrder() {
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayName(short DayOfWeekOrder) {

		string DayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };


		return DayNames[DayOfWeekOrder];
	}

	string DayName() {
		return DayName(DayOfWeekOrder());
	}

	static string MonthName(short Month) {

		string MonthNames[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return MonthNames[Month - 1];
	}

	string MonthName() {
		return MonthName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year) {

		printf("\n_________________%s_________________\n", MonthName(Month).c_str());
		cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		short DayOrder = DayOfWeekOrder(1, Month, Year);
		short NumberOfDays = NumberOfDaysInMonth(Month, Year);

		short Counter = 1, DayOrderCounter = DayOrder;

		int i;
		for (i = 0; i < DayOrder;i++)
			cout << "     ";

		for (short j = 1; j <= NumberOfDays;j++) {
			cout << setw(5) << j;
			if (++i == 7) {
				i = 0;
				cout << endl;
			}

		}


		cout << "\n_____________________________________\n";

	}

	void PrintMonthCalendar() {
		return PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short Year) {
		printf("\n ___________________________________\n");
		printf("\n\t  Calendar - %d", Year);
		printf("\n ___________________________________\n\n");
		for (short i = 1; i <= 12;i++) {
			PrintMonthCalendar(i, Year);
		}
	}

	void PrintYearCalendar() {
		return PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year) {
		short TotalDays = 0;

		for (short i = 1; i < Month;i++) {
			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		TotalDays += Day;
		return TotalDays;
	}

	short NumberOfDaysFromTheBeginningOfTheYear() {
		return NumberOfDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInAYear(short DayOrder, short Year) {
		clsDate sDate;

		short RemainingDays = DayOrder;
		short MonthDays = 0;
		sDate._Month = 1;
		sDate._Year = Year;

		while (true) {
			MonthDays = NumberOfDaysInMonth(sDate._Month, Year);

			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				sDate._Month++;
			}
			else {
				sDate._Day = RemainingDays;
				break;
			}
		}
		return sDate;
	}

	static clsDate DateAddDays(short Days, clsDate& sDate) {


		short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(sDate._Day, sDate._Month, sDate._Year);

		sDate._Month = 1;

		short MonthDays = 0;

		while (true) {

			MonthDays = NumberOfDaysInMonth(sDate._Month,sDate._Year);

			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				sDate._Month++;

				if (sDate._Month > 12) {
					sDate._Month = 1;
					sDate._Year++;
				}
			}
			else {
				sDate._Day = RemainingDays;
				break;
			}

		}

		return sDate;
	}

	void DateAddDays(short Days) {
		DateAddDays(Days, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month) ? true :
			((Date1._Month == Date2._Month) ? Date1._Day < Date2._Day : false) : false);

	}

	bool IsDateBeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;

	}

	bool IsDateEqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInYear(clsDate Date) {

		return (Date._Day == 31 && Date._Month == 12);

	}

	bool IsLastDayInYear() {
		return IsLastDayInYear(*this);
	}

	static bool IsLastDayInMonth(clsDate Date) {

		return (NumberOfDaysInMonth(Date._Month, Date._Year) == Date._Day);

	}

	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month) {
		return (Month == 12);
	}

	bool IsLastMonthInYear() {
		return IsLastMonthInYear(_Month);
	}

	static clsDate AddOneDay(clsDate Date) {

		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date._Month)) {
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;

			}
			else {
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
			Date._Day++;

		return Date;
	}
	void AddOneDay() {
		*this = AddOneDay(*this);
	}

	static string DateToString(clsDate Date) {
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString() {
		return DateToString(*this);
	}

	static clsDate GetSystemDate() {
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_mday;
		return Date;
	}
	
	static void SwapDates(clsDate& Date1, clsDate& Date2) {
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static short GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		short Days = 0;
		short SwapFlag = 1;

		if (!IsDate1BeforeDate2(Date1, Date2)) {
			SwapDates(Date1, Date2);
			SwapFlag = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2)) {
			Date1 = AddOneDay(Date1);
			Days++;
		}


		return IncludeEndDay ? (SwapFlag * ++Days) : (SwapFlag * Days);
	}

	short GetDifferenceInDays(clsDate Date2) {
		return GetDifferenceInDays(*this, Date2);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth) {
		return GetDifferenceInDays(DateOfBirth, GetSystemDate(), true);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, short Days) {

		for (short i = 1; i <= Days; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days) {
		IncreaseDateByXDays(*this,Days);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date) {
		Date = IncreaseDateByXDays(Date, 7);
		return Date;
	}

	void IncreaseDateByOneWeek() {
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, short Days) {
		for (short i = 1; i <= Days; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Days) {
		IncreaseDateByXWeeks(*this, Days);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date) {

		if (IsLastMonthInYear(Date._Month)) {
			Date._Month = 1;
			Date._Year++;
		}
		else
			Date._Month++;

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month,Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth) {
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth() {
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate& Date, short Days) {
		for (short i = 1; i <= Days; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Days) {
		IncreaseDateByXMonths(*this, Days);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date) {
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear() {
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate& Date, short Days) {

		Date._Year += Days;
		return Date;

	}

	void IncreaseDateByXYears(short Days) {
		IncreaseDateByXYears(*this, Days);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date) {
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade() {
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate& Date, short Days) {
		Date._Year += Days * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Days) {
		IncreaseDateByXDecades(*this, Days);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date) {
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury() {
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillenium(clsDate& Date) {

		Date._Year += 1000;

		return Date;
	}

	void IncreaseDateByOneMillenium() {
		IncreaseDateByOneMillenium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date) {

		if (Date._Day == 1) {
			if (Date._Month == 1) {
				Date._Year--;
				Date._Month = 12;
				Date._Day = 31;

			}
			else {
				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);

			}
		}
		else {
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, short Days) {

		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days) {
		DecreaseDateByXDays(*this,Days);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		for (short i = 1; i <= 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short Days) {
		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Days) {
		DecreaseDateByXWeeks(*this, Days);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {

		if (Date._Month == 1) {
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth) {
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static 	clsDate DecreaseDateByXMonths(clsDate& Date, short Months) {
		for (short i = 1; i <= Months; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months) {
		DecreaseDateByXMonths(*this, Months);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {
		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate& Date, short Years) {

		Date._Year -= Years;
		return Date;

	}

	void DecreaseDateByXYears(short Years) {
		DecreaseDateByXYears(*this, Years);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date) {
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, short Decades) {
		Date._Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades) {
		DecreaseDateByXDecades(*this, Decades);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date) {
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury() {
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillenium(clsDate& Date) {

		Date._Year -= 1000;

		return Date;
	}

	void DecreaseDateByOneMillenium() {
		DecreaseDateByOneMillenium(*this);
	}

	static bool IsEndOfWeek(clsDate Date) {
		return (DayOfWeekOrder(Date) == 6);
	}

	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekend(clsDate Date) {
		short DayOrder = DayOfWeekOrder(Date);
		return (DayOrder == 6 || DayOrder == 5);
	}

	bool IsWeekend() {
		return IsWeekend(*this);
	}

	static bool IsBusinessDay(clsDate Date) {

		return (!IsWeekend(Date));
	}

	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date) {
		short DayOrder = DayOfWeekOrder(Date);
		return 6 - DayOrder;
	}

	bool DaysUntilEndOfWeek() {
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date) {
		clsDate EndOfMonthDate;
		EndOfMonthDate._Day = NumberOfDaysInMonth( Date._Month, Date._Year);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);

	}

	bool DaysUntilEndOfMonth() {
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date) {
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	bool DaysUntilEndOfYear() {
		return DaysUntilEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate Start, clsDate End) {

		short DaysCounter = 0;

		while (IsDate1BeforeDate2(Start, End)) {

			if (IsBusinessDay(Start))
				DaysCounter++;

			Start = AddOneDay(Start);

		}
		return DaysCounter;
	}

	static short CalculateVacationDays(clsDate Start, clsDate End) {
		return CalculateBusinessDays(Start, End);
	}

	static clsDate CalculateVacationReturnDate(clsDate StartDate, short VacationDays) {
		short WeekEndCounter = 0;

		while (IsWeekend(StartDate))
			StartDate = AddOneDay(StartDate);

		for (short i = 1; i <= VacationDays + WeekEndCounter;i++) {

			if (IsWeekend(StartDate))
				WeekEndCounter++;

			StartDate = AddOneDay(StartDate);

		}

		while (IsWeekend(StartDate))
			StartDate = AddOneDay(StartDate);

		return StartDate;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(clsDate Date2) {
		return (IsDate1AfterDate2(*this, Date2));
	}

	static enCompareDates CompareDates(clsDate Date1, clsDate Date2) {
		if (IsDate1BeforeDate2(Date1, Date2))
			return enCompareDates::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enCompareDates::Equal;

		return enCompareDates::After;

	}

	enCompareDates CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}
	
};