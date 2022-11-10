#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
ll gcd(ll a ,ll b){
	if (b == 0) return a  ;
	return (b , a%b) ;
}
ll lcm(ll a  , ll b){
	return a*( b / gcd(a , b)) ;

}
void solve(){
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr);
   	ll n , m ;
   	while(cin >> n >> m){
	
   		vector<ll> a(m) ;
   		for(int i=0; i<m; i++) cin >> a[i] ;
		ll ans = 0 ;
		for(int i=0; i<(1 << m); i++){
			ll mult = 1 , bits = 0 ;
			
			for(int j=0; j<m; j++){
				if(i & (1 <<j)){
					
					mult = lcm(mult , a[j]) ;
					++bits ;
				}
			}
			ans += (n / mult) * (bits&1?-1:1) ;
		}
		cout << n - ans << "\n";

   }



}
int main(){
	int t = 1;
	while(t--){
		solve() ;
	}
}
/*
#include<bits/stdc++.h>
using namespace std ;
#define ll long long
string s ;
int in[3] , first[3] , second[3] ;
ll r ;

bool f(ll x){
	ll need = 0 ;
	for(int i=0; i<3; i++){
		ll stuff = max(0LL , x *in[i] - first[i]) ;
		need += (stuff*second[i]) ;
	}
	return need <= r ;
}
void solve(){
	int n , r ;
	cin >> n >> r ;
	vector<int> primes ;
	for(int i=2; i * i <=n; i++){
		if(n %i ==0){
			primes.push_back(i) ;
			while(n % i == 0){
				n /= i ;
			}
		}
	}
	if(n > 1){
		primes.push_back(n) ;
	}
	int sum = 0 ;
	for(int msk = 1; msk <(1 << primes.size()); msk++){
			int mult = 1 ,
			bits = 0 ;
			for(int j=0; j<(int) primes.size(); j++){
				if(msk & (1 << j)){
					++bits ;
					mult *= primes[j] ;

				}
			}
			sum += r / mult * (bits&1?1:-1) ;
			
	}
	cout << r - sum << "\n" ;
	
}
int main(){
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	cout.tie(nullptr) ;
	int t = 1; 
	//cin >> t ;
	while(t--){
		solve() ;
	}
}
*/

