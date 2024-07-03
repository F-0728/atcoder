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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vll Takoyaki(N);
    rep(i, N) cin >> Takoyaki.at(i);

    set<ll> s;
    s.insert(0);
    rep(i, K) {
        ll top = *s.begin();
        rep(j, N) {
            s.insert(top + Takoyaki.at(j));
        }
        s.erase(top);
    }
    cout << *s.begin() << endl;

    return 0;
}
