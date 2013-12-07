#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>

#ifndef HELP
#define HELP 0
#endif

using namespace std;

int main(){
	string line;
	
	int L,N;
	getline(cin,line);
	stringstream(line) >> L;
	getline(cin,line);
	stringstream(line) >> N;
	int med = 0;
	int medi = 0;
	int mer = 0;
	int meri = 0;
	int roll[1001];
	memset(roll,0,sizeof(int)*1001);
	for(int i=1;i<=N;i++){
		getline(cin,line);
		unsigned int P,K;
		stringstream(line) >> P >> K;
		unsigned int ned = K-P;
		if(ned>med){
			med = ned;
			medi = i;
		}
		unsigned int nrd = 0;
		for(unsigned int j=P;j<=K;j++){
			if(!roll[j]){
				nrd++;
				roll[j]=i;
			}
		}
		if(nrd>mer){
			mer = nrd;
			meri = i;
		}
	}
	printf("%u\n%u\n",medi,meri);
}