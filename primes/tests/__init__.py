import unittest
import primes
import primes.plot


class PrimesTest(unittest.TestCase):

    def test(self):
        assert primes.find(100) == primes._find_recursive(100)


class PlotTest(unittest.TestCase):

    def test_spiral(self):
        s = primes.plot.spiral_distribution(10)

        assert s == ([1, 1, -1, -1], [0, 1, 1, -1])
