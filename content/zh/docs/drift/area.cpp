#include <iostream> 
using namespace std;

void area(){
    double a;
    const double PI = 3.14;
    cout << "输入圆形的半径：";
    cin >> a;
    cout << "圆形的面积为：" << PI*a*a << endl;
}

int main(){
    void  area();
    area();
    return 0;
}


// 这段代码存在几个问题，我来帮你修正：
//
// **主要问题：**
// 1. `const PI = 3.14;` 需要指定数据类型
// 2. 缺少必要的头文件包含
// 3. 函数没有返回值类型
//
// **修正后的代码：**
// ```cpp
// #include <iostream>
// using namespace std;
//
// void area(){
//     double a;
//     const double PI = 3.14;  // 添加double类型
//     cout << "输入圆形的半径：";
//     cin >> a;
//     cout << "圆形的面积为：" << PI * a * a << endl;
// }
// ```
//
// **或者更完整的版本：**
// ```cpp
// #include <iostream>
// using namespace std;
//
// void area() {
//     double radius;
//     const double PI = 3.14159;  // 使用更精确的π值
//
//     cout << "输入圆形的半径：";
//     cin >> radius;
//
//     // 计算并输出面积
//     double area = PI * radius * radius;
//     cout << "圆形的面积为：" << area << endl;
// }
//
// int main() {
//     area();  // 调用函数
//     return 0;
// }
// ```
//
// **主要修改：**
// - 添加了 `#include <iostream>` 和 `using namespace std;`
// - 将 `const PI` 改为 `const double PI`
// - 使用了更有意义的变量名 `radius`
// - 添加了 `main` 函数来测试
//
// 这样修正后代码就能正常编译和运行了。
//
//
