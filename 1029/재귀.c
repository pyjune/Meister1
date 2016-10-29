#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int A[] = {3, 2, 4, 5, 6};
int B[5];
void f(int n, int k);
long long fact(int n);
void binary(int n, int k);

int main(int argc, char *argv[]) {
	int i;
	int size = sizeof(A)/sizeof(A[0]);
	// f(0, size);
	f(0, 5);
	for(i=0;i<5;i++)
	printf("%d ", B[i]);
	printf("\n");
	 
	printf("%lld\n", fact(20));
	 
	binary(0, 3);
	 
	return 0;
}
// 0, 1로 배열 채우기
void binary(int n, int k)
{
	 int i;
	 if(n==k)
	 {
		  for(i=0;i<k;i++)
		   	printf("%d ", B[i]);
		  printf("\n");
		  return;
	 }
	 else
	 {
		  B[n] = 0;
		  binary(n+1, k);
		  B[n] = 1;
		  binary(n+1, k);
	 }
}
// 팩토리얼!
long long fact(int n)
{
	 if(n<2)
	  	return 1;
	 else
	  	return n*fact(n-1);
}
// 배열 복사
void f(int n, int k) 
{
	 if(n==k)
	 {
	  	return;
	 }
	 else
	 {
	  	B[n] = A[n];
	  	f(n+1, k);
	 }
}
