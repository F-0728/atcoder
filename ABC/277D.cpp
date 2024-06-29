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
    ll N, M;
    cin >> N >> M;
    vll cards;
    ll sum = 0;
    rep(i, N) {
        ll a;
        cin >> a;
        cards.push_back(a);
    }
    sort(cards.begin(), cards.end());
    rep(i, N) {
        sum += cards.at(i);
    }
    ll ans = 0;
    ll current = cards.at(0);
    ll streak = 1;
    rep(i, N - 1) {
        if (cards.at(i + 1) - cards.at(i) == 1) {
            current += cards.at(i + 1);
            streak++;
        } else if (cards.at(i + 1) == cards.at(i)) {
            current += cards.at(i + 1);
            streak++;
        } else { 
            ans = max(ans, current);
            current = cards.at(i + 1);
            streak = 1;
        }
    }
    if (cards.at(N - 1) == M - 1 && cards.at(0) == 0 && streak != N) {
        rep(i, N - 1) {
            if (cards.at(i + 1) - cards.at(i) == 1) {
                current += cards.at(i + 1);
            } else if (cards.at(i + 1) == cards.at(i)) {
                current += cards.at(i + 1);
            } else { 
                ans = max(ans, current);
                break;
            }
        }
    }
    ans = max(ans, current);
    cout << sum - ans << endl;


    return 0;
}
