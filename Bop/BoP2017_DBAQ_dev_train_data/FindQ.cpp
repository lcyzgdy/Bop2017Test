#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream in("BoP2017-DBQA.dev.txt");
ofstream out("ResultQuestions.dev.txt");

int main()
{
	string ans;
	string q, a;
	string last;
	while(in>>ans>>q)
	{
		getline(in, a);
		if(q==last) continue;
		out<<q<<"\r\n";
		last=q;
	}
	return 0;
}