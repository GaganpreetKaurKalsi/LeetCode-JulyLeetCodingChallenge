/*  Ugly Number II
    --------------

    Write a program to find the n-th ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

    Example:

    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

    Note:
    1 is typically treated as an ugly number.
    n does not exceed 1690.
*/

#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> possible_ugly,fixed_ugly;
        possible_ugly.insert(1);
        while(fixed_ugly.size()!=n){
            int next_ugly = *possible_ugly.begin();
            fixed_ugly.insert(next_ugly);
            possible_ugly.erase(next_ugly);
            possible_ugly.insert(next_ugly*2);
            possible_ugly.insert(next_ugly*3);
            possible_ugly.insert(next_ugly*5);
        }
        return *fixed_ugly.rbegin();
    }
};

int main()
{
    int n,uglynum;
    cout<<"Enter the value of n where n is the nth ugly number : ";
    cin>>n;
    Solution obj;
    uglynum=obj.nthUglyNumber(n);
    cout<<endl<<uglynum<<endl;
}


/*
    NOT EFFICIENT FOR GREATER VALUE OF N
    ****OTHERWISE WORKING PERFECTLY****

class Solution {
public:
    int nthUglyNumber(int n) {
        int i=1,num=1,temp;
        while(true){
            if(i==n){return num;}
            num++;
            temp=num;
            while(temp%2==0 && temp!=1){temp=temp/2;}
            while(temp%3==0 && temp!=1){temp=temp/3;}
            while(temp%5==0 && temp!=1){temp=temp/5;}
            if(temp==1){
                cout<<num<<" ";
                i++;  // i is the counter which counts the number of ugly numbers
            }
        }
    }
};
*/
