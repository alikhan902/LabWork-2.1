#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    double sum = 0;
    double x;
    
    fstream inp1("a1.txt"); // открываем файл a1
    if (!inp1.is_open()) puts("File not found!"); // проверяем открыт ли файл
    else {

        while (inp1 >> x) { // перебираем файл
            if (x > 0) sum += x; // считаем сумму положительных чисел файла a1
        }
    }
        inp1.close(); // закрываем файл
        
    fstream inp2("a2.txt"); // открываем файл a2
    if (!inp2.is_open()) puts("File not found!"); // проверяем открыт ли файл
    else {
        while (inp2 >> x) { // перебираем файл
            if (x > 0) sum += x; // продолжаем считать сумму положительных, но уже в файле а2
        }
        inp2.close(); // закрываем файл
    }
    cout << "Сумма: " << sum;
}