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
        throw std::runtime_error { std::string("Failed to open file: ") + path.data() };
    }

    // The only way to know how much data can be read is by reading the file!
    file.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize length = file.gcount();
    file.clear(); // Since ignore will have set eof.
    file.seekg( 0, std::ios_base::beg );

    std::vector<char> data(length, '\0');
    file.read(data.data(), data.capacity());
    data.resize(file.gcount());

    return data;
}

} // namespace util
} // namespace mmolch
