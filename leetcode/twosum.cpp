#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
	unordered_map<int, int> mark;
	vector<int> result;

	for(int i=0; i<nums.size(); i++){
		bool findSecond = mark.find(nums[i]) != mark.end();
		if(!findSecond){
			mark[target - nums[i]] = i;
			printf("num[%d]=%d, mark[%d]=%d\n",i, nums[i],target-nums[i],i);
		}
		else
		{
			printf("nums[%d]=%d\n",i,nums[i]);
			result.push_back(mark[nums[i]]);
			result.push_back(i);
			printf("result.push_back[%d, %d]\n",mark[nums[i]],i);
			break;
		}
	}
	return result;
}

int main(){
	vector<int> input;
	input.push_back(33);
	input.push_back(2);
	input.push_back(7);
	input.push_back(15);
	input.push_back(3);

	vector<int> a = twoSum(input,5);

	printf("[%d,%d]\n",a[0],a[1]);
	return 0;
}
