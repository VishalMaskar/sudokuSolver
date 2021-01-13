# sudokuSolver
The Repository also contains a detailed Informatioin about Project in PDF form. Please go through it...

Sudoku Solver
Aim: 
To solve the 9X9 Sudoku Grid.
Input: 
A Partially filled 9 X 9, 2D Array.
Output: 
A Completely solved Sudoku.
Edge Cases: 
1.	If the grid is completely pre-filled/solved already,
	Program will exit with appropriate Message.
2.	If the Values are Incorrect and a Sudoku grid cannot be made then,
	Program will exit with Appropriate Message.
Technologies Used: 
Open CV, Visual Studio 2019, C++
How to run the Program:
Installation of Required Software’s:
You can Refer to my YouTube Channel: https://youtu.be/riArxlmRMoQ
Approach:
1.	Find out a cell which is empty.
-	Keep track of Column Number and Row Number.
2.	Consider A number to be filled in the empty cell.
-	First check if it is Safe (Traverse and check rows and columns do not have, selected element that we want to enter).
-	If Yes (Safe) assign the number to the current empty cell.
-	Else Try a different number.
3.	Similarly try to fill other empty cells, Recursively.
4.	If you are able to fill all the cells without any conflict then simply return the solved sudoku.

Algorithm:
Step 1: Start
Step 2: Check if Sudoku grid is Valid
Step 3: Create a function to check if a value is placed in current position in grid, does it becomes 	Unsafe or Not.
Step 4: Create a recursive function that takes a grid, to solve grid.
Step 5: Check for unassigned location.
-	assign a number from 1 to 9
-	check if assigning the number to current index makes the grid unsafe or not
-	if safe then recursively call the function for all safe cases from 0 to 9.
-	if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.
Step 6: If solution found Print Solved Sudoku
	Else Print Invalid Sudoku, and Exit
Step 7: Stop

Functions Used:
1.	bool FindUnassignedLocation(int grid[N][N], int row, int col)
- This function finds the location/Position of empty cells in the Grid.

2.	bool isSafe(int grid[N][N], int row, int col, int num);
- Function to check if it is safe to, Enter the selected value at current position.

3.	bool SolveSudoku(int grid[N][N]);
- Reccursive Function to solve the Sudoku problem by putting different values in Empty Cells.

4.	bool UsedInRow(int grid[N][N], int row, int num);
- Function to Check if Selected Value exists in the Row.

5.	bool UsedInCol(int grid[N][N], int col, int num);
- Function to Check if Selected Value exists in the Collumn.

6.	bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
- Function to Check if Selected Value exists in the 3x3 sub-grid.

7.	void printGrid(int grid[N][N]);
- A utility function to print grid.

8.	void is_sudoku_valid(int grid[N][N]);
- Function to check if Sudoku is Valid.

9.	void sudokuInput(int choice);
- Input Function having 2 suduko grids: default and custom.

10.	int main();
- Driver Function to run the Program.
