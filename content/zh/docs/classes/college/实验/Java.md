# Java 实验

实验一 熟悉Java编程环境
实验目的：
       熟悉MyEclipse的编程环境，学习编写和调试第一个 Java应用程序。
实验内容：
（1）编写Java应用程序，输出以下信息，程序运行结果如图1.1所示：

图1.1 

（2）编写Java应用程序，输出Fibonacci数列的前20个数。斐波那契数列（Fibonacci sequence），又称黄金分割数列、因数学家莱昂纳多·斐波那契（Leonardoda Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，指的是这样一个数列： 1、1、2、3、5、8、13、21、34。程序运行结果如图1.2所示：

图1.2

（3）编写Java应用程序，输入一个整数，判断其是否是素数，并输出。程序运行结果如图1.3所示： 

图1.3 

源程序及运行结果


### 实验一（1）：输出指定信息
```java
public class Experiment1_1 {
    public static void main(String[] args) {
        // 使用System.out.println输出指定信息
        System.out.println("******************************");
        System.out.println("     欢迎进入Java编程世界");
        System.out.println("******************************");
        System.out.println("姓名：张三");
        System.out.println("学号：2023001");
        System.out.println("班级：计算机1班");
    }
}
```

### 实验一（2）：输出Fibonacci数列前20项
```java
public class Experiment1_2 {
    public static void main(String[] args) {
        int n = 20; // 定义要输出的斐波那契数列项数
        long[] fib = new long[n]; // 使用long类型防止数值过大
        
        // 初始化前两项
        fib[0] = 1;
        fib[1] = 1;
        
        // 计算斐波那契数列
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        // 输出结果
        System.out.println("Fibonacci数列的前20项为：");
        for (int i = 0; i < n; i++) {
            System.out.print(fib[i] + " ");
            // 每5个数字换行，使输出更整齐
            if ((i + 1) % 5 == 0) {
                System.out.println();
            }
        }
    }
}
```

### 实验一（3）：判断素数
```java
import java.util.Scanner;

public class Experiment1_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("请输入一个整数：");
        int num = scanner.nextInt();
        
        // 处理特殊情况
        if (num <= 1) {
            System.out.println(num + " 不是素数");
            return;
        }
        
        boolean isPrime = true; // 标记是否为素数
        
        // 判断素数：只需检查到sqrt(num)
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        // 输出结果
        if (isPrime) {
            System.out.println(num + " 是素数");
        } else {
            System.out.println(num + " 不是素数");
        }
        
        scanner.close();
    }
}
```

### 运行说明：
1. **实验1**：直接运行即可输出格式化的欢迎信息
2. **实验2**：运行后自动输出斐波那契数列前20项
3. **实验3**：运行后需要从键盘输入一个整数，程序会判断并输出是否为素数

### 注意事项：
- 确保已安装Java开发环境
- 代码中的类名需要与文件名一致
- 实验3需要导入Scanner类进行输入操作
- 斐波那契数列使用long类型防止数值溢出



## 实验二 类和对象的创建
实验目的： 
        熟悉Java类和对象的创建和使用，了解类中方法重载和方法覆盖的概念。
实验内容：
（1）编写Java应用程序，执行此程序输出箱子的体积和重量。定义一个类，类中包含长、宽、高和比重，方法有：求体积和重量。构造方法定义时采用方法重载。程序运行结果如图2.1所示：

图2.1

（2）编写Java应用程序，执行此程序输出数组元素的最大值。定义一个类，类中包含数组，方法：求数组中的最大值。程序运行结果如图2.2所示：

图2.2

源程序及运行结果

## 示例

## （1）箱子体积和重量计算程序

```java
// Box类定义
class Box {
    private double length;    // 长
    private double width;     // 宽
    private double height;    // 高
    private double density;   // 比重
    
    // 构造方法重载
    public Box() {
        this.length = 1.0;
        this.width = 1.0;
        this.height = 1.0;
        this.density = 1.0;
    }
    
    public Box(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
        this.density = 1.0;
    }
    
    public Box(double length, double width, double height, double density) {
        this.length = length;
        this.width = width;
        this.height = height;
        this.density = density;
    }
    
    // 求体积
    public double getVolume() {
        return length * width * height;
    }
    
    // 求重量
    public double getWeight() {
        return getVolume() * density;
    }
    
    // 显示箱子信息
    public void displayInfo() {
        System.out.println("箱子信息：");
        System.out.println("长：" + length + "，宽：" + width + "，高：" + height);
        System.out.println("比重：" + density);
        System.out.println("体积：" + getVolume());
        System.out.println("重量：" + getWeight());
    }
}

// 主程序
public class Experiment2_1 {
    public static void main(String[] args) {
        // 使用不同的构造方法创建对象
        Box box1 = new Box();
        Box box2 = new Box(2.0, 3.0, 4.0);
        Box box3 = new Box(1.5, 2.5, 3.5, 2.0);
        
        System.out.println("=== 实验二（1）箱子体积和重量计算 ===");
        System.out.println();
        
        box1.displayInfo();
        System.out.println();
        
        box2.displayInfo();
        System.out.println();
        
        box3.displayInfo();
    }
}
```

## （2）数组最大值计算程序

```java
// ArrayProcessor类定义
class ArrayProcessor {
    private int[] array;
    
    // 构造方法
    public ArrayProcessor(int[] array) {
        this.array = array;
    }
    
    // 求数组最大值
    public int getMaxValue() {
        if (array == null || array.length == 0) {
            throw new IllegalArgumentException("数组不能为空");
        }
        
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }
    
    // 显示数组内容和最大值
    public void displayArrayAndMax() {
        System.out.print("数组元素：");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i < array.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
        System.out.println("数组中的最大值：" + getMaxValue());
    }
}

// 主程序
public class Experiment2_2 {
    public static void main(String[] args) {
        System.out.println("=== 实验二（2）数组最大值计算 ===");
        System.out.println();
        
        // 测试用例1
        int[] arr1 = {12, 45, 67, 23, 9, 56, 78, 34};
        ArrayProcessor processor1 = new ArrayProcessor(arr1);
        processor1.displayArrayAndMax();
        
        System.out.println();
        
        // 测试用例2
        int[] arr2 = {5, 89, 23, 47, 12, 66, 91, 34, 72};
        ArrayProcessor processor2 = new ArrayProcessor(arr2);
        processor2.displayArrayAndMax();
    }
}
```

## 程序运行结果示例：

**实验（1）输出：**
```
=== 实验二（1）箱子体积和重量计算 ===

箱子信息：
长：1.0，宽：1.0，高：1.0
比重：1.0
体积：1.0
重量：1.0

箱子信息：
长：2.0，宽：3.0，高：4.0
比重：1.0
体积：24.0
重量：24.0

箱子信息：
长：1.5，宽：2.5，高：3.5
比重：2.0
体积：13.125
重量：26.25
```

**实验（2）输出：**
```
=== 实验二（2）数组最大值计算 ===

数组元素：12, 45, 67, 23, 9, 56, 78, 34
数组中的最大值：78

数组元素：5, 89, 23, 47, 12, 66, 91, 34, 72
数组中的最大值：91
```

## 实验要点说明：

1. **方法重载**：Box类中提供了3个不同参数的构造方法
2. **封装性**：使用private修饰成员变量，通过public方法访问
3. **数组处理**：ArrayProcessor类演示了如何操作数组和查找最大值
4. **异常处理**：在getMaxValue方法中检查数组是否为空

这两个程序完整实现了实验要求的所有功能。

## 实验三 Java接口的应用
实验目的：
     熟悉Java 接口的定义和使用，学会编写类和用类来实现接口。
实验内容：
（1）定义一个接口，包含一个方法，实现在两数中求最大数。编写类实现这个接口，并用执行类执行此程序。程序运行结果如图3.1所示：

图3.1
（2）定义接口Container及其实现类并进行测试
定义一个接口Container，在其中定义： 2个成员函数分别用来求面积area和体积volume；一个常量PI，PI的值为3.1415926；
定义Container实现类正方体Cube，该类中有一个私有成员radius，定义有参的构造函数，定义计算面积area和体积volume的函数； 
定义Container实现类球体Sphere，该类中有一个私有成员radius，定义有参的构造函数，定义计算面积area和体积volume的函数；
定义Container实现类圆柱体Cylinder，该类中有2个私有成员半径radius和高度height，定义有参的构造函数，定义计算面积area和体积volume的函数； 
编写一个类Test2，其中定义一个函数totalarea求所有图形的总面积，定义一个函数totalvolume求所有图形的总体积，编写主函数main对以上代码进行测试。程序运行结果如图3.2所示：

图3.2

源程序及运行结果

## 示例

## （1）两数求最大数接口

```java
// 定义接口
interface MaxFinder {
    int findMax(int a, int b);
}

// 实现类
class MaxFinderImpl implements MaxFinder {
    @Override
    public int findMax(int a, int b) {
        return (a > b) ? a : b;
    }
}

// 执行类
public class Test1 {
    public static void main(String[] args) {
        MaxFinder finder = new MaxFinderImpl();
        int num1 = 25;
        int num2 = 38;
        int max = finder.findMax(num1, num2);
        
        System.out.println("两个数分别是：" + num1 + " 和 " + num2);
        System.out.println("最大数是：" + max);
    }
}
```

## （2）Container接口及其实现类

```java
// 定义Container接口
interface Container {
    double PI = 3.1415926;
    
    double area();
    double volume();
}

// 正方体实现类
class Cube implements Container {
    private double radius; // 边长
    
    public Cube(double radius) {
        this.radius = radius;
    }
    
    @Override
    public double area() {
        return 6 * radius * radius; // 6个面的总面积
    }
    
    @Override
    public double volume() {
        return radius * radius * radius;
    }
}

// 球体实现类
class Sphere implements Container {
    private double radius;
    
    public Sphere(double radius) {
        this.radius = radius;
    }
    
    @Override
    public double area() {
        return 4 * PI * radius * radius;
    }
    
    @Override
    public double volume() {
        return (4.0 / 3.0) * PI * radius * radius * radius;
    }
}

// 圆柱体实现类
class Cylinder implements Container {
    private double radius;
    private double height;
    
    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }
    
    @Override
    public double area() {
        return 2 * PI * radius * (radius + height); // 底面积*2 + 侧面积
    }
    
    @Override
    public double volume() {
        return PI * radius * radius * height;
    }
}

// 测试类
public class Test2 {
    // 求所有图形的总面积
    public static double totalarea(Container[] containers) {
        double total = 0;
        for (Container container : containers) {
            total += container.area();
        }
        return total;
    }
    
    // 求所有图形的总体积
    public static double totalvolume(Container[] containers) {
        double total = 0;
        for (Container container : containers) {
            total += container.volume();
        }
        return total;
    }
    
    public static void main(String[] args) {
        // 创建各种图形对象
        Container cube = new Cube(5.0);
        Container sphere = new Sphere(3.0);
        Container cylinder = new Cylinder(2.0, 4.0);
        
        // 将图形对象放入数组
        Container[] containers = {cube, sphere, cylinder};
        
        // 计算总面积和总体积
        double totalArea = totalarea(containers);
        double totalVolume = totalvolume(containers);
        
        // 输出结果
        System.out.println("正方体：");
        System.out.println("  面积：" + cube.area());
        System.out.println("  体积：" + cube.volume());
        
        System.out.println("球体：");
        System.out.println("  面积：" + sphere.area());
        System.out.println("  体积：" + sphere.volume());
        
        System.out.println("圆柱体：");
        System.out.println("  面积：" + cylinder.area());
        System.out.println("  体积：" + cylinder.volume());
        
        System.out.println("所有图形的总面积：" + totalArea);
        System.out.println("所有图形的总体积：" + totalVolume);
    }
}
```

## 运行结果示例：

**Test1运行结果：**
```
两个数分别是：25 和 38
最大数是：38
```

**Test2运行结果：**
```
正方体：
  面积：150.0
  体积：125.0
球体：
  面积：113.097336
  体积：113.097336
圆柱体：
  面积：75.3982224
  体积：50.2654816
所有图形的总面积：338.4955584
所有图形的总体积：288.3628176
```

这个实验完整展示了：
1. 接口的定义和实现
2. 接口常量的使用
3. 多态性的应用
4. 数组作为参数传递
5. 不同几何图形的面积和体积计算

## 实验四 输入和输出流
实验目的：
掌握标准输入输出流、文件输入输出流和过滤输入输出流的使用方法。 
实验内容：
（1）编写Java应用程序。采用过滤输入流的方法从文件中读入整数，判断此数 是否为素数，并从屏幕输出结果。程序运行结果如图4.1所示：
  
					         图4.1

（2）读出文本文件中的内容然后在控制台输出。程序运行结果如图4.2所示：

图4.2


源程序及运行结果

## 示例


## 任务一：判断文件中的整数是否为素数

```java
import java.io.*;
import java.util.Scanner;

public class PrimeNumberChecker {
    
    // 判断是否为素数的方法
    public static boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        if (number == 2) {
            return true;
        }
        if (number % 2 == 0) {
            return false;
        }
        
        // 检查从3到sqrt(number)的奇数
        for (int i = 3; i * i <= number; i += 2) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        // 创建测试数据文件
        createTestFile();
        
        try {
            // 使用过滤输入流读取文件
            DataInputStream dis = new DataInputStream(
                new BufferedInputStream(
                    new FileInputStream("numbers.dat")
                )
            );
            
            System.out.println("从文件中读取数字并判断是否为素数：");
            System.out.println("==================================");
            
            // 读取文件中的所有整数
            while (dis.available() > 0) {
                int number = dis.readInt();
                boolean prime = isPrime(number);
                
                System.out.printf("数字 %d %s素数%n", 
                    number, prime ? "是" : "不是");
            }
            
            dis.close();
            
        } catch (IOException e) {
            System.out.println("文件读取错误: " + e.getMessage());
        }
    }
    
    // 创建测试数据文件的方法
    private static void createTestFile() {
        try {
            DataOutputStream dos = new DataOutputStream(
                new BufferedOutputStream(
                    new FileOutputStream("numbers.dat")
                )
            );
            
            // 写入一些测试数字
            int[] testNumbers = {2, 3, 4, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
            for (int num : testNumbers) {
                dos.writeInt(num);
            }
            
            dos.close();
            System.out.println("测试数据文件已创建: numbers.dat");
            
        } catch (IOException e) {
            System.out.println("创建测试文件错误: " + e.getMessage());
        }
    }
}
```

## 任务二：读取文本文件并在控制台输出

```java
import java.io.*;

public class TextFileReader {
    
    public static void main(String[] args) {
        // 首先创建一个示例文本文件
        createSampleTextFile();
        
        System.out.println("读取文本文件内容：");
        System.out.println("==================");
        
        try {
            // 使用缓冲字符流读取文本文件
            BufferedReader reader = new BufferedReader(
                new FileReader("sample.txt")
            );
            
            String line;
            int lineNumber = 1;
            
            // 逐行读取并输出
            while ((line = reader.readLine()) != null) {
                System.out.printf("第%d行: %s%n", lineNumber, line);
                lineNumber++;
            }
            
            reader.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("文件未找到: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("读取文件时发生错误: " + e.getMessage());
        }
    }
    
    // 创建示例文本文件的方法
    private static void createSampleTextFile() {
        try {
            PrintWriter writer = new PrintWriter(
                new BufferedWriter(
                    new FileWriter("sample.txt")
                )
            );
            
            // 写入一些示例文本
            writer.println("Java输入输出流实验");
            writer.println("==================");
            writer.println("这是第一行文本内容");
            writer.println("这是第二行文本内容");
            writer.println("文件输入输出流的使用");
            writer.println("过滤流的使用方法");
            writer.println("实验完成！");
            
            writer.close();
            System.out.println("示例文本文件已创建: sample.txt\n");
            
        } catch (IOException e) {
            System.out.println("创建文本文件错误: " + e.getMessage());
        }
    }
}
```

## 程序特点说明：

### 任务一特点：
1. **使用过滤输入流**：`DataInputStream` 包装 `BufferedInputStream` 和 `FileInputStream`
2. **二进制文件处理**：使用 `readInt()` 方法直接读取整数
3. **素数判断算法**：优化了判断逻辑，只检查到平方根

### 任务二特点：
1. **字符流处理**：使用 `BufferedReader` 和 `FileReader` 处理文本文件
2. **逐行读取**：使用 `readLine()` 方法按行读取
3. **格式化输出**：显示行号和内容

## 运行结果示例：

**任务一输出：**
```
测试数据文件已创建: numbers.dat
从文件中读取数字并判断是否为素数：
==================================
数字 2 是素数
数字 3 是素数
数字 4 不是素数
数字 5 是素数
...
```

**任务二输出：**
```
示例文本文件已创建: sample.txt

读取文本文件内容：
==================
第1行: Java输入输出流实验
第2行: ==================
第3行: 这是第一行文本内容
第4行: 这是第二行文本内容
...
```

这两个程序完整实现了实验要求，展示了标准输入输出流、文件输入输出流和过滤输入输出流的使用方法。



## 实验五 Java多线程设计
实验目的：
    掌握线程的概念，学会用两种方法进行多线程的设计。 
实验内容：
（1）用继承Thread类的方法进行多线程设计。
第一个线程FacThread的功能为：用于输出1到10的阶乘。每输出一次，暂时休眠若干毫秒。
第二个线程PrimeThread的功能为：判断100至200年之间的每个数是否是质数，如果该数是质数，则输出该数。每判断一次，暂时休眠若干毫秒。
测试这两个线程
（2）用Runnable接口的方法进行多线程设计。
第一个线程LeapThread的功能为：判断2000至3000年之间的每个数是否是闰年，每判断一次，暂时休眠若干毫秒。
第二个线程Thread2的功能为：判断100至200年之间的每个数是否能够被3整除，能则输出该数。每判断一次，暂时休眠若干毫秒。
测试这两个线程

源程序及运行结果

## （1）继承Thread类的方法

```java
// 阶乘线程
class FacThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            long factorial = 1;
            for (int j = 1; j <= i; j++) {
                factorial *= j;
            }
            System.out.println(i + "的阶乘 = " + factorial);
            try {
                Thread.sleep(100); // 休眠100毫秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// 质数判断线程
class PrimeThread extends Thread {
    @Override
    public void run() {
        for (int i = 100; i <= 200; i++) {
            if (isPrime(i)) {
                System.out.println(i + " 是质数");
            }
            try {
                Thread.sleep(50); // 休眠50毫秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    // 判断质数的方法
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

// 测试类
public class ThreadTest {
    public static void main(String[] args) {
        FacThread facThread = new FacThread();
        PrimeThread primeThread = new PrimeThread();
        
        facThread.start();
        primeThread.start();
    }
}
```

## （2）实现Runnable接口的方法

```java
// 闰年判断线程
class LeapThread implements Runnable {
    @Override
    public void run() {
        for (int year = 2000; year <= 3000; year++) {
            if (isLeapYear(year)) {
                System.out.println(year + " 是闰年");
            }
            try {
                Thread.sleep(80); // 休眠80毫秒
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

// 能被3整除判断线程
class DivisibleByThreeThread implements Runnable {
    @Override
    public void run() {
        for (int i = 100; i <= 200; i++) {
            if (i % 3 == 0) {
                System.out.println(i + " 能被3整除");
            }
            try {
                Thread.sleep(60); // 休眠60毫秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// 测试类
public class RunnableTest {
    public static void main(String[] args) {
        LeapThread leapThread = new LeapThread();
        DivisibleByThreeThread divThread = new DivisibleByThreeThread();
        
        Thread thread1 = new Thread(leapThread);
        Thread thread2 = new Thread(divThread);
        
        thread1.start();
        thread2.start();
    }
}
```

## 程序说明：

### 第一部分（继承Thread类）：
- **FacThread**：计算1-10的阶乘，每次计算后休眠100毫秒
- **PrimeThread**：判断100-200之间的质数，每次判断后休眠50毫秒
- 两个线程同时启动，交替执行

### 第二部分（实现Runnable接口）：
- **LeapThread**：判断2000-3000年之间的闰年，每次判断后休眠80毫秒
- **DivisibleByThreeThread**：判断100-200之间能被3整除的数，每次判断后休眠60毫秒
- 通过Thread类包装Runnable对象来启动线程

### 运行结果特点：
- 由于多线程并发执行，输出结果会交替显示
- 休眠时间不同，各线程执行速度也不同
- 可以观察到线程间的切换和并发执行效果

这个实验完整展示了Java多线程的两种实现方式，并包含了具体的业务逻辑实现。




## 实验六 Java数据库编程

实验目的：
灵活运用Java接口，熟悉JDBC数据库编程方法，学会进行数据库程序设计。
实验内容：
使用Java实现图书管理系统功能，MyEclipse Derby作为后台数据库，功能包括图书信息的显示和图书信息增加功能.
建立数据表book并添加测试数据（至少3条），测试数据中其中一本书的作者要是你自己的名字。

| 序号 | 字段名称     | 字段说明 | 类型        | 备注 |
|------|--------------|----------|-------------|------|
| 1    | book_id      | 书号     | int         | 主键 |
| 2    | book_name    | 书名     | Varchar(20) |      |
| 3    | book_price   | 价格     | double      |      |
| 4    | book_publish | 出版社   | Varchar(20) |      |
| 5    | book_author  | 作者     | Varchar(20) |      |
| 6    | book_type    | 类型     | Varchar(20) |      |


（2）使用MyEclipse创建Web项目——Book学号（例：Book0215101），导入数据库驱动包，在源文件夹中创建2个包：entity包用于存放实体类，dao包用于存放数据访问类
（3）创建实体类：Book.java
（4）创建DAO基类：BaseDao.java，设计两个方法
数据库资源的获取            2) 释放数据库资源
（5）创建DAO类：BookDao.java 继承BaseDao
编写查询方法public List displayBook()，查询所有的图书信息，按照价格升序排列 ，并返回查询结果；
编写添加书信息方法将添加的书信息保存到数据库。
（6）设计网页，显示数据库中所有图书信息，并能实现图书信息的添加

## 源程序及运行结果

## 1. 数据库准备

首先在Derby数据库中创建book表并插入测试数据：

```sql
CREATE TABLE book (
    book_id INT PRIMARY KEY,
    book_name VARCHAR(20),
    book_price DOUBLE,
    book_publish VARCHAR(20),
    book_author VARCHAR(20),
    book_type VARCHAR(20)
);

INSERT INTO book VALUES 
(1, 'Java编程思想', 89.00, '机械工业出版社', 'Bruce Eckel', '编程'),
(2, '设计模式', 59.00, '人民邮电出版社', 'Erich Gamma', '计算机'),
(3, '数据库系统概念', 75.00, '机械工业出版社', '张三', '数据库');
```

## 2. 项目结构

```
Book学号/
├── src/
│   ├── entity/
│   │   └── Book.java
│   └── dao/
│       ├── BaseDao.java
│       └── BookDao.java
├── WebContent/
│   ├── displayBook.jsp
│   └── addBook.jsp
└── lib/
    └── derby.jar
```

## 3. 实体类 Book.java

```java
package entity;

public class Book {
    private int bookId;
    private String bookName;
    private double bookPrice;
    private String bookPublish;
    private String bookAuthor;
    private String bookType;
    
    // 构造方法
    public Book() {}
    
    public Book(int bookId, String bookName, double bookPrice, 
                String bookPublish, String bookAuthor, String bookType) {
        this.bookId = bookId;
        this.bookName = bookName;
        this.bookPrice = bookPrice;
        this.bookPublish = bookPublish;
        this.bookAuthor = bookAuthor;
        this.bookType = bookType;
    }
    
    // Getter和Setter方法
    public int getBookId() { return bookId; }
    public void setBookId(int bookId) { this.bookId = bookId; }
    
    public String getBookName() { return bookName; }
    public void setBookName(String bookName) { this.bookName = bookName; }
    
    public double getBookPrice() { return bookPrice; }
    public void setBookPrice(double bookPrice) { this.bookPrice = bookPrice; }
    
    public String getBookPublish() { return bookPublish; }
    public void setBookPublish(String bookPublish) { this.bookPublish = bookPublish; }
    
    public String getBookAuthor() { return bookAuthor; }
    public void setBookAuthor(String bookAuthor) { this.bookAuthor = bookAuthor; }
    
    public String getBookType() { return bookType; }
    public void setBookType(String bookType) { this.bookType = bookType; }
}
```

## 4. DAO基类 BaseDao.java

```java
package dao;

import java.sql.*;

public class BaseDao {
    private static final String DRIVER = "org.apache.derby.jdbc.EmbeddedDriver";
    private static final String URL = "jdbc:derby:bookdb;create=true";
    
    // 获取数据库连接
    public Connection getConnection() {
        Connection conn = null;
        try {
            Class.forName(DRIVER);
            conn = DriverManager.getConnection(URL);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return conn;
    }
    
    // 释放数据库资源
    public void closeAll(Connection conn, Statement stmt, ResultSet rs) {
        try {
            if (rs != null) rs.close();
            if (stmt != null) stmt.close();
            if (conn != null) conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

## 5. 数据访问类 BookDao.java

```java
package dao;

import entity.Book;
import java.sql.*;
import java.util.*;

public class BookDao extends BaseDao {
    
    // 查询所有图书信息，按价格升序排列
    public List<Book> displayBook() {
        List<Book> bookList = new ArrayList<>();
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        
        try {
            conn = getConnection();
            String sql = "SELECT * FROM book ORDER BY book_price ASC";
            pstmt = conn.prepareStatement(sql);
            rs = pstmt.executeQuery();
            
            while (rs.next()) {
                Book book = new Book();
                book.setBookId(rs.getInt("book_id"));
                book.setBookName(rs.getString("book_name"));
                book.setBookPrice(rs.getDouble("book_price"));
                book.setBookPublish(rs.getString("book_publish"));
                book.setBookAuthor(rs.getString("book_author"));
                book.setBookType(rs.getString("book_type"));
                bookList.add(book);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll(conn, pstmt, rs);
        }
        return bookList;
    }
    
    // 添加图书信息
    public boolean addBook(Book book) {
        Connection conn = null;
        PreparedStatement pstmt = null;
        boolean success = false;
        
        try {
            conn = getConnection();
            String sql = "INSERT INTO book (book_id, book_name, book_price, book_publish, book_author, book_type) VALUES (?, ?, ?, ?, ?, ?)";
            pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, book.getBookId());
            pstmt.setString(2, book.getBookName());
            pstmt.setDouble(3, book.getBookPrice());
            pstmt.setString(4, book.getBookPublish());
            pstmt.setString(5, book.getBookAuthor());
            pstmt.setString(6, book.getBookType());
            
            int result = pstmt.executeUpdate();
            success = result > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            closeAll(conn, pstmt, null);
        }
        return success;
    }
}
```

## 6. 显示图书信息页面 displayBook.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="dao.BookDao, entity.Book, java.util.List" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>图书信息显示</title>
</head>
<body>
    <h2>图书信息列表</h2>
    <a href="addBook.jsp">添加新图书</a>
    <table border="1" cellspacing="0" cellpadding="5">
        <tr>
            <th>书号</th>
            <th>书名</th>
            <th>价格</th>
            <th>出版社</th>
            <th>作者</th>
            <th>类型</th>
        </tr>
        <%
            BookDao bookDao = new BookDao();
            List<Book> bookList = bookDao.displayBook();
            for (Book book : bookList) {
        %>
        <tr>
            <td><%= book.getBookId() %></td>
            <td><%= book.getBookName() %></td>
            <td><%= book.getBookPrice() %></td>
            <td><%= book.getBookPublish() %></td>
            <td><%= book.getBookAuthor() %></td>
            <td><%= book.getBookType() %></td>
        </tr>
        <% } %>
    </table>
</body>
</html>
```

## 7. 添加图书页面 addBook.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="dao.BookDao, entity.Book" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>添加图书</title>
</head>
<body>
    <h2>添加新图书</h2>
    <a href="displayBook.jsp">返回图书列表</a>
    
    <form method="post" action="">
        <table>
            <tr>
                <td>书号:</td>
                <td><input type="text" name="bookId" required></td>
            </tr>
            <tr>
                <td>书名:</td>
                <td><input type="text" name="bookName" required></td>
            </tr>
            <tr>
                <td>价格:</td>
                <td><input type="text" name="bookPrice" required></td>
            </tr>
            <tr>
                <td>出版社:</td>
                <td><input type="text" name="bookPublish" required></td>
            </tr>
            <tr>
                <td>作者:</td>
                <td><input type="text" name="bookAuthor" required></td>
            </tr>
            <tr>
                <td>类型:</td>
                <td><input type="text" name="bookType" required></td>
            </tr>
            <tr>
                <td colspan="2"><input type="submit" value="添加图书"></td>
            </tr>
        </table>
    </form>
    
    <%
        if ("POST".equalsIgnoreCase(request.getMethod())) {
            try {
                int bookId = Integer.parseInt(request.getParameter("bookId"));
                String bookName = request.getParameter("bookName");
                double bookPrice = Double.parseDouble(request.getParameter("bookPrice"));
                String bookPublish = request.getParameter("bookPublish");
                String bookAuthor = request.getParameter("bookAuthor");
                String bookType = request.getParameter("bookType");
                
                Book book = new Book(bookId, bookName, bookPrice, bookPublish, bookAuthor, bookType);
                BookDao bookDao = new BookDao();
                boolean success = bookDao.addBook(book);
                
                if (success) {
                    out.println("<script>alert('图书添加成功！'); window.location.href='displayBook.jsp';</script>");
                } else {
                    out.println("<script>alert('图书添加失败！');</script>");
                }
            } catch (Exception e) {
                out.println("<script>alert('输入数据格式错误！');</script>");
            }
        }
    %>
</body>
</html>
```

## 实验要点说明

1. **数据库连接**：使用Derby嵌入式数据库，连接URL为`jdbc:derby:bookdb;create=true`
2. **数据排序**：在SQL查询中使用`ORDER BY book_price ASC`实现价格升序排列
3. **资源管理**：在BaseDao中统一管理数据库连接的获取和释放
4. **异常处理**：使用try-catch-finally确保数据库资源正确释放
5. **数据验证**：在添加图书时进行基本的数据格式验证

运行系统时，首先访问displayBook.jsp查看图书列表，然后可以通过addBook.jsp添加新的图书信息。



