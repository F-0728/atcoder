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
    ll N, K, P;
    cin >> N >> K >> P;
    vll price_forward(N / 2);
    vll price_backward(N - N / 2);
    rep(i, N / 2){
        cin >> price_forward.at(i);
    }
    rep(i, N - N / 2){
        cin >> price_backward.at(i);
    }
    vvll bitSearch_forward;
    rep(i, 1 << price_forward.size()) {
        vll bit;
        rep(j, price_forward.size()) {
            if(i >> j & 1){
                bit.push_back(j);
            }
        }
        bitSearch_forward.push_back(bit);
    }
    vvll bitSearch_backward;
    rep(i, 1 << price_backward.size()) {
        vll bit;
        rep(j, price_backward.size()) {
            if(i >> j & 1){
                bit.push_back(j);
            }
        }
        bitSearch_backward.push_back(bit);
    }

    vvll forward(K + 1);
    vvll backward(K + 1);
    rep(i, bitSearch_forward.size()){
        ll sum = 0;
        if (bitSearch_forward.at(i).size() > K) {
            continue;
        }
        rep(j, bitSearch_forward.at(i).size()){
            sum += price_forward.at(bitSearch_forward.at(i).at(j));
        }
        forward.at(bitSearch_forward.at(i).size()).push_back(sum);
    }

    rep(i, bitSearch_backward.size()){
        ll sum = 0;
        if (bitSearch_backward.at(i).size() > K) {
            continue;
        }
        rep(j, bitSearch_backward.at(i).size()){
            sum += price_backward.at(bitSearch_backward.at(i).at(j));
        }
        backward.at(bitSearch_backward.at(i).size()).push_back(sum);
    }

    rep(i, K + 1){
        sort(forward.at(i).begin(), forward.at(i).end());
        sort(backward.at(i).begin(), backward.at(i).end());
    }
    ll ans = 0;
    rep(i, K + 1){
        rep(j, forward.at(i).size()){
            ll sum = forward.at(i).at(j);
            ll cnt = upper_bound(backward.at(K - i).begin(), backward.at(K - i).end(), P - sum) - backward.at(K - i).begin();
            ans += cnt;
        }
    }
    cout << ans << endl;

    return 0;
}
