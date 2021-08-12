# 배열

배열 요소를 모두 0으로 초기화

```c
int arr[10] = { 0, }; // 배열의 모든 요소를 모두 0으로 초기화
```

```c
int arr[5][5] = { 0, }; // 2차 배열에서도 사용 가능
```

그렇다면 3으로 초기화를 시켜보자.

```c
int arr[5] = { 3, };

printf("%d\n", arr[0]);
printf("%d\n", arr[1]);
printf("%d\n", arr[2]);
printf("%d\n", arr[3]);
printf("%d\n", arr[4]);
```

0번째 인덱스만 3으로 나오고, 나머지는 0으로 나오게 된다.

```c
int arr[5] = {};

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
    printf("%d\n", arr[4]);
```
0을 넣는 것과 위와 같이 초기화하는거랑 별 다를바 없다.