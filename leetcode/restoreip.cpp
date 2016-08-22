/*93. Restore IP Addresses
Total Accepted: 63767
Total Submissions: 259119
Difficulty: Medium
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		int len = s.size();
		if(len<4 || len>12)
			return result;
		string ip;
		genAddress(s,0,0,ip,result);
		return result;
    }

	void genAddress(const string &s,int start,int partNum,string ip,vector<string> &result){
		int len = s.size();
		if(len-start < 4-partNum || len-start > (4-partNum)*3){
			cout << start <<  " valid length for generate ip! "<<partNum << endl;
			return;
		}

		if(partNum == 4 && start == len){
			ip.erase(ip.size()-1);
			cout <<"partNum="<<partNum << " result.push_back(" << ip.c_str()<<")"<<endl;
			result.push_back(ip);
			return;
		}
		int num=0;
		for(int i=start; i<start+3;i++){
			if(i>=len)
				break;
			num = num*10 + s[i]-'0';
			if(num<256){
				ip+=s[i];
				//ip.push_back('.');
				cout <<"---num="<<num <<" partNum="<< partNum <<" : " << ip.c_str() << endl;
				genAddress(s, i+1, partNum+1, ip+'.', result);
				if(num==0){
					break;//0.0.01.108 is valid
				}
			}
		}
		cout <<"num="<<num <<" partNum="<< partNum <<" : " << ip.c_str() << endl;
	
	}
};

int main(){
	vector<string> strs;
	//strs.push_back("8888");
	strs.push_back("000108");
	//strs.push_back("19216811");
	//strs.push_back("127001");
	//strs.push_back("2552551113");

	Solution sol;
	for(int i=0;i<strs.size();i++){
		cout << "str="<< strs[i].c_str() << endl;

		vector<string> ips=sol.restoreIpAddresses(strs[i]);
	
		for(int i=0;i< ips.size();i++){
			cout << ips[i]<<endl;
		}
		cout << endl;
	}
	return 0;
}
