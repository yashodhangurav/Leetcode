class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<bool> vis(V, false);
        vector<int> colour(V, -1);

        for(int i = 0; i < V; i++){  
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = true;
                colour[i] = 0;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    for(int v : graph[curr]){
                        if(!vis[v]){
                            vis[v] = true;
                            q.push(v);
                            colour[v] = !colour[curr];
                        }
                        else{
                            if(colour[v] == colour[curr]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};