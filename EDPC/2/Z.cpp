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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

//f[j](x) = a[j]x + b[j]でaがjの増加に伴い単調減少する場合
//クエリのxが単調でない場合はコメントアウトしたにぶたんの方を用いる
template<typename T> class CHT
{
private:
    using ptt = pair<T, T>;
    bool check(ptt l1, ptt l2, ptt l3){
        return (l2.first-l1.first)*(l3.second-l2.second)>=(l2.second-l1.second)*(l3.first-l2.first);
    }
    T f(int i, T x){
        return lines[i].first * x + lines[i].second;
    }
public:
    vector<ptt> lines;
    int head;
    CHT(): head(0){};
    void add(T a, T b){
        ptt line(a, b);
        while((int)lines.size() - head >= 2 && check(*(lines.end()-2), lines.back(), line)){
            lines.pop_back();
        }
        lines.emplace_back(line);
    }
    T get(T x){
        while((int)lines.size() - head >= 2 && f(head, x) >= f(head + 1, x)){
            head++;
        }
        return f(head, x);
        // int low = -1, high = lines.size() - 1;
        // while (high - low > 1) {
        // 	int mid = (high + low) / 2;
        //     if(f(mid, x) >= f(mid+1, x)){
        //         low = mid;
        //     }else{
        //         high = mid;
        //     }
        // }
        // return f(high, x);
    }
};


int main() {
    ll N, C;
    cin >> N >> C;
    vll h(N);
    rep(i, N) cin >> h[i];

    vll dp(N, INF);
    dp[0] = 0;
    CHT<ll> cht;
    rep(i, N - 1) {
        cht.add(-2 * h[i], dp[i] + h[i] * h[i]);
        dp[i + 1] = cht.get(h[i + 1]) + h[i + 1] * h[i + 1] + C;
    }

    cout << dp[N - 1] << endl;


    return 0;
}
