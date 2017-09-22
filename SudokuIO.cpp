#include<SudokuIO.h>

void SudokuIO::SudokuIO_open() {
	outfile.open("Sudoku.txt");
}

void SudokuIO::SudokuIO_write(int sudoku[][9],int count) {
	if (count > 1)
		outfile << endl;
	for(int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			outfile << sudoku[i][j];
			if (j < 8) outfile << " ";
			else outfile << endl;
		}
}

void SudokuIO::SudokuIO_write(char * msg) {
	outfile << msg << endl;
}

void SudokuIO::SudokuIO_read(char* path) {
	infile.open(path);
	if (!infile) 
		cout << "数独题目不存在" << endl;	
}

bool SudokuIO::SudokuIO_update(int sudoku[][9]) {
	int count = 0;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			if(infile >> sudoku[i][j])
				count++;
		}
	if (count == 81)
		return true;
	else
		return false;
}

void SudokuIO::SudokuIO_close() {
	outfile.close();
	if(infile) infile.close();
}