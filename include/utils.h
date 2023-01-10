#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

namespace utils
{

/**
 * @brief read all the file to one big string
 *
 * @param path to the file
 * @return std::string
 */
inline std::string readFile(const std::string &path)
{
    std::ifstream file;
    file.open(path, std::ios_base::in);

    if (!file.is_open())
    {
        std::cerr << "ERROR: could not open file \'" + path + "\': " << strerror(errno) << std::endl;
    }

    std::stringstream stream;
    stream << file.rdbuf();

    file.close();
    return stream.str();
}
}  // namespace utils
