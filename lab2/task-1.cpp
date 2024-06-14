#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
setlocale(LC_ALL, "Russian");
int a,b;
double F;
cout << "Линейный алгоритм \n";
cout << "Введите a:"; cin >> a;
cout << "Введите b: "; cin >> b;
F=(8,15*cbrt(b)*log(a))/(24.38*cos(b)*(exp(a)-pow(a,2)));
cout <<"F="<<F<< "\n";
return 0;
}