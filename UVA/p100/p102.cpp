#include <iostream>
#include<string>
#include <cstdio>
using namespace std;


int main() {
    string ANSWERS[6] = { 
        "BCG", "BGC", "CBG", "CGB", "GBC", "GCB"
    };
  int brown[5], green[5], clear[5];
  while (scanf("%d", &brown[0]) != EOF) {
    scanf("%d%d%d%d%d%d%d%d", &green[0], &clear[0], 
      &brown[1], &green[1], &clear[1], 
      &brown[2], &green[2], &clear[2]);

    int move[10] = { 0 };
    move[0] = brown[1] + brown[2] + green[0] + green[1] + clear[0] + clear[2];
    move[1] = brown[1] + brown[2] + green[0] + green[2] + clear[0] + clear[1];
    move[2] = brown[0] + brown[2] + green[0] + green[1] + clear[1] + clear[2];
    move[3] = brown[0] + brown[1] + green[0] + green[2] + clear[1] + clear[2];
    move[4] = brown[0] + brown[2] + green[1] + green[2] + clear[0] + clear[1];
    move[5] = brown[0] + brown[1] + green[1] + green[2] + clear[0] + clear[2];

    int minIndex = 0;
    for (int i = 1 ; i < 6 ; i++) {
      if (move[i] < move[minIndex]) {
        minIndex = i;
      }
    }
    cout<<ANSWERS[minIndex]<<" "<<move[minIndex]<<endl;
  }
  return 0;
}