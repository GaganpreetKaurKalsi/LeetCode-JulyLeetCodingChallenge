/*
    Prison Cells After N Days
    -------------------------

    There are 8 prison cells in a row, and each cell is either occupied or vacant.
    Each day, whether the cell is occupied or vacant changes according to the following rules:
    If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
    Otherwise, it becomes vacant.
    (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
    We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
    Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

    Example 1:

    Input: cells = [0,1,0,1,1,0,0,1], N = 7
    Output: [0,0,1,1,0,0,0,0]
    Explanation:
    The following table summarizes the state of the prison on each day:
    Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
    Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
    Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
    Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
    Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
    Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
    Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
    Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

    Example 2:

    Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
    Output: [0,0,1,1,1,1,1,0]

    Note:

    cells.length == 8
    cells[i] is in {0, 1}
    1 <= N <= 10^9
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells,int N) {

        unordered_map<string, int> _map;
        if(N==0){return cells;}
        else{
            for(int i=0;i<N;i++){
                string s(cells.begin(),cells.end());
                if(_map.find(s) != _map.end()){
                    int loop_length = i - _map[s];
                    int remaining_days = (N-i)%loop_length;
                    return prisonAfterNDays(cells,remaining_days);
                }
                else{
                _map.insert({s,i});
                int previous,current;
                previous = cells[0];
                cells[0]=0;
                for(int j=1;j<7;j++){
                    current = cells[j];
                    if((previous==0 &&cells[j+1]==0) || (previous==1 &&cells[j+1]==1)){
                            cells[j]=1;
                    }
                    else{
                        cells[j]=0;
                    }
                    previous = current;
                }
                cells[7]=0;}
            }
        }
        return cells;
    }
};

int main(){
    vector<int> cells,cp;
    int i=0,a;
    int N;
    cout<<"Enter the cell values : ";
    while(i<8){
        cin>>a;
        cells.push_back(a);
        i++;
    }
    cout<<"Enter number of days : ";
    cin>>N;
    Solution obj;
    cp = obj.prisonAfterNDays(cells,N);
    for(i=0;i<8;i++){
        cout<<cp[i]<<" ";
    }
}
