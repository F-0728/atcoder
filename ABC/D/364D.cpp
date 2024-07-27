#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace atcoder;

using ll = long long;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>

int main() {
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    vector<pll> query(Q);
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        query.at(i) = make_pair(x, y);
    }

    vll ans(Q);
    rep(i, Q) {
        ll b = query.at(i).first;
        ll k = query.