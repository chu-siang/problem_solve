//uva12908  超級重要
#include <iostream>
using namespace std;

int main()
{
	int n;

	while (cin >> n, n)
	{
		int i = 0, sum = 0;
		while (sum <= n) sum += ++i;
		cout << sum - n << " " << i << "\n";
	}
}