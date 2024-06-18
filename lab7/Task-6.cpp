#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double R;
public:
    Circle(double radius) {
        if (radius > 0) {
            R = radius;
        } else {
            cout << "Радиус должен быть положительным\n";
            R = 0;
        }
    }
    ~Circle() {
    }
    double square() {
        return M_PI * R * R;
    }
    double length() {
        return 2 * M_PI * R;
    }
    void info() {
        cout << "Радиус окружности: " << R << endl;
        cout << "Площадь окружности: " << fixed << square() << endl;
        cout << "Длина окружности: " << fixed << length() << endl;
    }
    double getRadius() {
        return R;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    double squares = 0;
    cout << "Введите количество окружностей: ";
    cin >> N;
    Circle** circles = new Circle*[N];
    for (int i = 0; i < N; ++i) {
        double radius;
        cout << "Введите радиус " << i + 1 << "-й окружности: ";
        cin >> radius;
        circles[i] = new Circle(radius);
        squares += circles[i]->square();
    }
    double avgsquares = squares / N;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        circles[i]->info();
        if (circles[i]->square() < avgsquares) {
            count++;
        }
    }
    cout << "Количество окружностей с площадью меньше средней: " << count << endl;
    for (int i = 0; i < N; ++i) {
        delete circles[i];
    }
    delete[] circles;
    return 0;
}