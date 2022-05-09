#include<iostream>
#include<fstream>
#include<cstring>
#include "travellers_diary.hpp"
//#include "user_string.hpp"

const char ext[] = ".db";

std::ofstream users("users.db", std::ios::out | std::ios::binary | std::ios::app);

/*void write_user_in_file(std::ofstream& file, const User& new_user)
{
    file << new_user.get_username() << ' ' 
         << new_user.get_password() << ' ' 
         << new_user.get_email() << '\n' ;

    file.close();
}*/

void write_user_in_file(std::ofstream& file, const User& new_user)
{
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<const char *>(&new_user), sizeof(User));
}

void registration()
{
    User u1;
    
    std::cout << "Enter username: ";
    std::cin >> u1.username;

    std::cout << "Enter password: ";
    std::cin >> u1.password;

    std::cout << "Enter email address: ";
    std::cin >> u1.email;
    
    write_user_in_file(users, u1);

    create_user_database(u1);

    std::cout << "You have registered successfully!\n";
}

void login()
{
    User u1;

    std::cout << "Enter username: ";
    std::cin >> u1.username;

    std::cout << "Enter password: ";
    std::cin >> u1.password;
}

std::ofstream create_user_database(User& new_user)
{
    char filename[105];
    strncpy(filename, new_user.get_username(), strlen(new_user.get_username()) + 1);
   // std::cout << filename;
    strcat(filename, ext);
    
    filename[strlen(filename) + 1] = '\0';
    //std::cout << filename << '\n';
    std::ofstream user_db(filename, std::ios::out | std::ios::binary);
    write_user_in_file(user_db, new_user);

    return user_db;
}

User::User(const char *_username, const char *_password, const char *_email)
{
    strncpy(username, _username, 100);
    username[strlen(_username) - 1] = '\0';

    strncpy(password, _password, 100);
    username[strlen(_password) - 1] = '\0';

    strncpy(email, _email, 200);
    username[strlen(_email) - 1] = '\0';
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
            registration();
        }

        else if(strcmp(command, "login") == 0)
        {
            login();
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