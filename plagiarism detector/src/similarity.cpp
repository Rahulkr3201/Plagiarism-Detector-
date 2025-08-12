#include "similarity.h"
#include <set>
#include <algorithm>

double jaccardSimilarity(const std::vector<std::string> &set1,
                         const std::vector<std::string> &set2)
{
    std::set<std::string> s1(set1.begin(), set1.end());
    std::set<std::string> s2(set2.begin(), set2.end());

    std::vector<std::string> intersection;
    std::vector<std::string> uni;

    std::set_intersection(s1.begin(), s1.end(),
                          s2.begin(), s2.end(),
                          std::back_inserter(intersection));

    std::set_union(s1.begin(), s1.end(),
                   s2.begin(), s2.end(),
                   std::back_inserter(uni));

    if (uni.empty())
        return 0.0;
    return (double)intersection.size() / uni.size();
}
