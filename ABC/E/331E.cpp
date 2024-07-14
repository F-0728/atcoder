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
    ll N, M, L;
    cin >> N >> M >> L;
    vll A(N), B(M);
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> B.at(i);
    set<pll> CD;
    rep(i, L) {
        ll C, D;
        cin >> C >> D;
        C--;
        D--;
        CD.insert({C, D});
    }

    vector<int> ord_b(M);
    for (int i = 0; i < M; i++) ord_b[i] = i;
    sort(begin(ord_b), end(ord_b), [&](int i, int j) { return B[i] > B[j]; });
    
    priority_queue<pll> pq;
    vll idx(N, 0);
    rep(i, N) {
        pq.push({A.at(i) + B.at(ord_b.at(0)), i});
    }
    while (!pq.empty()) {
        auto [sum, i] = pq.top();
        pq.pop();
        // cout << sum << " " << i << " " << ord_b.at(idx.at(i)) << endl;
        if (CD.count({i, ord_b.at(idx.at(i))}) == 0) {
            cout << sum << endl;
            return 0;
        }
        idx.at(i)++;
        if (idx.at(i) < M) {
            pq.push({A.at(i) + B.at(ord_b.at(idx.at(i))), i});
        }
    }

    return 0;
}
