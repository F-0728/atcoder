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

vector<ll> divisors(ll x) {
    vector<ll> divs;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vll grundy(1e5 + 5);
    grundy.at(0) = 0;
    grundy.at(1) = 0;
    for (ll i = 2; i <= 1e5; i++) {
        set<ll> s;
        vll divs = divisors(i);
        for (ll d : divs) {
            if (d == i) continue;
            s.insert(grundy.at(d));
        }
        ll g = 0;
        while (s.count(g)) g++;
        grundy.at(i) = g;
    }

    ll ans = 0;
    for (ll a : A) {
        ans ^= grundy.at(a);
    }
    if (ans == 0) {
        cout << "Bruno" << endl;
    } else {
        cout << "Anna" << endl;
    }


    return 0;
}
