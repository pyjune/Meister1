#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void f1(int n)
{
	n = n+10;
	printf("%d\n",n);
}
void f2(int *p)  // 주소를 이용해 원본에 접근한다.. 
{
	*p = *p * 2;
}
void f3(int arr[])
{
	printf("arr[0] : %d\n", arr[0]);	
} 
void f4(int *p)
{
	printf("*p : %d\n", *p);	
}
void f5(int *p)
{
	printf("p[0] : %d\n", p[0]);	
}
int main(int argc, char *argv[]) {
	
	int arr[10]={7, 8, 9};
	int a = 10;
	
	int * pA; 
	
	f1(a);
	printf("a : %d\n", a);
	f2(&a);// a값을 두배로 증가..a의 주소를 알려줌.. 
	printf("a : %d\n", a);
	f3(arr);
	f4(arr);
	f5(arr);
	
	pA = &a;
	printf("&a : %p\n", &a);
	printf("pA : %p\n", pA);
	printf("&arr[0] : %p\n", &arr[0]);
	printf("&arr[1] : %p\n", &arr[1]);	
	printf("&arr[2] : %p\n", &arr[2]);
	
	return 0;
}




