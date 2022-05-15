#ifndef __DIARY_HPP
#define __DIARY_HPP

#include "user_string.hpp"
#include "date.hpp"
#include "users.hpp"

class Diary: public User
{
    private:
        User_string destination;
        Date from;
        Date until;
        unsigned short grade;
        User_string comment;
        size_t number_of_photos;
        User_string *photos;
        
        //void read_diary_entry(Diary& new_diary);
        

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
        void create_diary_entry(User& user, std::istream& in = std::cin);

        friend std::ostream& operator<<(std::ostream& out, const Diary& diary);

        ~Diary();


};

void write_user_strings(std::ofstream& file, Diary& new_diary);
void write_date_in_file(std::ofstream& file, const Date& _date);

//std::ostream& operator<<(std::ostream& out, const Diary& diary);

#endif