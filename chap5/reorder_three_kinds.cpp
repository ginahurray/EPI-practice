#include <iostream>
#include <vector>
using namespace std;

void reorder_three_kinds(vector<int> &A){
	int i=0, j=0, k=A.size()-1, t1 = A[0], t2;
	bool seen2 = false;
	while(i<=k){
		if(!seen2){
			if(A[i]==t1){
				swap(A[i],A[j]);
				i++;
				j++;
			}else{//new input;
				t2 = A[i];
				seen2 = true;
				continue;
			}
		}else{//already seen 2 kinds;
			if(A[i]==t1){
				swap(A[i],A[j]);
				i++;
				j++;
			}else if(A[i]==t2){
				i++;
			}else{// the third kind
				swap(A[i],A[k]);
				k--;
			}
		}
	}
}

void reorder_boolean(vector<bool> &A){
	int i = 0, k= A.size()-1;
	while(i<=k){
		if(A[i]){
			i++;
		}else{
			swap(A[i],A[k]);
			k--;
		}
	}
}

void reorder_four_kinds(vector<int> &A){
	int  i = 0, j = 0, k = 0, l = A.size()-1, t1 = A[0], t2, t3;
	bool seen2 = false;
	bool seen3 = false;
	while(i<=l){
		if(!seen2){
			if(A[i]==t1){
				swap(A[i],A[j]);
				i++;
				j++;
				k++;
			}else{
				t2 = A[i];
				seen2 = true;
				continue;
			}
		}else if(seen2 && !seen3){
			if(A[i]==t1){
				swap(A[i],A[j]);
				i++;
				j++;
				k++;
			}else if(A[i]==t2){
				swap(A[i],A[k]);
				i++;
				k++;
			}else{
				t3 = A[i];
				seen3 = true;
				continue;
			}
		}else{
			if(A[i]==t1){
				swap(A[i],A[k]);
				swap(A[k],A[j]);
				i++;
				j++;
				k++;
			}else if(A[i]==t2){
				swap(A[i],A[k]);
				i++;
				k++;
			}else if(A[i]==t3){
				swap(A[i], A[l]);
				l--;
			}else{
				i++;
			}
		}
	}
}

int main(){
	vector<int> int_test = {3,2,3,1,1,3,3,1,2,2,3};
	cout <<"before: ";
	for(auto &s:int_test){
		cout << s << " ";
	}
	cout << endl;
	reorder_three_kinds(int_test);
	cout <<"after: ";
	for(auto &s:int_test){
		cout << s << " ";
	}
	cout << endl;
	/*****************************************/
	vector<bool> bool_test = {true, false, false, false, true, true, false,true};
	cout <<"before: ";
	for(auto s:bool_test){
		cout << s << " ";
	}
	cout << endl;
	reorder_boolean(bool_test);
	cout <<"after: ";
	for(auto s:bool_test){
		cout << s << " ";
	}
	cout << endl;
	/*****************************************/
	vector<int> four_int_test = {1,2,3,4,1,2,3,4,1,4,2,3,4,1,4,2,3,2,1};
	cout <<"before: ";
	for(auto &s:four_int_test){
		cout << s << " ";
	}
	cout << endl;
	reorder_four_kinds(four_int_test);
	cout <<"after: ";
	for(auto &s:four_int_test){
		cout << s << " ";
	}
	cout << endl;
	return 0;
}