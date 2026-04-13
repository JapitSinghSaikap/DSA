// #include<bits/stdc++.h>

// using namespace std;

// class heap{
//     public:
//     int arr[100];
//     int size = 0;

//     heap(){
//         arr[0]=-1;
//         size=0;
//     }

//     void insert(int val){
//         size = size+1;
//         int index = size;
//         arr[index] = val;

//         while(index>1){
//             int parent = index/2;

//             if(arr[parent]<arr[index]){
//                 swap(arr[parent],arr[index]);
//                 index = parent;
//             }else{
//                 return ;
//             }
//         }
//     }

//     void print(){
//         for(int i=1;i<=size;i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };



// int main(){
//     heap h;
//     h.insert(50);
//     h.insert(55);
//     h.insert(53);
//     h.insert(54);
//     h.insert(52);
//     h.print();
//}
   
#include <iostream>
using namespace std;


void printPrimeFactors(int n, int divisor) {
    
    if (n == 1) {
        return;
    }

    if (n % divisor == 0) {
        cout << divisor << " "; 
        printPrimeFactors(n / divisor, divisor);
    } else {
        printPrimeFactors(n, divisor + 1);
    }
}


int main() {
    int n;
    cin >> n;
    printPrimeFactors(n, 2);
    cout << endl; 

    return 0;
}

