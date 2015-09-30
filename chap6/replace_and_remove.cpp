#include <iostream>
#include <string>
using namespace std;

void replace_and_remove(string &s){
	int a_count=0, idx = 0;
	//delete b first
	for(const char &c:s){
		if(c=='a'){
			s[idx++] = c;
			a_count++;
		}else if(c=='b'){
			continue;
		}else{//not 'a' nor 'b'
			s[idx++] = c;		
		}
	}
	int cur = idx+a_count-1;
	s.resize(idx+a_count);
	for(int i = idx-1;i>=0;i--){
		if(s[i]=='a'){
			s[cur] = 'd';
			s[cur-1] = 'd';
			cur -=2; 
		}else{
			s[cur] = s[i];
			cur--;
		}
	}
}



int main(){
	string s = "abworamsmacw";
	cout << "before: " << s <<endl;
	replace_and_remove(s);
	cout << "after replace 'a' with 'dd' and remove b:" << s << endl;
	return 0;
}