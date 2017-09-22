#include<iostream>
#include<cstdlib>
#include<SudokuGenerator.h>
#include<SudokuSolve.h>

using namespace std;
int main(int argc, char * argv[]) {
	if (argc != 3) {
		cout << "���������������" << endl;
		return 0;
	}
	else {
		if (strcmp(argv[1], "-c") == 0) {
			if (atoi(argv[2]) >= 1 && atoi(argv[2]) <= 1000000) {
				SudokuGenerator SudokuGenerator(1, atoi(argv[2]));
				SudokuGenerator.run();
			}
			else
				cout << "�������������������Ϸ�" << endl;
			
		}
		else if (strcmp(argv[1], "-s") == 0) {
			SudokuSolve SudokuSolve(argv[2]);
			SudokuSolve.run();
		}
	}
	return 0;
}