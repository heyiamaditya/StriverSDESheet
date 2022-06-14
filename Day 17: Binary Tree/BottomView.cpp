https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

Input:
       1
     /   \
    3     2
Output: 3 1 2

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
  
Note:- Draw a horizontal line starting to root and atke root as 0
and -1 to its left and +1 to its right follow it untill the base case hit.
  
vector <int> bottomView(Node *root) {
    
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int>topnode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            Node* frontnode=it.first;
            int hd=it.second;
            
            topnode[hd]=frontnode->data;
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        
        for(auto it:topnode){
            ans.push_back(it.second);
        }
        return ans;
        
    }
