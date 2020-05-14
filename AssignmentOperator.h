#ifndef ASSIGNMENT_OPERATOR_H_
#define ASSIGNMENT_OPERATOR_H_
class CMyString
{
  public:
    CMyString(const char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString &operator=(const CMyString &str);

    void Print();

  private:
    char *m_pData;
};

void AssignmentOperatorTest1();
void AssignmentOperatorTest2();
void AssignmentOperatorTest3();
#endif
