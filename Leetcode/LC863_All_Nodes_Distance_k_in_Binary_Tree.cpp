#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void getParents(TreeNode* root, unordered_map<TreeNode*, pair<TreeNode*, bool>> &mapping){
        if (root->left){
            mapping[root->left] = {root, false};
            getParents(root->left, mapping);
        }

        if (root->right){
            mapping[root->right] = {root, false};
            getParents(root->right, mapping);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map< TreeNode*, pair<TreeNode*, bool> > mapping;
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;

        mapping[root] = {NULL, false};
        getParents(root, mapping);

        q.push({target, 0});
        mapping[target].second = true;

        while (!q.empty()){
            pair<TreeNode*, int> front = q.front();
            TreeNode* node = front.first;
            int level = front.second;
            if (level==k) ans.push_back(node->val);
            q.pop();

            if (node->left && !mapping[node->left].second && level<k){
                q.push({node->left, level+1});
                mapping[node->left].second = true;
            }

            if (node->right && !mapping[node->right].second && level<k){
                q.push({node->right, level+1});
                mapping[node->right].second = true;
            }

            if (mapping[node].first && !mapping[node].second && level<k){
                q.push({mapping[node].first, level+1});
                mapping[mapping[node].first].second = true;
            }
        }
    }
};