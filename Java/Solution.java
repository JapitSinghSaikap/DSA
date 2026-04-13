import java.util.*;

public class Solution {

    public static void rotateArray(int[] nums) {
        int n = nums.length;
        if (n <= 1) return;

        int lastElement = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = lastElement;
    }

    public static void printArray(int[] nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};

        System.out.println("Original Array:");
        printArray(nums);

        rotateArray(nums);

        System.out.println("Rotated Array: ");
        printArray(nums);
    }
}
