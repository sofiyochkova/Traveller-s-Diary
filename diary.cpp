#include "travellers_diary.hpp"
#include<iostream>
#include<fstream>

Diary::Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, User_string *_photos)
    : destination(_destination), from(from), until(_until), grade(_grade), comment(_comment)
{
    // TODO: implement array of photo names
}

bool validate_grade(const unsigned short grade)
{
    return grade >= 1 && grade <= 5;
}

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

std::istream& operator>>(std::istream& in, Date& _date)
{
    in >> _date.day >> _date. month >> _date.year;
}

void Diary::read_diary_entry(Diary& new_diary)
{
    std::cout << "Enter destination:\n";
    std::cin >> new_diary.destination;

    do{
        std::cout << "Enter grade:\n";
        std::cin >> new_diary.grade;
    } while(!validate_grade(grade));

    do
    {
        std::cout << "Enter start date:\n";

        // TODO: operator>> for Date
        std::cin >> new_diary.from;

        std::cout << "Enter end date:\n";
        std::cin >> new_diary.until;
    } while (!(from.validate_date() && until.validate_date()));
    
}

void write_user_strings(std::ofstream& file, const Diary& new_diary)
{
    file.write(new_diary.get_destination().get_string(), new_diary.get_destination().get_size() + 1);

    file.write(reinterpret_cast<char*>(new_diary.get_grade()), 2);

    file.write(reinterpret_cast<char*>(&(new_diary.get_from_date())), sizeof(Date) + 1);

    file.write(reinterpret_cast<char*>(&(new_diary.get_until_date())), sizeof(Date) + 1);

    file.write(new_diary.get_comment().get_string(), new_diary.get_comment().get_size() + 2);

    // TODO: also for photos
}