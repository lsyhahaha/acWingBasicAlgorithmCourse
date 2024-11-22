#include<bits/stdc++.h>

using namespace std;

const int N = 100;

int n;

// 朴素版本的Dijkstra算法
int g[N][N]; // 存储每一条边
int dist[N]; // 存储1号节点到每一个点的最短距离
bool st[N]; // 存储每个节点的最短路是否已经确定

// 求1号到n号节点的最短路，如果不存在则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++) {

        int t = -1; // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                // 条件说明：①该节点的最短路还未确定； ②如果i到t的距离比i到j的距离大  则 t = j
                t = j;
            }
        } // end for 此时t是在所有为确定最短路的点集中，到i节点距离最短的节点

        // 用t更新其他节点的距离(其他点的已经确定最短的的点集的距离)
        for (int j = 1; j <= n; j ++ ) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        } 

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f) return -1;
    return dist[n];
}











// 记录最短路径版本的dijkstra算法
int g[N][N]; // 存储每一条边
int dist[N]; // 存储1号节点到每一个点的最短距离
bool st[N]; // 存储每个节点的最短路是否已经确定
int pre[N]; // 记录每个节点的前驱节点，用于恢复最短路径
// 求1号到n号节点的最短路，如果不存在则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(pre, -1, sizeof pre); // 初始化前驱节点数组
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        int t = -1; // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        // 更新其他节点的距离
        for (int j = 1; j <= n; j++) {
            if (g[t][j] != 0 && dist[t] + g[t][j] < dist[j]) {
                dist[j] = dist[t] + g[t][j];
                pre[j] = t; // 记录路径
            }
        }

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f) return -1; // 如果无法到达n号节点，返回-1

    // 恢复路径
    vector<int> path;
    for (int i = n; i != -1; i = pre[i]) {
        path.push_back(i); // 从终点回溯到起点
    }
    reverse(path.begin(), path.end()); // 反转路径
    // 输出路径
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    return dist[n]; // 返回最短路径的长度
}