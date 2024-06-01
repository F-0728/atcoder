#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, M;
    cin >> N >> M;
    vvll cave(N);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        cave.at(A - 1).push_back(B - 1);
        cave.at(B - 1).push_back(A - 1);
    }
    vll ans(N, -1);
    ans.at(0) = 0;
    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll current = q.front();
        q.pop();
        for (ll next : cave.at(current)) {
            if (ans.at(next) != -1) continue;
            ans.at(next) = current;
            q.push(next);
        }
    }
    Yes;
    for (ll i = 1; i < N; i++) {
        cout << ans.at(i) + 1 << endl;
    }

    return 0;
}
