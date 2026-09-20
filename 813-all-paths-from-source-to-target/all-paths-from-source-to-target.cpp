class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<vector<int>>> memo;
        return dfs(0, n - 1, graph, memo);
    }

private:
    vector<vector<int>> dfs(int curr, int target, vector<vector<int>>& graph, unordered_map<int, vector<vector<int>>>& memo) {
        
        if (curr == target) {
            return {{target}};
        }
        
        
        if (memo.find(curr) != memo.end()) {
            return memo[curr];
        }
        
        vector<vector<int>> allPaths;
        
        
        for (int nextNode : graph[curr]) {
            vector<vector<int>> pathsFromNext = dfs(nextNode, target, graph, memo);
            for (auto path : pathsFromNext) {
                vector<int> currentPath = {curr};
                currentPath.insert(currentPath.end(), path.begin(), path.end());
                allPaths.push_back(currentPath);
            }
        }
        
        return memo[curr] = allPaths;
    }
};