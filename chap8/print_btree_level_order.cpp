#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void print_BT_level_order(TreeNode* root){
	if(!root)
		return;
	queue<TreeNode*> q;
	TreeNode *cur;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		cur = q.front();
		if(!cur){
			cout << endl;
			q.pop();
			//this is to avoid infinite loop

			if(!q.empty())
				q.push(NULL);
		}else{
			cout << cur->val << " ";
			if(cur->left)
				q.push(cur->left);
			if(cur->right)
				q.push(cur->right);
			q.pop();

		}

	}
	/*queue<TreeNode*> q;
	q.push(root);
	int count = q.size();//number of elements in this level
	while(!q.empty()){
		cout << q.front()->val << " ";
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
		count--;
		if(count==0){
			cout << endl;
			count = q.size();
		}
	}*/
	return;
}

int main(){
	TreeNode *head  = new TreeNode(314);
	head->left = new TreeNode(6);
	head->right = new TreeNode(6);
	TreeNode *p,*q;
	p = head->left; q = head->right;
	p->left = new TreeNode(271);
	p->right = new TreeNode(561);
	q->left = new TreeNode(2);
	q->right = new TreeNode(271);
	p = p->left;
	p->left = new TreeNode(28);
	p->right = new TreeNode(0);
	q = q->left;
	q->right = new TreeNode(1);
	q = q->right;
	q->left = new TreeNode(401);
	q->right = new TreeNode(257);
	q = q->left;
	q->right = new TreeNode(641);
	print_BT_level_order(head);

	return 0;
}