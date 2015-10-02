#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int find_kth_largest(vector<int> &A, const int &k){
	if(k>A.size())
		return -1;
	else{
		int indx = rand() % (A.size());
		int val = A[indx];//record the number less than val;
		indx = 0;
		for(int i = 0;i<A.size();i++){
			if(A[i]<val){
				swap(A[i],A[indx]);
				indx++;
			}
		}
		if(indx==k-1){
			return val;
		}else if(indx>k-1){
			vector<int> B (A.begin(),A.begin()+indx);
			return find_kth_largest(B,k);
		}else{//idx<k-1
			vector<int> B (A.begin()+indx,A.end());
			return find_kth_largest(B,k-indx);
		}
	}
}


int main(){
	vector<int> A = {6,3,16,11,7,17,14,8,5,19,15,1,2,4,18,13,9,20,10,12};
	int k = 15;
	cout << "The " <<k <<" th largest number in A: " << find_kth_largest(A, k) << endl;
	return 0;
}