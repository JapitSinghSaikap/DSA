#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data=data1;
        next = nullptr;
        back = nullptr; 
    }
};

Node* arrtoDll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL || head->next==nullptr){
        return NULL;
    }
    Node* temp = head;
    head = head->next; // temp mein head ki value preserve hogyi hai so head ko aage shift krdiya;
    head->back = nullptr;  // for the new head the back should be nullptr connection todne ke liye
    temp->next = nullptr; // aur iske liye next wala mtlb aage wala connection tod diya
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    Node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteKthel(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
    }else if(prev==NULL){
        return deleteHead(head);
    }else if(front==NULL){
        return deleteTail(head);
    }
    
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
        return head;
    

}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
   
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return ;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back =  nullptr;
    
    free(temp);


}

Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}


Node* insertBeforetail(Node* head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }   
    Node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeKtheEle(Node* head,int k,int val){
        if(k==1){
            return insertBeforeHead(head,val);
        }
        int cnt = 0;
        Node* temp = head;
        while(temp!=NULL){
            cnt++;
            if(cnt==k) break;
            temp=temp->next;
        }
        Node* prev = temp->back;
        Node* newNode = new Node(val,temp,prev);
        prev->next = newNode;
        temp->back = newNode;
        return head;
}

void insertBeforeNode(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main(){
    vector<int> arr = {12,5,7,8};
    Node* head = arrtoDll(arr);
    //head = insertBeforeKtheEle(head,5,10);
    insertBeforeNode(head->next,100);                                                                                            
    print(head);
    return 0;
}