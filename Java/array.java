import java.util.*;

public class array {
  //array declaration
  public static void main(String args[]){
   
    Scanner sc = new Scanner(System.in); 
    int size = sc.nextInt();
    int[] arr = new int[size];
    for(int i=0;i<size;i++){
        arr[i] = sc.nextInt();
    }

    System.out.print("Enter the num: ");
    int num = sc.nextInt();
    
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            System.out.println("The number is present at index:  "+i);
        }
    }
    sc.close();
  }
} 