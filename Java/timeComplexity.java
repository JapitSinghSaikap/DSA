public class timeComplexity{
    public static void main(String[] args){
        int n =5;
        //By formula O(1) T.C
        int sum = n*(n+1)/2;
        System.out.println("The sum using formula is : "+sum);
        // By For loop O(n) T.C
        int summ = 0;
        for(int i=1;i<=n;i++){
            summ+=i;
        }
        System.out.println("The Sum using for loop is : "+summ);
        

    }
}

