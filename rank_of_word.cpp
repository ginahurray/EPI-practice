#include <string>
#include <iostream>
#include <vector>
#include <numeric> 
#define _MODULO 1000000007
using namespace std;

long int nChoosek(int n, int k){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    long int result = n;
    for( int i = 2; i <= k; i++ ) {
        result *= (n-i+1);
        result /= i;
        result%=_MODULO;
    }
    return result;
}

long long int allpermutation(const vector<int> &d){
	int n = accumulate(d.begin(),d.end(),0);
	if(n==1)
		return 1;
	//total number of letters
	long long int combinations = 1;
	//calculater all permutation O(n);
	int i = 0;
	while(i<26 && n >0){
		if(d[i]>0){
			combinations*=nChoosek(n,d[i]);
			n -= d[i];	
		}
		i++;
		combinations%=_MODULO;
	}
	return combinations;	
}

int get_rank_helper(string w, vector<int> &d) {
	if(w.size()==1)
		return 0;
	if(w[0]>'a'){
		int lessthan = 0;
		int temp = 0;
		vector<int> dd;
		for(int i = 0; i<(w[0]-'a');i++){
			//lessthan indicates # of letters that is prior to w[0]
			if(d[i]>0){
				dd = d;// a copy of original dictionary
				dd[i]-=1;
				temp += allpermutation(dd);//number of permutations with d[i] as the first letter
				temp%=_MODULO;//number of permutations with d[i] as the first letter
			}
		}
		d[w[0]-'a']--;
		return (temp+get_rank_helper(w.substr(1), d))%_MODULO;
	}else{//w[0]=='a'
		d[0]--;
		return get_rank_helper(w.substr(1), d)%_MODULO;
	}
}

vector<int> get_rank(vector<string> words){
	vector<int> answer;
	for(auto w:words){
		//count # of occurance of each letter
		vector<int> dictionary(26,0);
		for(auto &c:w){
			dictionary[c-'a']++;
		}
		answer.push_back(get_rank_helper(w, dictionary));
	}
	return answer;
}

int main(){
	string mystr = "axaelixedhtshsixbuzouqtjrkpyafthezfuehcovcqlbvmkbrwxhzrxymricmehktxepyxomxcx";
	vector<string> myvec;
	myvec.push_back(mystr);
	vector<int> sol = get_rank(myvec);
	for(int &ans:sol)
		cout << "ans: " << ans << endl;
	return 0;
}