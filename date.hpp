#ifndef __DATE_HPP
#define __DATE_HPP

class Date
{
    private:
        unsigned short day;
        unsigned short month;
        unsigned short year;

    public:
        bool validate_date();
        friend std::istream& operator>>(std::istream& in, Date& _date);
        friend std::ostream& operator<<(std::ostream& out, Date& _date);

};

void write_date_in_file(std::ofstream& file, const Date& _date)

#endif