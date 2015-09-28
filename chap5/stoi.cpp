#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

string intToString(int x){
	string s;
	if(x){
		return s = intToString(x/10)+string(1,'0'+(x%10));
	}else{
		return "";
	}
}

int stringToint(string s){
	int n = s.size(), x = 0, begin;
	bool isNeg;
	if(isNeg = (s[0]=='-'))
		begin = 1;
	else
		begin = 0; 
	for(int i = begin;i<n;i++){
		if((s[i]-'0'<0)|(s[i]-'0'>9)){//illegal
			throw invalid_argument("illegal input");
		}else{
			x = 10*x+s[i]-'0';
		}
	}
	if(isNeg)
		return (-1)*x;
	else
		return x;
}

int main() {
	int test = 0;
	//cout << "Enter test: ";
	//cin >> test;
	//cout << "after stoi: ";
	bool isNeg = (test<0);
	if(test == -2147283648){
		cout << "-2147283648" << endl;
	}else if(test == 0){
		cout << "0" <<endl;
	}else{
		string result = intToString(abs(test));
		if(isNeg){
			result = "-"+result;
		}
		cout<< result << endl;
	}
	cout << "*****************" << endl;
	string t = "-";
	if(t=="-")
		throw invalid_argument("illegal input");
	cout << stringToint(t) << endl;
	return 0;
}