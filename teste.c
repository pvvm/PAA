#include <stdio.h>

int main(void) {
	int num = 0;
    while(num != 42 && num < 100){
        scanf("%d", &num);
        if(num != 42)
            printf("%d\n", num);
    }
	return 0;
}