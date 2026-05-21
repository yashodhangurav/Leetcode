class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;                //max heap

        for(int i = 0; i<stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() > 1){
            int y = maxHeap.top(); maxHeap.pop();   //largest
            int x = maxHeap.top(); maxHeap.pop();   //secondLargest

            if(y!=x){
                maxHeap.push(y-x);
            }
        }

        return maxHeap.empty()? 0: maxHeap.top();
    }
};