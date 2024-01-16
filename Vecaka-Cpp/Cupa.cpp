/******************
LIO 2024 novada posma vecakas grupas uzdevuma "Skaitlu cupa" risinajums


Ideja - ielasitas skaitlu vertibas aizstaj pec (mod M)[atlikuma dalot ar M].
Ta ka M<=1e9, tad atlikumi ari ir <=1e9 - tos masiva nevares saglabat.
Izmantojam map<long long, long long>, kas glabas skaitlu vertibas un daudzuma parus {atlikuma vertiba, daudzums}

Lai skaitlu para summa dalitos ar M, to atlikumu summai jadalas ar M. Tatad
atlikums i bus pari ar atlikumu (M-i), bet atlikumi 0 veidos parus pasi ar sevi.
Ja M = 0 (mod 2), tad bus ari kâda videja vertiba. Lai izvairitos no kludam, aplukosim so vertibu
atseviski, tas ir, skaitli ar vertibu (M/2) veidos parus tikai pasi ar sevi jeb paru daudzums bus (daudzums/2).

Atlikumus [i un (M-i)] glabasim pie i daudzuma. Ja i<=(M/2), daudzumu palielinasim par ielasito
vertibu, bet, ja i>(M/2), tad atnemsim. Ta uzreiz varesim iegut ari izveidotos parus, lai nebutu velreiz
jaapluko saglabatas vertibas.
Izveidoto paru skaits palielinasies tikai tad, ja jau daudzums no {atl.vert, daudz.} bus ar preteju zimi neka
tiks pieskaitis/atnemts. Paru skaits bus min(abs(daudzums),dz) [deretu sevi parliecinat, ka ta ir].

Beigas atliks pieskaitit parus, kurus var izveidot no elementiem, kuri dod atlikumu 0 un (M/2).

Piemers.
10 10   | N=10; M=10
32 23   | 32 = 2(mod M) -> 2<=M/2 -> map pievieno {2,23}
11 34   | 11 = 1(mod M) -> 1<=M/2 -> map pievieno {1,34}
25 45   | 25 = 5(mod M) -> 5<=M/2 -> map pievieno {5,45}
14 56   | 14 = 4(mod M) -> 4<=M/2 -> map pievieno {4,56}
33 67   | 33 = 3(mod M) -> 3<=M/2 -> map pievieno {3,67}
97 78   | 97 = 7(mod M) -> 7>M/2  -> (M-7)=3 -> map no {3,67} atnem 78; atbildei pieskaita min(67,78)=67 -> {3,-11}
35 89   | 35 = 5(mod M) -> 5<=M/2 -> map pieskaita 89 -> {5,134}
21 91   | 21 = 1(mod M) -> 1<=M/2 -> map pieskaita 91 -> {1,125}
31 1    | 31 = 1(mod M) -> 1<=M/2 -> map pieskaita 1  -> {1,126}
16 12   | 16 = 6(mod M) -> 6>M/2  -> (M-6)=4 -> map no {4,56} atnem 12; atbildei pieskaita min(56,12)=12 -> {4,44}

Beigas ir 0 skaitlu ar atlikumu 0, tadel atbilde += 0.
Ir 134 skaitli ar atlikumu (M/2) [dati {5,134}], tadel atbildei += 134/2 jeb atbilde += 67

atbilde = 67 + 12 + 67 = 146
*******************/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll,ll> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, answer=0;
    cin >> N >> M;
    for(ll i=0; i<N; ++i) {
        ll num, dz;
        cin >> num >> dz; num%=M;
        auto sch = mp.find(num), sch2 = mp.find(M-num);                             // Noskaidrojam vai sis atlikuma vertibas ir jau map
        if(sch!=mp.end()) {                                                         // Ja num<=M/2 un ir
            if((*sch).second<0) answer+=min(abs((*sch).second),dz);
            (*sch).second += dz;
        }
        else if(sch2!=mp.end()) {                                                   // Ja num>M/2 un ir
            if((*sch2).second>0) answer+=min(abs((*sch2).second),dz);
            (*sch2).second -= dz;
        }
        else if(num>M/2)                                                             // Ja num>M/2 un nav
            mp.insert({M-num, (-1)*dz});
        else                                                                        // Ja num<=M/2 un nav
            mp.insert({num, dz});
    }

    auto f1=mp.find(0); if(f1!=mp.end()) answer+=((*f1).second)/2;                     // Noskaidrojam vai (mod M) = 0 ir kada vertiba. Ja ir, pieskaitâm pie "answer"
    if(M%2==0) {auto f2 = mp.find(M/2); if(f2!=mp.end()) answer+=((*f2).second)/2;}    // Noskaidrojam vai (mod M) = M/2 ir kâda vertîba; ja ir, pieskaitâm pie "answer"

    cout << answer;
    return 0;
}
