#include <bits/stdc++.h>

using namespace std;

const int MX = 4097;

vector <pair<long long int, long long int> > v1, v2;
int N, node[MX];
long  long int X1, Y1, X2, Y2, Answer;

void Update(int L , int R){
    R++;
    while(L < MX) node[L]++, L += L & -L;
    while(R < MX) node[R]--, R += R & -R;
}

int Query(int i){
    int ret = 0;
    while(i) ret += node[i], i -= i & -i;
    return ret;
}

bool able(vector <pair<long long int, long long int> > &v, long long int d){
    memset(node, 0, sizeof(node));
    map <long long  int, int> comp;
    for(auto p : v) comp.insert({p.first - d, 0}), comp.insert({p.second - d , 0}), comp.insert({p.first + d , 0}), comp.insert({p.second + d,  0});
    comp.insert({LONG_LONG_MAX, 0});
    int cnt = 1;
    for(auto it = comp.begin(); it != comp.end(); it++) it->second = cnt++;
    for(auto p : v){
        pair <int, int> r1 = {comp[p.first - d], comp[p.first + d]}, r2 = {comp[p.second - d], comp[p.second + d]};
        if(r1.second >= r2.first) Update(r1.first, r2.second);
        else Update(r1.first, r1.second), Update(r2.first, r2.second);
    }
    for(int i = 1; i <= (int)comp.size(); i++) if(Query(i) == N) return true;
    return false;
}

long long int solve(vector <pair<long long int, long long int> > &v){
    long long int p1 = 0, p2 = INT_MAX;
    while(p1 < p2){
        long long int mid = (p1 + p2) >> 1;
        if(able(v, mid)) p2 = mid;
        else p1 = mid + 1;
    }
    return p1;
}

int main(int argc, char** argv){
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++){
		Answer = 0;
		v1.clear(), v2.clear();
		cin >> N;
		for(int i = 0; i < N; i++){
            cin >> X1 >> Y1 >> X2 >> Y2;
            X1 *= 2, Y1 *= 2, X2 *= 2, Y2 *= 2;
            if(X1 > X2) swap(X1, X2);
            if(Y1 > Y2) swap(Y1, Y2);
            v1.push_back({X1, X2});
            v2.push_back({Y1, Y2});
		}
		Answer = max(solve(v1), solve(v2));
		cout << "Case #" << test_case+1 << endl;
		cout << Answer / 2;
		if(Answer & 1) cout << ".5";
		cout << endl;
	}

	return 0;
}
