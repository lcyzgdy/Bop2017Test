#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

ifstream inq("FinalQuestion.key.jieba.txt");
ifstream ina("FinalAnswer.key.jieba.txt");
ofstream out("FinalResult2.txt");

const long long max_size = 2000;         // max length of strings
const long long N = 10;                  // number of closest words that will be shown
const long long max_w = 50;              // max length of vocabulary entries

string question;
string answer;

int main()
{
	FILE *f;
    char st1[max_size];
    char *bestw[N];
    char file_name[max_size], st[100][max_size];
    float len;
    long long words, size, a, b, c, cn, bi[100];
    float *M;
    char *vocab;
    //if (argc < 2) {
        //printf("Usage: ./distance <FILE>\nwhere FILE contains word projections in the BINARY FORMAT\n");
        //return 0;
    //}
    //strcpy(file_name, argv[1]);
	strcpy(file_name, "vectors.bin");
    f = fopen(file_name, "rb");
    if (f == NULL) {
        printf("Input file not found\n");
        return -1;
    }
    fscanf(f, "%lld", &words);
    fscanf(f, "%lld", &size);

	vocab = (char *)malloc((long long)words * max_w * sizeof(char));
    for (a = 0; a < N; a++) bestw[a] = (char *)malloc(max_size * sizeof(char));
    M = (float *)malloc((long long)words * (long long)size * sizeof(float));
    if (M == NULL) 
	{
        printf("Cannot allocate memory: %lld MB    %lld  %lld\n", (long long)words * size * sizeof(float) / 1048576, words, size);
        return -1;
    }
    for (b = 0; b < words; b++) 
	{
        a = 0;
        while (1) {
            vocab[b * max_w + a] = fgetc(f);
            if (feof(f) || (vocab[b * max_w + a] == ' ')) break;
            if ((a < max_w) && (vocab[b * max_w + a] != '\n')) a++;
        }
        vocab[b * max_w + a] = 0;
        for (a = 0; a < size; a++) fread(&M[a + b * size], sizeof(float), 1, f);
        len = 0;
        for (a = 0; a < size; a++) len += M[a + b * size] * M[a + b * size];
        len = sqrt(len);
        for (a = 0; a < size; a++) M[a + b * size] /= len;
    }
    fclose(f);

	inq.ignore();
	ina.ignore();
	int yyyy=0;

	while(1)
	{
		float questionVector[max_size];
		float answerVector[max_size];
		bool eofFlag=true;
		memset(questionVector, 0, sizeof(questionVector));
		memset(answerVector, 0, sizeof(answerVector));

    	while (inq>>question)
		{
			a = 0;
			if(question=="##")
			{
				eofFlag=false;
				break;
			}
			//cout<<question<<endl;
			eofFlag=false;
       		cn = 0;
       		b = 0;
       		c = 0;
			strcpy(st[0], question.c_str());

			a=0;
			
	        for (b = 0; b < words; b++) if (!strcmp(&vocab[b * max_w], st[a])) break;
	        if (b == words) b = -1;
	        bi[a] = b;
	        
	        if (b == -1) continue;
		
	        float first[max_size], second[max_size];
	        for (a = 0; a < size; ++a)
			{
	            first[a] = M[a + bi[0] * size];
	        }
	        for (a = 0; a < size; ++a) 
			{
				questionVector[a]+=first[a];
	        }
	    }

		while (ina>>answer)
		{
	        if (answer=="##") 
			{
				eofFlag=false;
				break;
			}
			//cout<<answer<<endl;
			eofFlag=false;
			a = 0;
	        cn = 0;
	        b = 0;
	        c = 0;
			strcpy(st[0], answer.c_str());
			a=0;
			
	        for (b = 0; b < words; b++) if (!strcmp(&vocab[b * max_w], st[a])) break;
	        if (b == words) b = -1;
	        bi[a] = b;
	        
	        if (b == -1) continue;
		
	        float first[max_size];
	        for (a = 0; a < size; ++a)
			{
	            first[a] = M[a + bi[0] * size];
	        }
	        for (a = 0; a < size; ++a)
			{
				answerVector[a]+=first[a];
	        }
	    }

	    float product1 = 0.0, product2 = 0.0, sum12 = 0.0;

		for (a = 0; a < size; ++a) 
		{
	    	product1 = product1 + questionVector[a] * questionVector[a];
	    	product2 = product2 + answerVector[a] * answerVector[a];
	        sum12 = sum12 + questionVector[a] * answerVector[a];
	    }

	    float len1 = sqrt(product1);
	    float len2 = sqrt(product2);
		//cout<<len1<<' '<<len2<<endl;
	    float similarity = sum12/(len1 * len2);
		if(eofFlag && yyyy>0) break;

		if(len1 * len2 == 0 && yyyy>0) out<<0.0f<<"\r\n";
		else if(yyyy==0)
		{
			yyyy++;
			continue;
		} 
		else out << similarity << "\r\n";
		//out<<similarity<<"\r\n";
		yyyy++;
	}
	return 0;
}