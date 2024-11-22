#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> p;  // 父节点数组
    vector<int> size;  // 记录每个集合的大小（用于按秩合并）
    
public:
    // 构造函数，初始化父节点数组和集合大小
    UnionFind(int n) {
        p.resize(n + 1);  // 索引从1到n，所以需要n+1
        size.resize(n + 1, 1);  // 每个集合初始大小为1
        
        // 初始化父节点，每个节点指向自己
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }
    
    // 查找操作（路径压缩）
    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);  // 路径压缩，直接将x指向根节点
        }
        return p[x];
    }
    
    // 合并操作（按秩合并，保持树的平衡）
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // 按秩合并：将较小的集合合并到较大的集合
            if (size[rootX] < size[rootY]) {
                p[rootX] = rootY;
                size[rootY] += size[rootX];  // 更新根节点的大小
            } else {
                p[rootY] = rootX;
                size[rootX] += size[rootY];  // 更新根节点的大小
            }
        }
    }
    
    // 判断两个元素是否在同一个集合
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;  // 输入节点数和操作数
    
    UnionFind uf(n);  // 创建一个并查集实例，包含n个节点
    
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        
        if (op == 1) {
            // 合并两个节点所在的集合
            uf.unionSets(x, y);
        } else if (op == 2) {
            // 判断两个节点是否在同一个集合
            if (uf.isConnected(x, y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}
