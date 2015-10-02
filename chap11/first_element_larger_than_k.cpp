#include <iostream>
#include <vector>
using namespace std;


int first_element_larger_than_k(const vector<int> &A, const int &k){
	int n = A.size();
	if(A[n-1]<=k)//max does not exceed k
		return -1;
	else{
		int L = 0, U = n-1, M;
		while(L<U){
			M = (L>>1)+(U>>1);
			if(A[M]<=k){
				L = M+1;
			}else{//A[M]>k
				U = M;
			}
		}
		return L;
	}

}


int main(){
	vector<int> A = {101,500,500,500,500,500,500,500,500};
	cout << first_element_larger_than_k(A,500) << endl;
	cout << first_element_larger_than_k(A,101) << endl;
	cout << first_element_larger_than_k(A,-11) << endl;
	return 0;
}