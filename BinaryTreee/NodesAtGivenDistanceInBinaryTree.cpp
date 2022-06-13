void mark_parent(unordered_map<Node*,Node*>&parent_track,Node*root,int target){
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            if(curr->data==target){
                T=curr;
            }
            
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
       unordered_map<Node*,Node*>parent_track;
       mark_parent(parent_track,root,target);
       
       unordered_map<Node*,bool>vis;
       queue<Node*>q;
       q.push(T);
       
       vis[T]=true;
       
       int lvl=0;
       
       while(!q.empty()){
           int size=q.size();
           if(lvl++ == k){
               break;
           }
           
           for(int i=0;i<size;i++){
               Node*curr= q.front();
               q.pop();
               
               if(curr->left and !vis[curr->left]){
                   vis[curr->left]=true;
                   q.push(curr->left);
               }
               
                if(curr->right and !vis[curr->right]){
                   vis[curr->right]=true;
                   q.push(curr->right);
               }
               
               if(parent_track[curr] and !vis[parent_track[curr]]){
                   vis[parent_track[curr]]=true;
                   q.push(parent_track[curr]);
               }
           }
           
           
       }
       vector<int>v;
       while(!q.empty()){
           Node* curr = q.front();
           v.push_back(curr->data);
           q.pop();
       }
       sort(v.begin(), v.end());
       return v;

    }
