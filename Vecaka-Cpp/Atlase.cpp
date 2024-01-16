/******************************
LIO 2024 novada posma vecakas grupas uzdevuma "Kandidatu atlase" risinajums


Ideja: priority queue. Glabajam (-1)*ielasita vertiba. Lielako (pec abs mazako) vertibu aizstajam,
ja jau ir K uzaicinati ar atnakuso. Ta turpina, lidz beigam.
*******************************/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> atb;
priority_queue<ll> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll K, M, N;
    cin >> K >> M >> N;
    for(ll i=0; i<N; ++i) {
        ll sk;
        cin >> sk;
        if(sk>=M) {
            sk*=-1;
            if(q.size()==K && q.top()>sk) {
                q.pop();
                q.push(sk);
                atb.push_back(sk);
            }
            else if(q.size()!=K) {
                q.push(sk);
                atb.push_back(sk);
            }
        }
    }
    cout << atb.size() << "\n";
    for(auto i:atb) {
        cout << (i)*(-1) << " ";
    }
    return 0;
}
