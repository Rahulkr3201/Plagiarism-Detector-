#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Cannot open file: " + filename);

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}
