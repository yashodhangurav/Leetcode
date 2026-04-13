class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int srow = 0, scol = 0;
        int erow = n-1, ecol = m-1;

    vector<int> ans;

    while(srow<=erow && scol<=ecol){
        for(int j = scol; j<=ecol; j++){
            cout<<mat[srow][j]<<" ";
            ans.push_back(mat[srow][j]);
        }
        for(int j = srow+1; j<=erow; j++){
            cout<<mat[j][ecol]<<" ";
            ans.push_back(mat[j][ecol]);
        }
        for(int j = ecol-1; j>=scol; j--){
            if(srow == erow) break;
            cout<<mat[erow][j]<<" ";
            ans.push_back(mat[erow][j]);
        }
        for(int j = erow-1; j>=srow+1; j--){
            if(scol == ecol) break;
            cout<<mat[j][scol]<<" ";
            ans.push_back(mat[j][scol]);
        }

        srow++;
        scol++;
        erow--;
        ecol--;
        
    }
    return ans;

    }
};