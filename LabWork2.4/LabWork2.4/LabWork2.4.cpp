#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    fstream inp("a.txt"); // открываем файлы
    ofstream Chet("Chet.txt");
    ofstream NeChet("NeChet.txt");
    if (!inp.is_open()) puts("File not found!"); // проверяем открыт ли файл
    else {
        int k1 = 1;
        int x;
        while (inp >> x) { // перебираем файл
            if (k1 % 2 == 1) { // проверка четности позиции числа
                Chet << x<< " ";
            }
            else {
                NeChet << x << " ";
            }
            k1++;
        }
        inp.close(); // закрываем файлы
        Chet.close();
        NeChet.close();

    }
}