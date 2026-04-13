import java.util.*;

public class linearSearch{

    static int lS(int[] nums,int target,int i){
        // int i=0;
       if(i==nums.length) return -1;
       HashMap<Integer,Integer> mpp = new HashMap<>();

       mpp.put(1,2);
       mpp.put(2,3);        

       for(Map.Entry<Integer,Integer> e:mpp.entrySet()){
        System.out.println(e.getKey()+" "+e.getValue());    
        
        if(nums[i]==target){
            return i;
        }
        return lS(nums,target,i+1);


    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        int target = 8;
        int i=0;
        int index = lS(nums,target,i);
        System.out.println(index);
    }
}
