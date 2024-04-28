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
        {"Madaev A. A.", 1, {3, 4, 5}, 2000},
        {"Ivanov B. B.", 2, {2, 3, 4}, 1800},
        {"Petrov C. C.", 1, {5, 5, 5}, 1500}
    };

    // Записываем информацию о студентах в файл
    for (const auto& student : students) {
        // Проверяем, есть ли у студента оценка 2
        bool hasGradeTwo = false;
        for (int i = 0; i < 3; ++i) {
            if (student.performance[i] == 2) {
                hasGradeTwo = true;
                break;
            }
        }

        // Устанавливаем размер стипендии с учетом наличия или отсутствия оценки 2
        float scholarship = student.scholarship;
        if (!hasGradeTwo) {
            scholarship *= 1.3; // Увеличиваем стипендию на 30%
        }

        // Создаем студента с учетом измененного размера стипендии
        Student modifiedStudent = student;
        modifiedStudent.scholarship = scholarship;

        // Записываем студента в файл
        writeStudent(outFile, modifiedStudent);
    }

    // Закрываем файл
    outFile.close();

    // Открываем файл для чтения
    ifstream inFile("students.bin", ios::binary);

    // Читаем и выводим информацию о студентах
    cout << "All students\n";
    Student tempStudent;
    while (inFile.peek() != EOF) {
        readStudent(inFile, tempStudent);
        cout << "Name: " << tempStudent.name << endl;
        cout << "Group: " << tempStudent.group << endl;
        cout << "Academic performance: ";
        for (int i = 0; i < 3; ++i) {
            cout << tempStudent.performance[i] << " ";
        }
        cout << endl;
        cout << "Scholarship amount: " << tempStudent.scholarship << endl << endl;
    }

    // Закрываем файл
    inFile.close();

    return 0;
}