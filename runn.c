#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(){
	int result;
	int n1 = 1;
	int n2 = 2;
	syscall(327, n1, n2, &result);
	printf("result: %d", result);
	return 0;
}

