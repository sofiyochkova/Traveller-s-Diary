#ifndef __TRAVELLERSDIARY_HPP
#define __TRAVELLERSDIARY_HPP

class User
{
    private:
        char username[100];
        char password[100];
        char email[200];

        friend void registration();
        friend void login();

    public:
        User(const char *_username = "\0", const char *_password = "\0", const char *_email = "\0");

        char const *get_username() const { return username; }
        char const *get_password() const { return password; }
        char const *get_email() const { return email; }
};

std::ofstream create_user_database(User& new_user);

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

class Diary
{
    private:
        char *destination;
        Date from;
        Date until;
        unsigned short grade;
        char *comment;
        char *photos;
};

#endif