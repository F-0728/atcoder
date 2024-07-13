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
    vll A(N);
    rep(i, N) cin >> A.at(i);
    vll count(N + 1, 0);
    rep(i, N) {
        if (A.at(i) > N) {
            count.at(N)++;
        } else {
            count.at(A.at(i))++;
        }
    }
    set<ll> s;
    rep(i, N + 1) {
        if (count.at(i) == 0) {
            s.insert(i);
        }
    }
    rep(i, Q) {
        ll it, xt;
        cin >> it >> xt;
        it--;
        ll target = min(A.at(it), N);
        if (count.at(target) == 1) {
            s.insert(target);
        } 
        count.at(target)--;
        A.at(it) = xt;
        target = min(A.at(it), N);
        if (count.at(target) == 0) {
            s.erase(target);
        }
        count.at(target)++;
        cout << *s.begin() << endl;
    }
    

    return 0;
}
