#ifndef GENERATE_READ_WRITE_H
#define GENERATE_READ_WRITE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "struct_operators.h"

/**
 * @brief Генерация тестовых данных.
 * Создает текстовый файл (input_data.txt) и записывает в него 100 000 
 * случайно сгенерированных записей о кораблях для последующей сортировки.
 */
void file_generate();

/**
 * @brief Чтение исходных данных из файла.
 * Открывает файл input_data.txt, считывает характеристики кораблей 
 * и добавляет их в конец переданного вектора.
 * * @param my_vector Ссылка на вектор объектов Ship, который будет заполнен прочитанными данными.
 */
void file_read(std::vector<Ship>& my_vector);

/**
 * @brief Запись отсортированного массива в файл.
 * Построчно выгружает все элементы вектора в итоговый файл (output_data.txt).
 * * @param my_vector Ссылка на вектор объектов Ship, данные из которого необходимо сохранить.
 */
void file_write(std::vector<Ship>& my_vector);

#endif