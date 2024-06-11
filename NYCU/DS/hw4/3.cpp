//uva 12347
#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
struct Node{
    Node*left,*right;
    int value;
};


Node* newNode(int val){
    Node *tmp = new Node;
    tmp->value = val;
    tmp->left = tmp->right = nullptr;
    return tmp;
}

Node *buildtree(Node *root,int val){
    if(root == nullptr){
        root = newNode(val);
        return root;
    }else if(root->value >= val){
        root->left = buildtree(root->left,val);
    }else{
        root->right = buildtree(root->right,val);
    }
    return root;
}

void dfs(Node *root){
    if(root == nullptr)return;
    dfs(root->left);
    dfs(root->right);
    ans.push_back(root->value);
}

signed main(){
    Node*root = nullptr;
    int x;
    ans.clear();
    int t;
    cin >> t;
    while(t--){
        cin >> x;
        root = buildtree(root,x);
    }
    dfs(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}