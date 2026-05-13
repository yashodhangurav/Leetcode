/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* buildFromSorted( vector<int> &arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end-st)/2;

    TreeNode* curr = new TreeNode(arr[mid]);
    curr->left = buildFromSorted(arr, st, mid-1);
    curr->right = buildFromSorted(arr, mid+1, end);

    return curr;
}

void getInorder(TreeNode* root, vector<int> &nodes){
    if(root == NULL){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->val);
    getInorder(root->right, nodes);
}

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
    getInorder(root, nodes);
    // build balanced BST from the sorted array
   return buildFromSorted(nodes, 0, nodes.size()-1);
}

};