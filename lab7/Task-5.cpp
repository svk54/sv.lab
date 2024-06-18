#include <iostream>
#include <cmath>
using namespace std;

class Box {
private:
    double a, b;
public:
    Box() : a(0), b(0) {}\

    Box(double a, double b) : a(a), b(b) {}

    double diag() const {
        return sqrt(a * a + b * b);
    }

    double per() const {
        return 2 * (a + b);
    }
    double square() const {
        return a * b;
    }
    bool isQuad() const {
        return a == b;
    }
    void info() const {
        cout << "Стороны: a = " << a << ", b = " << b << endl;
        cout << "Диагональ: " << diag() << endl;
        cout << "Периметр: " << per() << endl;
        cout << "Площадь: " << square() << endl;
        cout << "Квадрат: " << (isQuad() ? "Да" : "Нет") << endl;
    }
};

int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество прямоугольников: ";
    cin >> N;
    double totalSquare = 0;
    Box* rects = new Box[N];
    double* squares = new double[N];

    for (int i = 0; i < N; ++i) {
        double a, b;
        cout << "Введите длины сторон a и b для прямоугольника " << i + 1 << ": ";
        cin >> a >> b;
        rects[i] = Box(a, b);
        squares[i] = rects[i].square();
        totalSquare += squares[i];
    }

    double avgSquare = totalSquare / N;
    int countAboveAverage = 0;

    for (int i = 0; i < N; ++i) {
        if (squares[i] > avgSquare) {
            ++countAboveAverage;
            rects[i].info();
        }
    }

    cout << "Количество прямоугольников с площадью больше средней: " << countAboveAverage << endl;

    delete[] squares;
    delete[] rects;
    return 0;
}




