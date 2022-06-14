https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/

Input:
      1
   /    \
  2      3
Output: 2 1 3
  
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

  
Note:- Draw a horizontal line starting to root and atke root as 0
and -1 to its left and +1 to its right follow it untill the base case hit and take the first element of the new horizontal distance.

vector<int> topView(Node *root){
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
            
            if(topnode.find(hd)==topnode.end()){
            topnode[hd]=frontnode->data;
            }
            
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
