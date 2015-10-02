#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
	char val;
	TreeNode *left, *right;
	TreeNode(char x):val(x),left(NULL),right(NULL){}
};

void print_BT_level_order(TreeNode* root){
	queue<TreeNode*> q;
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
	}
	return;
}

TreeNode* reconstruct_Tree(const vector<TreeNode*> &in, const vector<TreeNode*> &pre){
	if(in.empty())
		return NULL;
	if(in.size()==1)
		return *(in.begin());
	else{
		TreeNode *root = *(pre.begin());
		vector<TreeNode*>::const_iterator it;
		it = find(in.begin(),in.end(),root);
		
		vector<TreeNode*> inleft (in.begin(),it);
		vector<TreeNode*> inright (it+1,in.end());
		
		vector<TreeNode*> preleft (pre.begin()+1,pre.begin()+inleft.size()+1);
		vector<TreeNode*> preright (pre.begin()+inleft.size()+1,pre.end());	
		root->left = reconstruct_Tree(inleft, preleft);
		root->right = reconstruct_Tree(inright, preright);
		return root;
	}
}


TreeNode* reconstruct_Tree2(const vector<TreeNode*> &in, const vector<TreeNode*> &post){
	if(in.empty())
		return NULL;
	if(in.size()==1)
		return *(in.begin());
	else{
		TreeNode *root = *(post.end()-1);
		vector<TreeNode*>::const_iterator it;
		it = find(in.begin(),in.end(),root);
		
		vector<TreeNode*> inleft (in.begin(),it);
		vector<TreeNode*> inright (it+1,in.end());
		
		vector<TreeNode*> postleft (post.begin(),post.begin()+inleft.size());
		vector<TreeNode*> postright (post.begin()+inleft.size(),post.end()-1);	
		root->left = reconstruct_Tree2(inleft, postleft);
		root->right = reconstruct_Tree2(inright, postright);
		return root;
	}
}

int main(){
	TreeNode *A = new TreeNode('A');
	TreeNode *B = new TreeNode('B');
	TreeNode *C = new TreeNode('C');
	TreeNode *D = new TreeNode('D');
	TreeNode *E = new TreeNode('E');
	TreeNode *F = new TreeNode('F');
	TreeNode *G = new TreeNode('G');
	TreeNode *H = new TreeNode('H');
	TreeNode *I = new TreeNode('I');
	//vector<TreeNode*> inorder = {D,A,E,B,C,F};
	//vector<TreeNode*> preorder = {B,A,D,E,C,F};
	
	vector<TreeNode*> inorder = {F,B,A,E,H,C,D,I,G};
	vector<TreeNode*> preorder = {H,B,F,E,A,C,D,G,I};
	vector<TreeNode*> postorder = {F,A,E,B,I,G,D,C,H};
	TreeNode *head = reconstruct_Tree(inorder,preorder);
	print_BT_level_order(head);
	cout << "*****" << endl;
	head = reconstruct_Tree2(inorder,postorder);
	print_BT_level_order(head);
	return 0;
}