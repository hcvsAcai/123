#include<iostream>
#include<queue>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<stack>
#include<sstream>
#include<map>
#include<cstring>
#include<fstream>

using namespace std;
#define ll long long int
#define MAX 25
struct Node{
    int x; int y;
};
int ans[MAX];
int t,cnt;
Node dist[4] = {{-1,0},{0,1}, {1,0}, {0,-1}};
char road[MAX][MAX];
bool vis[MAX][MAX];
int Wsize, Hsize;
inline void init_road(){
    memset(vis, true, sizeof(vis));
}
void solve(){
    while (cin >> Wsize >> Hsize && Wsize && Hsize){    
        init_road();    
        queue<Node> q;
        Node start;char data_road;
        for (int i = 1; i <= Hsize; i++){
            for (int j = 1; j <= Wsize; j++){
                cin >> data_road;
                if (data_road == '@') {
                    start.x = i, start.y = j;
                    q.push(start); vis[i][j] = false;
                }
                if (data_road == '.') vis[i][j] = false;
            }
        }
        cnt = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                Node cur;
                for (int j = 0; j < 4; j++){
                    cur.x = q.front().x + dist[j].x;
                    cur.y = q.front().y + dist[j].y;
                    if (!vis[cur.x][cur.y]){
                        q.push(cur);
                        vis[cur.x][cur.y] = true;
                        cnt++;
                    }
                }
                q.pop(); 
            }
        }
        cout << cnt << endl;
    }
    
}
