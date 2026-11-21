// Approach:
// 1. Ek unordered_map banaya jisme key number hogi aur value us number ke saare indices ki vector hogi.
// 2. Pehli array ko traverse kiya aur har number ke index ko map mein store kiya.
//    Vector use ki taake agar koi number multiple times aaye toh uske saare indices preserve rahen.
// 3. Doosri array ko traverse kiya aur har number ke liye required number calculate kiya:
//    required = target - arr2[j]
// 4. map.find() se check kiya ke required number pehli array mein mojood hai ya nahi.
// 5. Agar required number mil jaye toh uski vector mein jitne indices hain,
//    utni baar valid pair {required, arr2[j]} result mein add kiya.
// 6. Aakhir mein result ko sort kiya taake pairs first element ke increasing order mein aa jayen.
// 7. Sorted result return kar diya.
//
// Time Complexity: O(n + m + k log k) average, where k is the number of resulting pairs.
// Space Complexity: O(n + k)


class Solution {
public:
    vector<vector<int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {

        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;

        // Store all indices of arr1 elements
        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]].push_back(i);
        }

        // Search required elements in arr2
        for (int j = 0; j < arr2.size(); j++) {

            int required = target - arr2[j];

            if (mp.find(required) != mp.end()) {

                for (int i = 0; i < mp[required].size(); i++) {
                    result.push_back({required, arr2[j]});
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
