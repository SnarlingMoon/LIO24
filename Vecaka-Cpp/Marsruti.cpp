/******************************
LIO 2024 novada posma vecakas grupas uzdevuma "Vilcienu marsruti" risinajums


Ideja: veidosim grafu. Uzdevuma teikts, ka no jebkuras virsotnes var nonakt uz
jebkuru citu un ir tikai viens cels, kas savieno divas virsotnes <- japatur prata,
jo bus butiski risinajuma.

Izgriezisim virsotni 1 no grafa, t.i., ignoresim visas ievaditos celus, kuru kada no virsotnem ir 1.
Tad no si un iepriekseja fakta varam secinat, ka celam starp divam virsotnem ir jaiet
caur virsotni 1, ja tagad vairs nevares izveidot marsrutu starp sim divam virsotnem a un b.
Ja to joprojam vares izdarit, tad virsotne 1 netiek apmekleta ejot so marsrutu.

Risinajuma palenam apvienojam grafus ar virsotnem, saglabajot katras virsotnes "vecaku".
Ja abam virsotnem vecaks ir viens un tas pats, tad virsotne 1 nav ieklauta marsruta, bet
ja divi dazadi, tad ir [tiek izmantots "Disjoint Set Union"].
*******************************/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> v;

class DSU {                                                            // Estetikai lietosu class
public:
    v prnt, rng;                                                        // prnt - glaba i-ta elementa "vecaku";
    DSU(ll N) {                                                         //      rng - glaba konkreta grafa dalas "lielumu"/rangu
        prnt.assign(N, 0); rng.assign(N, 0);
        for(int i=0; i<N; ++i) prnt[i]=i;
    }

    ll findPrnt(ll a) {return (prnt[a]==a) ? a : prnt[a]=findPrnt(prnt[a]);}    // Atrod elementa a "vecaku"
    bool samePrnt(ll a, ll b) {return findPrnt(a)==findPrnt(b);}                // Salidzina, vai a un b elementu "vecaki" ir vienadi

    void join(ll a, ll b) {                                             // Apvieno grafus
        if(samePrnt(a,b)) return;                                       // Neko nedara, jo a un b jau ir viena grafa
        ll x=findPrnt(prnt[a]), y=findPrnt(prnt[b]);
        if(rng[x]<rng[y]) swap(x,y);
        if(rng[x]==rng[y]) ++rng[x];
        prnt[y]=prnt[x];
        return;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    v answ;
    ll N, M;
    cin >> N >> M;
    DSU V(N);
    for(ll i=0; i<N-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;                                                       // Visu laiku -1, jo pozicijas skaitam sakot ar 0 nevis 1 ka dots uzdevuma
        if(a!=0 && b!=0) V.join(a,b);
    }
    for(ll i=0; i<M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        if(V.samePrnt(V.prnt[a],V.prnt[b])) answ.push_back(0);
        else answ.push_back(1);
    }
    for(auto i:answ)
        cout << i << "\n";
    return 0;
}
