#include <iostream>
#include <vector>
#include <chrono>   // Для замера времени
#include <fstream>
#include <algorithm> // Для std::sort

#include "generate_read_write.h"
#include "sortings.h"

using namespace std;
using namespace std::chrono;

int main() {
    cout << "1. Генерация данных..." << endl;
    file_generate(); 

    cout << "2. Чтение данных в вектор..." << endl;
    vector<Ship> full_fleet;
    file_read(full_fleet);
    cout << "Прочитано кораблей: " << full_fleet.size() << endl;

    if (full_fleet.empty()) {
        cout << "ОШИБКА: Вектор пуст! Проверь чтение или файл input_data.txt" << endl;
        return 1;
    }

    // Открываем CSV файл для записи результатов
    ofstream csv_file("results.csv");
    if (!csv_file.is_open()) {
        cout << "ОШИБКА: Не удалось создать results.csv" << endl;
        return 1;
    }
    // Заголовок для таблицы
    csv_file << "Size,Insertion,Pyramid,Merge,StdSort\n";

    // Наборы данных (11 точек от 100 до 100000)
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 20000, 40000, 60000, 80000, 90000, 100000};

    cout << "3. Запуск тестирования времени (в секундах)..." << endl;
    cout << "ВНИМАНИЕ: На больших объемах сортировка вставками может занять минуту и более. Не закрывайте программу!" << endl;

    for (int s : sizes) {
        cout << "Обработка размера: " << s << " ... ";
        
        // Отрезаем нужный размер от общего массива
        vector<Ship> base_fleet(full_fleet.begin(), full_fleet.begin() + s);

        // 1. Сортировка простыми вставками
        vector<Ship> fleet_insert = base_fleet;
        auto start1 = high_resolution_clock::now();
        sort_insert(fleet_insert);
        auto end1 = high_resolution_clock::now();
        double time_insert = duration<double>(end1 - start1).count();

        // 2. Пирамидальная сортировка
        vector<Ship> fleet_pyramid = base_fleet;
        auto start2 = high_resolution_clock::now();
        sort_pyramid(fleet_pyramid);
        auto end2 = high_resolution_clock::now();
        double time_pyramid = duration<double>(end2 - start2).count();

        // 3. Сортировка слиянием
        vector<Ship> fleet_merge = base_fleet;
        auto start3 = high_resolution_clock::now();
        sort_merge(fleet_merge, 0, fleet_merge.size() - 1);
        auto end3 = high_resolution_clock::now();
        double time_merge = duration<double>(end3 - start3).count();

        // 4. Эталонная сортировка std::sort
        vector<Ship> fleet_std = base_fleet;
        auto start4 = high_resolution_clock::now();
        sort(fleet_std.begin(), fleet_std.end());
        auto end4 = high_resolution_clock::now();
        double time_std = duration<double>(end4 - start4).count();

        cout << "ОК" << endl;

        // Записываем результаты в файл
        csv_file << s << "," << time_insert << "," << time_pyramid << "," 
                 << time_merge << "," << time_std << "\n";

        // По заданию нужно сохранить отсортированный массив в файл
        // Сохраним его на последней итерации (максимальный размер)
        if (s == 100000) {
            file_write(fleet_merge); 
        }
    }

    csv_file.close();
    cout << "4. Запись отсортированного массива в output_data.txt завершена." << endl;
    cout << "ГОТОВО! Результаты времени лежат в results.csv" << endl;

    return 0;
}