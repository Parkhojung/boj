#include <iostream>
using namespace std;

int main() {

	char c;
	int i;
	i = 0;
	while (true) {
		if ((c = cin.get()) == '\n')
			break;
		cout << c;
		if (((i+1) % 10) == 0)
			cout << endl;

		i++;
	}
	return 0;
}