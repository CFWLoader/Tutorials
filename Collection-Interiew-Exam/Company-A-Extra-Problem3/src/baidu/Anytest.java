package baidu;

/**
 * Created by cfwloader on 4/19/15.
 */

class Super {
    public Super() {
        System.out.println("S");

    }
}

public class Anytest extends Super{

    String name = new String("Tom");

    public Anytest{
        System.out.println("AT");
        Super();
    }

    public static void main(String args[]){
        Anytest anytest = new Anytest();

        System.out.println(this.name);
    }
}
