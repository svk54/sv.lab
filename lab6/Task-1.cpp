#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale (LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* x = new int[n];
    int* y = new int[n];

    cout << "Введите элементы массива X: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    y[0] = x[0];
    y[n-1] = x[n-1];
    for (int i = 1; i < n-1; i++) {
        y[i] = x[n-i];
    }

    ofstream file("result.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << y[i] << " ";
        }
        file.close();
        cout << "Массив Y записан в файл output.txt" << endl;
    } else {
        cout << "Ошибка чтения/записи файла!" << endl;
    }

    delete[] x;
    delete[] y;

    return 0;
}
