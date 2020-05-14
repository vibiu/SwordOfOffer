#if !defined(STRING_PATH_IN_MATRIX_H)
#define STRING_PATH_IN_MATRIX_H

bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char *str, int &pathLength,
                 bool *visited);

bool hasPath(const char *matrix, int rows, int cols, const char *str);

void StringPathInMatrixTest(const char *testName, const char *matrix, int rows, int cols, int row, int col,
                            const char *str, bool expected);

void StringPathInMatrixTest1();
#endif // STRING_PATH_IN_MATRIX_H
