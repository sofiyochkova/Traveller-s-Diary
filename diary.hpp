#ifndef __DIARY_HPP
#define __DIARY_HPP

#include "user_string.hpp"
#include "date.hpp"

class Diary
{
    private:
        User_string destination;
        Date from;
        Date until;
        unsigned short grade;
        User_string comment;
        User_string photos[];
        
        //void read_diary_entry(Diary& new_diary);
        void create_diary_entry();
        void write_date_in_file();

    public:
        Diary() = default;
        Diary(User_string _destination, Date _from, Date _until, unsigned short _grade, User_string _comment, User_string *_photos);
        
        void add_photos(std::istream& in = std::cin);
        
        const User_string get_destination() const { return destination.get_string(); }
        const unsigned short get_grade() const { return grade; }
        const User_string get_comment() const { return comment.get_string(); }
        const Date get_from_date() const { return from; }
        const Date get_until_date() const { return until; }

};

#endif