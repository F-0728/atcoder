#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll n, q;
    cin >> n >> q;
    deque<ll> a(n);

    rep(i, n) cin >> a[i];
    rep(i, q) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            swap(a[x - 1], a[y - 1]);
        } else if (t == 2) {
            ll tmp = a.back();
            a.pop_back();
            a.push_front(tmp);
        } else {
            cout << a[x - 1] << endl;
        }
    }
    return 0;
}
