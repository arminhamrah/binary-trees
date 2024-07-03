#include <iostream>
#include <vector>
using namespace std;

//Recursion: Base case, root, then just loop through left & right
//Recursive helper functions common thing - no other way to do it

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeStudentTree() {
    TreeNode *temp = new TreeNode;
    temp->value = "Jerry Xu";
    temp->left = new TreeNode;
    temp->left->value = "Armin Hamrah";
    temp->left->right = new TreeNode;
    temp->left->right->value = "Ayaan Govil";
    temp->left->left = new TreeNode;
    temp->left->left->value = "Aidan Bhatnagar";
    temp->left->left->left = new TreeNode;
    temp->left->left->left->value = "Aarav Chandrasekar";
    temp->left->right->right = new TreeNode;
    temp->left->right->right->value = "Benjamin Co";
    temp->right = new TreeNode;
    temp->right->value = "Paul Fong";
    temp->right->left = new TreeNode;
    temp->right->left->value = "Lucy Knox";
    temp->right->left->left = new TreeNode;
    temp->right->left->left->value = "Leila Nawas";
    temp->right->left->right = new TreeNode;
    temp->right->left->right->value = "Nic Nikcevic";
    temp->right->right = new TreeNode;
    temp->right->right->value = "Theo Parker";
    return temp;
}

int size(TreeNode* tree) {
    if(tree==nullptr)
        return 0;
    else
        return 1 + size(tree->left) + size(tree->right);
}

bool contains(TreeNode* tree, string str) {
    if (tree==nullptr)
        return false;
    else if (tree->value == str)
        return true;
    else
        return contains(tree->left, str) || contains(tree->right, str);
}

int countAs(string str) {
    if (str.length() == 0)
        return 0;
    else if (tolower(str[0]) == 'a')
        return 1 + countAs(str.substr(1));
    else
        return 0 + countAs(str.substr(1));
}

int countAs(TreeNode* tree) { //chang one of function names
    if (tree==nullptr)
        return 0;
    else
        return countAs(tree->value) + countAs(tree->left) + countAs(tree->right);
}

int height(TreeNode* tree) {
    if (tree==nullptr)
        return 0;
    else
        return 1 + max(height(tree->left), height(tree->right));
}

//if (tree==nullptr) return; & else is same as just doing tree!=nullptr
void printTree(TreeNode* tree) {
    if (tree==nullptr)
        return;
    else {
        printTree(tree->left);
        cout << tree->value << endl; //where this goes makes big difference
        printTree(tree->right);
    }
}

bool isEqual(TreeNode* first, TreeNode* second) {
    if (first==nullptr && second==nullptr)
        return true;
    else if (first == nullptr || second == nullptr)
        return false;
    else
        return first->value == second->value &&
        isEqual(first->left, second->left) &&
        isEqual(first->right, second->right);
}

int countLeaves(TreeNode* tree) {
    if (tree==nullptr)
        return 0;
    else if (tree->left==nullptr && tree->right==nullptr)
        return 1;
    else
        return countLeaves(tree->left) + countLeaves(tree->right);
}

string getFirst(TreeNode* tree) {
    if (tree==nullptr)
        return "";
    TreeNode* temp = tree;
    while (temp->left!=nullptr)
        temp = temp->left;
    return temp->value;
}

void getVectorHelper(TreeNode* tree, vector<string> &vec) {
    if (tree == nullptr)
        return;
    else {
        getVectorHelper(tree->left, vec);
        vec.push_back(tree->value);
        getVectorHelper(tree->right, vec);
    }
}

vector<string> getVector(TreeNode* tree) {
    vector<string> result;
    getVectorHelper(tree, result);
    return result;
}

bool allEvenLength(TreeNode* tree) { //actual values even num chars
    if (tree==nullptr)
        return true;
    return tree->value.length()%2==0 && allEvenLength(tree->left) && allEvenLength(tree->right);
}

void flipTree(TreeNode* tree) { //exchange pointers, no changing values
    if (tree==nullptr) return;
    TreeNode* left = tree->left;
    TreeNode* right = tree->right;
    tree->left = right;
    tree->right = left;
    flipTree(tree->left);
    flipTree(tree->right);
}

TreeNode* makeFullTree(string str, int num) { //if str is lucy & num is 3, return tree with 3 levels of lucy (7 total)
    if (num == 0)
        return nullptr;
    TreeNode* tree = new TreeNode;
    tree->value = str;
    tree->left = makeFullTree(str, num-1);
    tree->right = makeFullTree(str, num-1);
    return tree;
}

void removeLeaves(TreeNode* &tree) { //delete should be somewhere in solution
    if (tree==nullptr) return;
    if (tree->left==nullptr && tree->right==nullptr) {
        delete tree;
        tree=nullptr;
        return;
    }
    removeLeaves(tree->left);
    removeLeaves(tree->right);
}

void insertBST(TreeNode* &tree, string str) {
    if (tree==nullptr) {
        tree = new TreeNode;
        tree->value = str;
    }
    else if (str>tree->value) //>: alphabetically higher
        insertBST(tree->right, str);
    else if (str < tree->value)
        insertBST(tree->left, str);
    else //inserting something already there
}

int containsBST(TreeNode* tree, string str) {
    if (tree==nullptr)
        return false;
    else if (tree->value == str)
        return true;
    else if (str<tree->value)
        return containsBST(tree->left, str);
    else
        return containsBST(tree->right, str);
}

int main() {
    cout << "Hello, Binary Trees!" << endl;
    TreeNode *root = makeStudentTree();
    cout << size(root) << endl;
    if (contains(root, "Ben"))
        cout << "Yes" << endl;
    cout << countAs(root) << endl;
    cout << height(root) << endl;
    printTree(root);
    if (isEqual(root, root))
        cout << "The same" << endl;
    cout << countLeaves(root) << endl;
    cout << getFirst(root) << endl;
    vector<string> names = getVector(root);
    insertBST(root, "Kevin"); //always insert at the leaves of a binary search tree
    if (containsBST(root, "Ben"))
        cout << "Yes" << endl;
    return 0;
}