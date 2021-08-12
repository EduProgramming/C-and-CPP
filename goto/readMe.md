# goto

중간의 코드는 무시하고 원하는 부분으로 건너뛰어야 하는 사황이 생길 때 사용



```c
#include <stdio.h>

int main() {
    int num = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (num == 10)
                goto EXIT;
                
                num++;
        }
    }
    
    EXIT:
        printf("%d", num);
        return 0;
}
```

