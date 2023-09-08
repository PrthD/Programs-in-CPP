#include <iostream>
#include <cmath>
using namespace std;

bool isInteger(double N)
{
    // Convert float value
    // of N to integer
    int X = N;
 
    double rem = N - X;
 
    // If N is not an integer
    if (rem > 0) {
        return false;
    }
    return true;
}

int main(){
	// declare your variables
	int n,m;
	double power;

	// read the input
	cin >> n >> m;

	// solve, good luck!
	power = log2(m) / log2(n);
	
	if (isInteger(power)) {
        	cout << "GOOD" << endl;
    	}
    	else {
        	cout << "BAD" << endl;
   	}
    	return 0;
}
