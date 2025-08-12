#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H

#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string &text);
std::vector<std::string> generateNGrams(const std::vector<std::string> &tokens, int n);

#endif
