#include<bits/stdc++.h>
using namespace std;
int main()
{	int n;
	cout<<"\nEnter the No of sites: ";
	cin>>n;
	vector<int> M[n+1];
	vector<int> N[n+1];
	int L[n+1];
	double PR[n+1];
	int x,y;
	cout<<"\nEnter the outgoing links from each site: \n";
	for(int i=1;i<=n;i++)	//initialise the PR[P] = 1/n at first
		PR[i]=(double)1/n;
	for(int i=1;i<=n;i++)
	{	cout<<i<<": ";
		int size;
		cin>>size;
		for(int j=0;j<size;j++)		// declaring M[P]
		{	cin>>x;
			M[x].push_back(i);
			N[i].push_back(x);
		}
		L[i]=size;					// declaring L[P]
	}
	/* iterations are as follows              
	  t                                  t-1
	PR(P[i]) = (1-d) + d  *   SUM      PR(Q[i])/L(Q[i])
	                      Q[i]=M(P[i])
	*/
	double tm[n+1];
	for(int it=1;it<=10;it++)
	{	for(int i=1;i<=n;i++)
		{	double add = 0.15/n;
			for(int j=0;j<M[i].size();j++)
			{	double temp=0.0;
				for(int k=0;k<N[M[i][j]].size();k++)
					temp+=PR[N[M[i][j]][k]];
				add+=0.85*PR[M[i][j]]*(PR[i]/temp);
			}
			tm[i]=add;			
		}
		for(int i=1;i<=n;i++)
			PR[i]=tm[i];			
	}
	//cout<<"SITE NAME\tPAGE RANK\tINDEGREE\tOUTDEGREE\n";
	for(int i=1;i<=n;i++)
	{	cout<<i<<"\t"<<PR[i]<<endl;		
	}
}
