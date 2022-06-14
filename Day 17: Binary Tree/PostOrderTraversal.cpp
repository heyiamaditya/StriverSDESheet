https://practice.geeksforgeeks.org/problems/postorder-traversal/1


void posttree(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        
        posttree(root->left,v);
        posttree(root->right,v);
        v.push_back(root->data);
        
        return ;
    }

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
    vector<int>v;
    posttree(root,v);
    return v;
}
