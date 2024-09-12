#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out) {
    while (first1 != last1) {
        if (first2 == last2)
            return std::copy(first1, last1, out);

        if (*first1 < *first2)
            *out++ = *first1++;
        else {
            if (*first2 >= *first1)
                ++first1;
            ++first2;
        }
    }
    return out;

}

int main() {
    std::vector<int> in1 = {1, 3, 5, 5, 7};
    std::list<int> in2 = {1, 1, 2, 3};
    std::deque<int> out;

    SetDifference(in1.begin(), in1.end(),
                  in2.begin(), in2.end(),
                  std::back_inserter(out));
    for (auto it = out.begin(); it != out.end(); ++it) {
        std::cout << *it << " ";  //
    }
}