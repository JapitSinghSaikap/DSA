#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next=next1;
    }
    // multiple constructors to solve the issue fo writing nullptr
    public:
    Node(int data1){
        data =data1;
        next=nullptr;
    }  

};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}

int lenghtofLL(Node* head){
    int count=0;
    Node* temp= head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

Node* removesHead(Node* head){
    if(head== NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next==NULL) return NULL;
    
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

Node* deletek(Node* head,int k){
    if(head==NULL) return   head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteEl(Node* head,int k){
    // if(head==NULL) return   head;
    if(head->data==k){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    // int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){;
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


Node* insertELHEad(Node* head, int el){
    Node* temp = new Node(el,head);
    // temp=temp->next;
    return temp;
}

Node* insertTOTail(Node* head,int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
    }
    Node* value = new Node(val);
    temp->next=value;
    return head;
}

Node* insertkth(Node* head,int val,int k){
    if(head ==NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    int count = 0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* value = new Node(val);
            value->next=temp->next;
            temp->next=value;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head,int el,int val){
    if(head ==NULL){
        return NULL;
    }
    if(head->data==val){
        Node* temp = new Node(el,head);
        return temp;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* value = new Node(el);
            value->next=temp->next;
            temp->next=value;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Array conversion to linked list
int main(){
    vector<int> arr={12,5,6,7};
    // Node* head = convertArr2LL(arr);
    Node* head = convertArr2LL(arr);
    //head = removesHead(head);
    head = insertkth(head,69,3);
    print(head);
    // cout<<head->data;
    // Node* temp= head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
}
