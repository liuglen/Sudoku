#pragma once
#include <SudokuIO.h>
#ifndef SUDOKUSOLVE_H
#define SUDOKUSOLVE_H

using namespace std;

class SudokuSolve {
private:
	int sudoku[9][9];
	int count;
	SudokuIO SudokuIO;
public:
	SudokuSolve(char* path) {
		this->count = 0;
		SudokuIO.SudokuIO_open();
		SudokuIO.SudokuIO_read(path);
	}
	void run();
	bool iterator(int row, int col);
	bool exist(int row, int col, int num);
	void print(int sudoku[][9]);
};

#endif