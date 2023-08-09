class Sudoku {
public:
  // Constructor
  Sudoku(int numbers[9][9]);

  // Destructor
  ~Sudoku();

  // Print the sudoku status
  void Print();

  // Solve the sudoku
  bool Solve();

  // Check if n can be placed in [i][j]

  bool Check(int i, int j, int n);

  bool Validate();

private:
  int matrix[9][9];
};