# python3

import sys

class Solver:
	def __init__(self, s):
		self.s = s
	def ask(self, a, b, l):
		return s[a:a+l] == s[b:b+l]

def polyHash(s, prime, multiplier):
    hash = 0
    for c in reversed(s):
        hash = (hash * multiplier + ord(c)) % prime
    return hash
def precomputeHashes(text, len_pattern, prime, multiplier):
    H = [None] * (len(text) - len_pattern + 1)
    S = text[len(text) - len_pattern:]
    H[len(text) - len_pattern] = polyHash(S, prime, multiplier)
    y = 1
    for i in range(len_pattern):
        y = (y * multiplier) % prime
    for i in range(len(text) - len_pattern - 1, -1, -1):
        H[i] = (multiplier * H[i + 1] + ord(text[i]) -
                y * ord(text[i + len_pattern])) % prime
    # print(H)
    return H
def compute(a,b,l):
    h = precomputeHashes(s,l,prime, multiplier)
    return h[a] == h[b]

prime = 1610612741
multiplier = 263
s = sys.stdin.readline()
q = int(sys.stdin.readline())
solver = Solver(s)
for i in range(q):
	a, b, l = map(int, sys.stdin.readline().split())
	print("Yes" if compute(a, b, l) else "No")
