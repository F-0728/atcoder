#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll ans(N, 0);
    vll lastAdded(N, -1);
    set<ll> s;
    vll size(Q + 1, 0);
    vll sizeCSum(Q + 1, 0);

    rep(i, Q) {
        ll x;
        cin >> x;
        x--;
        if (s.count(x)) {
            s.erase(x);
            size.at(i + 1) = size.at(i) - 1;
            sizeCSum.at(i + 1) = sizeCSum.at(i) + size.at(i + 1);
            ans[x] += sizeCSum.at(i) - sizeCSum.at(lastAdded.at(x));
        } else {
            s.insert(x);
            lastAdded.at(x) = i;
            size.at(i + 1) = size.at(i) + 1;
            sizeCSum.at(i + 1) = sizeCSum.at(i) + size.at(i + 1);
        }
    }
    // outv(sizeCSum);
    for (auto x : s) {
        ans[x] += sizeCSum.at(Q) - sizeCSum.at(lastAdded.at(x));
    }

    outv(ans);

    return 0;
}
