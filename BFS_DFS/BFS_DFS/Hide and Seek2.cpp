//시간초과

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

class Variable {
public:
	int hide;
	int seek;
	int level = 1;
	queue<int> q;
	int count = 1;
};

void make_graph(Variable v);

int main() {

	Variable v;

	cin >> v.seek >> v.hide;
	
	v.q.push(v.seek);

	make_graph(v);

}

void make_graph(Variable v) {
	
	while (1) {
	
		int temp = v.q.front();
		v.q.pop();

		for (int i = 1; i < (v.hide - v.seek); i++)
		{
			int num1 = pow(3, i - 1);
			int num2 = pow(3, i);
			
			if ((num1 <= v.count) && (v.count <= num2)) {
				v.level = i;
				break;
			}
		}

		if (((temp - 1) != v.hide) && ((temp - 1) != v.hide) && ((2 * temp) != v.hide))
		{
			v.q.push(temp - 1);
			v.q.push(temp + 1);
			v.q.push(2 * temp);
			v.count += 1;
		}
		else {
			cout << v.level<<"초"<<endl;
			break;
		}
	}
}
