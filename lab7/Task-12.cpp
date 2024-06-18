#include <iostream>
#include <cmath>

using namespace std;

class Tree {
private:
double x1, y1;
double x2, y2;
double x3, y3;
public:
Tree(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3) {
x1 = _x1;
y1 = _y1;
x2 = _x2;
y2 = _y2;
x3 = _x3;
y3 = _y3;
}
~Tree() {}
double distance(double x1, double y1, double x2, double y2) {
return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
bool TrueTree() {
double a = distance(x1, y1, x2, y2);
double b = distance(x2, y2, x3, y3);
double c = distance(x3, y3, x1, y1);
return (a + b > c) && (a + c > b) && (b + c > a);
}
double per() {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    return a + b + c;
}
double square() {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
bool bedr() {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    return (a == b) || (b == c) || (c == a);
}
void Info() {
    cout << "Координаты точек: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")" << endl;
    cout << "Длина сторон:";
    cout << distance(x1, y1, x2, y2) << ", " << distance(x2, y2, x3, y3) << ", " << distance(x3, y3, x1, y1) << endl;
    cout << "Периметр: " << per() << endl;
    cout << "Площадь: " << square() << endl;
    if(bedr()) {
        cout << "Это равнобедренный треугольник." << endl;
    } 
    else 
    {
        cout << "Это не равнобедренный треугольник." << endl;
    }
}
};

int main() {
setlocale (LC_ALL, "Russian");
int N;
cout << "Введите количество треугольников: ";
cin >> N;
Trey* Treey[N];
for(int i = 0; i < N; i++) {
double x1, y1, x2, y2, x3, y3;
cout << "Введите координаты точек треугольника " << i+1 << ": ";
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
Treey[i] = new Tree(x1, y1, x2, y2, x3, y3);
}
double minSquare = Treey[0]->square();
double maxSquare = Treey[0]->square();
int min = 0;
int max = 0;
for (int i = 1; i < N; i++) {
if (Treey[i]->square() < minSquare) {
minSquare = Treey[i]->square();
min = i;
}
if (Treey[i]->square() > maxSquare) {
maxSquare = Treey[i]->square();
max = i;
}
}
cout << "Треугольник с минимальной площадью:" << endl;
    Treey[min]->Info();
    cout << "Треугольник с максимальной площадью:" << endl;
    Treey[max]->Info();
    for(int i = 0; i < N; i++) {
        delete Treey[i];
    }
    return 0;
}
