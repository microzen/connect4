#include <iostream>
#include <stack>
#include "../connect4/connect4.hpp"

class RecordingStru
{
public:
    RecordingStru(int spet, PieceColor color)
    {
        _spet = spet;
        _color = color;
    }

private:
    int _spet;
    PieceColor _color;
};
// template<typename T>
class recordingStack
{
public:
    void push(RecordingStru stru)
    {
        if (_index >= C4_MAXVALUE)
        {
            throw "";
        }
        _spets[++_index] = stru;
    }
    void pop()
    {
        if (_index < 0)
        {
            throw "";
        }
        // delete _spets[C4_MAXVALUE];
        _index--;
    }

private:
    int _index = -1;
    RecordingStru _spets[C4_MAXVALUE];
};

using namespace std;
class RecordingCore
{
private:
    stack<RecordingStru> _recording_stack;

public:
    RecordingCore();
    void addSpet(int spet, PieceColor color);
    int removeSpet();
    ~RecordingCore();
};

RecordingCore::RecordingCore()
{
}

RecordingCore::~RecordingCore()
{
}

void RecordingCore::addSpet(int spet, PieceColor color)
{
    RecordingStru re(spet, color);
    _recording_stack.push(re);
}
int RecordingCore::removeSpet()
{
    _recording_stack.pop();
}
