#include<iostream>
using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;

	ListNode(int val){
		this->val=val;
		this->next=NULL;
	}
};


ListNode* getNode(ListNode* temp,int i){
	int k=0;
	while(temp!=NULL && k<i){
		temp=temp->next;
		k++;
	}
	return temp;
		
}

ListNode* getTail(ListNode* temp){
	while(temp->next!=NULL){
		temp=temp->next;
	}
	return temp;
}

void InsertAtHead(ListNode*& head,int val){
	ListNode* n=new ListNode(val);
	n->next = head;
	head=n;
}
// ListNode* InsertAtHead(ListNode* head,int val){
// 	ListNode* n=new ListNode(val);
// 	n->next = head;
// 	head = n;
// 	return head;
// }

void InsertAtTail(ListNode*& head,int val){
	if(head==NULL){
		InsertAtHead(head,val);
		return ;
	}
	ListNode* tail=getTail(head);
	ListNode* n=new ListNode(val);
	tail->next=n;

}

void DeleteAtHead(ListNode*& head,int i){
	if(head==NULL){
		return;
	}
	ListNode* temp=head;
	head=head->next;
	delete temp;
}

void DeleteAtIndex(ListNode*& head,int i){
	if(i==0){
		DeleteAtHead(head,i);
		return;
	}
	ListNode* cur=getNode(head,i);
	if(cur==NULL){
		return;
	}
	ListNode* prev=getNode(head,i-1);
	prev->next=cur->next;
	delete cur;
}

void PrintLinkList(ListNode* head){
	while(head!=NULL){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}


void swapLinkList(ListNode* &head, int i, int j) {
    if (i == j) {
        // No need to swap if i and j are the same
        return;
    }
    
    ListNode* prevx = NULL;
    ListNode* prevy = NULL;

    if (i > 0) {
        prevx = getNode(head, i - 1);
    }
    if (j > 0) {
        prevy = getNode(head, j - 1);
    }
    
    ListNode* x = getNode(head, i);
    ListNode* y = getNode(head, j);

    // Adjust the next pointers to swap the nodes
    if (prevx != NULL) {
        prevx->next = y;
    } else {
        head = y; // Update head if x was the head
    }

    if (prevy != NULL) {
        prevy->next = x;
    } else {
        head = x; // Update head if y was the head
    }

    ListNode* temp = y->next;
    y->next = x->next;
    x->next = temp;
}

int main() {
	ListNode* head=NULL;
	InsertAtTail(head,5);
	InsertAtTail(head,6);
	InsertAtTail(head,7);
	InsertAtTail(head,8);
	InsertAtTail(head,9);
	InsertAtTail(head,10);
	PrintLinkList(head);
	swapLinkList(head,4,2);
	PrintLinkList(head);

	return 0;
}