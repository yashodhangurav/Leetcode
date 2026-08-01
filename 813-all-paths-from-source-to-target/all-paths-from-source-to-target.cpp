class Solution {
public:

    void dfs(int node, vector<vector<int>>& graph, 
             vector<int>& path, vector<vector<int>>& result) {

        // if reached destination
        if(node == graph.size() - 1){
            result.push_back(path);
            return;
        }

        // explore neighbours
        for(int next : graph[node]){
            path.push_back(next);              // choose
            dfs(next, graph, path, result);   // explore
            path.pop_back();                  // backtrack
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> path;

        path.push_back(0);  // start from node 0
        dfs(0, graph, path, result);

        return result;
    }
};