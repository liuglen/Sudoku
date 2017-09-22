#pragma once
#include <ctime>
#include <cstdlib>
#include <SudokuIO.h>
using namespace std;

#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H
class SudokuGenerator {
private:
	int sudoku[9][9];
	int list[9];
	int InitialValue;	//can't be changed
	int count;
	int set;
	SudokuIO SudokuIO;
public:
	SudokuGenerator(int InitialValue, int set) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				sudoku[i][j] = 0;

		for (int i = 0; i < 9; ++i)
			list[i] = i + 1;

		srand((int)time(NULL));
		for (int i = 0; i< 9; ++i) {
			int tmp = rand() % 9;
			int t = list[i];
			list[i] = list[tmp];
			list[tmp] = t;
		}

		this->InitialValue = InitialValue;
		this->count = 0;
		this->set = set;
		sudoku[0][0] = InitialValue;
		SudokuIO.SudokuIO_open();
	}
	void run();
	void iterator(int row, int col);
	bool exist(int row, int col, int num);
	void print(int sudoku[][9]);
};

#endif