/*  Binary Tree Level Order Traversal II
    ------------------------------------

    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class TreeNode {
    public:
      int val;
      TreeNode *left;
      TreeNode *right;
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root,int length) {
        vector<vector<int>> result;
        queue<TreeNode*> Q;  // contains object pointers
        if(!root){return result;}
        Q.push(root);
        while(!Q.empty()){
            vector<int> value;
            TreeNode* node;
            int siz;
            siz = Q.size();
            for(int i=0;i<siz;i++){
                node = Q.front();
                Q.pop();
                value.push_back(node->val);     //  {3}
                if(node->left){Q.push(node->left);}
                if(node->right){Q.push(node->right);}
            }
            result.push_back(value);    //  {{3}}
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

TreeNode* newNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(vector<int> arr, int i, int n)
{
    // Base case for recursion
    if (i >= n || arr[i]==0){return NULL;}
    TreeNode* root = newNode(arr[i]);

    // insert left child
    root->left = insertLevelOrder(arr,2 * i + 1, n);

    // insert right child
    root->right = insertLevelOrder(arr,2 * i + 2, n);
    return root;
}
void inOrder(TreeNode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->val <<" ";
		inOrder(root->right);
	}
}
int main(){
    vector<int> btree;
    vector<vector<int>> result;
    int a,length=0;
    cout<<"This code takes Binary Tree input in the form of vector array where 0 means no node\n\nFor Eg:- {3,9,20,0,0,15,7} here \n\n3(root) -> 9(left), 20(right)\n9 -> 0(noleft), 0(noright)\n20 -> 15(left), 7(right)\n";
    cout<<"\nEnter vector array : ";
    cin>>a;
    while(a!=-1){
        btree.push_back(a);
        length++;
        cin>>a;
    }
    TreeNode* root = insertLevelOrder(btree,0,length);
    Solution obj;
    result = obj.levelOrderBottom(root,length);
   // inOrder(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
