# 전역변수

전역공간에서 코드를 실행할 수 없다.

선언과 변수 초기화까지만 가능. (할당도 불가)

> C++의 경우 전역에서 실행하고 싶은게 있으면, 클래스 하나 만들어서 생성자에 원하는 코드를 집어 넣고, 그 클래스의 객체를 전역에서 선언 및 초기화하면 되긴 함.


**안되던 경우 예시)**

```c
#include <iostream>

using namespace std;

int test = 5;
test = 7;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}
```

위에 나와있듯, 전역공간에서 할당이 이뤄지면서 Error가 생김.