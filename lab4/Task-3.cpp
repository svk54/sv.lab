#include <iostream>
using namespace std;

int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int nodn(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = nod(result, arr[i]);
    }
    return result;
}
int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;
    int numbers[n];
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int result = nodn(numbers, n);
    cout << "Наибольший общий делитель всех чисел: " << result << endl;
    return 0;
}