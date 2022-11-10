#include<iostream>
#include<vector>
using namespace std ;
const int mxN = 18409202 ;
const int mxX = 1e5 ;
int main(){
	vector<bool> primes(mxN , true) ;
	vector<pair<int,int>> p(mxX +1) ;

	int pos = 1 ;
	int prev = 0 ;
	for(long long i = 3; pos<= mxX; i+=2){
		if(primes[i] == true){
			for(long long j= i * i; j <= mxN; j += i){
				primes[j] = false ;
			}

		}
		if( i == prev + 2 && primes[prev] && primes[i]){
			p[pos].first = prev ; 
			p[pos].second = i;
			pos ++ ;
		}
		prev = i ;
	}
	int s ;
	while(cin >> s){
		printf("(%d, %d)\n" , p[s].first ,p[s].second) ;
	}
}
