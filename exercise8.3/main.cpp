#include <vector>
#include <iostream>
#include <numeric>

using std::vector; using std::accumulate; using std::cout; using std::endl;

int main() {
/*
 * We were confused about this question at first because
 * we forgot the performance part of the question. We were
 * not sure how you would find the median without sorting
 * in a way that wasn't super convoluted.
 *
 * However, you could certainly do it with iterators. We will
 * show how to below. Main issue is that this algorithm is O(N^2)
 * instead of O(N log(N)). See:
 * https://stackoverflow.com/questions/33964676/find-the-median-of-an-unsorted-array-without-sorting#:~:text=You%20can%20certainly%20find%20the,value%20with%20the%20correct%20count.
 */
    typedef vector<double>::size_type sizetype;
    typedef vector<double>::iterator itertype;

    vector<double> v = {5, 4, 1, 2, 3, 6};
    sizetype size = v.size();
    vector<sizetype> points_to_find = {size/2};
    vector<double> median_values;

    if(size % 2 == 0){ // Vector has an even number of entries.
        points_to_find.push_back(size/2 -1);
    }

    // If size is odd we want size/2. Otherwise we want size/2 AND size/2 - 1.
        // The iter we use to find the median value(s)
    for(itertype iter1 = v.begin(); iter1 != v.end(); ++iter1){
        int count = 0;
        // The iter we use to compare with the candidate median value
        for(itertype iter2 = v.begin(); iter2 != v.end(); ++iter2){
            // Increase count for each vector element less than current candidate.
            // This is the index of the element in the sorted array!
            if(*iter2 <= *iter1 && iter1 != iter2){ // 2nd condition: Do not compare number to itself
                count += 1;
            }
        }
        for (sizetype point: points_to_find) {
            if(point == count){
                median_values.push_back(*iter1);
            }
        }
    }

    cout << "The median is: " << accumulate(median_values.begin(),
                                            median_values.end(),
                                            0.0)/median_values.size()
                                            << endl;
}
