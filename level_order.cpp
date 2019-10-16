/*problem 2:
Level wise list of nodes
Given a binary tree, output a list of lists where each list contains nodes at that level.
E.g.   

Input:
        5
      /  \
     2    6
    / \     \
   3   4     7


Output: [[5],[2,6],[3,4,7]]
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
};

vector<vector<int>> getList(Node *root){
  //your code here
  vector<vector<int>> ans;
  int elements;
  if (root == NULL)
        return ans;
  queue <Node *> q;
  vector<int> curr_level;
  q.push(root);
  while (!q.empty()) {
    elements = q.size();        // I was not able to figure out at that time that the NULL pointer is doing the same thing. 
    while (elements-- > 0) {    // We already know how many elements we have in the current level just by looking at the queue size.
      Node *last = q.front();
      curr_level.push_back(last -> val);
      q.pop();
      if (last -> left != NULL)
        q.push(last -> left);
      if (last -> right != NULL)
        q.push(last -> right);
    }
    ans.push_back(curr_level);
    curr_level.clear();
  }
 return ans;
}

int main() {
  Node *root = new Node;
  root -> left = new Node;
  root -> left -> left = new Node;
  root -> left -> right = new Node;
  root -> right = new Node;
  root -> right -> right = new Node;
  root -> val = 5;
  root -> left -> val = 2;
  root -> left -> left -> val = 3;
  root -> left -> right -> val = 4;
  root -> right -> val = 6;
  root -> right -> right -> val = 7;

  vector<vector<int>> v = getList(root);
  for (auto &x : v) {
    for (int k : x) {
      cout << k << " ";
    }
    cout << "\n";
  }
}