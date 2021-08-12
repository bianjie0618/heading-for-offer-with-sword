// 省份数量
// 并查集 算法
#include <vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> unionSet(isConnected.size());
        init(unionSet);
        int len1 = isConnected.size();
        int len2 = len1;
        for (int i = 0; i < len1; ++i ) {
            for (int j = i + 1; j < len2; ++j) {
                if (isConnected[i][j] == 1)
                    doUnion(unionSet, j, i);
            }
        }
        return countIslated(unionSet);
    }

private:
    void init(vector<int>& unionSet) {
        for(int i = 0; i < unionSet.size(); ++i) {
            unionSet[i] = i;
        }

    }

    int countIslated(vector<int>& unionSet) {
        int count = 0;
        int len = unionSet.size();
        for ( int i = 0; i < len; ++i ) {
            if (unionSet[i] == i) {
                count++;
            }
        }
        return count;
    }

    int find(vector<int>& unionSet, int key) {
        while (unionSet[key] != key) {
            key = unionSet[key];
        }
        return key;
    }

    void doUnion(vector<int>& unionSet, int x, int y) {
        int root = find(unionSet, y);
        while (unionSet[x] != root) {
            int key = unionSet[x];
            unionSet[x]  =root;
            x = key;
        }
        
    }
};