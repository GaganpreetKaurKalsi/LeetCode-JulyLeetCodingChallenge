/*  Hamming Distance
    ----------------

    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    Given two integers x and y, calculate the Hamming distance.

    Note:
    0 ≤ x, y < 231.

    Example:
    Input: x = 1, y = 4
    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑

    The above arrows point to positions where the corresponding bits are different.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<typeinfo>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=0;
        bitset<32> a(x),b(y);
        cout<<a<<" "<<b<<endl;
        if(x<=31 && y<=31){
            for(int i=0;i<5;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        else if(x<=1023 && y<=1023){
            for(int i=0;i<10;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        else if(x<=32767 && y<=32767){
            for(int i=0;i<15;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        else if(x<=1048575 && y<=1048575){
            for(int i=0;i<20;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        else if(x<=33554431 && y<=33554431){
            for(int i=0;i<25;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        else{
            for(int i=0;i<32;i++){
                if(a[i]!=b[i]){result++;}
            }
        }
        return(result);
    }
};

int main(){
    int x,y,result;
    cout<<"Enter 2 integer values : ";
    cin>>x>>y;
    Solution obj;
    result = obj.hammingDistance(x,y);
    cout<<result;
}
