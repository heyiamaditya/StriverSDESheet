https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1/#

AntiClockwisw


Approach:- First take transpose of matrix then reverse it column wise.
  
  CODE->
  
  	void rotateMatrix(vector<vector<int>>& a, int n) {
	    
	
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(a[i][j],a[j][i]);
        }
	    
	    int ind=n-1;
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n/2;j++){
	            int temp=a[j][i];
	            a[j][i]=a[ind][i];
	            a[ind][i]=temp;
	            ind--;
	        }
	        ind=n-1;
	    }
	    
	}

---------------------------------------------------------------------------XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-------------------------------------------------

https://leetcode.com/problems/rotate-image/submissions/

Clockwisw


Approach:- First take transpose of matrix then reverse it Row wise.
  
CODE->
  
 void rotate(vector<vector<int>>& a) {
        
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(a[i][j],a[j][i]);
        }
        
        for(int i=0;i<n;i++){
            reverse(a[i].begin(),a[i].end());
        }
        
    }







