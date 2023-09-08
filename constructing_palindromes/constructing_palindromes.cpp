#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	// declare your variables
	int n;
	string str;
	int length = 0;
	bool flag = false;
	map <char, int> lettercount;

	// read the input
	cin >> n;
	cin >> str;

	// solve, good luck
	for (char i: str)lettercount[i]++;
	for (auto k:lettercount){
		if (k.second % 2 == 0){
			length = length + k.second;
		} else{
			length = length + k.second - 1;
			flag = true;
		}
	}
	if (flag){
		length++;
	}
	cout << length << endl;
	return 0;
}
