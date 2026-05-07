#ifndef STRUCT_OPERATORS_H
#define STRUCT_OPERATORS_H

#include <string>

struct Ship {
    std::string ship_name;
    int year_build;
    std::string country_build;
    std::string ship_type;
    std::string captain_name;
};

bool operator< (const Ship& left, const Ship& right);
bool operator> (const Ship& left, const Ship& right);
bool operator<= (const Ship& left, const Ship& right);
bool operator>= (const Ship& left, const Ship& right);

#endif