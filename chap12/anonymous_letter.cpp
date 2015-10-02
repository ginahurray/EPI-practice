#include <map>
#include <iostream>
using namespace std;


bool anonymous_letter(const string &L, const string &M){
	map<char,int> mymap;

	for(int i = 0;i<L.size();i++){
		mymap[L[i]]++;
	}

	for(const char &c:M){
		auto it = mymap.find(c);
		if(it!=mymap.cend()){//exists //多的找不到算了
			it->second--;
			if(it->second == 0){
				mymap.erase(it);
				if(mymap.empty()){
					return true;
				}
			}
		}
	}
	return mymap.empty();
}

int main(){
	string L = "ninjako";
	string M = "Gina jogging";
	cout << anonymous_letter(L,M)<<endl;
	return 0;
}