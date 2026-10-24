/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
Node* insert(Node* &clhead,Node* &cltail, Node* temp){
    Node* newNode = new Node(temp->val);
    if(clhead==NULL){
        clhead=newNode;
        cltail=newNode;
    }
    else{
        cltail->next=newNode;
        cltail=newNode;

    }
    return clhead;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        // 5 step
        Node* clhead=NULL;
        Node* cltail=NULL;


        // copy normal LL
        Node* temp=head;
        while(temp!=NULL){
            clhead=insert(clhead,cltail,temp);
            temp=temp->next;
        }

        //merge both LL side by side
        temp=head;
        Node*  temp1=clhead;
        Node* next =NULL;
        Node* next1=NULL;
        while(temp!=NULL && temp1!=NULL){
            next=temp->next;
            next1=temp1->next;
            temp->next=temp1;
            temp=next;
            temp1->next=temp;
            temp1=next1;
        }

        //assign random pointer to the copy one from orignal ll as it just after it
        temp=head;
        
        while(temp!=NULL){
            temp1=temp->next;
            if(temp->random!=NULL){
                temp1->random=temp->random->next;
            }
                
            else{
                temp1->random=NULL;
            }
            temp=temp1->next;
        }

        // jaise merge kia tha waise hi nakal do..
        temp=head;
        temp1=head->next;
        next =NULL;
        next1=NULL;
        while(temp!=NULL && temp1!=NULL){
            temp->next=temp1->next;
            temp=temp->next;
            if(temp!=NULL){
                temp1->next=temp->next;
                temp1=temp1->next;
            }
            
        }

        // LL copy ho gai..
        return clhead;
        
    }
};