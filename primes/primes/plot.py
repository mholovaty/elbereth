from matplotlib import pyplot
from . import find


def _spiral_gen():
    """For each edge of the spiral generate n, length, x, y"""
    n = l = x = y = 0

    while True:
        n += 1
        d = (n + 1) / 2
        l += d

        k = n % 4

        if k == 1:
            x += d
        elif k == 2:
            y += d
        elif k == 3:
            x -= d
        else:
            y -= d

        yield n, l, x, y


def _spiral_point(positive_integer, edge):
    """Coordinates of a positive integer on the spiral where

    l_edge(n-1) < l_i < l_edge(n)

    """
    n, l, x, y = edge
    k = n % 4

    d = l - positive_integer

    if k == 1:
        return x - d, y
    elif k == 2:
        return x, y - d
    elif k == 3:
        return x + d, y
    else:
        return x, y + d


def spiral(n):
    """Spiral plot function for n edges."""
    xs = []
    ys = []

    g = _spiral_gen()

    for _ in xrange(n):
        n, l, x, y = g.next()
        xs.append(x)
        ys.append(y)

    return xs, ys


def spiral_distribution(n):
    """Prime spiral plot function for n primes."""
    primes = find(n)

    xs = []
    ys = []

    spiral_gen = _spiral_gen()
    spiral_edge = spiral_gen.next()

    for prime in primes:
        while prime - 1 > spiral_edge[1]:
            spiral_edge = spiral_gen.next()

        x, y = _spiral_point(prime - 1, spiral_edge)

        xs.append(x)
        ys.append(y)

    return xs, ys


def show(n, f=spiral_distribution):
    xs, ys = f(n)

    pyplot.plot(xs, ys, 'ro')
    pyplot.autoscale()
    pyplot.grid()
    pyplot.show()
