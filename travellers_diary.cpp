#include<iostream>
#include<fstream>
#include<cstring>
#include "travellers_diary.hpp"

const char ext[] = ".db";
char test[] = "\0";
    
std::ofstream users("users.db", std::ios::out | std::ios::binary | std::ios::app);

void write_user_strings(std::ofstream& file, const User& new_user)
{
    file.write(new_user.get_username(), new_user.username.get_size() + 1);

    file.write(new_user.get_password(), new_user.password.get_size() + 1);

    file.write(new_user.get_email(), new_user.email.get_size() + 2);
}

void write_user_in_file(std::ofstream& file, const User& new_user)
{
    file.seekp(0, std::ios::end);

    write_user_strings(file, new_user);
}

bool validate_username(User_string& username)
{
    for(size_t i = 0; i < username.get_size(); i++)
    {
        if(!(username[i] >= '0' && username[i] <= '9') &&
           !(username[i] >= 'A' && username[i] <= 'Z') &&
           !(username[i] >= 'a' && username[i] <= 'z'))
        {
            std::cerr << "Invalid username! You can only use letters and numbers!\n";
            return false;
        }
    }

    return true;
}

void User::registration()
{
    do
    {
        std::cout << "Enter username: ";
        std::cin >> username;
    } while (!validate_username(username));
    
    std::cout << "Enter password: ";
    std::cin.clear();
    std::cin >> password;

    std::cout << "Enter email address: ";
    std::cin >> email;

    write_user_in_file(users, *this);

    create_user_database(*this);
    std::cout << "You have registered successfully!\n";
}

void User::login()
{
    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;
}

std::ofstream create_user_database(const User& new_user)
{
    User_string filename = new_user.get_username();
    filename += ext;
 
    std::ofstream user_db(filename.get_string(), std::ios::out | std::ios::binary);

   return user_db;
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
    char command[100];

    menu_commands();

    while(strcmp(command, "exit") != 0)
    {
        std::cin >> command;

        if(strcmp(command, "register") == 0)
        {
            User u1(test, test, test);
            u1.registration();
        }

        else if(strcmp(command, "login") == 0)
        {
            User u2(test, test, test);
            u2.login();
        }

        else if(strcmp(command, "help") == 0)
        {
            menu_commands();
        }

        else if(strcmp(command, "exit") != 0)
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