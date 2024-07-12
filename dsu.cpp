#include<iostream>
#include<unordered_map>
using namespace std;
template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, int> rankMap;   // to store a mapping b/w vertices & their ranks i.e. sizes

public :

	void createSet(T x) {
		parentMap[x] = x;
		rankMap[x] = 1;
	}

	T findSet(T x) {
		if (parentMap[x] == x) {
			return x;
		}

		return parentMap[x] = findSet(parentMap[x]); // path compression
	}

	void unionSet(T x, T y) {
		T lx = findSet(x);
		T ly = findSet(y);

		if (lx != ly) {

			int rx = rankMap[lx];
			int ry = rankMap[ly];

			if (rx > ry) {
				parentMap[ly] = lx;
				rankMap[lx] += rankMap[ly];
			} else {
				parentMap[lx] = ly;
				rankMap[ly] += rankMap[lx];
			}

		}
	}


};
int main(){

    return 0;
}