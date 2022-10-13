#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include <range.hpp>


struct TestEntry
{
    int start;
    int end;
    int step;
    std::vector<int> results;
};

const std::vector<TestEntry> tests {
    { 1, 2, 3, { 1 } },
    { 5, 3, 1, {} },
    { -10, -15, -1, { -10, -11, -12, -13, -14 } },
    { -10, 20, 5, { -10, -5, 0, 5, 10, 15 } }
};

int main( int argc, char const *argv[] )
{
    for( auto& [start, end, step, results] : tests )
    {
        int count = 0;

        for( auto i : mmolch::util::range( start, end, step ) )
        {
            assert( count < results.length() );
            assert( i == results[count] );

            ++count;
        }
    }
    
    return 0;
}
