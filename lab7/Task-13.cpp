#include <iostream>
#include <cmath>

using namespace std;

class Box {
private:
double x1, y1, x2, y2, x3, y3, x4, y4;
public:
Box(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
: x1(a1), y1(b1), x2(a2), y2(b2), x3(a3), y3(b3), x4(a4), y4(b4) {}
~Box() {}
double Side(double x1, double y1, double x2, double y2) {
return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
double Diag() {
return sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
}
double Per() {
double s1 = Side(x1, y1, x2, y2);
double s2 = Side(x2, y2, x3, y3);
double s3 = Side(x3, y3, x4, y4);
double s4 = Side(x4, y4, x1, y1);
return s1 + s2 + s3 + s4;
}
double Square() {
double s1 = Side(x1, y1, x2, y2);
double s2 = Side(x2, y2, x3, y3);
double s3 = Side(x3, y3, x4, y4);
double s4 = Side(x4, y4, x1, y1);
double p = Per() / 2;
return sqrt((p - s1) * (p - s2) * (p - s3) * (p - s4));
}
bool Romb() {
double d1 = Side(x1, y1, x3, y3);
double d2 = Side(x2, y2, x4, y4);
if (d1 == d2) {
return true;
}
return false;
}
};
int main() {
    setlocale (LC_ALL, "Russian");
    int n;
    cout << "Введите количество четырехугольников: ";
    cin >> n;
    Box* Boxs[n];
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cout << "Введите координаты четырехугольника " << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Boxs[i] = new Box(x1, y1, x2, y2, x3, y3, x4, y4);
        cout << "Длины сторон: " << Boxs[i]->Side(x1, y1, x2, y2) << ", " << Boxs[i]->Side(x2, y2, x3, y3)
             << ", " << Boxs[i]->Side(x3, y3, x4, y4) << ", " << Boxs[i]->Side(x4, y4, x1, y1) << endl;
        cout << "Диагонали: " << Boxs[i]->Diag() << endl;
        cout << "Площадь: " << Boxs[i]->Square() << endl;
        cout << "Периметр: " << Boxs[i]->Per() << endl;
    }
    double mSquare = 0;
    int mSquare1 = 0;
    for (int i = 0; i < n; i++) {
        double Square1 = Boxs[i]->Square();
        if (Square1 > mSquare) {
            mSquare = Square1;
            mSquare1 = 1;
        } else if (Square1 == mSquare) {
            mSquare1++;
        }
    }
    cout << "Количество четырехугольников с максимальной площадью: " << mSquare1 << endl;
    for (int i = 0; i < n; i++) {
        delete Boxs[i];
    }
    return 0;
}
