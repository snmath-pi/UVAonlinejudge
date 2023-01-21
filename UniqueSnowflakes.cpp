/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

set<int> S;
queue<int> Q;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, X;
    cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++) {
        cin >> X;
        if(S.count(X)) {
            ans = max(ans, (int)S.size());
            while(Q.front() != X) {
                S.erase(Q.front());
                Q.pop();
            }
            Q.pop();
        }
        Q.push(X);
        S.insert(X);
    }
    cout << max(ans, (int) S.size());
    
    return 0;
}
