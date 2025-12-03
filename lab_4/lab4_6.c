#include <stdio.h>
int main(void){	
	unsigned char c;
	unsigned char r;
	unsigned char k = 2;
	unsigned char sum;
	unsigned char a = 17;
	c = a >> k;
	r = a << (8 - k);
	sum = c | r;
    printf("%d\n", sum);
}
