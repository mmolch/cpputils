#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include <mmolch/range.hpp>


struct TestEntry
{
    int start;
    int end;
    int step;
    std::vector<int> results;
};

const std::vector<TestEntry> testdata {
    { 1, 2, 3, { 1 } },
    { 5, 3, 1, {} },
    { -10, -15, -1, { -10, -11, -12, -13, -14 } },
    { -10, 20, 5, { -10, -5, 0, 5, 10, 15 } }
};

int main (int argc, char const *argv[])
{
    for (auto& [start, end, step, results] : testdata)
    {
        int loopCounter = 0;

        for (auto i : mmolch::range(start, end, step))
        {
            assert (loopCounter < results.size());
            assert (i == results[loopCounter]);

            ++loopCounter;
        }
    }
    
    return 0;
}
