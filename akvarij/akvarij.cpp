#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>

#ifndef HELP
#define HELP 0
#endif

using namespace std;
string line;
int b[100000];
int mins[100000];
int maxes[100000];
int ds[100000];

int main(){
	unsigned int M,N;
	getline(cin,line);
	stringstream(line) >> N >> M;
	int i=0,n;
	for(unsigned int i=0;i<N;i++) scanf("%u ",b+i);
	for(unsigned int i=0;i<N;i++){
		maxes[i] = b[i+1]>b[i]?b[i+1]:b[i];
		mins[i] = b[i+1]<b[i]?b[i+1]:b[i];
		ds[i] = maxes[i]-mins[i];
	}
	if(HELP)for(unsigned int i=0;i<N-1;i++)printf("Section %u: %u ds %u, maxes %u, mins %u\n",i,b[i], ds[i],maxes[i],mins[i]);
	scanf("\n");
	for(int i=0;i<M;i++){
		char t;
		scanf("%c ",&t);
		if(t=='Q'){
			int j;
			scanf("%u\n",&j);
			if(HELP)printf("Querying h=%u\n",j);
			float total = 0;
			for(unsigned int k=0;k<N-1;k++){
				if(j<=mins[k]) continue;
				if(j>=maxes[k]){
					total += (j-maxes[k])+ds[k]*0.5;
				}else{
					total += ((float)(j-mins[k]))*(j-mins[k])/ds[k]*0.5;
				}
				if(HELP)printf("Section %u: new total %f\n",k,total);
			}
			printf("%.3f\n",total);
		}else{
			int j,h;
			scanf("%u %u\n",&j,&h);
			b[j] = h;
			maxes[j-1] = b[j-1]>b[j]?b[j-1]:b[j];
			 mins[j-1] = b[j-1]<b[j]?b[j-1]:b[j];
			   ds[j-1] = maxes[j-1]-mins[j-1];
			if(HELP) printf("Section %u: %u ds %u, maxes %u, mins %u\n",j-1,b[j-1], ds[j-1],maxes[j-1],mins[j-1]);
			if(i<M){
				maxes[j] = b[j+1]>b[j]?b[j+1]:b[j];
				 mins[j] = b[j+1]<b[j]?b[j+1]:b[j];
				   ds[j] = maxes[j]-mins[j];
				if(HELP) printf("Section %u: %u ds %u, maxes %u, mins %u\n",j,b[j], ds[j],maxes[j],mins[j]);
			}
		}
	}
}