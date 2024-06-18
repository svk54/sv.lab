#include <iostream>
#include <cmath>

using namespace std;

class Box {
private:
    double side1, side2, side3, side4;

public:
    Box(double s1, double s2, double s3, double s4) : side1(s1), side2(s2), side3(s3), side4(s4) {
        if (!TrueBox()) {
            cout << "Четырехугольник с такими сторонами не существует!\n";
            exit(1);
        }
    }
    ~Box() {}
    bool TrueBox() {
        return side1 + side2 + side3 > side4 && side1 + side2 + side4 > side3 && side1 + side3 + side4 > side2 && side2 + side3 + side4 > side1;
    }
    double Per() {
        return side1 + side2 + side3 + side4;
    }
    double Square() {
        double p = 0.5 * Perimeter();
        return sqrt((p - side1) * (p - side2) * (p - side3) * (p - side4));
    }
    double Diag1() {
        return sqrt(side1 * side1 + side3 * side3 - 2 * side1 * side3 * cos(M_PI / 180 * 90));
    }
    double Diag2() {
        return sqrt(side2 * side2 + side4 * side4 - 2 * side2 * side4 * cos(M_PI / 180 * 90));
    }
    void Info() {
        cout << "Стороны: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << endl;
        cout << "Периметр: " << Per() << endl;
        cout << "Площадь: " << Square() << endl;
        cout << "Диагонали: " << Diag1() << ", " << Diag2() << endl;
        cout << endl;
    }
};
int main() {
    setlocale (LC_ALL, "Russian");
    int N;
    double avgPer = 0, avgSquare = 0;
    cout << "Введите количество четырехугольников : ";
    cin >> N;
    for (int i = 0; i < N; ++i) {
        double s1, s2, s3, s4;
        cout << "Введите стороны четырехугольника " << i + 1 << ": ";
        cin >> s1 >> s2 >> s3 >> s4;
        Box Boxs(s1, s2, s3, s4);
        Boxs.Info();
        avgPer += Boxs.Per();
        avgSquare += Boxs.Square();
    }
    avgPer /= N;
    avgSquare /= N;
    cout << "Средний периметр для четырехугольников: " << avgPer << endl;
    cout << "Средняя площадь для четырехугольников: " << avgSquare << endl;
    return 0;
}
