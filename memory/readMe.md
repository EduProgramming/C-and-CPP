# 메모리 사용하기

메모리는 `malloc -> 사용 -> free` 패턴으로 사용



## 1. 메모리 할당하기

메모리를 사용하려면 `malloc 함수`로 사용할 메모리 공간을 확보해야 한다.

이때 필요한 메모리 크기는 byte단위로 지정(메모리 할당, 해제 함수는 `stdlib.h` 헤더 파일에 선언되어 있다.)



같은 메모리 주소라도 내부적으로 약간의 차이가 있다. 변수는 **`스택(stack)`**에 생성되며, malloc함수는  **`힙(heap)`** 부분의 메모리를 사용한다. 스택과 힙의 큰 차이점은 **메모리 해제**이다. 스택에 생성된 변수는 사용한 뒤 따로 처리를 해주지 않아도 되지만, `malloc함수`를 사용하여 힙에 할당한 메모리는 반드시 해제를 해주어야 한다.



- **malloc**

```c
포인터 = malloc(크기);
```

> **`void malloc(size_t_Size);`**
>
> : 성공하면 메모리 주소를 반환, 실패하면 NULL을 반환



- **free**

```c
free(포인터); // 동적으로 할당한 메모리 해제
```

>**`void free(void *_Block);`**
>
>: 동적으로 할당한 메모리 해제

메모리 해제는 선택이 아닌 필수.

메모리를 해제하지 않아 메모리 사용량이 계속 증가하는 현상을 메모리 누수(memory leak)라 한다.



```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 5;
    int *numPointer;
    
    numPointer = &num;
    
    int *numPointer2;
    numPointer2 = malloc(sizeof(int)); // 4byte 동적 메모리 할당
    
    printf("%d\n", sizeof(numPointer2));
    
    printf("%p\n", numPointer);
    printf("%p\n", numPointer2);
    
    free(numPointer2);
    
    return 0;
}
```





## 2. 메모리에 값 저장하기

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numPointer;
    
    numPointer = malloc(sizeof(int)); // 4byte 동적 메모리 할당
    
    *numPointer = 7;
    
    printf("%d\n", *numPointer);
    
    free(numPointer);
    
    return 0;
}
```



## 3. 메모리 내용을 한꺼번에 설정하기

- **memset**

**mem**ory **set**에서 따왔으며, `string.h`파일에 선언되어 있다.

```c
memset(포인터, 설정할값, 크기);
```

> **void memset(void *_Dst, int _Val, size_t_Size);**
>
> : 값 설정이 끝난 포인터를 반환



```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long *numPointer = malloc(sizeof(long long)); // 동적 메모리 할당
    
    memset(numPointer, 0x27, 8); // 8byte만큼 0x27로 설정
    
    printf("0x%llx\n", *numPointer); // 11이 아닌 ll(long long)
    // 0x2727272727272727: 27이 8개 들어가 있음
    
    free(numPointer); // 동적 할당 메모리 해제
    
    return 0;
}
```

`memset`함수는 주로 설정할 값을 0으로 지정하여 메모리의 내용을 모두 0으로 만들 때 주로 사용.

```c
memset(numPointer, 0, 8); // numPointer 가리키는 메모리를 8byte만큼 0으로 설정
```



## 4. Null 포인터 사용하기

메모리가 할당된 포인터도 있겠지만, 메모리가 할당되지 않은 포인터도 있을 것이다.

```c
#include <stdio.h>

int main() {
    int *numPointer = NULL;
    
    printf("%p\n", numPointer);
    
    return 0;
}
```

메모리 할당이 `NULL`이면 처리하는 방법

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numPointer = NULL;
    
    if (numPointer == NULL) {
        numPointer = malloc(1024);
    }
    
    printf("%p\n", numPointer);
    
    free(numPointer);
    
    return 0;
}
```

