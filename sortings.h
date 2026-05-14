#ifndef SORTINGS_H
#define SORTINGS_H

#include <vector>
#include <string>
#include <utility>

#include "struct_operators.h"

/**
 * @brief Сортировка простыми вставками (Insertion Sort).
 * * Алгоритм проходит по массиву и вставляет каждый элемент 
 * на его правильное место в уже отсортированной левой части.
 * Медленный алгоритм для больших массивов.
 * * @param my_vector Ссылка на вектор объектов Ship для сортировки.
 */
void sort_insert(std::vector<Ship>& my_vector);

/**
 * @brief Пирамидальная сортировка (Heapsort).
 * * Строит сортирующее дерево (max-heap) из элементов массива, а затем 
 * последовательно извлекает максимальный элемент, помещая его в конец.
 * * @param my_vector Ссылка на вектор объектов Ship.
 */
void sort_pyramid(std::vector<Ship>& my_vector);

/**
 * @brief Сортировка слиянием (Merge Sort).
 * * Рекурсивно делит массив пополам, пока не останутся одиночные элементы, 
 * а затем сливает их в правильном порядке.
 * * @param my_vector Ссылка на вектор объектов Ship.
 * @param start Индекс начала сортируемого подмассива.
 * @param end Индекс конца сортируемого подмассива.
 */
void sort_merge(std::vector<Ship>& my_vector, int start, int end);

#endif