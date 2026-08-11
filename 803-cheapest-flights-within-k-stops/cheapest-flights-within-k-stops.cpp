class Solution {
public:

    class Info{
        public:
            int u;
            int cost;
            int stops;

            Info(int u, int cost, int stops){
                this->u = u;
                this->cost = cost;
                this->stops = stops;
            }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dest(V,INT_MAX);

        dest[src] = 0;
        q.push(Info(src,0,-1));

        while(q.size() > 0){
            Info curr = q.front();
            q.pop();

            for(int i = 0; i<flights.size(); i++){
                if(flights[i][0] == curr.u){
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if(dest[v] > curr.cost + wt && curr.stops+1 <= k){
                        dest[v] = curr.cost+wt;
                        q.push(Info(v,dest[v],curr.stops+1));
                    }
                }
            }
        }
        if(dest[dst] == INT_MAX){
            return -1;
        }
        return dest[dst];

    }   
};