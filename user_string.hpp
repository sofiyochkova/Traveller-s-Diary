#ifndef __USER_STRING_HPP
#define __USER_STRING_HPP

#include <cstddef>
#include<iostream>

class User_string
{
    private:
        char *string;
        size_t size;

        void set_string(const char *_string);

    public:

        User_string() = default;

        User_string(const char *_string);

        User_string(const User_string& other);
        
        void swap_string(User_string& other);
        
        char* get_string() const { return string; }
        const size_t get_size() const { return size; }

        User_string& operator=(const User_string& other);

        bool operator==(const User_string& other);
        bool operator!=(const User_string& other);
        char operator[](size_t pos);
        User_string& operator+=(const char rhs[]);

        friend std::istream& operator>>(std::istream& in, User_string& name);

        ~User_string()
        {
            delete[] string;
        }
};
#endif