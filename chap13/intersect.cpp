#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(const vector<int> &B, const vector<int> &C){
	vector<int> itrs;
	vector<int>::const_iterator p = B.cbegin();
	vector<int>::const_iterator q = C.cbegin();
	while(p!=B.cend() || q!=C.cend()){
		if(p==B.cend()){
			q++;
		}else if(q==C.cend()){
			p++;
		}else if(*p==*q){
			itrs.push_back(*p);
			p++;
			q++;
		}else if(*p<*q){
			p++;
		}else{
			q++;
		}
	}
	return itrs;
}


int main(){
	vector<int> B = {12,20,2,14,15,10,13,18,8,9,1,5,17};
	vector<int> C = {22,21,7,4,8,2,16,6,11,19,10,17,14};
	sort(B.begin(),B.end());
	for(auto &i:B)
		cout << i << " ";
	cout << endl;
	sort(C.begin(),C.end());
	for(auto &i:C)
		cout << i << " ";
	cout << endl;
	vector<int> p = intersect(B,C);
	for(auto &i:p)
		cout << i << endl;
	return 0;
}