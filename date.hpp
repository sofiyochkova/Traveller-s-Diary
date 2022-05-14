#ifndef __DATE_HPP
#define __DATE_HPP

class Date
{
    private:
        unsigned short day;
        unsigned short month;
        unsigned short year;

    public:

        Date(unsigned short _day = 0, unsigned short _month = 0, unsigned short _year = 0);

        friend std::istream& operator>>(std::istream& in, Date& _date);
        bool operator<(const Date& rhs) const;

        const unsigned short get_day() const { return day; }
        const unsigned short get_month() const { return month; }
        const unsigned short get_year() const { return year; }
};

bool validate_date(const Date& date);
//void write_date_in_file(std::ofstream& file, const Date& _date);
std::ostream& operator<<(std::ostream& out, Date& _date);

#endif