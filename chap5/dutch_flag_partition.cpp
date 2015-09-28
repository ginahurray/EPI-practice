#include <iostream>
#include <vector>
using namespace std;

vector<int> dutch_flag_partition(vector<int> &A, int m){
	int i=0, j=0, k=A.size()-1,t = A[m];
	while(i<=k){
		if(A[i]<t){
			swap(A[i],A[j]);
			i++;
			j++;
		}else if(A[i]>t){
			swap(A[i],A[k]);
			k--;
		}else{
			i++;
		}
	}
	return A;
}


int main(){
	vector<int> A = {1,9,8,3,7,8,5,36,7,4,5,2,3,4,1,51,2};
	dutch_flag_partition(A, 5);
	for(auto &a:A){
		cout << a <<endl;
	}
	return 0;
}