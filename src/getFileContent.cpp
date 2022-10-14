#include "getFileContent.hpp"

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
    auto available = file.rdbuf()->in_avail();

    // use a two-step approach. Try to read as much as possible directly into the returned vector first
    std::vector<char> data(available, '\0');

    if (file.read(data.data(), data.size()))
    {
        // There's still more data. Use a buffer.
        // Use the previous available size (should be the buffer size of the rdbuf() backing the stream)
        std::vector<char> buffer(available, '\0');

        while (file.read(buffer.data(), buffer.size()))
        {
            // Looks initimdating at first but uses memmove under the hood. The rest is constant
            data.insert(data.begin(), buffer.begin(), std::next(buffer.begin(), file.gcount()));
        }

        data.insert(data.begin(), buffer.begin(), std::next(buffer.begin(), file.gcount()));
    }

    return data;
}

} // namespace util
} // namespace mmolch
