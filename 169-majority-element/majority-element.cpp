class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;

   for(int i = 0; i<nums.size(); i++){
        if(m.find(nums[i]) != m.end()){
            m[nums[i]]++;                         //if the element is already present in the map then its freq value will be increased by 1
        }else{
            m[nums[i]] = 1; //if the element is not present in the map then it will be added with freq val 1
        }
    }
                               

   for(pair<int, int> ele : m){
        if(ele.second > nums.size()/2){
            return ele.first;
        }
   }
  return -1;
    }
};