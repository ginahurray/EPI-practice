#include <iostream>
#include <vector>
#include <string>
using namespace std;
const vector<string> M = {"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

vector<string> phone_acrynom(const string &p, int i){
	if(i>0){
		vector<string> A;
		for(int j = 0;j<M[p[i]-'0'].size();j++){
			vector<string> temp = phone_acrynom(p,i-1);
			for(auto &s:temp){
				s = s+string(1,M[p[i]-'0'][j]);
			}
			A.insert(A.end(),temp.begin(),temp.end());
		}
		return A;
	}else{
		vector<string> A;
		for(auto const &c:M[p[0]-'0']){
			A.push_back(string(1,c));
		}
		return A;
	}
}
int main(){
	string phone = "12345";
	vector<string> result = phone_acrynom(phone,phone.size()-1);
	for(string &s:result){
		cout << s <<endl;
	}
	cout << result.size()<<endl;

	return 0;
}