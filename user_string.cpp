#include<cstring>
#include<iostream>
#include<algorithm>
#include "user_string.hpp"

User_string::User_string()
    : string(nullptr), size(0)
{   
    set_string("\0");
}

User_string::User_string(const char *_string)
    : string(nullptr)
{   
    set_string(_string);
}

User_string::User_string(const User_string& other)
    : string(nullptr), size(other.size)
{
    set_string(other.get_string());
}

void User_string::set_string(const char *_string)
{
    delete[] string;
    size = strlen(_string);
    string = new char[size + 1];
    strncpy(string, _string, size);
    string[size] = '\0';
}

bool User_string::operator==(const User_string& other)
{
    return strcmp(string, other.string) == 0;
}

bool User_string::operator!=(const User_string& other)
{
    return !(*this == other);
}

User_string& User_string::operator+=(const char rhs[])
{
    strcat(this->get_string(), rhs);
    this->size += strlen(rhs);

    return *this;
}

User_string& User_string::operator=(const User_string& other)
{
    if(this != &other)
    {
        User_string copy(other);

        swap_string(copy); 
    } 

    return *this;
}

void User_string::swap_string(User_string& other)
{
    std::swap(string, other.string);
    std::swap(size, other.size);
}

std::istream& operator>>(std::istream& in, User_string& name)
{
    in >> name.string;
    name.size = strlen(name.get_string());

    return in;
}
