#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define sc second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
const int n = 1e6;
mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
int gen(ll l,ll r){
    return g() % (r-l+1) + l;
}
void gen1(){
    fstream test;
    test.open("test_1.inp", fstream::out);
    test << n << '\n';
    for(int i = 1;i<=n;++i){
        test << i <<  ' ';
    }
    test.close();
}
void gen2(){
    fstream test;
    test.open("test_2.inp", fstream::out);
    test << n << '\n';
    for(int i = 1;i<=n;++i){
        test << n + 1 - i << ' ';
    }
    test.close();
}

void gentest(int x){

    fstream test;
    test.open(("test_" + to_string(x) +".inp").c_str(), fstream::out);
    test << n << '\n';
    for(int i = 1;i<=n;++i){
        test << fixed << setprecision(2);
        double x = gen(1,1e7);
        test << (double)(x/100) << ' ';
    }
    test.close();
}
int main(){
    for(int i = 1;i<=10;++i){
        if(i==1) gen1();
        else if(i==2) gen2();
        else gentest(i);
    }
}



