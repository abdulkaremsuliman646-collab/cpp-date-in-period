#include <iostream>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

bool IsDate1BeforeDate2(const stDate& Date1, const stDate& Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
            ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(const stDate& Date1, const stDate& Date2)
{
    return (Date1.Year == Date2.Year) &&
        (Date1.Month == Date2.Month) &&
        (Date1.Day == Date2.Day);
}

bool IsDate1AfterDate2(const stDate& Date1, const stDate& Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enDateCompare CompareDates(const stDate& Date1, const stDate& Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsOverlapPeriods(const stPeriod& Period1, const stDate& Period2)
{
    if (
        CompareDates(Period2, Period1.StartDate) == enDateCompare::Before
        ||
        CompareDates(Period2, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true;
}

short ReadDay()
{
    short Day;
    cout << "Please enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{
    cout << "Enter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stDate Period2 = ReadFullDate();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";

    system("pause>0");
    return 0;
}