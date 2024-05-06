#include<bits/stdc++.h>
using namespace std;
//撲克牌 亂數取兩張牌交換 重複一萬次洗完排

void wash(int card[]){
    srand(time(NULL));
    int t,t1;
    for(int i = 0; i < 100000; i++){
        t = rand()%52;
        t1 = rand()%52;
        while(t == t1)t1 = rand()%52;
        swap(card[t],card[t1]);
    }
}

//print2 先照數字後照花色
void M_sort(int my_card[]){
    for(int i = 0; i < 13; i++){
        for(int j = 1; j < 13-i; j++){
            if(my_card[j] < my_card[j-1])swap(my_card[j],my_card[j-1]);
        }
    }
}
//flower first
void print1(int x){
    int flower = x/13;
    if(flower == 0)cout << "♠";
    else if(flower == 1)cout << "♥";
    else if(flower == 2)cout <<"♦";
    else cout <<"♣";
    int digit = x%13+1;
    switch(digit){
        case 1:
            cout << " A";
            break;
        case 11:
            cout << " J";
            break;
        case 12:
            cout << " Q";
            break;
        case 13:
            cout << " K";
            break;
        default:
            cout <<' '<< digit;
            break;
    }
}
// S H D C
//number first
void print2(int x){
    int flower = x%4;
    if(flower == 0)cout << "♠";
    else if(flower == 1)cout << "♥";
    else if(flower == 2)cout <<"♦";
    else cout <<"♣";
    int digit = x/4+1;
    switch(digit){
        case 1:
            cout << " A";
            break;
        case 11:
            cout << " J";
            break;
        case 12:
            cout << " Q";
            break;
        case 13:
            cout << " K";
            break;
        default:
            cout <<' '<< digit;
            break;
    }
}

int main(){
    //diamond_1
    int card[52],my_card[13];
    // 0-3(梅花1-黑桃1) 4-7(梅花2-黑桃2)
    for(int i = 0; i < 52; i++)card[i] = i;
    wash(card);
    for(int i = 0; i < 13; i++){
        my_card[i] = card[i];
    }
    M_sort(my_card);
    //sort(my_card,my_card+13);
    for(int i = 0; i < 13; i++) print2(my_card[i]),cout << ' ';
}