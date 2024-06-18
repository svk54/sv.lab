#include <iostream>
#include <cmath>
using namespace std;

class tree {
private:
    double a, b, c;
    double angle(double side1, double side2, double oppositeSide) {
        return acos((side1 * side1 + side2 * side2 - oppositeSide * oppositeSide) / (2 * side1 * side2));
    }
public:
    tree(double sideA = 0, double sideB = 0, double sideC = 0) : a(sideA), b(sideB), c(sideC) {}
    ~tree() {}
    bool truetree() {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    double per() {
        return a + b + c;
    }
    double square() {
        double s = per() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    bool bdr() {
        return (a == b) || (a == c) || (b == c);
    }
    void info() {
        cout << "Стороны треугольника: a = " << a << ", b = " << b << ", c = " << c << endl;
        cout << "Периметр треугольника: " << per() << endl;
        cout << "Площадь треугольника: " << square() << endl;
        double angle1 = angle(b, c, a);
        double angle2 = angle(a, c, b);
        double angle3 = angle(a, b, c);
        cout << "Углы треугольника в градусах: " << angle1 * (180 / M_PI) << ", "
             << angle2 * (180 / M_PI) << ", " << angle3 * (180 / M_PI) << endl;
    }
};
int main() {
    setlocale(LC_ALL, "Russian");
    int K;
    cout << "Введите количество треугольников: ";
    cin >> K;
    tree* treey = new tree[K];
    double sideA, sideB, sideC, totalsquare = 0;
    int truetree = 0;
    for (int i = 0; i < K; ++i) {
        cout << "Введите длины сторон треугольника " << i + 1 << ": ";
        cin >> sideA >> sideB >> sideC;
        tree t(sideA, sideB, sideC);
        if (t.truetree()) {
            treey[truetree++] = t;
            totalsquare += t.square();
            t.info(); 
        } else {
            cout << "Треугольник не существует." << endl;
        }
    }
    double averageSquare = truetree > 0 ? totalsquare / truetree : 0;
    cout << "Средняя площадь треугольников: " << averageSquare << endl;
    delete[] treey;
    return 0;
}

