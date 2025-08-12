#include "file_reader.h"
#include "text_processor.h"
#include "similarity.h"
#include <iostream>

int main()
{
    try
    {
        // Read text files
        std::string text1 = readFile("data/file1.txt");
        std::string text2 = readFile("data/file2.txt");

        // Tokenize
        auto tokens1 = tokenize(text1);
        auto tokens2 = tokenize(text2);

        // Create n-grams (3 words each)
        auto ngrams1 = generateNGrams(tokens1, 3);
        auto ngrams2 = generateNGrams(tokens2, 3);

        // Calculate similarity
        double similarity = jaccardSimilarity(ngrams1, ngrams2) * 100;

        std::cout << "Plagiarism Similarity: " << similarity << "%\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
