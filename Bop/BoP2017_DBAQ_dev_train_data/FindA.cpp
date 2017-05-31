#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream in("BoP2017-DBQA.dev.txt");
ofstream out("ResultAnswer.dev.txt");

int main()
{
	string ans;
	string q, a;
	string last;
	while(in>>ans>>q)
	{
		getline(in, a);
		if(q!=last) out<<"\r\n\r\n";
		out<<a;
		last=q;
	}
	return 0;
}