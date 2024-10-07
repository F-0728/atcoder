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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    rep(i, N) cin >> A[i];
    reverse(A.begin(), A.end());

    vll count(N);

    vpll stack;
    rep(i, N) {
        if (A[i] == 1) {
            ll next = 2;
            while (!stack.empty() && stack.back().first == next) {
                stack.pop_back();
                next++;
            }
            if (stack.empty()) {
                count[i] = i + 1;
            } else {
                count[i] = i - stack.back().second;
            }
        } else {
            stack.push_back({A[i], i});
        }
        // cout << "i: " << i << endl;
        // rep(j, stack.size()) {
        //     cout << stack[j].first << " " << stack[j].second << endl;
        // }
        // count[i] = i - stack.back().second + 1;
    }

    reverse(count.begin(), count.end());

    ll ans = 0;
    rep(i, N) {
        ans += count[i];
    }

    // outv(count);

    cout << ans << endl;


    return 0;
}
