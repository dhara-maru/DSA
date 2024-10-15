public class bitmanipulation {
    public static void main(String[] args) {

        // GET OPERATION
        int n = 5; // 0101
        int position = 3;
        int bitmask1 = 1 << position;

        if ((bitmask1 & n) == 0) {
            System.out.println("Bit was zero");
        } else {
            System.out.println("Bit was one");
        }

        // SET OPERATION
        int n2 = 5; // 0101
        int position2 = 1;
        int bitmask2 = 1 << position;

        int setnumnew = bitmask2 | n;
        System.out.println(setnumnew);

    }
}