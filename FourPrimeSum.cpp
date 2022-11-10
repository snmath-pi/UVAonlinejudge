#include<iostream>
#include<vector>
using namespace std ;
const int mxN = 18409202 ;
const int mxX = 1e5 ;
const int mxY = 1e7 ;
vector<int> getPrimes() {
	vector<bool> primes(mxY , true) ;
	primes[0] = primes[1] = false ;
	vector<int> primeNumbers(mxY + 1 ,0 ) ;
	primeNumbers[0] = 0 , primeNumbers[1] = 1 , primeNumbers[2] = 2 ;
	
	for(int i=4; i <= mxY ; i+=2) primes[i] = false ;
	
	for(int i=3; i<= mxY; i+=2){
		if(primes[i]){
			primeNumbers[i] = i ;
			for(int j= i + i ; j <= mxY ; j+=i){
				primes[i] = false;
			}
		}
	}
	int prev = 3 ;
	for(int i=4; i<= mxY; i++){
		if(primeNumbers[i] == 0){
			primeNumbers[i] = prev; 
		}else{
			prev = primeNumbers[i] ;
		}

	}
	//cout << primes[1e7] ;
	//cout << primes[9999993]; 
	return primeNumbers; 
}
int main(){
	vector<int> p = getPrimes() ;
	int N ;
	
	while(cin >> N){
		if(N < 8){
			cout << "Impossible. \n" ;
			continue ;
		}
		for(int i=3; i>=0; i--){
			int prime = p[N - 2*i];
			cout << prime << " " ;
			N -= prime ;
		}
		cout << '\n' ;
	}
}
