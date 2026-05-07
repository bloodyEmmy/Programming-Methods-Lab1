#ifndef GENERATE_READ_WRITE_H
#define GENERATE_READ_WRITE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "struct_operators.h"

void file_generate();
void file_read(std::vector<Ship>& my_vector);

#endif