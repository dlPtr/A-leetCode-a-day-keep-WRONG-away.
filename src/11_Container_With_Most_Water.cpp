#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int maxArea(vector<int>& height) {
        for (vector<int>::iterator it = height.begin(); it != height.end(); it++) {
            cout << *(it) << endl;
        }

        return 0;
    }
};

int main(int argc, char *argv[])
{
    const int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> input(arr, arr + sizeof(arr) / sizeof(int) - 1);
    Solution demo;

    cout << demo.maxArea(input) << endl;

    return 0;
}