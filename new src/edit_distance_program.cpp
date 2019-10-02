#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int minimum(int a, int b)
{
	return (a>b)?b:a;
}

string readfile(char* filename)
{
	ifstream file;
	file.open(filename);
	char ch;
	string s;
	while(!file.eof())
	{
		file>>ch;
		if(ch!=' ' || ch != '\n' || ch != '\t')
			s.push_back(ch);
	}
	return s;
}

int edit_distance(string x, string y)
{
	int lc,tc,cc;
	int **t = new int*[x.size()+1];
	for(int i=0;i<x.size()+1;i++)
	{
		t[i] = new int [y.size()+1];
		for(int j=0;j<y.size()+1;j++)
		{
			t[i][j] = -1;
		}
	}
	
	for(int i=0;i<x.size()+1;i++)
	{
		t[i][0] = i;
	}
	for(int j=0;j<y.size()+1;j++)
	{
		t[0][j] = j;
	}
	
	for(int i=1;i<x.size()+1;i++)
	{
		for(int j=1;j<y.size()+1;j++)
		{
			lc = t[i][j-1];
			lc++; // deletion
			
			// T[i-1][j]
			tc = t[i-1][j];
			tc++; // insertion
			
			// Top-left (corner) cell
			// T[i-1][j-1]
			cc = t[i-1][j-1];
			
			// edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
			cc += (x[i-1] != y[j-1]); // may be replace
			
			// minimumimum cost of current cell
			// Fill in the next cell T[i][j]
			t[i][j] = minimum(lc,minimum( tc, cc));
		}
	}
	return t[x.size()][y.size()];
}

int main(int argc,char *argv[])
{
	string ff,ss;
	ff = readfile(argv[1]);
	ss = readfile(argv[2]);
	int sum =0,sum2 =0;
	
	if(ff.size() > ss.size())
	{
		auto t = ff;
		ff=ss;
		ss=t;
	}
	
	int f = minimum(edit_distance(ff,ss),ff.size());
	int s = minimum(edit_distance(ss,ff),ss.size());
	//cout<<f<<"\t\t"<<s<<endl<<ff.size()<<"\t\t"<<ss.size()<<endl;
	float m = ( (float(f)/ff.size()) * ( float(ff.size()) / ( ff.size()+ss.size() ) ) ) + ( (float(s)/ss.size()) * ( float(ss.size()) / ( ff.size()+ss.size() ) ) );
	//cout<< 100*(1-float(f)/ff.size())<<endl<<100*(1-float(s)/ss.size());
	cout<<100*(1 - m);
	return 0;
}