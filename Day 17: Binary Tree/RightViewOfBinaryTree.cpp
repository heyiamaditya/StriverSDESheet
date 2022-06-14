https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/


 void solve(Node *root,vector<int>&ans,int lvl){
     if(root==NULL){
         return ;
     }
     
     if(lvl==ans.size()){
         ans.push_back(root->data);
     }
     
     solve(root->right,ans,lvl+1);
     solve(root->left,ans,lvl+1);
}
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int>ans;
      int lvl=0;
      solve(root,ans,lvl);
      return ans;
    }
