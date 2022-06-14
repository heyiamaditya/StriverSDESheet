https://practice.geeksforgeeks.org/problems/preorder-traversal/1

void pretree(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        
        v.push_back(root->data);
        pretree(root->left,v);
        pretree(root->right,v);
        
        return ;
    }

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
    vector<int>v;
    pretree(root,v);
    return v;

  
}
