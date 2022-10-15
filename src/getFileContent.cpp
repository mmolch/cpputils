#include "getFileContent.hpp"

#include <iostream>
#include <fstream>
#include <limits>

namespace mmolch
{
namespace util
{

std::vector<char> getFileContent(std::string_view path)
{
    std::ifstream file(path.data(), std::ios::binary);
    if (!file)
    {
        throw std::runtime_error { std::string("Failed to open file for reading: ") + path.data() };
    }

    // in_avail() returns the number of characters available for reading before the buffer must be refilled
    // At least on Linux with GCC 12.2.0 this returns the filesize even for huge files (tested with a 222 GB file).
    // In other cases this value should be a reasonable buffer size.
    auto available = file.rdbuf()->in_avail();

    if (available == 0)
    {
        return std::vector<char>();
    }

    // use a two-step approach. Try to read as much as possible directly into the returned vector first
    std::vector<char> data(available);

    if (file.read(data.data(), data.size()))
    {
        // There's still more data. Use a buffer of the previously determined size
        std::vector<char> buffer(available);

        while (file.read(buffer.data(), buffer.size()))
        {
            // Might look initimdating at first but uses memmove under the hood. The rest is constant
            data.insert(data.end(), buffer.begin(), std::next(buffer.begin(), file.gcount()));
        }

        data.insert(data.end(), buffer.begin(), std::next(buffer.begin(), file.gcount()));
    }

    return data;
}

} // namespace util
} // namespace mmolch
