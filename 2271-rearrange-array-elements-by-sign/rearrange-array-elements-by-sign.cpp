class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> pos, neg;
        int n = nums.size();
        vector<int> ans(n,0);

        for(int i =0; i<n; i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        } 

        if(neg.size()>pos.size()){
            for(int i = 0; i<pos.size(); i++){
                ans[2*i] = pos[i];
                ans[2*i+1] = neg[i];
            }

            int index = pos.size() *2;
            for(int i = index; i<neg.size(); i++){
                ans[index] = neg[i];
                index++;
            }
        }
        else{
            for(int i = 0; i<neg.size(); i++){
                ans[2*i] = pos[i];
                ans[2*i+1] = neg[i];
            }
            int index = neg.size() *2;

            for(int i = index; i<pos.size(); i++){
                ans[index] = pos[i];
                index++;
            }
        }
        return ans;
    }
};