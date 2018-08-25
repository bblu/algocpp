//
//  maxArea.cpp - weekly
//
//  Created by lu wenbo on 2018/8/24.
//  Copyright © 2018 lu wenbo. All rights reserved.
//
/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int area = 0;
        unsigned long range = height.size();
        if(range < 2) return area;
        int a = 0;
        for(int i=0; i< range-1; i++){
            for(int j = i + 1; j < range; j++){
                a = std::min(height[i],height[j]) * (j-i);
                if( a>area) area = a;
            }
        }
        return area;
    }
};

int main(){
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    Solution *sol = new Solution();
    int area = sol->maxArea(h);
    
    cout << "area:"<< area << endl;
    return 0;
}
