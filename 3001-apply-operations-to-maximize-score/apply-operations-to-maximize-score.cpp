class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> sieveOfEranthoses(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> prime;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) prime.push_back(i);
        }
        return prime;
    }

    vector<int> findprimeScores(vector<int> &nums) {
        int n = nums.size();
        vector<int> primescores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieveOfEranthoses(maxElement);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int prime : primes) {
                if ((prime * prime) > x) break;
                if (x % prime == 0) {
                    primescores[i]++;
                    while (x % prime == 0) {
                        x /= prime;
                    }
                }
            }
            if (x > 1) primescores[i]++; 
        }
        return primescores;
    }

    long long findPower(long long a, long long b) {
        long long result = 1;
        a = a % mod; 
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }

    vector<int> nextGreaterEq(vector<int> &primescores) {
        int n = primescores.size();
        vector<int> res(n, n); 
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primescores[st.top()] <= primescores[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> prevGre(vector<int> &primescores) {
        int n = primescores.size();
        vector<int> res(n, -1); 
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primescores[st.top()] < primescores[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primescores = findprimeScores(nums);
        vector<int> nextGreater = nextGreaterEq(primescores);
        vector<int> prevGreaterEq = prevGre(primescores);
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        vector<long long> subarrays(n, 0);

        for (int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreaterEq[i]);
        }

        sort(sorted.begin(), sorted.end(), greater<>());
        long long ans = 1;

        for (int idx = 0; k > 0 && idx < sorted.size(); idx++) {
            auto [num, i] = sorted[idx];
            long long operations = min((long long)k, subarrays[i]);

            ans = (ans * findPower(num, operations)) % mod;
            k -= operations;  
        }

        return ans;
    }
};
