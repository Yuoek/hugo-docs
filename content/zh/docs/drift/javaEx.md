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

实验项目5：Java多线程设计
实验类型（验证/设计/创新）：设计
学时：2
 
实验内容：
 
1. 用继承Thread类的方法进行多线程设计。
 
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

