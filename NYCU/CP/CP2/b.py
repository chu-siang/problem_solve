#	Wizard of Odds
n,k = map(int,input().split())

if pow(2,k) >= n:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")