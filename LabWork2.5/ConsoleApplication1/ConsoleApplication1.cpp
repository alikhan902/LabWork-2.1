#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Person { // Объявляем структуру данных человека
    string surname;
    string name;
    string patronymic;
    char gender;
    string nationality;
    int height;
    int weight;
    string birthdate;
    string phoneNumber;
    string address;
};

int main() {
    ifstream inputFile("JJAAA.txt"); 
    if (!inputFile) { // Проверяем открыт ли файл
        cerr << "Unable to open file";
        return 1;
    }

    vector<Person> people; // Вектор для хранения информации о людях из файла

    string line;
    while (getline(inputFile, line)) { // Перебираем файл
        if (line.find("Person") != string::npos) { 
            Person person;
            getline(inputFile, line); // Читаем следующую строку, чтобы получить Фамилию
            person.surname = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Имя
            person.name = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Отчество
            person.patronymic = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Пол
            person.gender = line.substr(line.find(":") + 2)[0];
            getline(inputFile, line); // Национальность
            person.nationality = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Рост
            person.height = stoi(line.substr(line.find(":") + 2));
            getline(inputFile, line); // Вес
            person.weight = stoi(line.substr(line.find(":") + 2));
            getline(inputFile, line); // Дата рождения
            person.birthdate = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Номер телефона
            person.phoneNumber = line.substr(line.find(":") + 2);
            getline(inputFile, line); // Домашний адрес
            person.address = line.substr(line.find(":") + 2);
            
            people.push_back(person); // Записываем структуру в вектор
        }
    }

    inputFile.close();

    // Поиск самого молодого человека
    int MaxYear = INT_MIN;
    int MaxMonth = INT_MIN;
    int MaxDay = INT_MIN;
    Person youngestPerson;

    for (const auto& person : people) {
        int birthYear = stoi(person.birthdate.substr(6, 4));
        int birthMonth = stoi(person.birthdate.substr(3, 2));
        int birthDay = stoi(person.birthdate.substr(0, 2));


        if (birthYear > MaxYear) {
            MaxYear = birthYear;
            MaxMonth = birthMonth;
            MaxDay = birthDay;
            youngestPerson = person;
        }
        else if (birthYear == MaxYear) {
            if (MaxMonth < birthMonth) {
                MaxYear = birthYear;
                MaxMonth = birthMonth;
                MaxDay = birthDay;
                youngestPerson = person;
            }
            else if (MaxMonth == birthMonth) {
                if (birthDay > MaxDay) {
                    MaxYear = birthYear;
                    MaxMonth = birthMonth;
                    MaxDay = birthDay;
                    youngestPerson = person;
                }
            }
        }
    }


    // Вывод информации о самом молодом человеке
    cout << "Youngest Person:" << endl;
    cout << "Surname: " << youngestPerson.surname << endl;
    cout << "Name: " << youngestPerson.name << endl;
    cout << "Patronymic: " << youngestPerson.patronymic << endl;
    cout << "Gender: " << youngestPerson.gender << endl;
    cout << "Nationality: " << youngestPerson.nationality << endl;
    cout << "Height: " << youngestPerson.height << endl;
    cout << "Weight: " << youngestPerson.weight << endl;
    cout << "Birthdate: " << youngestPerson.birthdate << endl;
    cout << "Phone Number: " << youngestPerson.phoneNumber << endl;
    cout << "Address: " << youngestPerson.address << endl;

    return 0;
}

