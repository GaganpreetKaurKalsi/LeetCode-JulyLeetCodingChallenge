/*  Island Perimeter
    ----------------

    You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
    Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island
    (i.e., one or more connected land cells).
    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1.
    The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

    Input:
    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]

    Output: 16
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int c=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){                              // The whole matrix is covered with water on all 4 sides
                    if(i-1 < 0){c++;}                           //check if there is a boundary on top - > means 1 lies on topmost row
                    if(i+1 >= m){c++;}                          //check if there is a boundary at bottom - > means 1 lies on last row
                    if(j-1 < 0){c++;}                           //check if there is a boundary on left - > means 1 lies in 1st column
                    if(j+1 >= n){c++;}
                    if(i-1>=0 && grid[i-1][j]==0){c++;}
                    if(i+1<m && grid[i+1][j]==0){c++;}
                    if(j-1>=0 && grid[i][j-1]==0){c++;}
                    if(j+1<n && grid[i][j+1]==0){c++;}
                }
            }
        }
        return(c);
    }
};
int main(){
    int m,n,count;
    cout<<"Enter width(int) and height(int) : ";
    cin>>m>>n;
    vector<vector<int>> grid(m);
    cout<<"\nEnter the elements of the 2D vector array : "<<endl;
    for(int i=0;i<m;i++){
            grid[i]=vector<int>(n);
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;
    count = obj.islandPerimeter(grid);
    cout<<"\nThe PERIMETER of the island is : "<<count;
}
