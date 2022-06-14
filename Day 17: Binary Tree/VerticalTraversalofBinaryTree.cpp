https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
  
Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
  
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Note:- Map of Horizontal distance with level wise node like->hd,(lvl,vector of nodes)
  
vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[hd][lvl].push_back(frontnode->data);
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
     
    }
};
