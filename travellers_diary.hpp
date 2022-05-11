#ifndef __TRAVELLERSDIARY_HPP
#define __TRAVELLERSDIARY_HPP
#include "user_string.hpp"

class User
{
    private:
        User_string username;
        User_string password;
        User_string email;

    public:
        User() = default;

        User(const User_string _username, const User_string _password, const User_string _email)
        : username(_username), password(_password), email(_email)
        {}

        void registration();
        void login();

        char *get_username() const { return username.get_string(); }
        char *get_password() const { return password.get_string(); }
        char *get_email() const { return email.get_string(); }

        friend void validate_username(User_string& username);
        friend void write_user_strings(std::ofstream& file, const User& new_user);
};

void menu();

std::ofstream create_user_database(const User& new_user);

//void write_user_strings(std::ofstream& file, const User& new_user);
void write_user_in_file(std::ofstream& file, const User& new_user);

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

class Diary
{
    private:
        User_string *destination;
        Date from;
        Date until;
        unsigned short grade;
        User_string *comment;
        User_string *photos;
};

#endif