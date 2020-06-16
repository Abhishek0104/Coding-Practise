/*  
    Backtracking Algorithm to find out whether a knight starting from first cell of 8x8 chess board
    can cover each an every cell of the board exactly once or not.
*/
#include<bits/stdc++.h>
using namespace std;
#define N 8 
//This code checks whether the cells are valid or not.
int IsSafe(int x, int y, int sol[N][N])
{
    if(x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    else
    {
        return 0;
    }
    
}
//prints the solution.
void PrintSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) 
    { 
        for (int y = 0; y < N; y++) 
            cout << " " << setw(2)  
                        << sol[x][y] << " "; 
        cout << endl; 
    } 
    return;
}
//The puprose of this code is to find solution using backtracking.
int NextStep(int x, int y, int move, int sol[N][N], int xmove[], int ymove[])
{
    int nextx, nexty; //variable to find out the next x and y for movement.
    if(move == N*N)
        return 1;
    //function to move the knight on all the 8 possible ways.
    for(int i = 0; i < 8; i++)
    {
        nextx = x + xmove[i];
        nexty = y + ymove[i];
        //if the movement is valid then recursively we find the next step.
        if(IsSafe(nextx, nexty, sol))
        {
            sol[nextx][nexty] = move;
            //the main recursive function.
            if(NextStep(nextx, nexty, move+1, sol, xmove, ymove) == 1)
                return 1;
            else
            {
                sol[nextx][nexty] = -1;
            }
            
        }
    }
    return 0;
}
//This fucntion initializes all the necessary variables and conditions.
void Solver()
{
    int sol[N][N]; //array to store the solution.
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            sol[i][j] = -1;
    }
    //all the possible x and y movements of the knight.
    int xmove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    if(NextStep(0, 0, 1, sol, xmove, ymove) == 0)
        cout << "Solution does not exists.";
    else
    {
        PrintSolution(sol);
    }
    
}
int main()
{
    Solver();
    return 0;
}
