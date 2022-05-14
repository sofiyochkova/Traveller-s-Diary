#include<iostream>
#include<fstream>
#include "diary.hpp"

Diary::Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, User_string *_photos[])
    : destination(_destination), from(_from), until(_until), grade(_grade), comment(_comment)
{
    //add_photos();
    size_t photo_size = sizeof(_photos) / sizeof(_photos[0]);
    *photos = new User_string[photo_size];

    for(size_t i = 0; i < photo_size; i++)
    {
        photos[i] = _photos[i]; 
    }
}

bool validate_grade(const unsigned short grade)
{
    return grade >= 1 && grade <= 5;
}

void Diary::add_photos(std::istream& in)
{
    size_t photo_count = 0;

    do
    {
        in >> *(photos[photo_count]);
        photo_count++;

        print_array_of_user_string(photos, photo_count);

    } while(in);
    
}

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
    } while (!(validate_date(from) && validate_date(until) && (from < until)));    
}

void write_date_in_file(std::ofstream& file, const Date& _date)
{
    file.write(reinterpret_cast<const char*>(&_date), sizeof(Date));
}

void write_user_strings(std::ofstream& file, Diary& new_diary)
{
    file.write(new_diary.get_destination().get_string(), new_diary.get_destination().get_size() + 1);

    file.write(reinterpret_cast<char*>(new_diary.get_grade()), 2);

    write_date_in_file(file, new_diary.get_from_date());

    file.write(new_diary.get_comment().get_string(), new_diary.get_comment().get_size() + 2);

    // TODO: also for photos
}
