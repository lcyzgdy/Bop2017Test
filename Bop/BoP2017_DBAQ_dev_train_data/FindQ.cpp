#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

//ifstream in("BoP2017-DBQA.train.txt");
ifstream in("BoP2017-DBQA.test.txt");
//ofstream out("ResultQuestions.train.txt");
ofstream out("FinalQuestion.txt");

int main()
{
	string ans;
	string q, a;
	string last;
	while(in>>q)
	{
		getline(in, a);
		//if(q==last) continue;
		//if(ans=="1")
		out<<q<<"\r\n";
		//last=q;
	}
	return 0;
}