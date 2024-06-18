#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];
    int R;

    cout << "Введите число R: ";
    cin >> R;
    cout << "Введите " << N << " элементов массива:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxDiff = -1, elem1, elem2;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = abs(arr[i] - arr[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
                elem1 = min(arr[i], arr[j]);
                elem2 = max(arr[i], arr[j]);
            }
        }
    }

    cout << "Два различных элемента элемента массива, разность которых наиболее далека от R: " << elem1 << " и " << elem2 << endl;

    return 0;
}