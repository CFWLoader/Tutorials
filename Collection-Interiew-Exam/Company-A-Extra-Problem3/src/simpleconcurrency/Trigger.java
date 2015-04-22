package simpleconcurrency;

/**
 * Created by cfwloader on 4/19/15.
 */
public class Trigger {
    public static void main(String[] args) {

        ConcurrentCounter concurrentCounter = new ConcurrentCounter();

        Thread adder = new Thread(new AddCount(concurrentCounter));

        Thread misuser = new Thread(new MinusCount(concurrentCounter));

        adder.start();

        misuser.start();

        try {
            adder.join();
            misuser.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
