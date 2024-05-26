#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> A;
    rep(i, N) {
        ll a;
        cin >> a;
        A.push(a);
    }
    rep(i, M) {
        ll a = A.top();
        A.pop();
        A.push(a / 2);
    }

    ll ans = 0;
    rep(i, N) {
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;

    return 0;
}
