#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){if(b == 0) return a; return gcd(b, a % b);}

const int MX = 1e6 + 5;

int T, M;
long long int b[MX];

int solve(){
    bool allSame = true;
    for(int i = 1; i < M; i++) allSame &= (b[0] == b[i]);
    if(allSame) return 1;
    long long int temp = b[1] - b[0];
    for(int i = 2; i < M; i++)  temp = gcd(temp, b[i] - b[i - 1]);
    int ret = 0;
    for(long long int i = 1; i * i <= temp; i++){
        if(i * i == temp) ret++;
        else if(temp % i == 0) ret += 2;
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    for(int rep = 1; rep <= T; rep++){
        scanf("%d", &M);
        for(int i = 0; i < M; i++) scanf("%lld", &b[i]);
        printf("Case #%d\n%d\n", rep, solve());
    }
}
