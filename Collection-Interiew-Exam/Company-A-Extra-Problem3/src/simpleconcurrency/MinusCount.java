package simpleconcurrency;

/**
 * Created by cfwloader on 4/19/15.
 */
public class MinusCount implements Runnable {

    //private Integer count;

    private ConcurrentCounter concurrentCounter;

    public MinusCount(ConcurrentCounter concurrentCounter) {
        this.concurrentCounter = concurrentCounter;
    }

    @Override
    public void run() {
        while (true) {
            minus();
        }
    }

    public void minus() {
        synchronized (concurrentCounter) {
            while (concurrentCounter.getCount() < 0) {
                try {
                    concurrentCounter.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            concurrentCounter.minus();
            System.out.println("Minus: " + concurrentCounter.getCount());

            concurrentCounter.notify();
        }
    }
}
