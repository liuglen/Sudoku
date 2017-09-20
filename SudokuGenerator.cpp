#include <iostream>
#include <fstream>

using namespace std;

class SudokuGenerator {
private:
	int sudoku[9][9];
	bool flag[2][9];
	int InitialValue;	//can't be changed
	int count;

public:
	SudokuGenerator() {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				sudoku[i][j] = 0;

		this->InitialValue = 1;
		this->count = 0;
	}

	void clear() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 9; ++j)
				flag[i][j] = false;
	}

	void run() {
		iterator(1, 0);
	}

	bool iterator(int num, int i) {
		if (i == 9 && num == 9) {
			//print();
			count++;
			if (count == 100000)
				exit(0);
			return true;
		}
		if (i == 9 && num < 9)
			return iterator(num + 1, 0);

		if (i == 0) {
			clear();
			if (num == InitialValue) {
				sudoku[0][0] = InitialValue;
				flag[0][0] = true;
				flag[1][0] = true;
				iterator(num, i + 1);
			}
		}

		int j;
		for (j = 0; j < 9; ++j) {
			int x = i / 3 * 3 + j / 3;
			int y = (i % 3) * 3 + j % 3;
			if (flag[0][x] == false && flag[1][y] == false && sudoku[x][y] == 0) {
				flag[0][x] = true;
				flag[1][y] = true;
				sudoku[x][y] = num;
				
				if (iterator(num, i + 1) == true) {
					flag[0][x] = false;
					flag[1][y] = false;
					sudoku[x][y] = 0;
				}
			}
		}
		if (j == 9)
			return true;
	}


	void print() {
		//ofstream of;
		//of.open("sudoku.txt", ios::app);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << sudoku[i][j];
				if (j < 8) cout << " ";
				else cout << endl;
			}
		}
		cout << endl;
	}

};

//int main() {
//	SudokuGenerator sudoku;
//	sudoku.run();
//}