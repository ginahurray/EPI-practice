#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> printSubset(int i){
	if(i>1){
		vector<string> a = printSubset(i-1);
		vector<string> b = printSubset(i-1);
		cout << "********" << endl;
		for(auto &s:a){
			cout << "b4:" << s <<endl;
			s = s+","+to_string(i);
			cout << "after:" <<s <<endl;
		}
		cout << "********" << endl;
		a.insert(a.end(),b.begin(),b.end());
		return a;
	}else{
		vector<string> a;
		a.push_back(" ");
		a.push_back("1");
		return a;
	}
}

int main() {	
	vector<string> result = printSubset(2);
	vector<string>::iterator it = result.begin();
	while(it!=result.end()){
		cout<<*it<<endl;
		it++;
	}
	return 0;
}