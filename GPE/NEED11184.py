# import sys


def find(N):
    l,r = 0,N
    while r-l>1:
        m = (l+r)//2
        if m*m < N:
            l = m
        else:
            r = m
    return l

def main():
    # for line in sys.stdin:
    while True:
        # N = int(line.strip())
        N = int(input())
        if N == 0:
            break
        result = find(N+1)
        print(result*result)

# if __name__ == '__main__':
    # main()
main()