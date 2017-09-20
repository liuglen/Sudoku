#include<iostream>
#include<fstream>

using namespace std;

class SudokuSolve {
private:
	int sudoku[9][9];
	bool flag[2][9];
public:
	SudokuSolve() {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				cin >> sudoku[i][j];
	}

	void clear() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 9; ++j)
				flag[i][j] = false;
	}

	void run() {
		iterator(1, 0);
	}

	int iterator(int num, int i) {
		if (i == 9 && num == 9) {
			print();
			return 2;
		}
		if (i == 9 && num < 9)
			return iterator(num + 1, 0);

		if (i == 0) {
			clear();
			for (int p = 0; p < 9; ++p)
				for (int q = 0; q < 9; ++q)
					if (sudoku[p][q] == num) {
						flag[0][p] = true;
						flag[1][q] = true;
					}
		}

		int j;
		for (j = 0; j < 9; ++j) {
			int x = i / 3 * 3 + j / 3;
			int y = (i % 3) * 3 + j % 3;
			if (sudoku[x][y] == num && iterator(num, i + 1) == 1)
				return 1;
			if (flag[0][x] == false && flag[1][y] == false && sudoku[x][y] == 0) {
				flag[0][x] = true;
				flag[1][y] = true;
				sudoku[x][y] = num;
				print();
				if (iterator(num, i + 1) == 1) {
					flag[0][x] = false;
					flag[1][y] = false;
					sudoku[x][y] = 0;
				}
			}
		}
		if (j == 9)
			return 1;
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

int main() {
	SudokuSolve sudokusolve;
	sudokusolve.run();
}