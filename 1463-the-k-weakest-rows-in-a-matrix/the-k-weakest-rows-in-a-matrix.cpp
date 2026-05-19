class Row{
    public:
        int count;
        int idx;
        Row(int count, int idx){
            this->count = count;
            this->idx = idx;
        }

        bool operator < (const Row &obj) const{
            if(this->count == obj.count){
                return this->idx > obj.idx;
            }
            return this->count > obj.count;
        }
};


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> rows;
   
   for(int i = 0; i<mat.size(); i++){
        int count = 0;
        for(int j = 0; j<mat[i].size() && mat[i][j] == 1; j++){   //soldier count
            count++;
        }
        rows.push_back(Row(count, i));
   }

   priority_queue<Row> pq(rows.begin(), rows.end());

    vector<int> ans;
   for(int i = 0; i<k; i++){
        ans.push_back(pq.top().idx);
        pq.pop();
   }
   return ans;
    }
    
};