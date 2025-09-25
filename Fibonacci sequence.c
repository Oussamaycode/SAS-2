#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int fibonacci(int n){
	int T[n+1];
	T[0]=0;
	T[1]=1;
	if (n==0 || n==1){
		return n;
	}else{
	for(int i=2;i<=n;i++){
		T[i]=T[i-2]+T[i-1];
	}
	return T[n];
	}
}
int main(){
	printf("%d",fibonacci(5));
	return 0;
}
