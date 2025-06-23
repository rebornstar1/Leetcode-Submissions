class Solution {
public:
    // Correctly check if a number is a palindrome in the given base
    bool isPalindrome(long long num, int base) {
        // Edge cases
        if (num == 0) return true;
        
        // Store the digits in base-k
        vector<int> digits;
        long long temp = num;
        
        while (temp > 0) {
            digits.push_back(temp % base);
            temp /= base;
        }
        
        // Check if it's a palindrome
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left] != digits[right])
                return false;
            left++;
            right--;
        }
        
        return true;
    }
    
    // Generate all palindromes in a given length range efficiently
    vector<long long> generatePalindromes(int minLength, int maxLength) {
        vector<long long> result;
        
        // Handle single digit palindromes
        if (minLength <= 1) {
            for (int i = 1; i <= 9; i++) {
                result.push_back(i);
            }
            minLength = 2;
        }
        
        // Generate palindromes of length 2 or more
        for (int length = minLength; length <= maxLength; length++) {
            int halfLen = (length + 1) / 2;
            long long start = pow(10, halfLen - 1);
            long long end = pow(10, halfLen) - 1;
            
            for (long long i = start; i <= end; i++) {
                long long palindrome = i;
                long long temp = (length % 2 == 0) ? i : i / 10;
                
                while (temp > 0) {
                    palindrome = palindrome * 10 + temp % 10;
                    temp /= 10;
                }
                
                result.push_back(palindrome);
            }
        }
        
        return result;
    }
    
    long long kMirror(int k, int n) {
        // We need a different approach - generate progressively and check
        int count = 0;
        long long sum = 0;
        int currentLength = 1;
        int maxLength = 15; // Sufficiently large for the constraints
        
        while (count < n && currentLength <= maxLength) {
            // Generate all palindromes of the current length
            vector<long long> palindromes = generatePalindromes(currentLength, currentLength);
            
            // Check if they're also palindromes in base k
            for (long long num : palindromes) {
                if (isPalindrome(num, k)) {
                    sum += num;
                    count++;
                    
                    if (count == n) break;
                }
            }
            
            currentLength++;
        }
        
        return sum;
    }
};