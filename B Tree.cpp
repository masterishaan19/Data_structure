#include <bits/stdc++.h>

using namespace std;

int m = 5;
int min_keys = ceil(m/2.0)-1;

typedef struct node
{
    int no_of_keys = 0;
    vector<int> keys;
    vector<struct node*> children;
    struct node* parent = NULL;
    bool leaf = true;
    node()
    {
        for(int i=0; i<m; i++){
            keys.push_back(0);
            children.push_back(NULL);
        }
        children.push_back(NULL);
    }
}node;

node* deleteVal(node *root, int val);
void mergeNodes(node *leftSibling, node *rightSibling, int down_value, bool include_down_value, int shift_value, node *currParent);
node* getMinValNode(node *root);
node* getMaxValNode(node *root);
void preOrder(node *root);


int main()
{
    node *root = new node;
    
    root->keys[0] = 50;
    root->keys[1] = 80;
    root->no_of_keys = 2;
    root->leaf = false;

    
    root->children[0] = new node;
    root->children[0]->keys[0] = 10;
    root->children[0]->keys[1] = 20;
    root->children[0]->no_of_keys = 2;
    root->children[0]->parent = root;
    root->children[0]->leaf = false;
    
    root->children[0]->children[0] = new node;
    root->children[0]->children[0]->keys[0] = 4;
    root->children[0]->children[0]->keys[1] = 5;
    root->children[0]->children[0]->keys[2] = 6;
    root->children[0]->children[0]->no_of_keys = 3;
    root->children[0]->children[0]->parent = root->children[0];

    root->children[0]->children[1] = new node;
    root->children[0]->children[1]->keys[0] = 14;
    root->children[0]->children[1]->keys[1] = 15;
    root->children[0]->children[1]->keys[2] = 16;
    root->children[0]->children[1]->no_of_keys = 3;
    root->children[0]->children[1]->parent = root->children[0];
    
    root->children[0]->children[2] = new node;
    root->children[0]->children[2]->keys[0] = 23;
    root->children[0]->children[2]->keys[1] = 27;
    root->children[0]->children[2]->no_of_keys = 2;
    root->children[0]->children[2]->parent = root->children[0];
    
    root->children[1] = new node;
    root->children[1]->keys[0] = 60;
    root->children[1]->keys[1] = 70;
    root->children[1]->keys[2] = 75;
    root->children[1]->no_of_keys = 3;
    root->children[1]->parent = root;
    root->children[1]->leaf = false;
    
    root->children[1]->children[0] = new node;
    root->children[1]->children[0]->keys[0] = 51;
    root->children[1]->children[0]->keys[1] = 52;
    root->children[1]->children[0]->no_of_keys = 2;
    root->children[1]->children[0]->parent = root->children[1];
    
    root->children[1]->children[1] = new node;
    root->children[1]->children[1]->keys[0] = 64;
    root->children[1]->children[1]->keys[1] = 65;
    root->children[1]->children[1]->keys[2] = 68;
    root->children[1]->children[1]->no_of_keys = 3;
    root->children[1]->children[1]->parent = root->children[1];
    
    root->children[1]->children[2] = new node;
    root->children[1]->children[2]->keys[0] = 72;
    root->children[1]->children[2]->keys[1] = 73;
    root->children[1]->children[2]->no_of_keys = 2;
    root->children[1]->children[2]->parent = root->children[1];
    
    root->children[1]->children[3] = new node;
    root->children[1]->children[3]->keys[0] = 77;
    root->children[1]->children[3]->keys[1] = 78;
    root->children[1]->children[3]->keys[2] = 79;
    root->children[1]->children[3]->no_of_keys = 3;
    root->children[1]->children[3]->parent = root->children[1];
    
    root->children[2] = new node;
    root->children[2]->keys[0] = 90;
    root->children[2]->keys[1] = 95;
    root->children[2]->no_of_keys = 2;
    root->children[2]->parent = root;
    root->children[2]->leaf = false;
    
    root->children[2]->children[0] = new node;
    root->children[2]->children[0]->keys[0] = 81;
    root->children[2]->children[0]->keys[1] = 82;
    root->children[2]->children[0]->keys[2] = 89;
    root->children[2]->children[0]->no_of_keys = 3;
    root->children[2]->children[0]->parent = root->children[2];
    
    root->children[2]->children[1] = new node;
    root->children[2]->children[1]->keys[0] = 92;
    root->children[2]->children[1]->keys[1] = 93;
    root->children[2]->children[1]->no_of_keys = 2;
    root->children[2]->children[1]->parent = root->children[2];
    
    root->children[2]->children[2] = new node;
    root->children[2]->children[2]->keys[0] = 100;
    root->children[2]->children[2]->keys[1] = 110;
    root->children[2]->children[2]->keys[2] = 111;
    root->children[2]->children[2]->no_of_keys = 3;
    root->children[2]->children[2]->parent = root->children[2];
    
    //                  (           50                           80      )
    //                    /                     |                       \
    //      (  10   20   )        (   60      70     75    )            (    90      95  )
    //      /     |     \           /       |      \      \             /       |       \
    // (4 5 6)(14 15 16)(23 27) (51 52)(64 65 68)(72 73)(77 78 79) (81 82 89)(92 93)(100 110 111) 
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 64"<<endl;
    root = deleteVal(root, 64);
    //                  (           50                           80      )
    //                    /                     |                       \
    //      (  10   20   )        (   60    70     75    )          (    90      95  )
    //      /     |     \           /      |     |     \             /       |       \
    // (4 5 6)(14 15 16)(23 27) (51 52)(65 68)(72 73)(77 78 79) (81 82 89)(92 93)(100 110 111) 
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 23"<<endl;
    root = deleteVal(root, 23);
    //                  (           50                       80      )
    //                    /                 |                       \
    //      (  10   16   )      (   60    70     75    )          (    90      95  )
    //      /     |    \         /      |     |     \             /       |       \
    // (4 5 6)(14 15)(20 27) (51 52)(65 68)(72 73)(77 78 79) (81 82 89)(92 93)(100 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 72"<<endl;
    root = deleteVal(root, 72);
    //                  (           50                       80      )
    //                    /                 |                       \
    //      (  10   16   )      (   60    70     77    )       (    90      95  )
    //      /     |    \         /      |     |     \           /       |       \
    // (4 5 6)(14 15)(20 27) (51 52)(65 68)(73 75)(78 79) (81 82 89)(92 93)(100 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 65"<<endl;
    root = deleteVal(root, 65);
    //                  (           50                       80      )
    //                    /                 |                       \
    //      (  10   16   )      (      70     77    )         (    90      95  )
    //      /     |    \            /       |      \           /       |       \
    // (4 5 6)(14 15)(20 27) (51 52 60 68)(73 75)(78 79) (81 82 89)(92 93)(100 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 20"<<endl;
    root = deleteVal(root, 20);
    //                  (                      80                   )
    //                                  /                        \
    //      (  10        50            70     77   )        (    90      95  )
    //       /       |           |         |      \          /       |       \
    // (4 5 6)(14 15 16 27)(51 52 60 68)(73 75)(78 79) (81 82 89)(92 93)(100 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 70"<<endl;
    root = deleteVal(root, 70);
    //                  (                      80                   )
    //                                  /                        \
    //      (  10        50         68    77   )        (    90      95  )
    //       /       |          |       |      \          /       |       \
    // (4 5 6)(14 15 16 27)(51 52 60)(73 75)(78 79) (81 82 89)(92 93)(100 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 95"<<endl;
    root = deleteVal(root, 95);
    //                  (                      80                   )
    //                                  /                        \
    //      (  10        50         68    77   )        (    90      100  )
    //       /       |          |       |      \          /       |      \
    // (4 5 6)(14 15 16 27)(51 52 60)(73 75)(78 79) (81 82 89)(92 93)(110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 77"<<endl;
    root = deleteVal(root, 77);
    //                  (                   80                   )
    //                          /                        \
    //      (  10        50         68     )        (    90        100  )
    //       /       |          |       \               /       |      \
    // (4 5 6)(14 15 16 27)(51 52 60)(73 75 78 79) (81 82 89)(92 93)(110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 80"<<endl;
    root = deleteVal(root, 80);
    //                  (                   81                   )
    //                          /                        \
    //      (  10        50         68     )        (    90      100  )
    //       /       |          |       \              /      |      \
    // (4 5 6)(14 15 16 27)(51 52 60)(73 75 78 79) (82 89)(92 93)(110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 100"<<endl;
    root = deleteVal(root, 100);
    //                      (           68               )
    //                            /                  \
    //      (  10        50         )      (     81        90       )
    //       /       |          |            /        |         \   
    // (4 5 6)(14 15 16 27)(51 52 60) (73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 6"<<endl;
    root = deleteVal(root, 6);
    //                      (           68               )
    //                            /                  \
    //      (  10        50         )      (     81        90       )
    //       /       |          |            /        |         \   
    //   (4 5)(14 15 16 27)(51 52 60) (73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 27"<<endl;
    root = deleteVal(root, 27);
    //                  (           68               )
    //                     /                  \
    //      (  10        50   )       (     81        90       )
    //       /      |       \            /        |         \   
    //   (4 5)(14 15 16)(51 52 60) (73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 60"<<endl;
    root = deleteVal(root, 60);
    //                 (           68               )
    //                     /                  \
    //      (  10       50   )       (     81        90       )
    //       /      |      \            /        |         \   
    //   (4 5)(14 15 16)(51 52) (73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 16"<<endl;
    root = deleteVal(root, 16);
    //             (           68               )
    //                /                   \
    //      (  10    50   )       (     81        90       )
    //       /    |     \           /        |         \   
    //   (4 5)(14 15)(51 52) (73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    
    cout<<"Deleting 50"<<endl;
    root = deleteVal(root, 50);
    //      (  10         68         81        90       )
    //       /      |           |          |         \   
    //   (4 5)(14 15 51 52)(73 75 78 79)(82 89)(92 93 110 111)
    preOrder(root);
    cout<<endl;
    return 0;
    
}


node* deleteVal(node *root, int val)
{
    if(root==NULL)
    {
        cout<<"Empty tree"<<endl;
        return root;
    }
    
    node *curr = root;
    node *currParent;
    int currPosition = -1;
    int position;
    
    // find the value to be deleted
    while(curr != NULL)
    {
        position = lower_bound(curr->keys.begin(), curr->keys.begin() + curr->no_of_keys, val) - curr->keys.begin();
        if(position < curr->no_of_keys && curr->keys[position]==val)
            break;
        curr = curr->children[position];
    }
    
    // case of value not found
    if(curr==NULL)
    {
        cout<<"Value not found"<<endl;
        return root;
    }
    
    // if the node is a leaf node
    if(curr->leaf)
    {
        // delete the value
        int i=position+1;
        while(i<curr->no_of_keys)
        {
            curr->keys[i-1] = curr->keys[i];
            i++;
        }
        curr->no_of_keys --;
        // we will check the condition of min keys in the while loop later
    }
    // else the node is an internal node
    else
    {
        // if the successor has more than min no of keys
        node *successor = getMinValNode(curr->children[position+1]);
        if(successor && successor->no_of_keys > min_keys)
        {
            // find the value given by the successor 
            int successor_value = successor->keys[0];
            
            // remove this value from successor and shift all the keys
            int i=0;
            while(i<=successor->no_of_keys-2)
            {
                successor->keys[i] = successor->keys[i+1];
                i++;
            }
            successor->no_of_keys --;
            
            // replace the value to be deleted by its successor
            curr->keys[position] = successor_value;
            return root;   
        }
        
        // if the predecessor has more than min no of keys
        node *predecessor = getMaxValNode(curr->children[position]);
        if(predecessor && predecessor->no_of_keys > min_keys)
        {
            // find the value given by predecessor to curr
            int predecessor_value = predecessor->keys[predecessor->no_of_keys-1];
            // remove the value from predecessor
            predecessor->no_of_keys--;
            
            // replace the value to be deleted by its predecessor
            curr->keys[position] = predecessor_value;
            return root;
        }
        
        // both the predecessor and successor do not have more than min no of keys
        // merge the left and right children
        node *leftSibling = curr->children[position];
        node *rightSibling = curr->children[position+1];
        int down_value = curr->keys[position];
        int shift_value = position;
        mergeNodes(leftSibling, rightSibling, down_value, false, shift_value, curr);
        if(curr==root && curr->no_of_keys==0){
            free(root);
            root = leftSibling;
            root->parent = NULL;
            return root;
        }
    }
    
    // check if the node has less than the minimum keys
    // if the node is root node, then it is acceptable
    while(curr->no_of_keys < min_keys && curr!=root)
    {
        // find the parent of this node
        // currPosition is the index of the children array of currParent linked to current node
        currParent = curr->parent;
        
        for(int i=0; i<=currParent->no_of_keys; i++)
        {
            if(currParent->children[i]==curr)
            {
                currPosition = i;
                break;
            }
        }

        // if right sibling has more than min no of keys
        if(currPosition +1 <= currParent->no_of_keys && currParent->children[currPosition+1]!=NULL && currParent->children[currPosition+1]->no_of_keys > min_keys)
        {
            // find the right sibling
            node *rightSibling = currParent->children[currPosition+1];
            // find the value donated by the right sibling
            int up_value = rightSibling->keys[0];
            node* shifted_child = rightSibling->children[0];
            // remove that value from right sibling
            int i=0;
            while(i<=rightSibling->no_of_keys-2)
            {
                rightSibling->keys[i] = rightSibling->keys[i+1];
                rightSibling->children[i] = rightSibling->children[i+1];
                i++;
            }
            rightSibling->children[i] = rightSibling->children[i+1];
            rightSibling->no_of_keys --;
            
            // find the value which is to be given by the parent to the current node
            int down_value = currParent->keys[currPosition];
            // change the value in parent node to the value given by the right sibling
            currParent->keys[currPosition] = up_value;
            
            // add the value given by the parent to the curr node
            curr->keys[curr->no_of_keys] = down_value;
            curr->children[curr->no_of_keys+1] = shifted_child;
            curr->no_of_keys ++;
            return root;
        }
        // if the left sibling has more than min no of keys
        else if(currPosition -1 >= 0 && currParent->children[currPosition-1]!=NULL && currParent->children[currPosition-1]->no_of_keys > min_keys)
        {
            
            // find the left sibling
            node *leftSibling = currParent->children[currPosition-1];
            // find the value which the left sibling will give, and remove it from left sibling
            int up_value = leftSibling->keys[leftSibling->no_of_keys - 1];
            node* shifted_child = leftSibling->children[leftSibling->no_of_keys];
            leftSibling->no_of_keys --;
            
            // find value of parent node which will come down
            int down_value = currParent->keys[currPosition-1];
            // change the value in parent node to the value given by the left sibling
            currParent->keys[currPosition-1] = up_value;
          
            // shift the values of curr node, and add the value got from the parent node
            curr->children[curr->no_of_keys+1] = curr->children[curr->no_of_keys];
            int i=curr->no_of_keys-1;
            while(i>=0)
            {
                curr->keys[i+1] = curr->keys[i];
                curr->children[i+1] = curr->children[i];
                i--;
            }
            curr->keys[0] = down_value;
            curr->children[0] = shifted_child;
            curr->no_of_keys++;
            return root;
        }
        // else both left and right sibling have only min no of keys
        // so merge the curr node with either its left or right sibling
        else
        {
            node *leftSibling, *rightSibling;
            int down_value, shift_value;
            // down value is the value from parent node which will merge the two siblings
            // shift value is used to shift the values in parent node and remove this down_value from parent node
            
            // if left sibling exits, merging will be with left sibling
            if(currPosition -1 >= 0 && currParent->children[currPosition-1]!=NULL)
            {
                leftSibling = currParent->children[currPosition-1];
                rightSibling = curr;
                down_value = currParent->keys[currPosition-1];
                shift_value = currPosition-1;
            }
            // else merging with right sibling
            else
            {
                leftSibling = curr;
                rightSibling = currParent->children[currPosition+1];
                down_value = currParent->keys[currPosition];
                shift_value = currPosition;
            }
            
            mergeNodes(leftSibling, rightSibling, down_value, true, shift_value, currParent);
            if(currParent==root && currParent->no_of_keys==0){
                free(root);
                root = leftSibling;
                root->parent = NULL;
                return root;
            }
                
            // now check this parent if it satisfies the property of min keys or not
            curr = currParent;
        }
    }
        
    return root;
}

void mergeNodes(node *leftSibling, node *rightSibling, int down_value, bool include_down_value, int shift_value, node *currParent)
{
    // add the down_value(got from parent node) to the left sibling and update children and parent pointers as well
    if(include_down_value)
    {
        leftSibling->keys[leftSibling->no_of_keys] = down_value;
        leftSibling->no_of_keys ++;
    }
    
    leftSibling->children[leftSibling->no_of_keys] = rightSibling->children[0];
    if(rightSibling->children[0])
        rightSibling->children[0]->parent = leftSibling;
    
    // shift the values from rightSibling to the left sibling
    int i=0;
    while(i<rightSibling->no_of_keys)
    {
        leftSibling->keys[leftSibling->no_of_keys] = rightSibling->keys[i];
        leftSibling->no_of_keys ++;
        leftSibling->children[leftSibling->no_of_keys] = rightSibling->children[i+1];
        if(rightSibling->children[i+1])
            rightSibling->children[i+1]->parent = leftSibling;
        i++;
    }
    // delete the right sibling node
    free(rightSibling);
    
    // update the parent by removing the down_value and shifting all values after that
    i = shift_value;
    while(i<= currParent->no_of_keys-2)
    {
        currParent->keys[i] = currParent->keys[i+1];
        currParent->children[i+1] = currParent->children[i+2];
        i++;
    }
    currParent->no_of_keys --;
}

node* getMinValNode(node *root)
{
    if(root==NULL)
        return NULL;
    node* curr = root;
    while(!curr->leaf)
        curr = curr->children[0];
    return curr;
    
}

node* getMaxValNode(node *root)
{
    if(root==NULL)
        return NULL;
    node* curr = root;
    while(!curr->leaf)
        curr = curr->children[curr->no_of_keys];
    return curr;
}

void preOrder(node *root)
{
    if(root==NULL)
        return;
    
    cout<<"( ";
    for(int i=0; i<root->no_of_keys; i++)
        cout<<root->keys[i]<<" ";
    cout<<") ";;
    if(root->parent)
        cout<<" parent: "<<root->parent->keys[0]<<endl;
    else
        cout<<endl;
    for(int i=0; i<root->no_of_keys+1; i++)
        preOrder(root->children[i]);
}