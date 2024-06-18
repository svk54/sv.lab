#include <iostream>
#include <fstream>
using namespace std;

int coutdel(int num) {
    int del = 0;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            del++;
        }
    }
    return del;
}
bool std(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    ofstream outputFile("result.txt");
    int num;
    int coutstd = 0;
    cout << "Введите последовательность целых чисел :\n";
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }

        int del = coutdel(num);
        outputFile << "Число " << num << " имеет " << del << " делителей.\n";

        if (std(num)) {
            coutstd++;
        }
    }
    outputFile << "Общее количество простых чисел в последовательности: " << coutstd << end1;
    outputFile.close();
    cout << "Сохранено result.txt\n";
    return 0;
}