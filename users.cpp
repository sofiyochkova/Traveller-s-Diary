#include<iostream>
#include<cstring>
#include "users.hpp"
#include "diary.hpp"

const char ext[] = ".db";
    
std::fstream users("users.db", std::ios::out | std::ios::in | std::ios::binary | std::ios::app);

void write_user_data(std::fstream& file, const User& new_user)
{
    file.write(new_user.get_username(), new_user.username.get_size() + 1);

    file.write(new_user.get_password(), new_user.password.get_size() + 1);

    file.write(new_user.get_email(), new_user.email.get_size() + 2);
}

void write_user_in_file(std::fstream& file, const User& new_user)
{
    file.seekp(0, std::ios::end);

    write_user_data(file, new_user);
}

bool validate_username(const User_string& username)
{
    for(size_t i = 0; i < username.get_size(); i++)
    {
        if(!(username.get_string()[i] >= '0' && username.get_string()[i] <= '9') &&
           !(username.get_string()[i] >= 'A' && username.get_string()[i] <= 'Z') &&
           !(username.get_string()[i] >= 'a' && username.get_string()[i] <= 'z'))
        {
            std::cerr << "Invalid username! You can only use letters and numbers!\n";
            return false;
        }
    }

    return true;
}

bool validate_email(const User_string& email)
{
    bool has_at_symbol = false;

    for(size_t i = 0; i < email.get_size(); i++)
    {
        size_t pos;

        if(email.get_string()[i] == '@')
        {
            has_at_symbol = true;
            pos = i;
        }

        if(has_at_symbol && i > pos && email.get_string()[i] == '.')
        {
            return true;
        }
    }

    std::cout << "Invalid email!\n";

    return false;
}

char *get_filename(const User& new_user)
{
    User_string filename = new_user.get_username();
    filename += ext;

    return filename.get_string();
}

std::fstream create_user_database(const User& new_user)
{
    User_string filename = new_user.get_username();
    filename += ext;

    std::fstream user_db(filename.get_string(), std::ios::binary);

    return user_db;
}

void User::registration()
{
    do
    {
        std::cout << "Enter username: ";
        std::cin >> username;
    } while (!validate_username(username));
    
    std::cout << "Enter password: ";
    std::cin >> password;

    do
    {
        std::cout << "Enter email address: ";
        std::cin >> email;
    } while (!validate_email(email));
    
    write_user_in_file(users, *this);

    create_user_database(*this);

    std::cout << "You have registered successfully!\n";
}

void logged_in_menu(User& user)
{
    User_string command;

    std::cout << "Enter \"new_entry\" to create a new diary entry:\n";

    while(command != "exit")
    {
        std::cin >> command;

        if(command == "new_entry")
        {            
            User u1;
            Diary d1;

            std::cin.ignore();

            d1.create_diary_entry();
            
            std::fstream file(get_filename(user), std::ios::binary);
            write_user_diary(file, d1);
        }

        else if(command != "exit")
        {
            std::cerr << "Invalid command!\n";
        }
    }
}

void User::login()
{
    std::cout << "Enter username: ";
    std::cin >> username;
        
    std::cout << "Enter password: ";
    std::cin >> password;
    
    std::cout << "You have logged in successfully!\n";

    logged_in_menu(*this);
}

std::ostream& menu_commands()
{
    return std::cout << "Enter:\n" <<
        "1. \"register\" if you don't have an account;\n" <<
        "2. \"login\" if you have already registered;\n" <<
        "3. \"help\" to show the menu again;\n" <<
        "4. \"exit\" to leave the app.\n";
}

void menu()
{   
    User_string command;

    menu_commands();

    while(command != "exit")
    {
        std::cin >> command;

        if(command == "register")
        {
            User u1;
            u1.registration();
        }

        else if(command == "login")
        {
            User u2;
            u2.login();
        }

        else if(command == "help")
        {
            menu_commands();
        }

        else if(command != "exit")
        {
            std::cerr << "Invalid command!\n";
        }
    }
}

int main()
{
    menu();
    return 0;
}