#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Country {
	int num;
	int gold;
	int total;
	int population;
};
struct Rank {
	int gold;
	int total;
	int goldRatio;
	int totalRatio;
};
bool goldCompare(Country lhs, Country rhs) {
	return lhs.gold > rhs.gold;
}
bool totalCompare(Country lhs, Country rhs) {
	return lhs.total > rhs.total;
}
bool goldRatioCompare(Country lhs, Country rhs) {
	return lhs.gold * rhs.population > rhs.gold * lhs.population;
}
bool totalRatioCompare(Country lhs, Country rhs) {
	 return lhs.total * rhs.population > rhs.total * lhs.population;
}
int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF) {
		vector<Country> vec;
		vector<Rank> rankVec(N);
		for (int num = 0; num < N; ++num) {
			Country country;
			country.num = num;
			scanf("%d%d%d", &country.gold, &country.total, &country.population);
			vec.push_back(country);
		}
		sort(vec.begin(), vec.end(), goldCompare);	// 已经通过金牌从多到少排序
		for (int i = 0, rank = 1; i < vec.size(); ++i) {
			if (i >= 1 && vec[i].gold != vec[i - 1].gold) {
				rank = i + 1;
			}
			rankVec[vec[i].num].gold = rank;	// 记录gold方式的rank
		}
		sort(vec.begin(), vec.end(), totalCompare);	
		for (int i = 0, rank = 1; i < vec.size(); ++i) {
			if (i >= 1 && vec[i].total != vec[i - 1].total) {
				rank = i + 1;
			}
			rankVec[vec[i].num].total = rank;	// 记录total方式的rank
		}
		sort(vec.begin(), vec.end(), goldRatioCompare);
		for (int i = 0, rank = 1; i < vec.size(); ++i) {
			if (i >= 1 && 
				vec[i].gold * vec[i - 1].population != vec[i - 1].gold * vec[i].population) {
				rank = i + 1;
			}
			rankVec[vec[i].num].goldRatio = rank;	// 记录goldRatio方式的rank
		}
		sort(vec.begin(), vec.end(), totalRatioCompare);
		for (int i = 0, rank = 1; i < vec.size(); ++i) {
			if (i >= 1 &&
				vec[i].total * vec[i - 1].population != vec[i - 1].total * vec[i].population) {
				rank = i + 1;
			}
			rankVec[vec[i].num].totalRatio = rank;	// 记录totalRatio方式的rank
		}
		/*for (int i = 0; i < rankVec.size(); ++i) {
			auto c = rankVec[i];
			printf("i = %d rank1 = %d rank2 = %d rank3 = %d rank4 = %d\n",
				i, c.gold, c.total, c.goldRatio, c.totalRatio);
		}*/
		int countryNum;
		for (int idx = 0; idx < M; ++idx) {
			scanf("%d", &countryNum);
			int best = rankVec[countryNum].gold;
			int out = 1;
			if (rankVec[countryNum].total < best) {
				best = rankVec[countryNum].total;
				out = 2;
			}
			if (rankVec[countryNum].goldRatio < best) {
				best = rankVec[countryNum].goldRatio;
				out = 3;
			}
			if (rankVec[countryNum].totalRatio < best) {
				best = rankVec[countryNum].totalRatio;
				out = 4;
			}
			printf("%d:%d\n", best, out);
		}
		printf("\n");
	}
	return 0;
}