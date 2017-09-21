#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

ofstream of;

class SudokuGenerator {
private:
	int sudoku[9][9];
	int list[9];
	bool flag[2][9];
	int InitialValue;	//can't be changed
	int count;

public:
	SudokuGenerator(int InitialValue) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				sudoku[i][j] = 0;

		for (int i = 0; i < 9; ++i)
			list[i] = i + 1;
		
		srand((int)time(NULL));
		for (int i = 0; i< 9; ++i){
			int tmp = rand() % 9;
			int t = list[i];
			list[i] = list[tmp];
			list[tmp] = t;
		}

		this->InitialValue = InitialValue;
		this->count = 0;

		sudoku[0][0] = InitialValue;
	}

	void run() {
		iterator(0, 1);
	}

	void iterator(int row, int col) {
		if (row == 8 && col == 9) {
			count++;
			print();
			if (count == 100)
				exit(0);
			return;
		}

		if (col == 9) {
			row++;
			col = 0;
		}

		if (sudoku[row][col] == 0) {
			for (int i = 0; i < 9; ++i)
				if (exist(row, col, list[i])) {
					sudoku[row][col] = list[i];
					//print();
					iterator(row, col + 1);
					sudoku[row][col] = 0;
				}
		}

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
		of << this->count << endl;
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
	SudokuGenerator sudoku(1);
	of.open("sudoku.txt");
	sudoku.run();
	of.close();
}