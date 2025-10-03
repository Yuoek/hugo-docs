// #include <stdio.h>
//
// int main(void){
//   pid_t pid;
//   pid = fork();
//   if (pid == 0){
//     printf("Hello World!\n");
//   }
//   else if(pid > 0){
//     printf("How are you!\n");
//   }
//   return 0;
// }
//

#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t pid;
    pid = fork();
    if (pid == 0){
        printf("Hello World!\n");
    }
    else if(pid > 0){
        printf("How are you!\n");
    }
    return 0;
}


// 这段C语言代码演示了`fork()`系统调用的使用。让我分析一下执行过程：
//
// ## 代码执行流程：
//
// 1. **调用`fork()`**：创建子进程
//    - 父进程：返回子进程的PID（大于0）
//    - 子进程：返回0
//
// 2. **条件判断**：
//    - 子进程（pid == 0）：打印"Hello World!"
//    - 父进程（pid > 0）：打印"How are you!"
//
// ## 可能的输出结果：
//
// 由于进程调度顺序不确定，可能出现两种输出顺序：
//
// **情况1：**
// ```
// Hello World!
// How are you!
// ```
//
// **情况2：**
// ```
// How are you!
// Hello World!
// ```
//
// ## 关键点：
// - 父子进程并发执行，输出顺序不确定
// - 两个进程共享代码但拥有独立的地址空间
// - 父进程会等待子进程结束（隐式等待）
//
// 这是一个典型的进程创建示例，展示了Unix/Linux系统中进程的基本操作。
//
//
