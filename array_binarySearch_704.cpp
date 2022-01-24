#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;

int binarySeach(vector<int>& num,int target){
    int left = 0;
    int right = num.size() - 1;
    while (left <= right)
    {   
        // int middle = (left+right)/2;
        int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
        if( num[middle] >target){
            right = middle-1;
        }else if(num[middle]<target){
            left = middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}
int main(){
    vector<int> vec;
    // 输入数组
    int a;
    cin>>a;
    for (int i=0;i<a;i++){
        int b;
        cin>>b;
        vec.push_back(b);
    }
    /* 输出 */
    // sort(vec.begin(),vec.end());
    // for (int i=0;i<a;i++){
    //     cout<<vec[i]<<endl;
    // }
    
    int b = binarySeach(vec,9);
    cout<<b;
    system("pause");
}
