#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представления информации о студенте
struct Student {
    char name[20];  // Фамилия и инициалы
    int group;      // Номер группы
    int performance[3]; // Массив оценок
    float scholarship;  // Размер стипендии
};

// Функция для записи информации о студенте в бинарный файл
void writeStudent(ofstream& file, const Student& student) {
    file.write((char*)&student, sizeof(student));
}

// Функция для чтения информации о студенте из бинарного файла
void readStudent(ifstream& file, Student& student) {
    file.read((char*)&student, sizeof(student));
}

int main() {
    // Создаем и открываем бинарный файл для записи
    ofstream outFile("students.bin", ios::binary);

    // Пример студентов
    Student students[] = {
        {"Madaev A. A.", 1, {80, 90, 70}, 2000},
        {"Ivanov B. B.", 2, {65, 75, 85}, 1800},
        {"Petrov C. C.", 1, {50, 60, 70}, 1500}
    };

    // Записываем информацию о студентах в файл
    for (const auto& student : students) {
        writeStudent(outFile, student);
    }

    // Закрываем файл
    outFile.close();

    // Открываем файл для чтения
    ifstream inFile("students.bin", ios::binary);

    // Читаем и выводим информацию о студентах с положительными оценками
    cout << "Students with positive grades:\n";
    Student tempStudent;
    while (inFile.peek() != EOF) {
        readStudent(inFile, tempStudent);
        bool passed = true;
        for (int i = 0; i < 3; ++i) {
            if (tempStudent.performance[i] <= 50) { // Проверка на успеваемость
                passed = false;
                break;
            }
        }
        if (passed) {
            cout << "Name: " << tempStudent.name << endl;
            cout << "Group: " << tempStudent.group << endl;
            cout << "Academic performance: ";
            for (int i = 0; i < 3; ++i) {
                cout << tempStudent.performance[i] << " ";
            }
            cout << endl;
            cout << "Scholarship amount: " << tempStudent.scholarship << endl << endl;
        }
    }

    // Закрываем файл
    inFile.close();

    return 0;
}