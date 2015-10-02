#include <iostream>
#include <stack>
#include <array>
using namespace std;

void hanoi(int from, int to, int via, int n){
	if(n==1){
		cout << from << "->" << to << endl;
	}else{
		hanoi(from, via, to, n-1);
		cout << from <<"->" << to <<endl;
		hanoi(via, to , from, n-1);
	}
}


void transfer(int n, array<stack<int>,3>& pegs, int from, int to , int use){
	if(n>0){
		transfer(n-1, pegs, from ,use, to);
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		cout << "Move from peg"<< from << " to peg " << to << endl;
		transfer(n-1, pegs, use ,to, from);
	}
}

void move_tower_hanoi(int n){
	array<stack<int>,3> pegs;
	for(int i=n; i>=1;--i){
		pegs[0].push(i);
	}
	transfer(n,pegs,0,1,2);
}

int main(){
	move_tower_hanoi(3);
	hanoi(0,1,2,3);
	return 0;
}