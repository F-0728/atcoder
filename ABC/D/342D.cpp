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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vll squares(1e3);
    rep(i, 1e3) squares.at(i) = i * i;
    ll count = 0;

    vll B(N);
    rep(i, N) {
        if (A.at(i) > 0) {
            for (ll j = 1e3 - 1; j >= 0; j--) {
                if (A.at(i) % squares.at(j) == 0) {
                    B.at(i) = A.at(i) / squares.at(j);
                    break;
                }
            }
        } else {
            B.at(i) = 0;
        }
    }
    map<ll, ll> mp;
    rep(i, N) {
        if (mp.count(B.at(i))) {
            mp.at(B.at(i))++;
        } else {
            mp[B.at(i)] = 1;
        }
    }
    for (auto p : mp) {
        if (p.first == 0) continue;
        count += p.second * (p.second - 1) / 2;
    }
    count += mp[0] * (N - 1);
    count -= mp[0] * (mp[0] - 1) / 2;

    cout << count << endl;

    return 0;
}
