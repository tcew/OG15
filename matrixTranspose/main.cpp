#include <iostream>

#include "occa.hpp"

int main(int argc, char **argv){

  const int rows = 2;
  const int cols = 3;

  int *A  = (int*) malloc(rows * cols * sizeof(int));
  int *AT = (int*) malloc(cols * rows * sizeof(int));

  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < cols; ++c)
      A[c + r*cols] = c;
  }

  for(int c = 0; c < rows; ++c)
    for(int r = 0; r < cols; ++r){
      AT[c + r*rows] = 0;
  }

  // Transpose
  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < cols; ++c)
      AT[r + c*rows] = A[c + r*cols];
  }

  // Print Matrices
  printf("A  = \n");
  for(int r = 0; r < rows; ++r){
    printf("    |");

    for(int c = 0; c < cols; ++c)
      printf(" %d", A[c + r*cols]);

    printf(" |\n");
  }

  printf("AT = \n");
  for(int r = 0; r < cols; ++r){
    printf("    |");

    for(int c = 0; c < rows; ++c)
      printf(" %d", AT[c + r*rows]);

    printf(" |\n");
  }

  free(A);
  free(AT);

  return 0;
}
