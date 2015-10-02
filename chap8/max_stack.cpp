#include <stack>
#include <iostream>
using namespace std;

template<class T>
class max_stack{
public:
	stack<T> mystack;
	stack<T> aux;
	void pop(){
		mystack.pop();
		aux.pop();
	}
	void push(T x){	
		mystack.push(x);
		if(aux.empty())
			aux.push(x);
		else
			aux.push((x>aux.top())?x:aux.top());
	}
	T get_max(){
		if(aux.empty())
			throw invalid_argument("illegal input");
		else
			return aux.top();
	}
};

int main(){
	max_stack<char> S;
	S.push('0');
	S.push('9');
	S.push('c');
	cout << S.get_max() <<endl;
	S.pop();
	cout << S.get_max() <<endl;
	S.push('a');
	cout << S.get_max() <<endl;
	S.pop();
	cout << S.get_max() <<endl;
	return 0;
}