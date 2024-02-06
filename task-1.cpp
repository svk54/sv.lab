#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
int a,b;
double F;
cout << "Input a:"; cin >> a;
cout << "Input b: "; cin >> b;
F=(8,15*pow(b,1/3)*log(a))/(24.38*cos(b)*(exp(a)-pow(a,2)));
cout <<"F="<<F << "\n";
return 0;
}