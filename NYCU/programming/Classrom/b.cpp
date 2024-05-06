#include <iostream>
#include <fstream>
using namespace std;

void update(int Q[][9][10],int r, int c, int n)
{
	int d,r1,c1;
	for(d=1;d<=9;d++)
		Q[r][c][d]=0;
	for(c1=0;c1<9;c1++)
		Q[r][c1][n] = 0;
	for(r1=0;r1<9;r1++)
		Q[r1][c][n] = 0;
	for(r1=r/3*3;r1<=r/3*3+2;r1++)
		for(c1=c/3*3;c1<=c/3*3+2;c1++)
			Q[r1][c1][n] = 0;
	Q[r][c][n] = 1;
}

void read(int Q[][9][10])
{
	ifstream fin;
	int r,c,d,n;
	fin.open("Q1.txt");
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
			for(d=1;d<=9;d++)
				Q[r][c][d]=1;
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
		{
			fin >> n;
			Q[r][c][0] = n;
			if(n>0)
			{
				update(Q,r,c,n);
			}
		}
	fin.close();
}

void write(int Q[][9][10])
{
	ofstream f;
	f.open("a.txt");
	int r,c;
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			f << Q[r][c][0] << " ";
		}
		f << endl;
	}
	f.close();
}

int test(int Q[][9][10],int r,int c)
{
	int count=0,d,n;
	for(d=1;d<=9;d++)
	{
		if(Q[r][c][d]==1)
		{
			count++;
			n = d;
		}
	}
	if(count==1)
		return n;
	else
		return 0;
}

int main()
{
	int Q[9][9][10];
	read(Q);
	int r,c,n,change;
	do{
		change = 0;
		for(r=0;r<9;r++)
			for(c=0;c<9;c++)
			{
				if(Q[r][c][0]==0)
				{
					n = test(Q,r,c);
					if(n>0)
					{
						change=1;
						Q[r][c][0] = n;
						update(Q,r,c,n);
					}
				}
			}
	}while(change==1);
	write(Q);
	return 0;
}
