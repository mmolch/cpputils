#ifndef MMOLCH_GETFILECONTENT_HPP
#define MMOLCH_GETFILECONTENT_HPP

#include <string_view>
#include <vector>

namespace mmolch
{

/**
 * @brief Reads a file into memory
 * 
 * @param path The path / filename of the file to read
 * @return Returns a vector with the data
 * 
 * @throw Throws an std::runtime_error if the file can't be opened
 */
[[nodiscard]]
std::vector<char> getFileContent(std::string_view path);

} // namespace mmolch

#endif // MMOLCH_GETFILECONTENT_HPP
