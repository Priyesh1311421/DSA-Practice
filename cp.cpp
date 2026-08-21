#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        ll a, b, x;
        cin >> a >> b>> x;
        vector<ll> upper, lower;
        for(ll i = a; ; i/= x){
            upper.push_back(i);
            if(i ==0) break;
        }
        for(ll i = b; ; i/= x){
            lower.push_back(i);
            if(i== 0) break;
        }

        ll ans = (1LL << 62);

        for(int i = 0; i < (int)upper.size(); ++i){
            for(int j = 0; j < (int)lower.size(); ++j){
                ll d = upper[i] - lower[j];
                if(d < 0) d = -d;
                ans = min(ans, 1LL * i + j + d);

            }
        }
        cout<<ans<<endl;
    }

    return 0;
}