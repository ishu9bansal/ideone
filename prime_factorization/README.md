# Problem Statement
Calculate the prime factorization of an unsigned integer `[0,2^32-1]`.
Represent the factorization in the natural format.

# Solution
It uses seive to calculate all the primes upto `n = 2^16` (`p = 6542` primes in this range)
then uses those primes to factorize the all the numbers upto `N = 2^32`.

Prime factorization of a non prime number `k` will contain at least one factor less than `sqrt(k)`, otherwise `k` is prime.
Hence we only need to precalculate all the primes upto `2^16` only, and we can find all other factors recursively.

- Once we got the all the primes, we can just iterate over all the primes.
- Once we find a factor of the number we can reduce the search space substantially.
- If we divide the number by factor then the factors for the remaining number will also be factors of original number.
- Hence we can repeat the same procedure for remaining number until the number is `1` or we run out of our calculated primes to compare for.
- In the later case the remaining number is a prime as well, which would be greater than `n=sqrt(N)`

# Complexity
- Precomputation
    - Time: `O(n*log(n)) = O(sqrt(N)*log(N))`    
    because `sum_upto_sqrt_n(n/i-i) ~ (n*log(n) - n)/2`
    - Space: `O(p) ~ O(n/log(n))`    
    because of prime number theorem    
- Factorization
    - Time: `O(p*log(N)) ~ O(n) = O(sqrt(N))`
    Upper bound. Maximum number of factors of a number = `log(N)`. Length of the array = `p`.
    - Extra Space: `O(1)`  Only constant space is used, other than the space to store factorization itself.    
- Legend
    - `N`: maximum input number
    - `n`: `sqrt(N)`
    - `p`: number of primes found less than `n ~ n/log(n)`
- Bonus    
  - Factorization Time complexity tight bound: `O(p) ~ O(n/log(n)) = O(sqrt(N)/log(N))`    
  - Some more tight bound on factorization part, reveals that on an average square or cube of the calculated primes, goes off the ceiling. Only a few dozen of initial numbers is more than 5th or 6th power. Hence the total comparisons can be as less as `2*p`
  - Hence making the overall time complexity for factorization linear in `p`
  - analysis can be found here https://ideone.com/kJzElq
# Bonus
Natural way of writing a number in it's constituent parts. This reveals everything about that number.

# Link
https://ideone.com/DuqFYy

# Usage
https://leetcode.com/submissions/detail/388808430/
https://leetcode.com/submissions/detail/708379160/
