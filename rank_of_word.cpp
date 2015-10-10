#include <string>
#include <iostream>
#include <vector>
using namespace std;

long int nChoosek(int n, int k){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    long int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
        result%=1000000007;
    }
    return result;
}

long long int allpermutation(string s, const vector<int> &d){
	//total number of letters
	int n = s.size();
	long long int combinations = 1;
	//calculater all permutation O(n);
	int i = 0;
	while(i<26 && n >0){
		if(d[i]>0){
			combinations*=nChoosek(n,d[i]);
			n -= d[i];	
		}
		i++;
		if(combinations>1000000007)
			combinations%=1000000007;
	}
	return combinations;	
}

int get_rank_helper(string w, vector<int> &d) {
	if(w.size()==1)
		return 0;
	long int rank = 0;
	int lessthan = 0;
	if(w[0]>'a'){
		for(int i = 0; i<(w[0]-'a');i++){
			if(d[i]>0)
				lessthan++;
		}
		d[w[0]-'a']--;
		return (lessthan*allpermutation(w.substr(1), d)+get_rank_helper(w.substr(1), d))%1000000007;
	}else{
		d[0]--;
		return get_rank_helper(w.substr(1), d)%1000000007;
	}
}

vector<int> get_rank(vector<string> words){
	vector<int> answer;
	for(auto w:words){
		//count # of occurance O(n);
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
		cout << ans << endl;
	return 0;
}