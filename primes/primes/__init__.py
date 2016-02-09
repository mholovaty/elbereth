

def _find_recursive(n):
    """Find primes <= n"""
    if n == 1:
        return []

    primes = find(n-1)

    is_prime = True
    for p in primes:
        if n % p == 0:
            is_prime = False
            break

    if is_prime:
        primes.append(n)

    return primes


def find(n):
    """Find primes <= n"""
    primes = []

    if n == 1:
        return primes

    for i in xrange(2, n + 1):
        is_prime = True
        for p in primes:
            if i % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(i)

    return primes


