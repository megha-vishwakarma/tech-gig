/*
The Divisibility Dilemma (100 Marks)
In the picturesque village of Numeropolis, the annual "Divisibility Day" is celebrated with great enthusiasm. This day is marked by various mathematical challenges and games that put the villagers' arithmetic skills to the test. This year, the villagers are embarking on a quest to explore the distinctive properties of subarrays within integer arrays.

The village's renowned mathematician, Professor Arithmo, has crafted an intriguing challenge. He has provided the villagers with an integer array nums`and two additional integers, K and P. Professor Arithmo's challenge revolves around discovering and counting distinct subarrays from the array nums. The uniqueness of these subarrays is determined by their divisibility characteristics.

Specifically, Professor Arithmo asks the villagers to identify subarrays that have no more than K elements divisible by P. To put it simply, a subarray is considered valid if the count of elements divisible by P within it does not exceed K.

In Numeropolis, the concept of distinctiveness extends to subarrays as well. Two subarrays, subarray1 and subarray2, are said to be distinct under the following conditions:

1. They possess different lengths.
2. There is at least one index i where subarray1[i] is not equal to subarray2[I].

To assist the villagers in this quest, you are tasked with calculation of count of distinct subarrays that satisfy the divisibility condition and the distinctiveness condition.

Input Format
First line contains three space-separated integers N, K and P respectively.

Second line contains N space-separated integers representing elements of array nums.

Output Format
Print a single integer representing the count of distinct subarrays.

Sample TestCase 1
Input
4 1 2
3 4 5 6
Output
8

Explanation
There are a total of 8 subarrays following the condition:

{ 3 }

{ 3, 4 }

{3, 4, 5}

{ 4 }

{ 4, 5 }

{ 5 }  */


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int myvector(vector<int> &nums, int k, int p) {
    unordered_set<string> s;

    int left = 0;
    int pl = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % p == 0) {
            pl++;
        }
        while (pl > k) {
            if (nums[left] % p == 0)
                pl--;
            left++;
        }

        for (int i = left; i <= right; i++) {
            string a = "";
            for (int j = i; j <= right; j++) {
                a = a + to_string(nums[j]);
                if (j < right) {
                    a += ",";
                }
            }
            s.insert(a);
        }
    }

    return s.size();
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count = myvector(nums, k, p);
    cout << count << endl;

    return 0;
}


{ 5, 6 }

{ 6 }
