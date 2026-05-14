#ifndef STRUCT_OPERATORS_H
#define STRUCT_OPERATORS_H

#include <string>

/**
 * @brief Структура, описывающая сущность "Корабль".
 * Хранит основные характеристики судна и данные о капитане.
 */
struct Ship {
    std::string ship_name;     /**< Название корабля */
    int year_build;            /**< Год постройки */
    std::string country_build; /**< Страна постройки */
    std::string ship_type;     /**< Тип корабля (танкер, сухогруз и т.д.) */
    std::string captain_name;  /**< ФИО капитана */
};

/**
 * @brief Перегрузка оператора "Меньше".
 * Сравнение идет по приоритету: Год постройки -> Название корабля -> Тип корабля.
 * * @param left Левый операнд (корабль 1).
 * @param right Правый операнд (корабль 2).
 * @return true Если левый корабль "меньше" правого.
 * @return false Во всех остальных случаях.
 */
bool operator< (const Ship& left, const Ship& right);

/**
 * @brief Перегрузка оператора "Больше".
 * * @param left Левый операнд (корабль 1).
 * @param right Правый операнд (корабль 2).
 * @return true Если левый корабль "больше" правого.
 * @return false Во всех остальных случаях.
 */
bool operator> (const Ship& left, const Ship& right);

/**
 * @brief Перегрузка оператора "Меньше или равно".
 * * @param left Левый операнд (корабль 1).
 * @param right Правый операнд (корабль 2).
 * @return true Если левый корабль "меньше" или равен правому.
 * @return false Во всех остальных случаях.
 */
bool operator<= (const Ship& left, const Ship& right);

/**
 * @brief Перегрузка оператора "Больше или равно".
 * * @param left Левый операнд (корабль 1).
 * @param right Правый операнд (корабль 2).
 * @return true Если левый корабль "больше" или равен правому.
 * @return false Во всех остальных случаях.
 */
bool operator>= (const Ship& left, const Ship& right);

#endif