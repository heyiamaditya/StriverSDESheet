   https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#
   
   Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10
   
  Note:- lefttoright as bool, which tells in which order we have to store nodes values 
  
  vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	if(root==NULL){
    	    return res;
    	}
    	
    	queue<Node*>q;
    	q.push(root);
    	bool LeftToRight = true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>ans(size);
    	    
    	    for(int i=0;i<size;i++){
    	        Node* front=q.front();
    	        q.pop();
    	        
    	        int index=LeftToRight?i:size-i-1;
    	        ans[index]=front->data;
    	        
    	        if(front->left){
    	            q.push(front->left);
    	        }
    	        if(front->right){
    	            q.push(front->right);
    	        }
    	    }
    	    LeftToRight = !LeftToRight;
    	    for(auto it:ans){
    	    res.push_back(it);
    	    }
    	}
    	return res;
    }
