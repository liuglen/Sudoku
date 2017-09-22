#include<SudokuGenerator.h>
#include<iostream>
#include<SudokuIO.h>

void SudokuGenerator::run() {
	SudokuGenerator::iterator(0, 1);
}

void SudokuGenerator::iterator(int row, int col) {
	if (row == 8 && col == 9) {
		count++;
		print(sudoku);
		if (count == set) {
			cout << count <<"局数独生成完毕" << endl;
			SudokuIO.SudokuIO_close();
			exit(0);
		}
		return;
	}

	if (col == 9) {
		row++;
		col = 0;
	}

	if (sudoku[row][col] == 0) {
		for (int i = 0; i < 9; ++i)
			if (SudokuGenerator::exist(row, col, list[i])) {
				sudoku[row][col] = list[i];
				//print();
				SudokuGenerator::iterator(row, col + 1);
				sudoku[row][col] = 0;
			}
	}

}

bool SudokuGenerator::exist(int row, int col, int num) {
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

void SudokuGenerator::print(int sudoku[][9]) {
	SudokuIO.SudokuIO_write(sudoku, count);
}