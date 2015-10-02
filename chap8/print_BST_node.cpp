#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void print_BST_node(TreeNode* n){
	if(!n)
		return;
	stack<TreeNode*> BST;
	/*BST.push(n);
	TreeNode *cur = n, *p = NULL;
	while(!BST.empty()){
		while(cur->left && cur!=p){
			cur = cur->left;
			BST.push(cur);
		}
		cout << cur->val << " ";
		BST.pop();
		if(!BST.empty())
			p = BST.top();
		if(cur->right){
			BST.push(cur->right);
			cur = cur->right;
		}else{
			if(!BST.empty())
				cur = BST.top();
		}
	}*/
	while(!BST.empty() || n){
		if(n){
			BST.push(n);
			n = n->left;
		}else{
			n = BST.top();
			cout << n->val << " ";
			BST.pop();
			n = n->right;
		}
	}

}

int main(){
	TreeNode *head  = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(7);
	TreeNode *p,*q;
	p = head->left; q = head->right;
	p->left = new TreeNode(1);
	p->right = new TreeNode(4);
	q->right = new TreeNode(100);
	print_BST_node(head);
	return 0;
}