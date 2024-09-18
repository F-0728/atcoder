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
    string S;
    cin >> S;
    ll N = S.size();
    if (N == 1) {
        cout << S << endl;
        return 0;
    }
    vvll bitSearch;
    rep(i, 1 << (N - 1)){
        vll bit(N - 1);
        rep(j, N - 1){
            if (i >> j & 1){
                bit[j] = 1;
            }
        }
        bitSearch.push_back(bit);
    }

    ll ans = 0;
    for (vll b : bitSearch) {
        vll nums;
        ll num = 0;
        rep(i, N) {
            num *= 10;
            num += S[i] - '0';
            if (b[i]) {
                nums.push_back(num);
                num = 0;
            }
        }
        nums.push_back(num);
        ll sum = 0;
        for (ll n : nums) {
            sum += n;
        }
        ans += sum;
    }

    cout << ans << endl;

    return 0;
}
