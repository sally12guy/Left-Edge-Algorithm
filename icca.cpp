#include<iostream>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
    int s;
    int e;
    int num;
    int del;
};
int compare(const void *a, const void *b){
    struct node *c=(struct node*)a;
    struct node *d=(struct node*)b;
    /*if(c<d){
	  	return -1;
	}
    else if(c==d){
	  	return 0;
	}
    else 
	  	return 1;*/
	if(c->s == d->s){
		return (int)(c->num - d->num);
	}
	return (int)(c->s - d->s);
}
using namespace std;
int main(){
	fstream in;
	int i=0;
	char  filename[20]="rgb.txt";
	int size,num,s,e;
	printf("\nEnter Input filename: \n");
	scanf("%s",filename);
		in.open(filename);
    if(!in){
		printf("can not open this filename\n");
    	exit(1);
	}
	in>>size;
	node input[size];
	vector<int> reg[size];
	//cout<<size;
	for(int i=0;i<size;i++){
		in>>num>>s>>e;
		input[i].num=num;
		input[i].s=s;
		input[i].e=e;
		input[i].del=0;
	}
	qsort(input,size, sizeof(node),compare );
	//check sort data
	cout<<"******sort result*******"<<endl;
	for(int i=0;i<size;i++){
		cout<<input[i].num<<" "<<input[i].s<<" "<<input[i].e<<endl;
	}
	int index=0;
	int f=1;
	while(f){
		int last=0;
		for(int i=0;i<size;i++){
			if(input[i].s>=last and input[i].del==0){
				reg[index].push_back(input[i].num);
				input[i].del=1;
				last=input[i].e;
			}
		}
		//check if all del
		int t=0;
		for(int i=0;i<size;i++){
			t+=input[i].del;
		}
		if(t==size)
			f=0;
		index++;
	}
	cout<<"******number of register *******"<<endl;
	cout<<"need "<<index<<" registers"<<endl;
	cout<<"******left edge result*******"<<endl;
	for(int i=0;i<index;i++){
		cout<<"register num:"<<i+1<<":";
		for(int j=0;j<reg[i].size();j++){
			cout<<"v"<<reg[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
