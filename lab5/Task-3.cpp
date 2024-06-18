#include <iostream>
#include <fstream>
using namespace std;

void MinMaxElement(int A[][5], int M, int& minElement, int& maxElement) {
    minElement = A[M-1][0];
    maxElement = A[M-1][0];
    for (int i = M-2; i >= 0; i--) {
        for (int j = M-2-i; j >= 0; j--) {
            if (A[i][j] < minElement) {
                minElement = A[i][j];
            }
            if (A[i][j] > maxElement) {
                maxElement = A[i][j];
            }
        }
    }
}
int main() {
    const int M = 5;
    int A[M][M];
    ifstream file("matrix.txt");
    if (!file) {
        cout << "Ошибка чтения файла." << endl;
        return 1;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            file >> A[i][j];
        }
    }
    file.close();
    cout << "Матрица A:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    int minElement, maxElement;
    MinMaxElement(A, M, minElement, maxElement);
    cout << "Минимальный элемент под побочной диагональю: " << minElement << endl;
    cout << "Максимальный элемент под побочной диагональю: " << maxElement << endl;

    return 0;
}