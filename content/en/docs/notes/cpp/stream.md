## stream 流 

二进制的数据如同河流一样流进流出程序，在输入输出设备间得到相应。

流进：`>>`    
流出：`<<`    


```cpp 
std::cout 
std::cin    
std::cerr   
std::clog   


```
```cpp 
#include <iostream> 
#include <string>

int main(){
    int age = 24;
    double salary = 15.8;
    std::string name = "water";

    std::cout << "No money" << name << std::endl;

    return 0;
}

```

```cpp
#include <iostream> 
#include <string>

int main(){
    int age = 24;
    double salary = 15.8;
    std::string name = "water";

    std::cout << "No money " << age << salary << name << std::endl;  // 添加空格
    // 或者考虑使用这些变量
    // std::cout << name << " is " << age << " years old with salary: " << salary << std::endl;

    return 0;
}
```
