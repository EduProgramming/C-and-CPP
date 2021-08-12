#include <stdio.h>

int main() {
    int inputValue;
    scanf("%d", &inputValue);
    
    if (inputValue == 1)
        goto ONE;
    else if (inputValue == 2)
        goto TWO;
    else
        goto EXIT;
        
    ONE:
        printf("ONE");
        goto EXIT;
    TWO:
        printf("TWO");
        goto EXIT;
    EXIT:
        return 0;
}