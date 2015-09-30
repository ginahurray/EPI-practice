#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> &B){
	vector<int> count(10,0);
	for(int &i:B){
		if(i){
			count[i]++;
			if(count[i]>1)
				return false;
		}
	}
	return true;
}

bool sudoku_checker(vector<vector<int>> &A){
	//Check every row
	for(auto &a:A){
		if(!isValid(a))
			return false;
	}
	//Check every column
	for(int i = 0;i<9;i++){
		vector<int> col;
		for(auto &a:A){
			col.push_back(a[i]);
		}
		if(!isValid(col))
			return false;
	}
	//Check every block
	
	for(int i = 0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			vector<int> box;
			box.push_back(A[i][j]);
			box.push_back(A[i][j+1]);
			box.push_back(A[i][j+2]);
			box.push_back(A[i+1][j]);
			box.push_back(A[i+1][j+1]);
			box.push_back(A[i+1][j+2]);
			box.push_back(A[i+2][j]);
			box.push_back(A[i+2][j+1]);
			box.push_back(A[i+2][j+2]);
			if(!isValid(box))
				return false;
		}
	}

	return true;
}

int main(){
	vector<vector<int>> mysudoku;
	mysudoku.push_back({5,3,0,0,7,0,0,0,0});
	mysudoku.push_back({6,0,0,1,9,5,0,0,0});
	mysudoku.push_back({0,9,8,0,0,0,0,6,0});
	mysudoku.push_back({8,0,0,0,6,0,0,0,3});
	mysudoku.push_back({4,0,0,8,0,3,0,0,1});
	mysudoku.push_back({7,0,0,0,2,0,0,0,6});
	mysudoku.push_back({0,6,0,0,0,0,2,8,0});
	mysudoku.push_back({0,0,0,4,1,9,0,0,5});
	mysudoku.push_back({0,0,0,0,8,0,0,7,9});
	if(sudoku_checker(mysudoku))
		cout << "valid!" << endl;
	else
		cout << "invalid!" << endl;
	return 0;
}