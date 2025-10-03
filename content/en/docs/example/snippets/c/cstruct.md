
## cstruct
### 定义
```c
// 结构体定义
struct Student {
    int id;
    char name[20];
    float score;
    int age;
};
```

### 声明方式
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

### 初始化方法
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

### 普通变量访问
```c
struct Student stu;
stu.id = 1001;
strcpy(stu.name, "王五");
stu.score = 90.5;

printf("学号：%d\n", stu.id);
printf("姓名：%s\n", stu.name);
```

### 指针变量访问
```c
struct Student stu;
struct Student *p = &stu;

// 方式1：使用->运算符
p->id = 1002;
strcpy(p->name, "赵六");

// 方式2：使用*和.运算符
(*p).score = 88.5;
```

### 结构体数组
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

### 结构体作为函数参数
```c
// 值传递
void printStudent(struct Student stu) {
    printf("学号：%d，姓名：%s\n", stu.id, stu.name);
}

// 地址传递（推荐）
void modifyStudent(struct Student *pStu) {
    pStu->score += 5.0;
}
```

### 结构体作为函数返回值
```c
struct Student createStudent(int id, char *name, float score) {
    struct Student stu;
    stu.id = id;
    strcpy(stu.name, name);
    stu.score = score;
    return stu;
}
```

### 结构体嵌套
```c
struct Date {
    int year;
    int month;
    int day;
};

struct Employee {
    int id;
    char name[20];
    struct Date birthday;  // 结构体嵌套
    float salary;
};

// 初始化嵌套结构体
struct Employee emp = {
    1001, 
    "张三", 
    {1990, 5, 15},  // 嵌套结构体初始化
    8000.0
};

// 访问嵌套成员
printf("出生年份：%d\n", emp.birthday.year);
```

### 结构体指针数组
```c
struct Student *pStu[3];
for(int i = 0; i < 3; i++) {
    pStu[i] = &class[i];  // class为结构体数组
}
```

### 动态分配结构体
```c
#include <stdlib.h>

// 动态分配单个结构体
struct Student *p = (struct Student*)malloc(sizeof(struct Student));

// 动态分配结构体数组
struct Student *pArray = (struct Student*)malloc(10 * sizeof(struct Student));

// 使用后释放内存
free(p);
free(pArray);
```

### 结构体对齐（内存对齐）
```c
struct Example1 {    // 占用12字节
    char a;          // 1字节
    int b;           // 4字节（偏移量从4开始）
    char c;          // 1字节
};                   // 补齐到12字节

struct Example2 {    // 占用8字节
    char a;          // 1字节
    char c;          // 1字节
    int b;           // 4字节
};                   // 补齐到8字节
```

### 位域（Bit Fields）
```c
struct Status {
    unsigned int isReady : 1;    // 1位
    unsigned int isError : 1;    // 1位
    unsigned int code : 4;       // 4位
    unsigned int : 2;            // 2位未使用
};
```

### 柔性数组（C99）
```c
struct DynamicArray {
    int length;
    int data[];  // 柔性数组成员
};
```

### 结构体比较
```c
// 不能直接比较结构体，需要逐个比较成员
int compareStudents(struct Student s1, struct Student s2) {
    return s1.id == s2.id && strcmp(s1.name, s2.name) == 0;
}
```

### 结构体复制
```c
// 可以直接赋值（浅拷贝）
struct Student stu1 = {1001, "张三", 85.5};
struct Student stu2 = stu1;

// 深拷贝需要手动实现
void deepCopyStudent(struct Student *dest, const struct Student *src) {
    dest->id = src->id;
    strcpy(dest->name, src->name);
    dest->score = src->score;
}
```



