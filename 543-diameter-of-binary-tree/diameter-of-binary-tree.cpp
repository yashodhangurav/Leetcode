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
    pair<int, int> dia2(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }

        pair<int, int> leftInfo = dia2(root->left);
        pair<int, int> rightInfo = dia2(root->right);

        int currDia = leftInfo.second + rightInfo.second;
        int finalDia = max(currDia, max(leftInfo.first, rightInfo.first));
        int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

        return make_pair(finalDia, finalHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia2(root).first;
    
    }
};