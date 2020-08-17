#include <bits/stdc++.h>

using namespace std;

int T, N;

int solve(){
    if(N == 1) return 2;
    if(N == 2) return 3;
    //ab + a = n;
    int ret = N - 1, MAX = sqrt(N);
    for(int a = 2; a <= MAX; a++){
        if(N % a) continue;
        int b = N / a - 1;
        if(b <= a) continue;
        ret = b;
    }
    for(int b = 2; b <= MAX; b++){
        int temp = N, mem = -1;
        bool same = true;
        while(temp){
            if(mem == -1) mem = temp % b;
            else if(mem != temp % b) same = false;
            temp /= b;
        }
        if(same){ret = b; break;}
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    for(int rep = 1; rep <= T; rep++){
        scanf("%d", &N);
        printf("Case #%d\n%d\n", rep, solve());
    }
}
