import java.util.Scanner;

public class ConsecutiveSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] nums = new int[n];
      
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        int l = 0;
        int r = n - 1;

        while (l < r) {
            nums[l] = nums[l] + nums[r];
            l++;
            r--;
        }
   
        for (int i = 0; i < (n + 1) / 2; i++) {
            System.out.print(nums[i] + " ");
        }
        
        sc.close();
    }
}



// import java.util.ArrayList;
// import java.util.Scanner;

// public class ConsecutiveSum {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
        
       
//         int n = scanner.nextInt();
        
//         ArrayList<Integer> nums = new ArrayList<>();
//         ArrayList<Integer> ans = new ArrayList<>();
        
      
//         for (int i = 0; i < n; i++) {
//             int el = scanner.nextInt();
//             nums.add(el);
//         }
        
      
//         for (int i = 0; i < n - 1; i++) { 
//             int sum = nums.get(i) + nums.get(i + 1);
//             ans.add(sum);
//         }
        
       
//         for (int sum : ans) {
//             System.out.print(sum + " ");
//         }
        
//         scanner.close();
//     }
// }
