#pragma once

#include<fstream>
#include<iostream>
using namespace std;

#ifndef SUDOKUIO_H
#define SUDOKUIO_H

class SudokuIO {
private:
	ofstream outfile;
	ifstream infile;
public:
	SudokuIO() {}

	void SudokuIO_open();

	void SudokuIO_write(int sudoku[][9], int count);

	void SudokuIO_read(char* path);

	bool SudokuIO_update(int sudoku[][9]);

	void SudokuIO_close();

	void SudokuIO_write(char *msg);
};

#endif // !SUDOKUIO_H
