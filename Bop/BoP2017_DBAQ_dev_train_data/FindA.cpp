#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream in("BoP2017-DBQA.dev.txt");
ofstream out("FAnswer.txt");

int main()
{
	string ans;
	string q, a;
	string last;
	//in.ignore();
	while(in>>ans>>q)
	{
		getline(in, a);
		//if(q==last) continue;
		//if(ans=="1")
		out<<a<<"##";
		//last=q;
	}
	return 0;
}