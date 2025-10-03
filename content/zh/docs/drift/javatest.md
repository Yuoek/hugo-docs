



```c 
// 定义结构体数组
struct Student class[3] = {
    {1001, "张三", 85.5, 20},
    {1002, "李四", 92.0, 19},
    {1003, "王五", 78.5, 21}
};

// 访问结构体数组元素
for(int i = 0; i < 3; i++) {
    printf("学生%d：%s，成绩：%.1f\n", 
           class[i].id, class[i].name, class[i].score);
}

```

```c 
struct Student stu;
struct Student *p = &stu;

// 方式1：使用->运算符
p->id = 1002;
strcpy(p->name, "赵六");

// 方式2：使用*和.运算符
(*p).score = 88.5;

```

```c 
// 顺序初始化
struct Student stu1 = {1001, "张三", 85.5, 20};

// 指定成员初始化（C99标准）
struct Student stu2 = {
    .id = 1002,
    .name = "李四",
    .age = 21
};

// 部分初始化
struct Student stu3 = {1003}; // 其余成员自动初始化为0

```


```c 
// 方式1：先定义后声明
struct Student {
    int id;
    char name[20];
};
struct Student stu1;

// 方式2：定义时声明
struct Student {
    int id;
    char name[20];
} stu1, stu2;

// 方式3：使用typedef
typedef struct {
    int id;
    char name[20];
} Student;
Student stu1;

```

```c 
#include <stdio.h>

// 1 
struct Dog {
    char name[20];
    int age;
}; 

// 2 
struct Cat {
    char name[20]; 
    int age; 
}A, B; 

typedef struct {
    char name[20];
    int age; 

} Person;

int main(){
    // Person student = {"Sophie", 16};
    Person student = {
        .name = "Sophie",
        .age = 16
    };
    printf("%s\n", student.name);
    printf("Age: %d\n", student.age);

    Person owner = {"Yuoek", 24};
    Person* myself = &owner;

    printf("%s\n", myself -> name);
    printf("Age: %d\n", myself -> age);

    return 0;
}

```


```c 
// 结构体定义
struct Student {
    int id;
    char name[20];
    float score;
    int age;
};

```

```c 
struct Dog {
    char name[20];
    int age; 
    char color=[10];
};

```


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

```c 
#include <stdio.h> 
int main(){
    int arr[] = {2, 4, 5, 1, 8};
    int* prt = arr; 
    printf("Address of ptr: %p\n", prt);
    printf("Value of ptr: %d\n", *prt);

    prt++;
    printf("Address of ptr: %p\n", prt);
    printf("Value of ptr: %d\n", *prt);
    prt--;
    printf("Address of ptr: %p\n", prt);
    printf("Value of ptr: %d\n", *prt);

    for(int i=0; i < sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ---- ", i);
        printf("%d ---- ", *(prt+i));
        printf("%p", prt+i);
        printf("\n");
    }
    return 0;
}

```


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





```c 
#include <stdio.h> 
int main(){
    int num = 10; 
    int* p = &num;
    printf("Value of num: %d\n", num);
    printf("Value of p: %d\n", *p);
    printf("Address of p: %p\n", p);
    printf("Address of num: %p\n", &num);

    return 0;
}
```


```python 
my_list = [3, 1, 4, 1, 5]

# 排序（原地修改）
my_list.sort()              # [1, 1, 3, 4, 5]
my_list.sort(reverse=True)  # [5, 4, 3, 1, 1]

# 创建排序副本
sorted_list = sorted(my_list)

# 反转
my_list.reverse()           # [1, 1, 3, 4, 5] → [5, 4, 3, 1, 1]

```

```python 
my_list = [2, 3, 7, 1, 0, 8]
print(my_list)
my_list.sort()
print(my_list)
my_list.sort(reverse=True)
print(my_list)

```

```python
my_list = [10, 20, 30, 40, 50]

# 索引访问
print(my_list[0])    # 10
print(my_list[-1])   # 50（最后一个元素）

# 切片操作
print(my_list[1:3])  # [20, 30]
print(my_list[:3])   # [10, 20, 30]
print(my_list[2:])   # [30, 40, 50]
print(my_list[::2])  # [10, 30, 50]（步长为2）
```
```python 
my_list = [1, 2, 3, 9, 7, 2, 0] 
print(my_list[::3])
print(my_list[:3])
print(my_list[-1])
my_list[0] = 100 
print(my_list)

```






```java 
public interface Dog {
    void eat(); 
}

public class implements Dog, Cat {
    @Override 
    
}


```

```java 
public class Student {

    String name; 
    int age; 

    public Student ( ) {
        this.name = name; 
        this.age = age; 
    }

    
     public static void main(String[] args) {
         System.out.println("Hello\n"); 

}

```


好的，我们来详细讲解一下 Java 接口的核心概念和知识点。

### 1. 核心概念

**接口** 在 Java 中是一个完全抽象的引用类型。你可以把它理解为一个**契约**或**协议**。它定义了一组方法签名（行为规范），但**不提供这些方法的具体实现**。

任何类如果**实现**了这个接口，就必须**遵守**这个契约，即**提供接口中所有方法的具体实现**。

### 2. 关键知识点

#### 1. 声明接口
使用关键字 `interface`。
```java
public interface Animal {
    // 接口内容
}
```

#### 2. 接口的成员
在 Java 8 之前，接口只能包含：
*   **抽象方法**： 默认就是 `public abstract` 的，所以可以省略这些关键字。
*   **常量**： 默认就是 `public static final` 的。

**Java 8 及以后**，接口还可以包含：
*   **默认方法**： 使用 `default` 关键字，可以有方法体。主要用于接口的扩展，而不会破坏已有的实现类。
*   **静态方法**： 使用 `static` 关键字，可以有方法体。直接通过接口名调用。

**Java 9 及以后**，接口还可以包含：
*   **私有方法**： 使用 `private` 关键字，可以有方法体。用于在接口内部封装代码，供默认方法或静态方法使用。

**示例：**
```java
public interface Vehicle {
    // 常量 (public static final 可省略)
    int MAX_SPEED = 120;

    // 抽象方法 (public abstract 可省略)
    void start();
    void stop();

    // 默认方法 (Java 8+)
    default void honk() {
        System.out.println("Beep beep!");
        // 调用私有方法
        checkHorn();
    }

    // 静态方法 (Java 8+)
    static void getBrandInfo() {
        System.out.println("This is a Vehicle interface.");
    }

    // 私有方法 (Java 9+)
    private void checkHorn() {
        System.out.println("Horn is functional.");
    }
}
```

#### 3. 实现接口
类使用 `implements` 关键字来实现一个或多个接口。一个类可以实现多个接口（解决了 Java 单继承的限制）。

```java
// 实现一个接口
public class Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car is starting...");
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping...");
    }
    // honk() 方法有默认实现，可以不重写
}

// 实现多个接口
public class Drone implements Vehicle, Flyable {
    // 必须实现 Vehicle 和 Flyable 的所有抽象方法
    @Override
    public void start() { ... }
    @Override
    public void stop() { ... }
    @Override
    public void fly() { ... } // 来自 Flyable 接口
}
```

#### 4. 接口的继承
接口可以使用 `extends` 关键字继承其他接口，并且支持**多继承**（与类不同）。

```java
public interface Flyable {
    void fly();
}

public interface AdvancedVehicle extends Vehicle, Flyable { // 接口多继承
    void selfDrive();
}
```
任何实现 `AdvancedVehicle` 的类，必须实现 `Vehicle`、`Flyable` 和 `AdvancedVehicle` 中的所有抽象方法。

### 3. 接口 vs. 抽象类

这是一个非常重要的对比，帮助你理解何时该用接口，何时该用抽象类。

| 特性 | 接口 | 抽象类 |
| :--- | :--- | :--- |
| **方法** | 在 Java 8 前只能是抽象方法；之后可以有默认、静态、私有方法。 | 可以有抽象方法，也可以有具体实现的方法。 |
| **成员变量** | 只能是常量 (`public static final`)。 | 可以是各种类型的变量。 |
| **构造方法** | **没有**构造方法。 | **有**构造方法（虽然不能实例化，但用于子类初始化）。 |
| **继承关系** | 一个类可以**实现多个**接口。接口可以**继承多个**接口。 | 一个类只能**继承一个**抽象类。 |
| **设计理念** | **"has-a" 关系**，定义一种**能力**或**角色**。 (e.g., `Runnable`, `Comparable`) | **"is-a" 关系**，表示一种**所属关系**。 (e.g., `Animal` -> `Dog`) |
| **主要目的** | 定义**行为规范**，实现**多态**和**解耦**。 | 提供**代码复用**和**模板方法设计模式**的基础。 |

### 4. 接口的核心作用

1.  **实现多态**： 这是接口最重要的作用。你可以用接口类型来引用任何实现了该接口的类的对象。
    ```java
    Vehicle myVehicle = new Car();
    myVehicle.start(); // 调用 Car 的 start 方法
    myVehicle = new Bicycle(); // 只要 Bicycle 也实现了 Vehicle
    myVehicle.start(); // 调用 Bicycle 的 start 方法
    ```

2.  **实现完全抽象**： 将“做什么”和“怎么做”完全分离。接口只关心能做什么，不关心如何做。

3.  **实现多重继承**： Java 类不能多继承，但可以通过实现多个接口来达到类似的效果。

4.  **降低耦合**： 模块之间通过接口进行交互，而不是具体的实现类。这使得系统更灵活，易于扩展和维护。例如，Spring 框架就大量使用接口来解耦。

### 总结

Java 接口是一个强大的工具，它定义了行为的规范，是实现**多态**、**解耦**和**程序扩展性**的基石。从 Java 8 开始，接口的功能不断增强（默认方法、静态方法、私有方法），使其在软件设计中的地位更加重要。理解接口和抽象类的区别是掌握面向对象设计的关键一步。


