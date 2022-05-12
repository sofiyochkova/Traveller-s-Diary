#include<iostream>
#include<fstream>
#include "diary.hpp"

Diary::Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, User_string _photos[])
    : destination(_destination), from(_from), until(_until), grade(_grade), comment(_comment)
{
    //add_photos();
    
    // TODO: implement array of photo names
}

bool validate_grade(const unsigned short grade)
{
    return grade >= 1 && grade <= 5;
}

/*void Diary::add_photos(std::istream& in)
{
    unsigned photo_count = 0;

    do
    {
        in >> photos[photo_count];
        photo_count++;

    } while(in);
    
}*/

void Diary::create_diary_entry()
{
    std::cout << "Enter destination:\n";
    std::cin >> destination;

    do{
        std::cout << "Enter grade:\n";
        std::cin >> grade;
    } while(!validate_grade(grade));

    do
    {
        std::cout << "Enter start date:\n";

        std::cin >> from;

        std::cout << "Enter end date:\n";
        std::cin >> until;
    } while (!(from.validate_date() && until.validate_date()));    
}

void write_user_strings(std::ofstream& file, Diary& new_diary)
{
    file.write(new_diary.get_destination().get_string(), new_diary.get_destination().get_size() + 1);

    file.write(reinterpret_cast<char*>(new_diary.get_grade()), 2);

    write_date_in_file(file, new_diary.get_from_date());

    file.write(new_diary.get_comment().get_string(), new_diary.get_comment().get_size() + 2);

    // TODO: also for photos
}