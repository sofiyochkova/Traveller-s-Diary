#include<cstring>
#include<iostream>
#include<algorithm>

class User_string
{
    private:
        char *string;
        size_t size;
        size_t capacity;

    public:
        User_string()
            : string(nullptr), size(0), capacity(0)
        {}

        User_string(char *_string, size_t _capacity = 16)
        {  
            capacity = _capacity;
            
            size = strlen(_string) + 1;

            string = new char[size];
            
            strncpy(string, _string, strlen(_string));

            string[size - 1] = '\0';
        }

        /* void resize(size_t _capacity)
        {
            capacity = _capacity;

            char *new_string = new char[capacity];
            strncpy(new_string, string, size);
            new_string[size - 1] = '\0';
            
            delete[] string;
            string = new_string;

            if(capacity < size)
            {
                resize(2 * capacity);
            }
        }*/

        User_string(const User_string& other)
            : size(other.size)//, capacity(other.capacity)
        {
            string = new char[size];
            strncpy(string, other.string, size);
        }
        
        void swap_string(User_string& other);

        User_string& operator=(const User_string& other)
        {
            if(this != &other)
            {
                User_string copy(other);

                swap_string(copy); 
            } 

            return *this;
        }

        bool operator==(const User_string& other)
        {
            return strcmp(string, other.string) == 0;
        }

        char* get_string() const { return string; }
        size_t get_size() const { return size; }
        size_t get_capacity() const { return capacity; }

        ~User_string()
        {
            delete[] string;
        }
};

void User_string::swap_string(User_string& other)
{
    std::swap(string, other.string);
    std::swap(size, other.size);
}

int main()
{
    char test[] = "idkteeyeyeeyeyeyyeyeu";
    char test2[] = "idkteeyeyeeyeyeyyey";
    User_string c(test, 10);
    User_string k(test2);
    std::cout << c.get_string() << " " << c.get_size() << ' ' << c.get_capacity() << '\n';
    
    std::cout << (c == k) << '\n';

    return 0;
}