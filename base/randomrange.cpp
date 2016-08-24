//random range from m to n by bblu @ 2016-08-24
//

#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

// random range is [0,5)
// means [0,1,2,3,4]
int random5(){
	return random()%5;
}

//random5 * 5 => 0,5,10,15,20
//+random5=>0,1,2,3,4,5,6...24
//
int random7(){
	int r25;
	while(r25=random5()*5+random5() >=21);
	return r25/3;
}

int main(){
	int c=1000;
	int arr5[5] = {0};
	int arr7[7] = {0};
	for(int i=0; i<c;i++){
		arr5[random5()]++;
		arr7[random7()]++;
		//printf("h[%i]\n",i);
	}

	for(int i=0;i<5;i++){
		printf("random5[%i]=%f\n",i,(float)arr5[i]/c);
	}
	for(int i=0;i<7;i++){
		printf("random7[%i]=%f\n",i,(float)arr7[i]/c);
	}
	return 0;
}
