#include "sudoku.hh"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[]) {
  int puzzleId = 1;
  if (argc == 2) {
    puzzleId = atoi(argv[1]);
  }
  char file_name[30];
  sprintf(file_name, "./puzzles/puzzle_%d.txt", puzzleId);
  FILE* infile = fopen(file_name, "r");
  if (infile == NULL) {
    printf("Error opening file: %s\n", file_name);
    return 1;
  }

  int numbers[9][9];
  char t;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      t = getc(infile);
      numbers[i][j] = t-'0';
    }
  }
  Sudoku *puzzle = new Sudoku(numbers);

  puzzle->Print();
  auto start = chrono::steady_clock::now();

  bool solution = puzzle->Solve();

  auto end = chrono::steady_clock::now();

  if (solution && puzzle->Validate()) {
    puzzle->Print();
  }
  else if (solution) {
    printf("Error, sudoku no resuelto\n");
  }
  else {
    printf("El sudoku no tiene solucion\n");
  }

  auto diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
  fclose(infile);
  return 0;
}