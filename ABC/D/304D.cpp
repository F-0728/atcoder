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
    ll W, H;
    cin >> W >> H;
    ll N;
    cin >> N;
    vpll strawberry(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        strawberry[i] = {x, y};
    }
    ll A, B;
    cin >> A;
    vll a(A + 1);
    rep(i, A) {
        cin >> a.at(i);
    }
    a.at(A) = W;
    cin >> B;
    vll b(B + 1);
    rep(i, B) {
        cin >> b.at(i);
    }
    b.at(B) = H;
    map<pll, ll> mp;
    rep(i, N) {
        ll x = strawberry.at(i).first;
        ll y = strawberry.at(i).second;
        ll xIdx = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll yIdx = lower_bound(b.begin(), b.end(), y) - b.begin();
        mp[{xIdx, yIdx}]++;
    }
    ll m = INF;
    ll M = 0;
    ll sum = 0;
    for (auto [key, value] : mp) {
        m = min(m, value);
        M = max(M, value);
        sum++;
    }
    if (sum < (A + 1) * (B + 1)) {
        m = 0;
    }
    cout << m << " " << M << endl;

    return 0;
}

