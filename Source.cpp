// A Backtracking C++ program to solve Sudoku problem
#include <iostream>
using namespace std;

// UNASSIGNED shows empty
// cells in sudoku grid
#define UNASSIGNED 0

// N indicates the size of Sudoku grid.
// Size will be NxN
#define N 9

// Function to find the Position of EmptyCell
// that is still unassigned
bool FindUnassignedLocation(int grid[N][N], int& row, int& col);

// Function to check if it is safe to
// Enter the selected value at current position
bool isSafe(int grid[N][N], int row, int col, int num);

// Function to solve the Sudoku problem
// by putting different values in EmptyCell
bool SolveSudoku(int grid[N][N])
{
    int row, col;

    // If there is no more unassigned location left
    // we are Sucessful
    if (!FindUnassignedLocation(grid, row, col))
        return true;

    // Try values from digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {

        // Check if selected value is Safe!!!
        if (isSafe(grid, row, col, num))
        {
            // Putting the safe Value to Confirm
            grid[row][col] = num;

            // If value is Correct
            if (SolveSudoku(grid))
                return true;

            // If Incorrect value, try again.
            grid[row][col] = UNASSIGNED;
        }
    }

    // This triggers backtracking
    return false;
}

// Function to find if there are UNASSIGNED cells
// left or NOT.
bool FindUnassignedLocation(int grid[N][N], int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true; // UNASSIGNED cell found
    return false;      // NO UNASSIGNED cell left
}

// Function to Check if Selected Value
// exists in the Row.
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Function to Check if Selected Value
// exists in the Collumn.
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Function to Check if Selected Value
// exists in the 3x3 sub-grid.
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

// Function to Check if Selected Value
// is Safe to place at current UNASSIGNED position.
bool isSafe(int grid[N][N], int row, int col, int num)
{
    /* Function to Check if 'Selected Value' is not already placed in
      current row, current column and current sub-grid */
    int safe;
    if (!UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED)
    {
        safe = 1;
    }

    else
    {
        safe = 0;
    }

    return safe;
}

// A utility function to print grid
void printGrid(int grid[N][N])
{
    cout << endl;
    cout << "***** Solved Sudoku *****"<<endl << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        if (row == 2 || row == 5)
        {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

// Function to check if Sudoku is Valid
void is_sudoku_valid(int grid[N][N])
{
    int unfilledValue = 0;
    // Check if the Sudoku is Already Filled
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                unfilledValue = +1;
            }
        }
    }
    // If filled Display message and exit
    if (unfilledValue == 0)
    {
        cout << "\n Please Enter a Vallid Sudoku" << endl;
        cout << "\n This Sudoku is Already Filled" << endl;
        exit(1);
    }
    // Else solve the Sudoku
    else
    {
        if (SolveSudoku(grid) == true)
            printGrid(grid);
        else
            // If the Sudoku is Invalid, Having wrong prefilled Values
            cout << "No solution exists";
    }
}

// Input Function having 2 suduko grids: default and custom
void sudokuInput(int choice)
{
    if (choice == 1)
    {
        // 0 means unassigned cells
        int grid[N][N] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                          {6, 0, 0, 1, 9, 5, 0, 0, 0},
                          {0, 9, 8, 0, 0, 0, 0, 6, 0},
                          {8, 0, 0, 0, 6, 0, 0, 0, 3},
                          {4, 0, 0, 8, 5, 3, 0, 0, 1},
                          {7, 0, 0, 0, 2, 0, 0, 0, 6},
                          {0, 6, 0, 0, 0, 0, 2, 8, 0},
                          {0, 0, 0, 4, 1, 9, 0, 0, 5},
                          {0, 0, 0, 0, 8, 0, 0, 7, 9} };
        is_sudoku_valid(grid);
    }
    else if (choice == 2)
    {
        int grid[N][N];
        cout << "\nEnter the Sudoku Values" << endl;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> grid[i][j];

        is_sudoku_valid(grid);
    }
    else
    {
        cout << "Invalid Option";
        exit(1);
    }
}

// Driver Code
int main()
{
    int choice;
    cout << "*********Enter Your Choice*********";
    cout << "\n1: Default Sudoku Values" << endl;
    cout << "2: Custom Sudoku Values" << endl;
    cout << "Choice: ";
    cin >> choice;

    sudokuInput(choice);
    return 0;
}