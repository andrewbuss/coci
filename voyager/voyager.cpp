#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stack>
#include <stdlib.h>

#ifndef HELP
#define HELP 0
#endif

using namespace std;
string line;
char board[501][501];
bool v[4][501][501];
int N,M,PC,PR;
char dirs[4] = {'U','R','D','R'};

int next(int x, int y, char d){
	if(HELP){
		printf("At %u %u, going %u\n",x,y,d);
		printf("Board here is %c\n",board[y][x]);
	}
	if(v[d][y][x]) return -0x7FFFFFFF;
	v[d][y][x] = true;
	switch(d){
	case 0:
		if(y==0 or board[y-1][x] == 'C') return 1;
		if(board[y-1][x]=='/'){
			return next(x,y-1,1)+1;
		}
		else if(board[y-1][x]=='\\'){
			return next(x,y-1,3)+1;
		}
		else{
			return next(x,y-1,0)+1;
		}
	case 1:
		if(x==M-1 or board[y][x+1] == 'C') return 1;
		if(board[y][x+1]=='/'){
			return next(x+1,y,0)+1;
		}
		else if(board[y][x+1]=='\\'){
			return next(x+1,y,2)+1;
		}
		else{
			return next(x+1,y,1)+1;
		}
	case 2:
		if(y==N-1 or board[y+1][x] == 'C') return 1;
		if(board[y+1][x]=='/'){
			return next(x,y+1,3)+1;
		}
		else if(board[y+1][x]=='\\'){
			return next(x,y+1,1)+1;
		}
		else{
			return next(x,y+1,2)+1;
		}
	case 3:
		if(x==0 or board[y][x-1] == 'C') return 1;
		if(board[y][x-1]=='/'){
			return next(x-1,y,2)+1;
		}
		else if(board[y][x-1]=='\\'){
			return next(x-1,y,0)+1;
		}
		else{
			return next(x-1,y,3)+1;
		}
	}
}

int main(){
	getline(cin,line);
	stringstream(line) >> N >> M;
	for(int i=0;i<N;i++){
		getline(cin,line);
		for(int j=0;j<M;j++){
			board[i][j] = line[j];
		}
	}
	getline(cin,line);
	stringstream(line) >> PR >> PC;
	char maxd = 0;
	int max = 0;
	for(unsigned int d=0;d<4;d++){
		memset(&v[0][0][0],false,4*501*501*sizeof(bool));
		if(HELP) printf("Testing %c\n",dirs[d]);
		int rv = next(PR-1,PC-1,d);
		if(rv<0){
			printf("%c\nVoyager\n",dirs[d]);
			return 0;
		}
		else if(rv>max){
			max = rv;
			maxd = d;
		}
	}
	printf("%c\n%u\n",dirs[maxd],max);
}