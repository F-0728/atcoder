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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        a--;
        A.at(i) = a;
    }
    vll W(N);
    rep(i, N) {
        cin >> W.at(i);
    }
    vll count(N, 0);
    rep(i, N) {
        count.at(A.at(i))++;
    }
    vpll bag(N);
    rep(i, N) {
        bag.at(i) = {W.at(i), A.at(i)};
    }
    ll emp = 0;
    rep(i, N) {
        if (count.at(i) == 0) {
            emp++;
        }
    }
    sort(bag.begin(), bag.end());
    ll ans = 0;
    while (emp > 0) {
        rep(i, N) {
            if (count.at(bag.at(i).second) > 1) {
                count.at(bag.at(i).second)--;
                emp--;
                ans += bag.at(i).first;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
