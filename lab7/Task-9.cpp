#include <iostream>
#include <cmath>

using namespace std;

class box {
private:
    double side1, side2, side3, side4;
public:
    box(double s1, double s2, double s3, double s4) : side1(s1), side2(s2), side3(s3), side4(s4) {}
    ~box() {}
    double Diag1() {
        return sqrt(side1*side1 + side3*side3);
    }
    double Diag2() {
        return sqrt(side2*side2 + side4*side4);
    }
    double Peri() {
        return side1 + side2 + side3 + side4;
    }
    double Square() {
        double p = Per() / 2;
        return sqrt((p - side1) * (p - side2) * (p - side3) * (p - side4));
    }
    bool ThisBox() {
        return side1 == side2 && side2 == side3 && side3 == side4;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество четырехугольников: ";
    cin >> N;
    double minPer = INT_MAX;
    box minPerQuad(0, 0, 0, 0);
    for (int i = 0; i < N; i++) {
        double s1, s2, s3, s4;
        cout << " Введите стороны четырехугольника " << i+1 << ": ";
        cin >> s1 >> s2 >> s3 >> s4;
        box quad(s1, s2, s3, s4);
        if (quad.Per() < minPer) {
            minPer = quad.Per();
            minPerQuad = quad;
        }
    }
    cout << "Четырехугольник с минимальным периметром: ";
    cout << "Диагональ 1 = " << minPerQuad.Diag1() << ", ";
    cout << "Диагональ 2 = " << minPerQuad.Diag2() << ", ";
    cout << "Периметр: " << minPerQuad.Per() << ", ";
    cout << "Площадь: " << minPerQuad.Square() << ", ";

    if (minPerQuad.ThisBox()) {
        cout << "Это квадрат.";
    } else {
        cout << "Это не квадрат.";
    }
    return 0;
}
