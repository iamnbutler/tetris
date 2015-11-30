class Shape {
  boolean[][] matrix;
  int c;
   
  Shape(int n, int[] blockNums, color c) {
    matrix = new boolean[n][n];
    for (int x = 0; x < n; ++x)
      for (int y = 0; y < n; ++y)
        matrix[x][y] = false;
    for (int i = 0; i < blockNums.length; ++i)
      matrix[blockNums[i]%n][blockNums[i]/n] = true;
    this.c = c;
  }
   
  Shape(Shape other) {
    matrix = new boolean[other.matrix.length][other.matrix.length];
    for (int x = 0; x < matrix.length; ++x)
      for (int y = 0; y < matrix.length; ++y)
        matrix[x][y] = other.matrix[x][y];
    this.c = other.c;
  }
   
  
}