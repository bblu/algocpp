//check for the same charactor in a string
//
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

bool checkUnique1(const char* str){
	int s = strlen(str);
	std::map<char,short> strMap;
	for(short i=0;i < s; i++){
		strMap[str[i]]=i;
	}
	return s==strMap.size();	
}
bool checkUnique2(const char* str){
	int i=0;
	char chr = str[i];
	while(chr){
		int j=i+1;
		char nxt = str[j];
		while(nxt){
			if(chr == nxt)
				return false;
			nxt = str[j++];
		}
		chr = str[++i];
	}	
	return true;
}

bool checkUnique3(const char* str)
{
	short cmap[127]={0};
	int i=0;
	while(short c=(short)str[i++]){
		cmap[c]++;
		//printf("%s=%d ",&str[i],cmap[c]);
		if(cmap[c]>1){
			return false;
		}
	}
	return true;
}

int main()
{

string strs[ ]={"Hello","world","bblu","xiamen","12321"};
int s = sizeof(strs);

for(int i = 0; i < s; i++){
	const char* str = strs[i].c_str();
	if(checkUnique1(str))
		printf("[%d] %s is unique!\n",i,str);
	else 
		printf("[%d] %s is not unique!\n",i,str);

	if(checkUnique2(str))
		printf("[%d] %s is unique!\n",i,str);
	else 
		printf("[%d] %s is not unique!\n",i,str);

	if(checkUnique3(str))
		printf("[%d] %s is unique!\n",i,str);
	else 
		printf("[%d] %s is not unique!\n",i,str);
}
return 0;
}
