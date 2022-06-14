https://practice.geeksforgeeks.org/problems/inorder-traversal/1



void intree(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        
        intree(root->left,v);
        v.push_back(root->data);
        intree(root->right,v);
        
        return ;
    }
    
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>v;
        
        intree(root,v);
        return v;
        
    }
