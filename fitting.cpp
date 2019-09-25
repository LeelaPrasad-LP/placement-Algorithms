#include<bits/stdc++.h>
using namespace std;
struct memory{
	int Max;
	bool alloc;
	int process;
	memory(){Max=0;alloc=false;process=-1;}
	
};

void display(int proc[],int np,memory mem[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"  -----------------"<<endl;
		cout<<"||    MEMORY:"<<mem[i].Max<<"     ||"<<endl;
		if(mem[i].alloc)
		cout<<"||    Allocated:"<<proc[mem[i].process-1]<<"  ||"<<endl;
		cout<<"  -----------------"<<endl<<endl;
	}
}

void firstFit(int proc[],int np,memory mem[],int n)
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!mem[j].alloc&&mem[j].Max>proc[i])
				{mem[j].alloc=true;mem[j].process=i+1;break;}
		}
	}
	display(proc,np,mem,n);
}

void bestFit(int proc[],int np,memory mem[],int n)
{
	for(int i=0;i<np;i++)
	{
		int min=99999,index=-1;
		for(int j=0;j<n;j++)
		{
				int memory=mem[j].Max;
				if(min>=memory&&memory>=proc[i]&&!mem[j].alloc)
				{		min=memory;index=j;}
		}
		if(index>=0)
				{
				 mem[index].alloc=true;
				 mem[index].process=i+1;
				}
	}
	display(proc,np,mem,n);
}
void worstFit(int proc[],int np,memory mem[],int n)
{
	for(int i=0;i<np;i++)
	{
		int max=-1,index=-1;
		for(int j=0;j<n;j++)
		{
				int memory=mem[j].Max;
				if(max<=memory&&memory>=proc[i]&&!mem[j].alloc)
				{		max=memory;index=j;}
		}
		if(index>=0)
				{
				 mem[index].alloc=true;
				 mem[index].process=i+1;
				}
	}
	display(proc,np,mem,n);
}
int main()
{
	cout<<"no.Of Segments of memory"<<endl;
	int seg;
	cin>>seg;
	memory mem[seg];
	cout<<"enter segments memory size"<<endl;
	for(int i=0;i<seg;i++)
		cin>>mem[i].Max;
	int n;
	cout<<"Enter no of process requesting for memory"<<endl;
	cin>>n;
	int proc[n];
	cout<<"enter process - memory sizes"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>proc[i];
	}
	cout<<"enter choice of placement ALGORITHM 1:best 2:first 3.worst"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
				{bestFit(proc,n,mem,seg);
				break;}
		case 2:
				{firstFit(proc,n,mem,seg);
				break;}
		case 3:
				{worstFit(proc,n,mem,seg);
				break;}
}			
}
