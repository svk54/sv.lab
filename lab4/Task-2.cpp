#include <iostream>
#include <fstream>
using namespace std;

int coutdig(int num) {
    if (num == 0) {
        return 1; 
    }
    int cout = 0;
    while (num != 0) {
        num /= 10;
        cout++;
    }
    return cout;
}
int main() {
    ifstream inputFile("cout.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла\n";
        return 1;
    }
    int 1st = 0, 2nd = 0, 3rd = 0;
    int num;
    while (inputFile >> num) {
        int digit = coutdig(num);
        if (digit == 1) {
            1st++;
        } else if (digit == 2) {
            2nd++;
        } else if (digit == 3) {
            3rd++;
        }
    }
    inputFile.close();
    ofstream outputFile("result.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка записи в файл\n";
        return 1;
    }
    outputFile << "Количество однозначных чисел: " << 1st << endl;
    outputFile << "Количество двузначных чисел: " << 2nd << endl;
    outputFile << "Количество трехзначных чисел: " << 3rd << endl;
    outputFile.close();
    cout << "Результат записан в файл result.txt\n";
    return 0;
}