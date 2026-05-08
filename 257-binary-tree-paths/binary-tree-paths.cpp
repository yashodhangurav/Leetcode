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

    void solve(TreeNode* root, vector<int>& path, vector<string>& result) {
        if (root == NULL) return;

        // Add current node
        path.push_back(root->val);

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            string s = "";
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1) s += "->";
            }
            result.push_back(s);
        }

        // Recurse
        solve(root->left, path, result);
        solve(root->right, path, result);

        // Backtrack
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        solve(root, path, result);

        return result;
    }
};