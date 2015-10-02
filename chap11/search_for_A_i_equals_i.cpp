#include <iostream>
#include <vector>
using namespace std;

int search_for_A_i_equals_i(const vector<int> &A){
	int n = A.size(), L=0, U=n-1, M;
	while(L<=U){
		M = L+((U-L)>>1);
		if(A[M]-M==0)
			return M;
		else if(A[M]-M>0)
			U = M-1;
		else
			L = M+1;
	}
	return -1;
}

int main(){
	vector<int> A = {-14,-10,1,3,5,6,8,285,425,501};
	cout << search_for_A_i_equals_i(A)<<endl;
	return 0;
}