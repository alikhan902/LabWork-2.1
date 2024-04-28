#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    fstream inp("a.txt"); // открываем файл
    if (!inp.is_open()) puts("File not found!"); // проверяем открыт ли файл
    else {
        int k1 = 0; 
        int k2 = 0;
        double x;
        while (inp >> x) { // переюираем файл
            if (x > 0 ) ++k1; // считаем количество положетельных чисел
            else if (x < 0) ++k2; // считаем количество отрицательных чисел
        }
        inp.close(); // закрываем файл
        cout << "Количетво положительных: " << k1 << '\n';
        cout << "Количество отрицательных: " << k2 << '\n';
    }
}