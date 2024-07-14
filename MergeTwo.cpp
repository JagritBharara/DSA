// #include<iostream>

// using namespace std;

// class ListNode {
// public:

// 	int val;
// 	ListNode* next;

// 	ListNode(int val) {
// 		this->val = val;
// 		this->next = NULL;
// 	}

// };

// void insertAtHead(ListNode*& head, int val) {

// 	ListNode* n = new ListNode(val);
// 	n->next = head;
// 	head = n;

// }


// void printLinkedList(ListNode* head) {

// 	while (head) { // head != NULL
// 		cout << head->val << " ";
// 		head = head->next;
// 	}

// 	cout << endl;
// }

// ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

// 	// base case

// 	if (head1 == NULL) {
// 		// first LL is empty
// 		return head2;
// 	}

// 	if (head2 == NULL) {
// 		// second LL is empty
// 		return head1;
// 	}

// 	// recursive case

// 	ListNode* head;

// 	if (head1->val < head2->val) {

// 		head = head1;
// 		ListNode* headFromMyFriend = mergeSortedLinkedList(head1->next, head2);
// 		head->next = headFromMyFriend;

// 	} else {

// 		head = head2;
// 		ListNode* headFromMyFriend = mergeSortedLinkedList(head1, head2->next);
// 		head->next = headFromMyFriend;

// 	}


// 	return head;

// }

// ListNode* mergeSortedLinkedListIterative(ListNode* head1, ListNode* head2) {

// 	ListNode* dummy = new ListNode(0);
// 	ListNode* temp = dummy;

// 	while (head1 != NULL and head2 != NULL) {

// 		if (head1->val < head2->val) {

// 			temp->next = head1;
// 			head1 = head1->next;
// 			temp = temp->next;

// 		} else {

// 			temp->next = head2;
// 			head2 = head2->next;
// 			temp = temp->next;

// 		}

// 	}

// 	// while (head1 != NULL) {

// 	// 	temp->next = head1;
// 	// 	head1 = head1->next;
// 	// 	temp = temp->next;

// 	// }

// 	// while (head2 != NULL) {

// 	// 	temp->next = head2;
// 	// 	head2 = head2->next;
// 	// 	temp = temp->next;

// 	// }
//     if(head1!=NULL) temp->next=head1;
//     if(head2!=NULL) temp->next=head2;

// 	return dummy->next;

// }

// int main() {

// 	ListNode* head1 = NULL;

// 	insertAtHead(head1, 50);
// 	insertAtHead(head1, 30);
// 	insertAtHead(head1, 10);

// 	printLinkedList(head1);

// 	ListNode* head2 = NULL;

// 	insertAtHead(head2, 60);
// 	insertAtHead(head2, 40);
// 	insertAtHead(head2, 20);
//     insertAtHead(head2,25);
// 	printLinkedList(head2);

// 	// ListNode* head = mergeSortedLinkedList(head1, head2);

// 	ListNode* head = mergeSortedLinkedListIterative(head1, head2);

// 	printLinkedList(head);

// 	return 0;
// }
/*

given the pre-order traversal of a binary tree, output its level-order traversal.

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 20 30 40 50 60 70
*/

#include<iostream>
#include<queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* buildTree() {

	// 1. read the val of the root TreeNode
	int val;
	cin >> val;

	if (val == -1) {
		// construct an empty tree and return the pointer to its root
		return NULL;
	}

	// 2. construct the root TreeNode
	TreeNode* root = new TreeNode(val);

	// 3. read the preOrder traversal of the leftSubtree & build the leftSubtree
	root->left = buildTree();

	// 4. read the preOrder traversal of the rightSubtree & build the rightSubtree
	root->right = buildTree();

	return root;

}

void printLevelOrder(TreeNode* root) {

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode* front = q.front();
		q.pop();

		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}

		} else {

			// process the 'front' node

			cout << front->val << " ";

			if (front->left != NULL) {
				// visit the leftChild of frontNode
				q.push(front->left);
			}

			if (front->right != NULL) {
				// visit the rightChild of the frontNode
				q.push(front->right);
			}
		}
	}

}

int main() {

	TreeNode* root = buildTree();

	printLevelOrder(root);

	return 0;
}