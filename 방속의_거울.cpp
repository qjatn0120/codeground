#include <bits/stdc++.h>

using namespace std;

const int MX = 1005;
const int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
int T, N, arr[MX][MX], hit[MX][MX];

int solve(){
    int px = 0, py = 1, dir = 0;
    while(1){
        if(arr[px][py] == 1){
            int next_dir[4] = {3, 2, 1, 0};
            dir = next_dir[dir];
            hit[px][py] = true;
        }else if(arr[px][py] == 2){
            int next_dir[4] = {1, 0, 3, 2};
            dir = next_dir[dir];
            hit[px][py] = true;
        }
        px += dir_x[dir], py += dir_y[dir];
        if(px <= 0 || px > N || py <= 0 || py > N) break;
    }
    int ret = 0;
    for(int j = 1; j <= N; j++)
    for(int i = 1; i <= N; i++) ret += hit[i][j];
     return ret;
}

int main(){
    scanf("%d", &T);
    for(int rep = 1; rep <= T; rep++){
        scanf("%d", &N);
        for(int j = 1; j <= N; j++)
        for(int i = 1; i <= N; i++) scanf("%01d", &arr[i][j]), hit[i][j] = false;
        printf("Case #%d\n%d\n", rep, solve());
    }
}
