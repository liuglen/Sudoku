#include<iostream>
#include<fstream>

using namespace std;

class SudokuSolve {
private:
	int sudoku[9][9];
	bool flag[2][9];
	bool flag2[9];
public:
	SudokuSolve() {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				cin >> sudoku[i][j];
	}

	void run() {
		iterator(0, 0);
	}

	void iterator(int row, int col) {
		if (row == 8 && col == 9) {
			print();
			return;
		}

		if (col == 9) {
			row++;
			col = 0;
		}

		if (sudoku[row][col] == 0) {
			for (int num = 1; num <= 9; ++num)
				if (exist(row, col, num)) {
					sudoku[row][col] = num;
					//print();
					iterator(row, col + 1);
					sudoku[row][col] = 0;
				}
		}
		else
			iterator(row, col + 1);
	}

	bool exist(int row, int col, int num) {
		int x = row / 3 * 3,
			y = col / 3 * 3;

		for (int i = x; i < x + 3; ++i)
			for (int j = y; j < y + 3; ++j)
				if (sudoku[i][j] == num)
					return false;


		for (int i = 0; i < 9; ++i)
			if (sudoku[row][i] == num || sudoku[i][col] == num)
				return false;

		return true;
	}

	void print() {
		ofstream of;
		of.open("sudoku.txt", ios::app);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				of << sudoku[i][j];
				if (j < 8) of << " ";
				else of << endl;
			}
		}
		of << endl;
	}
};

//int main() {
//	SudokuSolve sudokusolve;
//	sudokusolve.run();
//}