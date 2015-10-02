#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL){}
};

void in_order_traversal(TreeNode *root){
	/*
	TreeNode *cur = root;
	TreeNode *prev = NULL, *next = NULL;
	while(cur){
		if(!prev || cur == prev->left || cur == prev->right){
			if(cur->left){//if left child exists, proceed
				next = cur->left;
			}else{
				cout << cur->val << " ";
				next = ((cur->right)?cur->right:cur->parent);//if right child exists
			}
		}else if(cur->left == prev){
			cout << cur->val << " ";
			next = ((cur->right)?cur->right:cur->parent);
		}else{//cur->right == prev
			next = cur->parent;
		}
		prev = cur;
		cur = next;

	}*/

	TreeNode *cur = root, *prev = NULL, *next = NULL;
	while(cur){
		if(!prev || prev->left == cur || prev->right == cur){
			if(cur->left)
				next = cur->left;
			else{
				cout << cur->val << " ";
				next = (cur->right)?cur->right:cur->parent;
			}
		}else if(cur->left == prev){//going backwards
			cout << cur->val << " ";
			next = (cur->right)?cur->right:cur->parent;
		}else{//cur->right == prev
			next = cur->parent;
		}
		//proceed
		prev = cur;
		cur = next;
	}








}

int main(){
	TreeNode *head  = new TreeNode(314);
	head->left = new TreeNode(6);
	head->right = new TreeNode(500);
	TreeNode *p,*q, *ptemp, *qtemp;
	p = head->left; q = head->right;
	p->parent = head;
	q->parent = head;

	p->left = new TreeNode(271);
	p->right = new TreeNode(561);
	p->left->parent = p;
	p->right->parent = p;
	
	p = p->right;
	p->left = new TreeNode(0);
	p->right = new TreeNode(999);
	p->left->parent = p;
	p->right->parent = p;

	in_order_traversal(head);


	

	return 0;
}