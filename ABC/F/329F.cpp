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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<set<ll>> C(N, set<ll>());
    rep(i, N) {
        ll c;
        cin >> c;
        C.at(i).insert(c);
    }

    rep(i, Q) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ll A = C.at(a).size();
        ll B = C.at(b).size();
        if (A <= B) {
            for (auto e : C.at(a)) {
                C.at(b).insert(e);
            }
            C.at(a).clear();
        } else {
            for (auto e : C.at(b)) {
                C.at(a).insert(e);
            }
            C.at(b).clear();
            swap(C.at(a), C.at(b));
        }
        cout << C.at(b).size() << endl;
    }

    return 0;
}
