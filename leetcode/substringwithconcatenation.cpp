/*30. Substring with Concatenation of All Words  QuestionEditorial Solution  My Submissions

You are given a string, s, and a list of words, words, 
that are all of the same length. 
Find all starting indices of substring(s) in s 
that is a concatenation of each word in words 
exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }

	int findSub(string &str,string sub){
		size_t pos = str.find(sub[0]);
		if(pos==str.end())
			return -1;
		

	
	}
};


int main(){

string s="barfoothefoobarman";
vector<string> words;
words.push_back("foo");
words.push_back("bar");
Solution sol;
vector<int> output = sol.findSubstring(s,words);


return 0;
}
