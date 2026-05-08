#include <iostream>
#include <vector>
#include "generate_read_write.h"
#include "sortings.h"

using namespace std;

int main() {
    cout << "1. Генерация данных..." << endl;
    file_generate(); 

    cout << "2. Чтение данных в вектор..." << endl;
    vector<Ship> fleet;
    file_read(fleet);
    cout << "Прочитано кораблей: " << fleet.size() << endl;

    if (fleet.empty()) {
        cout << "ОШИБКА: Вектор пуст! Проверь чтение или файл input_data.txt" << endl;
        return 1;
    }

    // Для начала возьми маленькое число, например 1000, 
    // чтобы не ждать вечность, пока Insertion Sort переварит 100к
    cout << "3. Сортировка..." << endl;
    sort_insert(fleet); 

    cout << "4. Запись в файл..." << endl;
    file_write(fleet);

    cout << "ГОТОВО! Проверь файл output_data.txt" << endl;

    return 0;
}