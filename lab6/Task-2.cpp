#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    setlocale (LC_ALL, "Russian");
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Ошибка чтения файла" << endl;
        return 1;
    }

    int n;
    file >> n;

    double** points = new double*[n];
    for (int i = 0; i < n; i++) {
        points[i] = new double[2];
    }

    for (int i = 0; i < n; i++) {
        file >> points[i][0] >> points[i][1];
    }

    double mdistance = INT32_MAX;
    int point1 = -1, point2 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = points[j][0] - points[i][0];
            double dy = points[j][1] - points[i][1];
            double distance = sqrt(dx * dx + dy * dy);

            if (distance < mdistance) {
                mdistance = distance;
                point1 = i;
                point2= j;
            }
        }
    }

    cout << "Координаты двух точек, наиболее близких друг к другу: (" << points[point1][0] << ", " << points[point2][1] << ") и (" << points[point1][0] << ", " << points[point2][1] << ")" << endl;
    cout << "Расстояние между ними: " << mdistance << endl;

    for (int i = 0; i < n; i++) {
        delete[] points[i];
    }
    delete[] points;

    file.close();

    return 0;
}
