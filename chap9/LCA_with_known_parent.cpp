#include <iostream>
#include <set>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL){}
};

const TreeNode* LCA_with_parent(const TreeNode* root, const TreeNode *p, const TreeNode *q){
	const TreeNode *l = p, *r = q;
	while(l!=r){
		l = (l==root)?q:l->parent;
		r = (r==root)?p:r->parent;
	}
	return l;
}

TreeNode* LCA_with_parent_using_set(TreeNode* root, TreeNode* p, TreeNode* q){
	set<TreeNode*> myset;
	while(p||q){//not to root yet
		if(p){
			if(myset.emplace(p).second)//first time
				p = p->parent;
			else
				return p;

		}
		if(q){
			if(myset.emplace(q).second)
				q = q->parent;
			else
				return q;
		}
	}
	throw invalid_argument("Not in the same tree!");
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
	ptemp = p->left;
	p->right = new TreeNode(561);
	p->left->parent = p;
	p->right->parent = p;
	p = p->right;
	p->left = new TreeNode(0);
	p->right = new TreeNode(999);
	p->left->parent = p;
	p->right->parent = p;
	qtemp = p->right;
	cout << "p:" << ptemp->val << "q:" << qtemp->val <<endl;
    cout << LCA_with_parent_using_set(head,ptemp,qtemp)->val << endl;
	return 0;
}