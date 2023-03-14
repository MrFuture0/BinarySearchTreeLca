#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;


struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;


  TreeNode(int v) : val(v) , left(NULL),right(NULL){}
};

class BinarySearchTree
{
    private:
    TreeNode* root;

      TreeNode* insertHelper(TreeNode* root, int val)
      {
          if(root == NULL)
          {
            return new TreeNode(val);
          }
          if(val < root->val)
          {
            root->left = insertHelper(root->left,val);
          }
          else if(val > root->val)
          {
            root->right = insertHelper(root->right,val);
          }
          return root;
      }

    public: 
    BinarySearchTree(vector<int>& preorder)
    {
        root = NULL;
        for(int i =0 ; i<preorder.size();i++)
        {
          root = insertHelper(root,preorder[i]);
        }
    }

    TreeNode* getRoot()
    {
      return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,int p , int q)
    {
      if(root == NULL || root->val == p || root->val ==q)
      {
        return root;
      }

      TreeNode* left = lowestCommonAncestor(root->left , p , q);
      TreeNode* right = lowestCommonAncestor(root->right , p, q );

      if(left == NULL)
      {
        return right;
      }
      else if( right == NULL)
      {
        return left;
      }
      else
      {
        return root;
      }
    }

};

string BinarySearchTreeLCA(string strArr[]) {
  
  // code goes here  
  vector<int> preorder;
  stringstream ss(strArr[0]);
  int val;
  char ch;

  while(ss >> ch  >> val >> ch)
  {
    preorder.push_back(val);
  }

  int p = stoi(strArr[1]);
  int q = stoi(strArr[2]);

  // Build 
  BinarySearchTree bst(preorder);

  //find lowst common ancestor
  TreeNode* root = bst.getRoot();
  TreeNode* lca = bst.lowestCommonAncestor(root,p,q);

  return to_string(lca->val);

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  cout << BinarySearchTreeLCA(A);
  return 0;
    
}