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

int main(){
	int N,nnice=0;
	getline(cin,line);
	stringstream(line) >> N;
	for(int i=0;i<N;i++){
		stack<char> s;
		s.push('C');
		getline(cin,line);
		if(line.length()%2) continue;
		int lasta = -1;
		int lastb = -1;
		for(unsigned int j=0;j<line.length();j++){
			if(line[j] == s.top()) s.pop();
			else s.push(line[j]);
		}
		if(s.size()==1)nnice++;
	}
	printf("%u\n",nnice);
}