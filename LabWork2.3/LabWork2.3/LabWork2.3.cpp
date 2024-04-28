#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main() {
    fstream inp("a.txt"); // открываем файл
    fstream outfile("new_file.txt"); // создаем новый файл
    if (!inp.is_open() || !outfile.is_open()) {
        cout << "Files not found";
    }// проверяем открыты ли файлы
    else {
        char x;
        while (inp.get(x)) { // перебираем файл "a1"
            outfile << static_cast<char>(toupper(x));  // Преобразуем символ к верхнему регистру и записываем в новый файл
        }
        inp.close(); // закрываем файл "a1"
        outfile.close();  // закрываем файл "new_file.txt"

        
        outfile.open("new_file.txt", ios::in); // Открываем новый файл для чтения и записи
        ofstream inp2("a.txt", ios::trunc); // Открываем файл "a.txt" для записи (с очисткой содержимого)
        while (outfile.get(x)) {
            inp2 << x;  // Записываем содержимое файла "new_file.txt" в файл "a.txt"
        }
        inp2.close();
        outfile.close();
    }
}