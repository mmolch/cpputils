#include <cassert>
#include <cstring>
#include <iostream>
#include <span>

#include <getFileContent.hpp>


const std::span testdata { "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." };

int main(int argc, char const *argv[])
{
    auto data = mmolch::util::getFileContent("../../testdata/loremipsum.txt");

    assert (static_cast<int>(data.size()) == testdata.size());

    assert (memcmp(data.data(), testdata, testdata.size()) == 0);

    return 0;
}
