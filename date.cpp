#include<fstream>
#include<iostream>
#include "date.hpp"

bool Date::validate_date()
{
    if(day >= 1 && day <= 31 && month >= 1 && month <= 12)
    {
        switch(month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return day <= 31;
            case 4: case 6: case 9: case 11: return day <= 30;
        
            case 2: 
                if(year % 4 == 0) 
                    return day <= 29;
                else return day <= 28;
        }
    }
    
    return false;
}

void write_date_in_file(std::fstream file, Date& _date)
{
    file.write(reinterpret_cast<char*>(&_date), sizeof(Date));
}

std::istream& operator>>(std::istream& in, Date& _date)
{   
    char c;
    in >> _date.day;
    in.get(c);
    in >> _date.month;
    in.get(c);
    in >> _date.year;

    return in;
}

std::ostream& operator<<(std::ostream& out, Date& _date)
{
    return out << _date.day << '.' << _date.month << '.' << _date.year << '\n';
}

int main()
{
    Date d1;
    std::cin >> d1;

    std::cout << d1 << '\n';
    return 0;
}
