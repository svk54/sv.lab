#include <iostream>
#include <cmath>

using namespace std;

class Quad {
private:
    double sideA, sideB, sideC, sideD;

public:
    Quad() : sideA(0), sideB(0), sideC(0), sideD(0) {}
    Quad(double a, double b, double c, double d) : sideA(a), sideB(b), sideC(c), sideD(d) {}
    ~Quad() {}
    double diag() {
        return sqrt(pow(sideA, 2) + pow(sideC, 2));
    }
    double per() {
        return sideA + sideB + sideC + sideD;
    }
    double square() {
        double s = per() / 2;
        return sqrt((s - sideA) * (s - sideB) * (s - sideC) * (s - sideD));
    }
    bool trap() {
        if ((sideA + sideC == sideB + sideD) || (sideA + sideD == sideB + sideC))
            return true;
        return false;
    }
    void description() {
        cout << "Сторона А: " << sideA << ", Сторона B: " << sideB << ", Сторона C: " << sideC << ", Сторона D: " << sideD << endl;
        cout << "Диагональ: " << diag() << endl;
        cout << "Периметр: " << per() << endl;
        cout << "Площадь: " << square() << endl;
        if (trap())
            cout << "Это трапеция." << endl;
        else
            cout << "Это не трапеция." << endl;
        cout << endl;
    }
};
int main() {
    setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество четырех угольников: ";
    cin >> N;
    Quad *quad = new Quad[N];
    for (int i = 0; i < N; i++) {
        cout << "Введите длины сторон: " << i + 1 << ": ";
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        quad[i] = Quad(a, b, c, d);
    }
    double maxsquare = 0;
    Quad maxQuad;
    for (int i = 0; i < N; i++) {
        if (quad[i].square() > maxsquare) {
            maxsquare = quad[i].square();
            maxQuad = quad[i];
        }
    }
    cout << "Максимальная площадь четырехугольника " << endl;
    maxQuad.description();

    delete[] quad;
    return 0;
}
