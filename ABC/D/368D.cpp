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

vvll G;
vector<bool> terminal;
vll chosen;
ll start = 0;
void selected(ll x, ll prev) {

    // cout << x << endl;
    // terminal
    if (terminal.at(x)) chosen.at(x) = 1;

    // leaf
    if (G.at(x).size() == 1 && x != start) {
        chosen.at(x) = terminal.at(x) ? 1 : 0;
    }

    for (ll p : G.at(x)) {
        if (p == x) continue;
        if (p == prev) continue;
        if (chosen.at(p) == -1) {
            selected(p, x);
        }
        if (chosen.at(p) == 1) {
            chosen.at(x) = 1;
        }
    }

}

int main() {
    ll N, K;
    cin >> N >> K;
    G.resize(N);
    rep(i, N - 1) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }
    terminal.resize(N, false);
    rep(i, K) {
        ll V;
        cin >> V;
        V--;
        terminal.at(V) = true;
    }

    chosen.resize(N, -1);
    while (terminal.at(start) == false) {
        start++;
    }
    // cout << start << endl;
    selected(start, -1);
    // outv(chosen);

    ll ans = 0;
    rep(i, N) {
        if (chosen.at(i) == 1) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
