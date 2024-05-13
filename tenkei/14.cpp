#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() { 
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<ll> B(N);
    rep(i, N) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0;
    rep(i, N) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;
    

    return 0;
}
