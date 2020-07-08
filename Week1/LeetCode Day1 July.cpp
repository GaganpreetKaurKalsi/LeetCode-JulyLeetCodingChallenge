/*  Arranging Coins
    ---------------

    You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
    Given n, find the total number of full staircase rows that can be formed.
    n is a non-negative integer and fits within the range of a 32-bit signed integer.

    Example 1:
    n = 5
    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤
    Because the 3rd row is incomplete, we return 2.

    Example 2:
    n = 8
    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤ ¤
    ¤ ¤
    Because the 4th row is incomplete, we return 3.

*/
#include<iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(long int n) {
        int sum=0,add=1;
        while((sum+=add)<=n){
            add++;
        }
        return add-1;
    }
};

int main()
{
    Solution obj;
    long int n,lines;
    cout<<"Enter Number of coins : ";
    cin>>n;
    lines=obj.arrangeCoins(n);
    cout<<"The number of complete lines : "<<lines;
}
