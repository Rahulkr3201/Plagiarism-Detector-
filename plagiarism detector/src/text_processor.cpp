#include "text_processor.h"
#include <sstream>
#include <algorithm>
#include <cctype>

std::vector<std::string> tokenize(const std::string &text)
{
    std::string clean;
    for (char c : text)
    {
        if (std::isalpha(c) || std::isspace(c))
            clean += std::tolower(c);
    }

    std::stringstream ss(clean);
    std::string word;
    std::vector<std::string> tokens;
    while (ss >> word)
        tokens.push_back(word);
    return tokens;
}

std::vector<std::string> generateNGrams(const std::vector<std::string> &tokens, int n)
{
    std::vector<std::string> ngrams;
    if (tokens.size() < n)
        return ngrams;

    for (size_t i = 0; i <= tokens.size() - n; i++)
    {
        std::string gram;
        for (int j = 0; j < n; j++)
        {
            gram += tokens[i + j] + " ";
        }
        ngrams.push_back(gram);
    }
    return ngrams;
}
