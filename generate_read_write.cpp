#include "generate_read_write.h"

using namespace std;

void file_generate() {
    string arr_ship_name[] = {"Атлант", "Титан", "Монарх", "Орион", "Феникс", "Шквал", "Варяг", "Витязь",
        "Тайфун", "Мираж", "Левиафан", "Авангард"};
    string arr_ship_country[] = {"США", "Китай", "Россия", "Индия", "Япония", "Великобритания", "Франция", "Италия"};
    string arr_ship_type[] = {"Танкер", "Сухогруз", "Пассажирский"};
    string arr_captain_name[] = {"Александр", "Максим", "Артем", "Дмитрий", "Марк", "Лев", "Виктор", "Роман", "Игорь"};
    string arr_captain_surname[] = {"Волков", "Белов", "Морозов", "Орлов", "Громов", "Лебедев", "Соколов"};
    string arr_captain_patronymic[] = {"Александрович", "Викторович", "Сергеевич", "Андреевич", "Дмитриевич"};

    ofstream file("input_data.txt");
    if (file.is_open() == false) {
        cout << "Не удалось сгенерировать файл input_data.txt" << "\n";
        return;
    }
    srand(time(0));

    for (int i = 0; i < 100000; i++) {
        file << arr_ship_name[rand() % size(arr_ship_name)] << "\n";
        file << (1900 + rand() % 127) << "\n";
        file << arr_ship_country[rand() % size(arr_ship_country)] << "\n";
        file << arr_ship_type[rand() % size(arr_ship_type)] << "\n";
        
        string captain = arr_captain_surname[rand() % size(arr_captain_surname)] + " " +
            arr_captain_name[rand() % size(arr_captain_name)] + " " +
            arr_captain_patronymic[rand() % size(arr_captain_patronymic)];
        file << captain << "\n";
    }

    file.close();
}

void file_read(vector<Ship>& my_vector) {
    ifstream file("input_data.txt");
    if (file.is_open() == false) {
        cout << "Не удалось открыть файл input_data.txt" << "\n";
        return;
    }
    Ship temp;
    while (getline(file, temp.ship_name)) {
        file >> temp.year_build;
        file.ignore();
        getline(file, temp.country_build);
        getline(file, temp.ship_type);
        getline(file, temp.captain_name);
        my_vector.push_back(temp);
    }
    
    file.close();
}

void file_write(vector<Ship>& my_vector) {
    ofstream file("output_data.txt");
    if (file.is_open() == false) {
        cout << "Не удалось открыть файл output_data.txt" << "\n";
        return;
    }
    for (int i = 0; i < my_vector.size(); i++) {
        file << my_vector[i].ship_name << "\n";
        file << my_vector[i].year_build << "\n";
        file << my_vector[i].country_build << "\n";
        file << my_vector[i].ship_type << "\n";
        file << my_vector[i].captain_name << "\n";
    }

    file.close();
}