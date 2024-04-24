#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> scores;
    rep(i, n) {
        ll A, B;
        cin >> A >> B;
        scores.push_back(B);
        scores.push_back(A - B);
    }
    ll ans = 0;
    sort(scores.rbegin(), scores.rend());
    rep(i, k) { ans += scores[i]; }
    cout << ans << endl;
    
    
    return 0;
}
