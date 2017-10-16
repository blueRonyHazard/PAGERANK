#include<bits/stdc++.h>
using namespace std;
const double e=0.00001;
int main()
{	int n;
	cout<<"\nEnter the No of sites: ";
	cin>>n;
	vector<int> M[n+1];
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
		}
		L[i]=size;					// declaring L[P]
	}
	/* iterations are as follows              
	  t                                  t-1
	PR(P[i]) = (1-d) + d  *   SUM      PR(Q[i])/L(Q[i])
	                      Q[i]=M(P[i])
	*/
	double tm[n+1];
	int it=0;
	int flag=1;
	while(flag)
	{	for(int i=1;i<=n;i++)
		{	double add = 0.15/n;
			for(int j=0;j<M[i].size();j++)
				add+=0.85*(PR[M[i][j]]/L[M[i][j]]);
			tm[i]=add;			
		}
		it++;
		for(int i=1;i<=n;i++)
		{	if(abs(PR[i]-tm[i])<e)
				flag*=0;
			PR[i]=tm[i];
		}				
	} 
	//cout<<"SITE NAME\tPAGE RANK\n";
	for(int i=1;i<=n;i++)
	{	cout<<i<<"\t"<<PR[i]<<endl;		
	}
	cout<<"\n The iterations are : "<<it;
	return 0;
}
