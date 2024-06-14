#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll Q;
    cin >> Q;
    priority_queue<ll, vll, greater<ll>> sorted;
    queue<ll> back;
    rep(i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll x;
            cin >> x;
            back.push(x);
        }
        if (q == 2) {
            if (sorted.empty()) {
                cout << back.front() << endl;
                back.pop();
            } else {
                cout << sorted.top() << endl;
                sorted.pop();
            }
        }
        if (q == 3) {
            while (!back.empty()) {
                sorted.push(back.front());
                back.pop();
            }
        }
    }

    return 0;
}
