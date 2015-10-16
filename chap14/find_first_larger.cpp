#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void find_first_larger(TreeNode *root, int key){
	bool absent = true;
	TreeNode *answer = NULL;
	TreeNode *p = root;
	while(p!=NULL){
		if(p->val>key){
			answer = p;
			p = p->left;
		}else if(p->val==key){
			absent = false;
			p = p->right;
		}else{//if(p->val<key)
			p = p->right;
		}
	}
	
	if(absent)
		cout << "NULL"<< endl;
	else{
		cout << answer->val << endl;
	}
}

int main(){
	TreeNode *head = new TreeNode(19);
	head->left = new TreeNode(7);
	head->right = new TreeNode(43);
	TreeNode *p = head->left, *q = head->right;
	p->left = new TreeNode(3);
	p->right = new TreeNode(11);
	q->left = new TreeNode(23);
	q->right = new TreeNode(47);
	p->left->left = new TreeNode(2);
	p->left->right = new TreeNode(5);
	p->right->right = new TreeNode(17);
	p->right->right->left = new TreeNode(13);
	q->left->right = new TreeNode(37);
	q->left->right->left = new TreeNode(29);
	q->left->right->right = new TreeNode(41);
	q->left->right->left->left = new TreeNode(24);
	q->left->right->left->right = new TreeNode(31);
	q->right->right = new TreeNode(53);
 	find_first_larger(head, 2);
	return 0;
}
