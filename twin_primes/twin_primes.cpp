// -------------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #1: Twin Primes
// -------------------------------------------------------

#include <iostream>
using namespace std;

bool isPrime(int n){
	if (n <= 1)
		return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

void twinPrimes(int k){
	int pair = 1;
	int count = 2;
	while (pair <= k){
		if (isPrime(count) && isPrime(count + 2)){
			cout << count << " " << count + 2 << endl;
			pair++;
		}
		count++;
	}
}

int main(){
	char charac;
	int integ;
	
	cin >> charac >> integ;

	if (charac == 'p'){
		if (isPrime(integ)){
			cout << "prime" << endl;
		} else{
			cout << "not prime" << endl;
		}
	} else{
		twinPrimes(integ);
	}
	return 0;
}	
