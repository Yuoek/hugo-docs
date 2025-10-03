---
title: "Class"
date: 2025-09-22T17:33:30+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

```cpp 
#include <iostream> 

using namespace std;

int main(){
    int a=10;
    int b=10;
    int c=10;
    cout << "a=" << a << "\nb=" << b << "\nc=" << c << endl;

    return 0;
}

```



```c
#include <stdio.h> 

void az();
int main(){
    int a=10;
    int b=10;
    int c=10;
    char num = 'a';
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    printf("%d\n", num);
    az();
    return 0;
}

void az(){
    int i;
    int n=255;
    for (i=0;i<n;i++){
        printf("%d = %c\n", i, i);
    }
}

```
