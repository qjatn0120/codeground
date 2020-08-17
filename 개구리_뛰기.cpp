#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;
int N, a[MX], K, T;

int solve(){
    int ret = 0, pos = 0;
    while(1){
        int next = upper_bound(a, a + N + 1, a[pos] + K) - a - 1;
        ret++;
        if(pos == next) return -1;
        if(next == N) return ret;
        pos = next;
    }
}

int main(){
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(int rep = 1; rep <= T; rep++){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
        scanf("%d", &K);
        printf("Case #%d\n", rep);
        printf("%d\n", solve());
    }
}
