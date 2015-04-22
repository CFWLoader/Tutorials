package simpleconcurrency;

/**
 * Created by cfwloader on 4/18/15.
 */
public class ConcurrentCounter {

    private volatile int count = 3;

    /*
    public static void main(String[] args) {

        Thread adder = new Thread(new AddCount(this));

        Thread misuser = new Thread(new MinusCount(count));

        adder.start();

        misuser.start();

        try {
            adder.join();
            misuser.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    */

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void add(){
        ++count;
    }

    public void minus(){
        --count;
    }
}
