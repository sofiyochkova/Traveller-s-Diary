#include<iostream>
#include<fstream>
#include<cstring>
#include "diary.hpp"

Diary::Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, size_t _number_of_photos, const User_string _photos[])
    : destination(_destination), from(_from), until(_until), grade(_grade), comment(_comment), number_of_photos(_number_of_photos)
{
    photos = new User_string[number_of_photos];

    for(size_t i = 0; i < number_of_photos; i++)
    {
        photos[i] = _photos[i];
    }
}

bool validate_grade(const unsigned short grade)
{
    return grade >= 1 && grade <= 5;
}

bool validate_extension(const char *filename)
{
    const char ext1[] = "jpeg";
    const char ext2[] = "png";

    char compare[5];
    size_t length = strlen(filename);

    if(filename[length - 4] == '.')
    {   
        size_t pos = 0;

        for(size_t i = length - 3; i < length; i++)
        {
            compare[pos] = filename[i];
            pos++;
        }

        compare[pos] = '\0';

        return strcmp(compare, ext2) == 0; 
    }

    else if(filename[length - 5] == '.')
    {
        size_t pos = 0;

        for(size_t i = length - 4; i < length; i++)
        {
            compare[pos] = filename[i];
            pos++;
        }

        compare[pos] = '\0';

        return strcmp(compare, ext1) == 0; 
    }

    return false;
}

bool validate_filenames(const char *filename)
{
    for(size_t i = 0; i < strlen(filename); i++)
    {
        if(!(filename[i] == '_') && !(filename[i] == '.') &&
        !(filename[i] >= 'A' && filename[i] <= 'Z') &&
        !(filename[i] >= 'a' && filename[i] <= 'z'))
        {
            std::cerr << "Invalid filename! You can only use letters and _!\n";
            return false;
        }
    }

    if(!validate_extension(filename))
    {
        std::cout << "Invalid file extension!\n";
        return false;
    }
    
    return true;
}

void Diary::add_photos(std::istream& in)
{   
    photos = new User_string[number_of_photos];
        
    for(size_t i = 0; i < number_of_photos; i++)
    {   
        char tmp[100];
        
        do
        {
            std::cout << "Enter name of photo " << i + 1 << ":\n";
            in.getline(tmp, 100);
            
        } while(strlen(tmp) <= 4 || !validate_filenames(tmp) /*|| !has_a_dot*/);
        
        photos[i].set_string(tmp);
    }

}

std::ostream& operator<<(std::ostream& out, const Diary& diary)
{
    out << diary.get_destination().get_string() << ' ' << diary.get_from_date() << diary.get_until_date() << diary.get_grade() << ' '
        << diary.get_comment().get_string() << '\n'; 
    
    for(size_t i = 0; i < diary.get_number_of_photos(); i++)
    {
        out << diary.photos[i].get_string() << '\n';
    }

    return out;

}

void Diary::create_diary_entry(User& user, std::istream& in)
{
    char _destination[200];

    std::cout << "Enter destination:\n";
    in.getline(_destination, 200);
    
    destination = _destination;
    
    do
    {
        std::cout << "Enter start date:\n";
        in >> from;

        std::cout << "Enter end date:\n";
        in >> until;
    } while (!(validate_date(from) && validate_date(until) && (from < until)));

    do{
        std::cout << "Enter grade:\n";
        in >> grade;
    } while(!validate_grade(grade));

    std::cout << "Enter comment:\n";
    char _comment[500];

    in.ignore();
    in.getline(_comment, 500);
    comment.set_string(_comment);

    std::cout << "Enter number of photos:\n";
    do{
        in >> number_of_photos;
    } while(number_of_photos <= 0);

    in.ignore();
    
    add_photos();
}

void write_date_in_file(std::ofstream& file, const Date& _date)
{
    file.write(reinterpret_cast<const char*>(&_date), sizeof(Date));
}

void write_user_strings(std::ofstream& file, Diary& new_diary)
{
    file.write(new_diary.get_destination().get_string(), new_diary.get_destination().get_size() + 1);

    file.write(reinterpret_cast<const char*>(new_diary.get_grade()), 2);

    write_date_in_file(file, new_diary.get_from_date());

    write_date_in_file(file, new_diary.get_until_date());

    file.write(new_diary.get_comment().get_string(), new_diary.get_comment().get_size() + 2);

    // TODO: also for photos
}

Diary::~Diary()
{
    delete[] photos;
}

int main()
{
    User_string p[] = {"winter", "summer"};

    //Diary d1(User_string("Burgas"), Date(2, 4, 2002), Date(3, 4, 2002), 3, User_string("nonono"), 2, p);
    //std::cout << d1;

    User u1;
    Diary d1;
    d1.create_diary_entry(u1);

    //std::cout << d1;
}
