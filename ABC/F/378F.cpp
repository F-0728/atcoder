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
    vvll G(N);
    rep(i, N - 1) {
        ll A, B;
        cin >> A >> B;
        A--, B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }
    set<ll> count3;
    rep(i, N) {
        if (G.at(i).size() == 3) {
            count3.insert(i);
        }
    }

    if (count3.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    while (count3.size() > 0) {
        ll start = *count3.begin();
        ll count = 0;
        queue<pll> q;
        q.push({start, -1});
        while (!q.empty()) {
            auto [now, p] = q.front();
            q.pop();
            if (G.at(now).size() != 2 && G.at(now).size() != 3) continue;
            if (G.at(now).size() == 2) {
                count++;
            } else {
                count3.erase(now);
                for (auto next : G.at(now)) {
                    if (next == p) continue;
                    q.push({next, now});
                }
            }
        }
        ans += count * (count - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
