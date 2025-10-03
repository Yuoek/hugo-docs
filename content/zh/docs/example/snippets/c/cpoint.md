## cpoint 
### 指针定义与初始化
```c
#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;  // 定义指向int的指针
    
    printf("变量值: %d\n", num);
    printf("指针指向的值: %d\n", *ptr);
    printf("指针地址: %p\n", ptr);
    printf("变量地址: %p\n", &num);
    
    return 0;
}
```

### 基本运算
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("初始指针位置: %p\n", ptr);
    printf("值: %d\n", *ptr);
    
    ptr++;  // 指针前进
    printf("前进后位置: %p\n", ptr);
    printf("值: %d\n", *ptr);
    
    ptr--;  // 指针后退
    printf("后退后位置: %p\n", ptr);
    
    return 0;
}
```

### 数组指针操作
```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    // 通过指针访问数组元素
    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(ptr+%d) = %d\n", 
               i, arr[i], i, *(ptr + i));
    }
    
    return 0;
}
```

### 指针作为函数参数
```c
#include <stdio.h>

// 交换两个变量的值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    
    printf("交换前: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("交换后: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

### 返回指针的函数
```c
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    return arr;
}

int main() {
    int *myArray = createArray(5);
    
    for(int i = 0; i < 5; i++) {
        printf("myArray[%d] = %d\n", i, myArray[i]);
    }
    
    free(myArray);  // 释放内存
    return 0;
}
```


### 二级指针示例
```c
#include <stdio.h>

int main() {
    int num = 100;
    int *ptr = &num;
    int **pptr = &ptr;  // 指向指针的指针
    
    printf("num的值: %d\n", num);
    printf("*ptr的值: %d\n", *ptr);
    printf("**pptr的值: %d\n", **pptr);
    
    printf("num的地址: %p\n", &num);
    printf("ptr的值: %p\n", ptr);
    printf("*pptr的值: %p\n", *pptr);
    
    return 0;
}
```

### 字符串指针操作
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    char *ptr = str;
    
    printf("字符串: %s\n", str);
    printf("通过指针: %s\n", ptr);
    
    // 遍历字符串
    while(*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");
    
    return 0;
}
```

### 函数指针基础
```c
#include <stdio.h>

// 简单的数学函数
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // 声明函数指针
    int (*operation)(int, int);
    
    int x = 10, y = 5;
    
    // 使用函数指针调用不同的函数
    operation = add;
    printf("%d + %d = %d\n", x, y, operation(x, y));
    
    operation = subtract;
    printf("%d - %d = %d\n", x, y, operation(x, y));
    
    operation = multiply;
    printf("%d * %d = %d\n", x, y, operation(x, y));
    
    return 0;
}
```

### malloc和free使用
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("请输入数组大小: ");
    scanf("%d", &n);
    
    // 动态分配内存
    int *arr = (int*)malloc(n * sizeof(int));
    
    if(arr == NULL) {
        printf("内存分配失败!\n");
        return 1;
    }
    
    // 初始化数组
    for(int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
    
    // 打印数组
    printf("动态数组内容: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 释放内存
    free(arr);
    
    return 0;
}
```

### 指针数组示例
```c
#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    int *ptr_arr[3];  // 指针数组
    
    ptr_arr[0] = &a;
    ptr_arr[1] = &b;
    ptr_arr[2] = &c;
    
    for(int i = 0; i < 3; i++) {
        printf("ptr_arr[%d]指向的值: %d\n", i, *ptr_arr[i]);
    }
    
    return 0;
}
```



## cpptemplate
### 模板声明语法
```cpp
template<typename T>  // 或 template<class T>
返回值类型 函数名(参数列表);

template<typename T>
class 类名 {
    // 类定义
};
```

### 基本用法
```cpp
template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

// 使用
int result = max<int>(5, 10);  // 显式实例化
auto result2 = max(5.5, 3.14); // 隐式实例化
```

### 特化与重载
```cpp
// 特化
template<>
const char* max<const char*>(const char* a, const char* b) {
    return strcmp(a, b) > 0 ? a : b;
}

// 重载
template<typename T>
T max(T a, T b, T c) {
    return max(max(a, b), c);
}
```


### 类模板基本语法
```cpp
template<typename T>
class Vector {
private:
    T* data;
    size_t size;
public:
    Vector(size_t n) : size(n), data(new T[n]) {}
    ~Vector() { delete[] data; }
    
    T& operator[](size_t index) { return data[index]; }
};
```

### 成员函数模板
```cpp
template<typename T>
class MyClass {
public:
    template<typename U>
    void process(U value) {
        // 实现
    }
};
```


### 类型参数
```cpp
template<typename T>          // 单个类型参数
template<typename T, typename U> // 多个类型参数
```

### 非类型参数
```cpp
template<typename T, int Size>
class Array {
    T data[Size];
};

// 使用
Array<int, 10> arr;
```

### 模板模板参数
```cpp
template<template<typename> class Container, typename T>
class Adapter {
    Container<T> data;
};
```

### 默认模板参数
```cpp
template<typename T = int, int Size = 10>
class Buffer {
    // 实现
};
```


### 全特化
```cpp
template<>
class Vector<bool> {
    // 针对bool类型的特殊实现
};
```

### 偏特化
```cpp
template<typename T>
class Pointer<T*> {
    // 针对指针类型的特殊实现
};
```

### 可变参数模板基本语法
```cpp
template<typename... Args>
void print(Args... args) {
    // 处理参数包
}
```

### 参数包展开
```cpp
template<typename... Args>
void print(Args... args) {
    (cout << ... << args); // C++17 折叠表达式
}
```

### 完美转发
```cpp
template<typename... Args>
void forwarder(Args&&... args) {
    some_function(std::forward<Args>(args)...);
}
```


### SFINAE（Substitution Failure Is Not An Error）
```cpp
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
process(T value) {
    return value * 2;
}
```

### 概念（Concepts）
```cpp
template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T process(T value) {
    return value * 2;
}
```


### 编译时计算
```cpp
template<int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};
```

### 类型特征
```cpp
template<typename T>
struct is_pointer {
    static const bool value = false;
};

template<typename T>
struct is_pointer<T*> {
    static const bool value = true;
};
```

### 友元模板
```cpp
template<typename T>
class MyClass {
    template<typename U>
    friend class FriendClass;
};
```

### 模板别名（C++11）
```cpp
template<typename T>
using MyVector = std::vector<T, MyAllocator<T>>;
```

### 变量模板（C++14）
```cpp
template<typename T>
constexpr T pi = T(3.1415926535897932385);
```

