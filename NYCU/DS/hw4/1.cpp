//uva 10701
#include<bits/stdc++.h>
using namespace std;

string a,b;
int idx = 0;
void travel(int l,int r){
    if(l > r)return;
    int i;
    for(i = l; i <= r; i++){
        if(a[idx] == b[i])break;
    }
    if(i != r+1){
        idx++;
        travel(l,i-1);//left
        travel(i+1,r);//right
        cout << b[i];//root;
    }
}

signed main(){
    while(cin >> a >> b){
        int l = a.length();
        travel(0,l-1);
        cout << '\n';
    }
}

/*
//solution 2 bad time complexity
#include<bits/stdc++.h>
using namespace std;
map<char,int>Inorder;
string Preorder;
int idx = 0;
struct Node{
    Node *left,*right;
    char ch;
};

Node *newNode(char chr){
    Node*tmp = new Node;
    tmp->left = tmp->right = nullptr;
    tmp->ch = chr;
    return (tmp);
}

Node *buildtree(int l,int r){
    if(l > r)return nullptr;
    char chr = Preorder[idx++];
    int curIndex = Inorder[chr];
    Node *current = newNode(chr);

    current->left = buildtree(l,curIndex-1);
    current->right = buildtree(curIndex+1,r);

    return current;
}


void dfs(Node *root){
    if(root == nullptr)return ;
    dfs(root->left);
    dfs(root->right);
    cout << root->ch;
}
signed main(){
    cin >> Preorder;
    string a;
    cin >> a;
    int n = a.size();
    for(int i = 0;i < n;i++){
        Inorder[a[i]] = i;
    }
    Node *root = buildtree(0,n-1);
    dfs(root);
    cout << '\n';
}
*/