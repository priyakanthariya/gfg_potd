class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> serialized;
        if (root == nullptr)
            return serialized;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *node = q.front();
            q.pop();

            if (node) {
                serialized.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                serialized.push_back(-1);
            }
        }

        return serialized;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if (A.empty() || A[0] == -1)
            return nullptr;

        Node *root = new Node(A[0]);
        queue<Node *> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < A.size()) {
            Node *node = q.front();
            q.pop();

            if (A[i] != -1) {
                node->left = new Node(A[i]);
                q.push(node->left);
            }
            i++;

            if (i < A.size() && A[i] != -1) {
                node->right = new Node(A[i]);
                q.push(node->right);
            }
            i++;
        }

        return root;
    }

};