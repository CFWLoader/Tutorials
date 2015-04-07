package problem3;


import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by cfwloader on 4/2/15.
 */
public class ProducerConsumer {

    class Apple {
    }

    private List<Apple> basket = new ArrayList<Apple>();

    private Boolean locked = false;             //Simulation of mutex.

    @Test
    public void testRun() {
        ProducerConsumer producerConsumer = new ProducerConsumer();
        Thread producer = new Producer(producerConsumer);
        Thread consumer = new Consumer(producerConsumer);
        producer.start();
        consumer.start();
        try {
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public boolean isFull() {
        if (basket.size() > 5) return true;
        else return false;
    }

    public boolean isEmpty() {
        if (basket.size() == 0) return true;
        else return false;
    }

    class Producer extends Thread {
        ProducerConsumer producerConsumer;

        Producer(ProducerConsumer pc) {
            producerConsumer = pc;
        }

        @Override
        public void run() {
            while (true) {
                addApple();
            }
        }

        void addApple() {
            synchronized (producerConsumer) {
                while (producerConsumer.isFull() || producerConsumer.locked) {
                    try {
                        producerConsumer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                }
                producerConsumer.locked = true;
                producerConsumer.basket.add(new Apple());
                System.out.println("Producer added a apple.");
                producerConsumer.locked = false;
                producerConsumer.notify();
            }
        }
    }

    class Consumer extends Thread {
        ProducerConsumer producerConsumer;

        Consumer(ProducerConsumer pc) {
            producerConsumer = pc;
        }

        @Override
        public void run() {
            while (true) {
                removeApple();
            }
        }

        public void removeApple() {
            synchronized (producerConsumer) {
                while (producerConsumer.isEmpty() || producerConsumer.locked) {

                    //System.out.println("Consumer is waiting");

                    try {
                        producerConsumer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                }
                producerConsumer.locked = true;
                producerConsumer.basket.remove(producerConsumer.basket.get(0));
                System.out.println("Consumer removed a apple.");
                producerConsumer.locked = false;
                producerConsumer.notify();
            }
        }
    }
}
