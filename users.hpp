#ifndef __USERS_HPP
#define __USERS_HPP
#include "user_string.hpp"
#include<fstream>

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

        friend void write_user_data(std::fstream& file, const User& new_user);
};

void menu();
void logged_in_menu(User& user);

bool validate_username(const User_string& username);
bool validate_email(const User_string& email);

std::fstream create_user_database(const User& new_user);
void write_user_in_file(std::fstream& file, const User& new_user);

bool check_username(std::fstream& file, const User_string& username);

#endif