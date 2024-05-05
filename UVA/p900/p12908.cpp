//uva12908
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input = 0;
    vector<int> table;

    for (int i = 0; i <= 20000; i++) {
        table.push_back((i * (i + 1)) / 2);
    }

    while (cin >> input && input) {
        vector<int>::iterator itTable = upper_bound(table.begin(), table.end(), input);
        cout << *itTable - input << " " << itTable - table.begin() << endl;
        
    }

    return 0;
}

/*#include <iostream>
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
}*/