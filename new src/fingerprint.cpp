#include<iostream>
#include<fstream>
#include<vector>
#include<string>

#define BLOCK_SIZE 4

using namespace std;

string fileread(string);
vector<string> break_string(string);
vector<pair<int,int>> winnow(vector<string>);

int main(int argc, char *argv[])
{
	string file1 = fileread(argv[1]);
	vector<string> f1 = break_string(file1);
	winnow(f1);
	return 0;
}

string fileread(string filename)
{
	ifstream file;
	file.open(filename.c_str());
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

vector<string> break_string(string str)
{
	vector<string> v;
	while(str.size() >= 5)
	{
		v.push_back(str.substr(0,5));
		str = str.substr(5);
	}
	return v;
}

vector<pair<int,int>> winnow(vector<string> v)
{
	pair<int,int> p;
	vector<int> w;
	vector<pair<int,int>> r;
	int min;
	for(auto &x:v)
	{
		int sum=0;
		for(auto &y:x)
		{
			y = (y>96 && y<123)? (y-32):y;
			sum+=y;
		}
		w.push_back(sum%99);
	}
	p.second = -1;
	for(int i=0;i<w.size()-BLOCK_SIZE+1;i++)
	{
		min=i;
		for(int j=1;j<BLOCK_SIZE;j++)
		{
			if(w[min]>=w[i+j])
				min=i+j;
		}
		if(min != p.second)
		{
			p.first = w[min];
			p.second = min;
			r.push_back(p);
		}
	}
	for(auto &x:r)
	{
		cout<<x.first<<endl;
	}
	cout<<endl<<endl;
	return r;
}