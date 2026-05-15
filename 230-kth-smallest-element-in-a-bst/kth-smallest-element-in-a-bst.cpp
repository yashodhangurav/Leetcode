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
    int search(TreeNode* root, int &k){
        if(root == NULL) return -1;

        int leftVal = search(root->left, k);
        if(leftVal != -1){
            return leftVal;
        }

        k--;
        if(k == 0){
            return root->val;
        }

        return search(root->right, k);

    }

    int kthSmallest(TreeNode* root, int k) {
        return search(root, k);
    }
};