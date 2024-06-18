#include <iostream>
#include <cmath>

using namespace std;

class Tree {
private:
double a, b, c; 
public:
Tree(double sideA, double sideB, double sideC) {
a = sideA;
b = sideB;
c = sideC;
}
~Tree() {}
double Per() {
    return a + b + c;
}
double square() {
    double p = Per() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void Info() {
    cout << "Стороны прямоугольного треугольника: " << a << ", " << b << ", " << c << endl;
    cout << "Периметр: " << Per() << endl;
    cout << "Площадь: " << square() << endl;
    if (a == b || b == c || a == c) {
        cout << "Прямоугольный треугольник равнобедренный." << endl;
    } else {
        cout << "Прямоугольный треугольник не равнобедренный" << endl;
    }
}
};
int main() {
setlocale (LC_ALL, "Russian");
int n;
cout << "Введите количество прямоугольных треугольников: ";
cin >> n;
double squares = 0;
Tree** Treey = new Tree*[n];
for (int i = 0; i < n; i++) {
    double sideA, sideB, sideC;
    cout << "Введите стороны треугольника " << i + 1 << ": ";
    cin >> sideA >> sideB >> sideC;
    Tree[i] = new Treey(sideA, sideB, sideC);
    squares += Tree[i]->square();
}
double avgsquare = squares / n;
int count = 0;
for (int i = 0; i < n; i++) {
    if (Tree[i]->square() < avgsquare) {
        count++;
    }
    cout << "Треугольник " << i + 1 << ":" << endl;
    Tree[i]->Info();
}
cout << "Количество треугольников, площадь которых меньше средней площади: " << count << endl;
for (int i = 0; i < n; i++) {
    delete Tree[i];
}
delete[] Tree;
return 0;
}