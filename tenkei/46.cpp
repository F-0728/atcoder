#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    unordered_map<ll, ll> A;
    unordered_map<ll, ll> B;
    unordered_map<ll, ll> C;
    rep(i, 46) {
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
    ll N;
    cin >> N;
    rep(i, N) {
        ll a;
        cin >> a;
        A[a % 46]++;
    }
    rep(i, N) {
        ll b;
        cin >> b;
        B[b % 46]++;
    }
    rep(i, N) {
        ll c;
        cin >> c;
        C[c % 46]++;
    }

    ll ans = 0;
    rep(i, 46) {
        rep(j, 46) {
            ll k = ((46 - i - j) % 46 + 46) % 46;
            ans += A[i] * B[j] * C[k];
        }
    }
    cout << ans << endl;

    return 0;
}
