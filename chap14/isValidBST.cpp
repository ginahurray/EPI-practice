#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool isValidBST(TreeNode *root){
	if(!root)//a leaf
		return true;
	else{
		if(root->left){
			if(root->left->val>root->val)
				return false;
			TreeNode *p = root->left;
			while(p->right){
				p = p->right;//predecessor
			}
			if(p->val>root->val)
				return false;
		}
		if(root->right){
			if(root->right->val<root->val)
				return false;
			TreeNode *p = root->right;
			while(p->left){
				p = p->left;//successor
			}
			if(p->val<root->val)
				return false;
		}
	}
	return isValidBST(root->left) && isValidBST(root->right);
}

int main(){
	/*
	TreeNode *head  = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(11);
	TreeNode *p,*q;
	p = head->left; q = head->right;
	p->left = new TreeNode(1);
	p->right = new TreeNode(2);
	q->right = new TreeNode(9);
	*/
	TreeNode *head = new TreeNode(1);
	TreeNode *p = head;
	p->right = new TreeNode(2);
	p = p->right;
	p->right = new TreeNode(3);
	p = p->right;
	p->right = new TreeNode(4);
	p = p->right;
	p->right = new TreeNode(5);
	p = p->right;
	p->right = new TreeNode(6);
	p = p->right;
	p->right = new TreeNode(7);
	p = p->right;
	cout <<isValidBST(head)<<endl;;
	return 0;
}
