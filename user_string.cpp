#include<cstring>
#include<iostream>
#include<algorithm>
#include "user_string.hpp"

User_string::User_string(char *_string)
{   
    size = strlen(_string) + 1;

    string = new char[size];
    
    strncpy(string, _string, strlen(_string));

    string[size - 1] = '\0';
}

User_string::User_string(const User_string& other)
    : size(other.size)
{
    string = new char[other.size + 1];
    strncpy(string, other.string, size);
    string[size] = '\0';
}

bool User_string::operator==(const User_string& other)
{
    return strcmp(string, other.string) == 0;
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

char User_string::operator[](size_t pos)
{
    return string[pos];
}

std::istream& operator>>(std::istream& in, User_string& name)
{
    in >> name.string;
    name.size = strlen(name.string); 

    return in;
}

int main1()
{
    char test1[] = "idkteeyeyeeyeyeyyeyeu";
    char test2[] = "idkteeyeyeeyeyeyyey";
    char test3[] = "\0";

    User_string c(test3);
    std::cin >> c;

    User_string k(test2);
    std::cout << c.get_string() << " " << c.get_size() << '\n';
    
    std::cout << (c == k) << '\n';

    return 0;
}