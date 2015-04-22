package simpleconcurrency;

/**
 * Created by cfwloader on 4/19/15.
 */
public class AddCount implements Runnable {

    //private Integer count;

    private ConcurrentCounter concurrentCounter;

    public AddCount(ConcurrentCounter concurrentCounter) {
        this.concurrentCounter = concurrentCounter;
    }

    @Override
    public void run() {
        while (true) {
            add();
        }
    }

    public void add() {
        synchronized (concurrentCounter) {
            while (concurrentCounter.getCount() > 10) {
                try {
                    concurrentCounter.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            concurrentCounter.add();
            System.out.println("Add: " + concurrentCounter.getCount());

            concurrentCounter.notify();
        }
    }
}
