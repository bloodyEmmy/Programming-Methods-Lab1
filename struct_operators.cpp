#include "struct_operators.h"

using namespace std;

bool operator< (const Ship& left, const Ship& right) {
    if (left.year_build != right.year_build) return left.year_build < right.year_build;
    else if (left.ship_name != right.ship_name) return left.ship_name < right.ship_name;
    else return left.ship_type < right.ship_type;
}

bool operator> (const Ship& left, const Ship& right) {
    return right < left;
}

bool operator<= (const Ship& left, const Ship& right) {
    return !(left > right);
}

bool operator>= (const Ship& left, const Ship& right) {
    return !(left < right);
}