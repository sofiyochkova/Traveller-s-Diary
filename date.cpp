#include<fstream>
#include<iostream>
#include "date.hpp"

Date::Date(unsigned short _day, unsigned short _month, unsigned short _year)
    : day(_day), month(_month), year(_year)
{}


bool validate_date(const Date& _date)
{
    if(_date.get_day() >= 1 && _date.get_day() <= 31 && _date.get_month() >= 1 && _date.get_month() <= 12)
    {
        switch(_date.get_month())
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return _date.get_day() <= 31;
            case 4: case 6: case 9: case 11: return _date.get_day() <= 30;
        
            case 2: 
                if(_date.get_year() % 4 == 0) 
                    return _date.get_day() <= 29;
                else return _date.get_day() <= 28;
        }
    }
    
    return false;
}

std::istream& operator>>(std::istream& in, Date& _date)
{   
    char c;

    do{
        in >> _date.day;
        in.get(c);
        in >> _date.month;
        in.get(c);
        in >> _date.year;
    } while(!validate_date(_date));

    return in;
}

std::ostream& operator<<(std::ostream& out, Date& _date)
{
    return out << _date.get_day() << '.' << _date.get_month() << '.' << _date.get_year() << '\n';
}

bool Date::operator<(const Date& rhs) const
{
    //*this < rhs
    if(get_year() <= rhs.get_year())
    {
        if(get_month() <= rhs.get_month())
        {
            if(get_day() <= rhs.get_day())
            {
                return true;
            }
        }
    }

    return false;
}
