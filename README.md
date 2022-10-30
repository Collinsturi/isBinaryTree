Seeing whether a Binary tree is a Binary Search Tree: 
    If a node is a left child then its data should be lesser than data in its root than if it is a right child where the data in it should be greater than the data in the root.
    
    

If I would have choosen to use recurssion on all the functions i.e functions to check if sub-tree is lesser  and if sub-tree is greater I would have constantly accessed elements and checking whether they are lesser or greater than their root. This would have been very expensive. In code: 

            bool isSubTreeLesser(node* root, int data){
            if(root == NULL) return true;

            if(root->data <= data && isSubTreeLesser(root->left, data) && isSubTreeLesser(root->right, data))
              return true;
            else
              return false;
            }
            bool isSubTreeGreater(node* root, int data){
            if(root == NULL) return true;

            if(root->data > data && isSubTreeGreater(root->left, data) && isSubTreeGreater(root->right, data))
              return true;
            else
              return false;
            }
            bool isBinarySearchTree(node* root){
            if(root == NULL) return true;

            if(isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && 
              isBinarySearchTree(root->left) && isBinarySearchTree(root->right)){
                return true;
            }else{
              return false;
            }
            }

This would have been the purely recurssion code.


I chose to use a utility function so that the user can just pass in the root in the call to a function. The function call to the user only accepts the pointer to root and which calls the utility function behind the scenes which accepts three formal parameters. 
The actual parameters I passed on the function call is the root parameter from the user, INT_MAX and INT_MIN which are macros to mean that I want to pass the Maximum and the Minimum possible values to that function which can be negative infinity to positive infinity but since the formal parameters stipulates that the data type is int the values passed are from negaative two million(*truncated value) to positive two million(*truncated value).


The recurrsion that will be done will now reduce the min and maximum values as more function calls will be made and therefore will reduce the cost of us checking if the binary tree is a binary tree. Visiting a node will take constant time.


Another approach would have been to find the min of the left sub tree and check it against the root and then finding the max of the right subtree and checking it against the root. If the min of the left subtree is less than the root and the max of the left subtree is greater than the root, the tree would be a Binary Search tree. Contrary to that will not be a Binary Search tree.
