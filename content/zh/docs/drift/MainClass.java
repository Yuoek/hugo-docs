Server error! Your code might have an INFINITE LOOP or be running for too long.
The server may also be OVERLOADED. Or you're behind a FIREWALL that blocks access.
Try again later. This site is free with NO technical support. [#UnknownServerError]
public class MainClass {
    public static void main(String[] args) {
        Runnable leapThread = new LeapThread();
        Runnable thread2 = new Thread2();
        
        Thread t1 = new Thread(leapThread);
        Thread t2 = new Thread(thread2);
        
        t1.start();
        t2.start();
        // 添加线程等待，确保程序正常结束
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class LeapThread implements Runnable {
    @Override
    public void run() {
        int count = 0;
        for (int year = 2000; year <= 3000 && count < 5; year++) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                System.out.println(year + " is leap year");
                count++;
            }
            
            try {
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
        int count = 0;
        for (int num = 100; num <= 200 && count < 5; num++) {
            if (num % 3 == 0) {
                System.out.println("divided by 3：" + num);
                count++;
            }
            
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
