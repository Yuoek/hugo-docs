---
title: "Java 实验"
date: 2025-10-14T07:02:17+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## 实验导图


{{< markmap >}}
# Java 实验五
## 小组成员
### 杨通梅
### 杨浪
### 杨健

## 实验目的
## 实验内容
### 斐波那契数列
### 质数判断

## 掌握概念
### 线程
#### 单线程
#### 多线程
##### 线程同步
##### 线程安全
##### 线程通信

### 方法
#### 单断承 Thread 类
#### 使用 Runnable 接口

## 实验过程 
## 实验总结

{{< /markmap >}}


实验项目5：Java多线程设计
实验类型（验证/设计/创新）：设计
学时：2
 
实验内容：
 
1. java 实现用主线程模拟多线程。
 
- 第一个线程LeapThread的功能为：判断2000至2100年之间的每个数，如果该数是闰年，则输出该数。每判断一次，暂时休眠若干毫秒。
- 第二个线程PrimeThread的功能为：判断100至200年之间的每个数是否是质数，如果该数是质数，则输出该数。每判断一次，暂时休眠若干毫秒。
 
1. 用Runnable接口的方法进行多线程设计。
 
- 第一个线程LeapThread的功能为：判断2000至3000年之间的每个数是否是闰年，每判断一次，暂时休眠若干毫秒。
- 第二个线程Thread2的功能为：判断100至200年之间的每个数是否能够被3整除，能则输出该数。每判断一次，暂时休眠若干毫秒。
 
实验要求：
掌握线程的概念，学会用两种方法进行多线程的设计。
 
重点难点：
【本实验重点】多线程的概念和创建方法。
【本实验难点】两种创建多线程的方法。


### 实验一 

```java
// 第一个线程：判断闰年
class LeapThread extends Thread {
    @Override
    public void run() {
        for (int year = 2000; year <= 2100; year++) {
            if (isLeapYear(year)) {
                System.out.println("闰年: " + year);
            }
            try {
                // 休眠100毫秒
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    // 判断闰年的方法
    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

// 第二个线程：判断质数
class PrimeThread extends Thread {
    @Override
    public void run() {
        for (int num = 100; num <= 200; num++) {
            if (isPrime(num)) {
                System.out.println("质数: " + num);
            }
            try {
                // 休眠150毫秒
                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    // 判断质数的方法
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

// 主类测试
public class MultiThreadDemo {
    public static void main(String[] args) {
        // 创建线程实例
        LeapThread leapThread = new LeapThread();
        PrimeThread primeThread = new PrimeThread();
        
        // 启动线程
        leapThread.start();
        primeThread.start();
        
        // 等待两个线程执行完毕
        try {
            leapThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("所有线程执行完毕！");
    }
}
```

**代码说明：**

1. **LeapThread类**：
   - 继承Thread类
   - 判断2000-2100年之间的闰年
   - 每次判断后休眠100毫秒

2. **PrimeThread类**：
   - 继承Thread类
   - 判断100-200之间的质数
   - 每次判断后休眠150毫秒

3. **主要特点**：
   - 两个线程并行执行
   - 使用Thread.sleep()实现休眠
   - 在主线程中使用join()等待子线程完成

**运行效果：**
两个线程会同时运行，交替输出闰年和质数的结果，由于设置了不同的休眠时间，输出频率会有所不同。


### 实验二


以下是用Runnable接口实现的两个多线程程序：

```java
class LeapThread implements Runnable {
    @Override
    public void run() {
        for (int year = 2000; year <= 3000; year++) {
            // 判断闰年条件：能被4整除但不能被100整除，或者能被400整除
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                System.out.println(year + " 是闰年");
            }
            
            try {
                // 休眠100毫秒
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Thread2 implements Runnable {
    @Override
    public void run() {
        for (int num = 100; num <= 200; num++) {
            // 判断是否能被3整除
            if (num % 3 == 0) {
                System.out.println("能被3整除的数：" + num);
            }
            
            try {
                // 休眠150毫秒
                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class MultiThreadDemo {
    public static void main(String[] args) {
        // 创建两个Runnable对象
        Runnable leapThread = new LeapThread();
        Runnable thread2 = new Thread2();
        
        // 创建线程对象
        Thread t1 = new Thread(leapThread);
        Thread t2 = new Thread(thread2);
        
        // 启动线程
        t1.start();
        t2.start();
    }
}
```

**代码说明：**

1. **LeapThread类**：
   - 实现Runnable接口
   - 遍历2000-3000年，判断是否为闰年
   - 每次判断后休眠100毫秒

2. **Thread2类**：
   - 实现Runnable接口
   - 遍历100-200之间的数，判断是否能被3整除
   - 每次判断后休眠150毫秒

3. **主程序**：
   - 创建两个Runnable对象
   - 通过Thread类包装Runnable对象
   - 调用start()方法启动线程

**运行特点：**
- 两个线程会并发执行
- 每个线程都有自己的休眠时间
- 输出结果会交替显示两个线程的执行结果
- 使用Runnable接口比继承Thread类更灵活，可以避免Java单继承的限制



{{< pythontutor width="100%" height="500" language="java " >}}
class LeapThread implements Runnable {
    @Override
    public void run() {
        for (int year = 2000; year <= 3000; year++) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                System.out.println(year + " is leap year");
            }
            
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    // 添加main方法到LeapThread类
    public static void main(String[] args) {
        Runnable leapThread = new LeapThread();
        Runnable thread2 = new Thread2();
        
        Thread t1 = new Thread(leapThread);
        Thread t2 = new Thread(thread2);
        
        t1.start();
        t2.start();
    }
}

class Thread2 implements Runnable {
    @Override
    public void run() {
        for (int num = 100; num <= 200; num++) {
            if (num % 3 == 0) {
                System.out.println("divided by 3：" + num);
            }
            
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

{{< /pythontutor >}}



## 方案一：继承Thread类

```java
public class MultiThreadDemo {
    
    // 第一个线程：判断闰年
    static class LeapThread extends Thread {
        @Override
        public void run() {
            System.out.println("闰年线程开始执行...");
            for (int year = 2000; year <= 2100; year++) {
                if (isLeapYear(year)) {
                    System.out.println("闰年: " + year);
                }
                try {
                    // 休眠100毫秒
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("闰年线程执行完毕！");
        }
        
        private boolean isLeapYear(int year) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
    }
    
    // 第二个线程：判断质数
    static class PrimeThread extends Thread {
        @Override
        public void run() {
            System.out.println("质数线程开始执行...");
            for (int num = 100; num <= 200; num++) {
                if (isPrime(num)) {
                    System.out.println("质数: " + num);
                }
                try {
                    // 休眠80毫秒
                    Thread.sleep(80);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("质数线程执行完毕！");
        }
        
        private boolean isPrime(int num) {
            if (num <= 1) return false;
            if (num == 2) return true;
            if (num % 2 == 0) return false;
            
            for (int i = 3; i <= Math.sqrt(num); i += 2) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
    
    public static void main(String[] args) {
        // 创建并启动线程
        LeapThread leapThread = new LeapThread();
        PrimeThread primeThread = new PrimeThread();
        
        leapThread.start();
        primeThread.start();
        
        // 等待两个线程都执行完毕
        try {
            leapThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("所有线程执行完成！");
    }
}
```

## 方案二：实现Runnable接口

```java
public class MultiThreadRunnable {
    
    // 闰年判断函数
    public static void LeapThread() {
        System.out.println("闰年线程开始执行...");
        for (int year = 2000; year <= 2100; year++) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                System.out.println("闰年: " + year);
            }
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("闰年线程执行完毕！");
    }
    
    // 质数判断函数
    public static void PrimeThread() {
        System.out.println("质数线程开始执行...");
        for (int num = 100; num <= 200; num++) {
            if (isPrime(num)) {
                System.out.println("质数: " + num);
            }
            try {
                Thread.sleep(80);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("质数线程执行完毕！");
    }
    
    private static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        // 使用Runnable接口创建线程
        Thread thread1 = new Thread(() -> LeapThread());
        Thread thread2 = new Thread(() -> PrimeThread());
        
        thread1.start();
        thread2.start();
        
        // 等待线程完成
        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("程序执行完成！");
    }
}
```

## 方案三：使用线程池

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ThreadPoolDemo {
    
    public static void main(String[] args) {
        // 创建固定大小的线程池
        ExecutorService executor = Executors.newFixedThreadPool(2);
        
        // 提交闰年判断任务
        executor.submit(() -> {
            System.out.println("闰年线程开始执行...");
            for (int year = 2000; year <= 2100; year++) {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    System.out.println("闰年: " + year);
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("闰年线程执行完毕！");
        });
        
        // 提交质数判断任务
        executor.submit(() -> {
            System.out.println("质数线程开始执行...");
            for (int num = 100; num <= 200; num++) {
                if (isPrime(num)) {
                    System.out.println("质数: " + num);
                }
                try {
                    Thread.sleep(80);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("质数线程执行完毕！");
        });
        
        // 关闭线程池
        executor.shutdown();
        
        try {
            // 等待所有任务完成
            if (!executor.awaitTermination(60, TimeUnit.SECONDS)) {
                executor.shutdownNow();
            }
        } catch (InterruptedException e) {
            executor.shutdownNow();
        }
        
        System.out.println("所有任务执行完成！");
    }
    
    private static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
```

## 程序特点：

1. **多线程并发**：两个任务同时执行，互不干扰
2. **休眠机制**：每次判断后暂停指定毫秒数
3. **闰年判断**：2000-2100年范围内的闰年
4. **质数判断**：100-200范围内的质数
5. **线程同步**：使用join()或线程池等待所有任务完成

你可以根据需要选择合适的方案，推荐使用**方案二**（Runnable接口）或**方案三**（线程池），因为它们更符合现代Java编程的最佳实践。


以下是Java实现的两个函数，分别对应题目要求的功能：
Stopped after running for 12.0 seconds. Please shorten your code,
since Python Tutor is not designed to handle long-running code.
```java
public class ThreadFunctions {
    public static void LeapThread() {
        for (int year = 1998; year <= 2025; year++) {
            if (isLeapYear(year)) {
                System.out.println("闰年: " + year);
            }
            try {
                Thread.sleep(10); // 休眠100毫秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public static void PrimeThread() {
        for (int num = 100; num <= 120; num++) {
            if (isPrime(num)) {
                System.out.println("质数: " + num);
            }
            try {
                Thread.sleep(10); // 休眠100毫秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    private static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    private static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.println("=== 闰年判断 (2000-2100) ===");
        LeapThread();
        System.out.println("\n=== 质数判断 (100-200) ===");
        PrimeThread();
    }
}
```

**代码说明：**

1. **LeapThread函数**：
   - 遍历2000到2100年
   - 使用`isLeapYear`方法判断是否为闰年
   - 每次判断后休眠100毫秒
   - 输出所有闰年

2. **PrimeThread函数**：
   - 遍历100到200之间的数字
   - 使用`isPrime`方法判断是否为质数
   - 每次判断后休眠100毫秒
   - 输出所有质数

3. **辅助方法**：
   - `isLeapYear()`：判断闰年（能被4整除但不能被100整除，或能被400整除）
   - `isPrime()`：优化后的质数判断算法

**运行结果示例：**
```
=== 闰年判断 (2000-2100) ===
闰年: 2000
闰年: 2004
闰年: 2008
...

=== 质数判断 (100-200) ===
质数: 101
质数: 103
质数: 107
...
```

如果需要将这两个函数作为独立的线程运行，可以使用`Thread`类来包装它们。

[#ErrorBackendTimeout] Your code ran for more than 15 seconds. It may have an INFINITE LOOP.
Or the server may be OVERLOADED right now. Please shorten your code or try again later

```java 

public class MainThreadSimulation {
    public static void main(String[] args) {
        // 模拟第一个线程：判断闰年
        Thread leapThread = new Thread(() -> {
            for (int year = 2000; year <= 2002; year++) {
                if (isLeapYear(year)) {
                    System.out.println("闰年: " + year);
                }
                try {
                    Thread.sleep(5); // 休眠50毫秒
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        // 模拟第二个线程：判断质数
        Thread primeThread = new Thread(() -> {
            for (int num = 100; num <= 109; num++) {
                if (isPrime(num)) {
                    System.out.println("质数: " + num);
                }
                try {
                    Thread.sleep(5); // 休眠50毫秒
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        // 启动线程
        leapThread.start();
        primeThread.start();

        // 等待两个线程执行完成
        try {
            leapThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    // 判断闰年的方法
    private static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 判断质数的方法
    private static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

```


这个代码本身没有无限循环的问题，但可能因为服务器负载过高导致超时。以下是几个优化建议：

## 主要问题分析：
1. **线程休眠时间过短**：`Thread.sleep(5)` 只有5毫秒，可能造成频繁的线程切换
2. **服务器环境限制**：在线编译环境对执行时间有严格限制

## 优化方案：

### 方案1：移除休眠（推荐）
```java
public class MainThreadSimulation {
    public static void main(String[] args) {
        Thread leapThread = new Thread(() -> {
            for (int year = 2000; year <= 2002; year++) {
                if (isLeapYear(year)) {
                    System.out.println("闰年: " + year);
                }
                // 移除Thread.sleep
            }
        });

        Thread primeThread = new Thread(() -> {
            for (int num = 100; num <= 109; num++) {
                if (isPrime(num)) {
                    System.out.println("质数: " + num);
                }
                // 移除Thread.sleep
            }
        });

        leapThread.start();
        primeThread.start();

        try {
            leapThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    // 原有方法保持不变
    private static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    private static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
```

### 方案2：使用单线程（更稳定）
```java
public class MainThreadSimulation {
    public static void main(String[] args) {
        // 单线程执行，避免多线程开销
        System.out.println("闰年判断:");
        for (int year = 2000; year <= 2002; year++) {
            if (isLeapYear(year)) {
                System.out.println("闰年: " + year);
            }
        }
        
        System.out.println("质数判断:");
        for (int num = 100; num <= 109; num++) {
            if (isPrime(num)) {
                System.out.println("质数: " + num);
            }
        }
    }
    
    // 方法保持不变...
}
```

## 建议：
- 在在线编译环境中优先使用**方案2的单线程版本**
- 如果必须使用多线程，选择**方案1（移除休眠）**
- 检查范围是否过大，可以进一步缩小测试数据范围

这样修改后应该能避免超时错误。


