#include<SudokuSolve.h>

void SudokuSolve::run() {
	while (SudokuIO.SudokuIO_update(sudoku)) {
		if (!SudokuSolve::iterator(0, 0))
			SudokuIO.SudokuIO_write("数独无解\n");
	}
	SudokuIO.SudokuIO_close();
	cout << "求解完毕" << endl;
}

bool SudokuSolve::iterator(int row, int col) {
	if (row == 8 && col == 9) {
		count++;
		print(sudoku);
		return true;
	}

	if (col == 9) {
		row++;
		col = 0;
	}

	if (sudoku[row][col] == 0) {
		for (int num = 1; num <= 9; ++num)
			if (exist(row, col, num)) {
				sudoku[row][col] = num;
				if (iterator(row, col + 1))
					return true;
				sudoku[row][col] = 0;
			}
	}
	else if(iterator(row, col + 1))
		return true;
	return false;
}

bool SudokuSolve::exist(int row, int col, int num) {
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

void SudokuSolve::print(int sudoku[][9]) {
	SudokuIO.SudokuIO_write(sudoku, count);
}
