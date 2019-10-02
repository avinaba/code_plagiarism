#include<iostream> 
#include<fstream>
#include<cmath>  
#include<climits> 
#include<vector>
#define MAXN 1001
using namespace std;

vector<int> readfile(char *filename);

vector<int> firstarr(MAXN),secondarr(MAXN); 
int firstarrlength,secondarrlength; 

int levelfirst[MAXN],levelsecond[MAXN]; //level is the independent level 
double ScoreDp[MAXN][MAXN];


double min(double a,double b)
{ 
	if(a<b) 
		return a; 
	else 
		return b; 
	
} 

bool isvalid(long long b)
{ 
	if(b>=10000) 
		return false; 
	else 
		return true; 
}

double calculateSimilarityMeasure(int i,int j)
{
	double sum=(double)fabs(firstarr[i]-secondarr[j])/(firstarr[i]+secondarr[j]); //Canberra Distance 
	return (sum*100.0); 
}

void init(int len1,int len2)
{ 
	firstarrlength=len1; 
	secondarrlength=len2; //worstscore=0;
}

int main(int argc,char *argv[])
{ 
	for(int i=0;i<MAXN;i++)
	{ 
		for(int j=0;j<MAXN;j++)
		{ 
			ScoreDp[i][j]=(double)(10000.0); 
		} 
	} 
	/*For all permutation of same level weneed to call init() --implement this later */
	//int len1=int(*argv[1])+8; 
	//int len2=int(*argv[2])+8; 
	//cout<<len1<<"\t\t"<<len2;
	//for(int i=0;i<len1;i++) 
		//cin>>firstarr[i]; 
	//cout <<"FirstTaken"<<endl; 
	//for(int i=0;i<len2;i++) 
		//cin>>secondarr[i]; 
	//cout <<"Second Taken"<<endl; 
	//init(len1,len2); 
	//int len1,len2;
	//cin>>len1>>len2;
	
	firstarr = readfile(argv[1]);
	secondarr = readfile(argv[2]);
	cout<<firstarr.size()<<"\t\t"<<secondarr.size();
	cout.flush();
	
	ScoreDp[0][0]=calculateSimilarityMeasure(0,0); 
	ScoreDp[0][1]=min(calculateSimilarityMeasure(0,0 ),calculateSimilarityMeasure(0,1));
	for(int i=1;i<firstarr.size();i++)
	{ 
		for(int j=1;j<secondarr.size();j++)
		{ 
			double a=(double)10000.0; 
			if(isvalid((long long)ScoreDp[i-1][j-1]))
			{ 
				a=((double)calculateSimilarityMeasure(i,j)+ (double)ScoreDp[i-1][j-1]);
				
			}
			double b=(double)10000.0; 
			if(i<j) 
				b=(double)ScoreDp[i][j-1];
			if(!isfinite(double(a)))
			{
				a=0;
			}
			if(!isfinite(double(b)))
			{
				b=0;
			}
			ScoreDp[i][j]=(double)min(b,a);
			//if (isnan(double(ScoreDp[i][j])))
				//ScoreDp[i][j] =0;
		} 
		
	} 
	cout <<"Similar Percentage :: "<<(100-(ScoreDp[firstarrlength-1][secondarrlength-1]) /firstarr.size()) <<"%"<<endl;
	return 0; 
	
}

vector<int> readfile(char *filename)
{
	cout.flush();
	fstream fp;
	fp.open(filename,ios::in);
	vector<int> lst;
	int i,j=0;
	char ch;
	while(!fp.eof())
	{
		fp>>i;
		lst.push_back(i);
		//cout<<i<<endl;
		//ch=getchar();
		j++;
	}
	return lst;
}