#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    fstream inp("a.txt"); // открываем файл
    if (!inp.is_open()) puts("File not found!"); // проверяем открыт ли файл
    else {
        double k = 1;
        double x;
        while (inp >> x) { // перебираем файл
            k *= x;
        }
        inp.close(); // закрываем файл
        cout << "Произведение чисел: " << k << '\n';

    }
}