https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/0/?category[]=Binary%20Search%20Tree&page=1&sortBy=accuracy&query=category[]Binary%20Search%20Treepage1sortByaccuracy#


int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceil= -1;
    while(root){
        
    if(root->data==input){
        ceil=root->data;
        return ceil;
    }
    else if(input>root->data){
        root=root->right;
    }
    else{
        ceil=root->data;
        root=root->left;
    }
        
    }
    return ceil;
}
