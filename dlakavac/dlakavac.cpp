#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <set>
#include <stdlib.h>

#ifndef HELP
#define HELP 0
#endif

using namespace std;
string line;
vector<int> inits,infected;
set<int> nif;

int main(){
	unsigned long long K;
	int M,N;
	getline(cin,line);
	stringstream(line) >> K >> M >> N;
	int n;
	while(cin >> n){
		inits.push_back(n);
		infected.push_back(n);
	}
	cin.clear();
	for(unsigned int i=1;i<K;i++){
		if(HELP)printf("Day %u\n",i);
		for(unsigned int j=0;j<infected.size();j++){
			for(unsigned int k=0;k<N;k++){
				nif.insert((infected[j]*inits[k])%M);
			}
		}
		infected.clear();
		for(set<int>::iterator it=nif.begin(); it!=nif.end(); ++it){
			if(HELP)printf("%u is infected\n",*it);
			infected.push_back(*it);
		}
	}
	for(unsigned int j=0;j<infected.size()-1;j++){
		printf("%u ",infected[j]);
	}
	printf("%u\n",infected[infected.size()-1]);
}