#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
void inordertraverse(const vector<Node>& tree,vector<int> &result,int root)
{
   if(root==-1)
    return;
      inordertraverse(tree,result,tree[root].left);
    result.push_back(tree[root].key);
      inordertraverse(tree,result,tree[root].right);
}
vector<int> inorder(const vector<Node>& tree)
{  vector<int> result;
  inordertraverse(tree,result,0);
return result;
}
bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size()>1){
  vector<int> v=inorder(tree);
  for(int i=1;i<v.size();i++)
    {if(v[i]<v[i-1])
      return false;}}
return true;
}


int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
