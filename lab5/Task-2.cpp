#include <iostream>
using namespace std;

int Part(int arr[], int size) {
    setlocale(LC_ALL, "Russian");
    int FP = 0;
    for (int i = 0; i < size; i++) {
        bool fav = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                fav = false;
                break;
            }
        }
        if (fav) {
            FP++;
        }
    }
    return FP1;
}
int main() {
    const int N = 10;
    int arr[N];
    cout << "Введите " << N << " элементов массива:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int FP = Part(arr, N);
    cout << "Количество уникальных элементов в массиве: " << FP << endl;
    return 0;
}