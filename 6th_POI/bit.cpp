#include <bits/stdc++.h>
using namespace std;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
bool a[202][202];
int ans[202][202];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            a[i][j] = c - '0'; 
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j]){
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m){
                if (!a[nx][ny]){
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                    a[nx][ny] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << ans[i][j];
            if(j != m)
            {
                cout << ' ';
            }
			// output format for old task archive
        }
    }
}