public class timecomplexity {
    // ==============================================
    // O(1) Time complexity : Constant Time : bcoz it don't have to do anything with
    // input n. it just have to find the element from the array only once and its
    // work is done. Example :
    static int getfirstelem(int[] arr) {
        return arr[0];
    }

    // ===============================================
    // O(n) : Linear time : if you double the input time, the execution time also
    // doubles. ex, finding an elem in array, if you add more elems, it'll take more
    // time to find. :
    int target = 4;

    boolean contains(int[] arr, int target) {
        for (int num : arr) {
            if (num == target) {
                return true; // The time increases with the number of elements in the array.
            }
        }
        return false;
    }

    // ================================================
    // O(n²) : Quadratic Time: execution time increases quadratically as the input
    // size grows. If you double the input size, the execution time increases
    // fourfold.
    void print() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) { // it'll loop 5 into 5 (5*5 = 25) so it's Quadratic.
                System.out.println(j);
            }
        }
    }

    // ================================================
    // O(log n) - Logarithmic Time: means the time it takes to complete a task grows
    // slowly as the input size increases, often by cutting the problem in half each
    // time. (so, it's the best after O(1) and before O(n). )
    // best example of it, is : Binary search (which divides the arr/problem in
    // half.)
    int binarySearch(int[] sortedArray, int target) {
        int left = 0, right = sortedArray.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // Reducing the search space.
            if (sortedArray[mid] == target) {
                return mid; // Time taken decreases significantly with each iteration.
            }

        }
        return -1; // target not found
    }

    public static void main(String[] args) {
        int[] arr = { 4, 9, 2, 5 };
        System.out.println(getfirstelem(arr));
        int[] sortedArray = { 1, 2, 3, 4, 5, 6 };
    }
}