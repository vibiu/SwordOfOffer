#if !defined(FIRST_CHARACTER_IN_STREAM_H_)
#define FIRST_CHARACTER_IN_STREAM_H_

class CharStatistics
{
  public:
    CharStatistics() : index(0)
    {
        for (int i = 0; i < 256; ++i)
        {
            occurrence[i] = -1;
        }
    }

    void Insert(char ch);

    char FirstAppearingOnce();

  private:
    int occurrence[256];
    int index;
};

void FirstCharacterInStreamTest(const char *testName, CharStatistics chars, char expected);

void FirstCharacterInStreamTest1();

#endif // FIRST_CHARACTER_IN_STREAM_H_
