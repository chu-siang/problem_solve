import sys
from math import factorial 

def main():
    while True:
        try:
            n = int(input())
            n = factorial(n)
            sum = 0
            while n>0:
                sum += n%10
                n = n//10
            print(sum)
        except EOFError:
            break
main()