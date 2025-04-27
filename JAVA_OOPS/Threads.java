class ThreadUsingThread extends Thread{
    @Override
    public void run() {
        System.out.println("Thread is running using Thread");
    }
}

class ThreadUsingRunnable implements Runnable{
    @Override
    public void run() {
        System.out.println("Thread is running using Runnable");
    }
}

class EvenThread extends Thread{
    public void run(){
        for(int i = 0; i<=20; i = i+2){
            System.out.println(i + " : Eventhread");
        }
    }
}


class OddThread extends Thread{
    public void run(){
        for(int i = 1; i<=20; i = i+2){
            System.out.println(i + " : Oddthread");
        }
    }
}

public class Threads {
    public static void main(String[] args) {
        
        ThreadUsingThread t = new ThreadUsingThread();
        t.start();

        ThreadUsingRunnable tr = new ThreadUsingRunnable();
        Thread r = new Thread(tr);
        r.start();

        EvenThread e = new EvenThread();
        OddThread o = new OddThread();
        e.start();
        o.start();
    }
    
}