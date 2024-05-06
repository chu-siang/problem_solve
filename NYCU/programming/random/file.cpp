#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
    char s[500];
    ifstream fin;
    ofstream fout;
    fin.open("msg.txt");
    fout.open("out.txt");
    int i = 0;
    while(fin >> s){
        cout << s << endl;
        fout << i << '\n';
    }
    
    fin.close();
    fout.close();
}