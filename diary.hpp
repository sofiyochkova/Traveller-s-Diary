#ifndef __DIARY_HPP
#define __DIARY_HPP

#include "user_string.hpp"
#include "date.hpp"
#include "users.hpp"

class Diary
{
    private:
        User_string destination;
        Date from;
        Date until;
        unsigned short grade;
        User_string comment;
        size_t number_of_photos;
        User_string *photos;
        
    public:
        Diary() = default;
        Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, size_t _number_of_photos, const User_string _photos[]);
        
        const User_string get_destination() const { return destination.get_string(); }
        const unsigned short get_grade() const { return grade; }
        const User_string get_comment() const { return comment.get_string(); }
        const Date get_from_date() const { return from; }
        const Date get_until_date() const { return until; }
        const size_t get_number_of_photos() const { return number_of_photos; }
        const User_string *get_photos() const { return photos; }
        
        void add_photos(std::istream& in = std::cin);
        void create_diary_entry(std::istream& in = std::cin);

        friend std::ostream& operator<<(std::ostream& out, const Diary& diary);

        ~Diary();
};

void write_user_diary(std::fstream& file, Diary& new_diary);
void write_date_in_file(std::fstream& file, const Date& _date);

#endif