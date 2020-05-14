#if !defined(ROBOT_MOVE_H)
#define ROBOT_MOVE_H
int movingCount(int threshold, int rows, int cols);

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited);

bool check(int threshold, int rows, int cols, int row, int col, bool *visited);

int getDigitSum(int number);

void RobotMoveTest(const char *testName, int threshold, int rows, int cols, int expected);

void RobotMoveTest1();

#endif // ROBOT_MOVE_H
