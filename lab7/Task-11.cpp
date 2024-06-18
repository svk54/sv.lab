#include <iostream>
#include <cmath>

using namespace std;

class Box {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Box(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
    ~Box() {}
    double Side(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    double Diag(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    double Per() {
        double per = Side(x1, y1, x2, y2);
        per += Side(x2, y2, x3, y3);
        per += Side(x3, y3, x4, y4);
        per += Side(x4, y4, x1, y1);
        return per;
    }
    double Square() {
        return abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1)) / 2;
    }
    bool PrimBox() {
        double side1 = Side(x1, y1, x2, y2);
        double side2 = Side(x2, y2, x3, y3);
        double side3 = Side(x3, y3, x4, y4);
        double side4 = Side(x4, y4, x1, y1);
        return (side1 == side3 && side2 == side4);
    }
    void Info() {
        cout << "Координаты точек: (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), (" << x3 << "," << y3 << "), (" << x4 << "," << y4 << ")" << endl;
        cout << "Длина сторон: ";
        cout << Side(x1, y1, x2, y2) << ", ";
        cout << Side(x2, y2, x3, y3) << ", ";
        cout << Side(x3, y3, x4, y4) << ", ";
        cout << Side(x4, y4, x1, y1) << endl;
        cout << "Длины диагоналей: ";
        cout << Diag(x1, y1, x3, y3) << ", ";
        cout << Diag(x2, y2, x4, y4) << endl;
        cout << "Периметр:" << Per() << endl;
        cout << "Площадь: " << Square() << endl;
          if (PrimBox()) {
        std::cout << "Это прямоугольник." << std::endl;
    } else {
        std::cout << "Это не прямоугольник." << std::endl;
    }
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество четырехугольников:";
    cin >> N;
    double mSquare = 999999;
    Box mSquareBox(0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < N; ++i) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cout << "Введите координаты четырехугольника " << i + 1 << " (x1 y1 x2 y2 x3 y3 x4 y4): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Box box(x1, y1, x2, y2, x3, y3, x4, y4);

        if (box.Square() < mSquare) {
            mSquare = box.Square();
            mSquareBox = box;
        }
    }
    cout << "Четырехугольник с минимальной площадью:" << endl;
    mSquareBox.Info();

    return 0;
}