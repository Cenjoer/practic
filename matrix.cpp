#include <iostream>

int** create_matrix(int rows,int cols)
{
  int** matrix =new int*[rows];
  int emergency_d = 0;
  try{
    for(int i =0;i < rows;i++){
        matrix[i]=new int[cols];
        emergency_d ++;
    }
  }
  catch(...){
    for(int j=0;j<emergency_d;j++){
        delete[] matrix[j];
    }
    delete[] matrix;
    throw;
  }
   return matrix;
}

void free_matrix(int **matrix, int rows) {
    if (matrix == nullptr) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool input_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(std::cin >> matrix[i][j])) {
                throw;
            }
        }
    }
    return true;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int **transpose_matrix(int **matrix, int rows, int cols) {
    int **transposed = create_matrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main()
{
  int rows;
  int cols;
  try{
    std::cin>>rows>>cols;
  }
  catch(...){
    return 1;
  }
  int** matrix = nullptr;
  int** trasported = nullptr;
  try{
    matrix = create_matrix(rows,cols);
  }
  catch(...){
        return 2;
  }
  try{
    input_matrix(matrix,rows,cols);
  }
  catch(...){
    free_matrix(matrix,rows);
    return 1;
  }
  try{
    trasported=transpose_matrix(matrix,rows,cols);
  }
  catch(...){
    return 2;
  }
  print_matrix(matrix,rows,cols);
  print_matrix(trasported,cols,rows);

  free_matrix(matrix,rows);
  free_matrix(trasported,cols);

  return 0;
}