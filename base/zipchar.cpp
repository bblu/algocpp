//express the string with repeat length
//eg: aabccccczzz => a2b1c5z3
//


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum { debug = 0 };

const char* input = "aabccccccccccczzziii";

void appendNum(char* buf,int &pos,int num){
	//char * ns = itoa(num);
	//while(&ns){
	//	buf[pos++]=&ns++;
	//}
	if(num<10){
		buf[pos++]=num+'0';
		return;
	}
	char b[16]={0};
	int idx=0;
	while(num > 0){
		int a=num%10;
		num /=10;
		b[idx++]= a +'0';		
	}
	for(int i=0;i < idx;i++){
		buf[pos++]=b[idx-i-1];
		if(debug) printf("b[%d]=%s\n",idx-i-1,&b[idx-i-1]);
	}
	if(debug) printf("num='%s' buf=%s \n",b,buf);
}

char* zipChar(const char* str){

	int len = strlen(str);
	printf("strlen = %d\n",len);

	char* buf= new char[len];
	strcpy(buf,str);
	printf("init buf is %s\n",buf);
	char cur=str[0];
	int num=1;
	int itr=0;
	for(int i = 1; i < len; i++){
		char nex = str[i];
		if(cur==nex)
			num++;
		else
		{
			buf[itr++]=cur;
			appendNum(buf,itr,num);
			//printf("num=%d, buf=%s cur=%s\n",num,buf,&cur);
			if(itr>=len)
				return strcpy(buf,str);
			cur = nex;
			num = 1;
		}
	}
	if(cur){
		buf[itr++]=cur;
		appendNum(buf,itr,num);
		//printf("num=%d, buf=%s,cur=%s\n",num,buf,&cur);
	}
	buf[itr]=0;
	return buf;
}

int main()
{

	char * output = zipChar(input);
	if(debug)
	for(int i=0;i < strlen(input);i++){
		printf("buf[%d]= %s\n",i,&output[i]);
	}
	printf("in=%s,out=%s\n",input,output);
	const char *in="abcdeeffgg";
	output = zipChar(in);
	printf("in=%s,out=%s\n",in,output);

	return 0;
}
