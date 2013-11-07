
/*********************************************
 *                                           *
 *  This program calculates the number of    *
 *  days elapsed between the two dates       *
 *  entered by the user.                     *
 *                                           *
 *  Copyright Maria Valentina Carlucci 2013  *
 *                                           *
 *********************************************/

#include <iostream>
#include <string>
using namespace std;

// a data structure for the dates
struct date {
    int day;
    int month;
    int year;
};

// function to enter the dates
void get_date (string in_or_fin, date &adate) {
    cout << "Enter the " << in_or_fin << " day, month, year, separated by spaces, then return: ";
    cin >> adate.day >> adate.month >> adate.year;
}

// this function returns 1 if the year is leap, 0 otherwise
int leap_check (int ayear){
    int check;
    if ((ayear%4 == 0 && ayear%100 != 0) || ayear%400 == 0) {
        check = 1;
    } else {
        check = 0;
    }
    return check;
}

int main () {
    
    // getting the date
    date in_date, fin_date;
    get_date ("initial", in_date);
    get_date ("final", fin_date);
    
    // here we count the days only in the complete years between the two dates
    int num_leap_betw = 0;
    for (int ayear = in_date.year+1; ayear < fin_date.year; ayear++) {
        num_leap_betw += leap_check(ayear);
    }
    int days_int_years = (fin_date.year-in_date.year-1)*365 + num_leap_betw;
    
    // now we pass to the complete months of the initial and final years
    int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days_int_in_month = 0;
    int days_int_fin_month = 0;
    for (int amonth = in_date.month+1; amonth <= 12; amonth++) {
        days_int_in_month += month_days[amonth-1];
    }
    if (in_date.month == 1) {
        days_int_in_month += leap_check(in_date.year);
    }
    for (int amonth = 1; amonth < fin_date.month; amonth++) {
        days_int_fin_month += month_days[amonth-1];
    }
    if (fin_date.month >= 3) {
        days_int_fin_month += leap_check(fin_date.year);
    }
    
    // finally, the spare days
    int spare_days_in = month_days[in_date.month-1] - in_date.day;
    if (in_date.month == 2 && leap_check(in_date.year) == 1 && in_date.day != 29) {
        spare_days_in++;
    }
    int spare_days_fin = fin_date.day;
    
    // drumroll
    int grandtotal = days_int_years + days_int_in_month + days_int_fin_month + spare_days_in + spare_days_fin;
    cout << "Elapsed days: " << grandtotal << endl;
    return 0;
}


