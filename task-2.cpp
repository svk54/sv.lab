#include<stdio.h>
#include<math.h>
#include<locale.h> 
int main()
{
setlocale(LC_ALL, "Russian");
float x,y,R;
printf("Разветвляющийся алгоритм \n");
printf("Bвeдитe значение Х: "); 
scanf("%f", &x) ;
printf("Bвeдитe значение У: ");
scanf("%f", &y) ;
R=sqrt(pow(x,2)+pow(y,2));
if (x >= 0 && R >= 1 && R <= 2)
{
	printf("точка с координатами (Х; У) принадлежит заштрихованной части плоскости\n");
}
else
	printf("точка с координатами (Х; У) не принадлежит заштрихованной части плоскости\n");
return 0;
}	