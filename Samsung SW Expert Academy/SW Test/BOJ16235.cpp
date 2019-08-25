// 나무 재테크 -> 시간초과 각 tree 위치를 vector<int> map[][]로 구현하면 가능. 구조체는 sorting에서 비효율적
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAP_MAX 11
#define MAX 8

struct treeLoc
{
	int x;
	int y;
	int age;
};

// 맵 크기, 심은 나무의 개수, k년, 나무의 좌표(x,y), 나무의 나이
int n, m, k, x, y, z;

int map[MAP_MAX][MAP_MAX];
int nutrient[MAP_MAX][MAP_MAX];
int dx[MAX] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[MAX] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<treeLoc> trees;

bool compare(const treeLoc &a, const treeLoc &b){
	if(a.x == b.x && a.y == b.y)
		return a.age < b.age;
	else{
		if(a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
}

void simulation()
{
	while(k--)
	{

		vector<treeLoc> alive;
		vector<treeLoc> dead;
		vector<treeLoc> birth;

		sort(trees.begin(), trees.end(), compare);
		// 봄
		for(auto tree : trees)
		{
			int x = tree.x;
			int y = tree.y;
			int age = tree.age;

			// 나무가 양분을 먹을 수 없으면,
			if(map[y][x] < age)
				dead.push_back({x, y, age});
			// 나무가 양분을 먹을 수 있으면,
			else
			{
				// map 양분 감소
				map[y][x] -= age;

				// 나무 나이 증가
				tree.age++;

				// 살아남은 나무 추가
				alive.push_back({x, y, tree.age});

				// 새로 태어날 나무 추가
				if(tree.age % 5 == 0)
					birth.push_back({x, y, 1});
			}
		}

		// 여름
		for(auto tree : dead)
		{
			int x = tree.x;
			int y = tree.y;
			int age = tree.age;
			int nut = age / 2;

			map[y][x] += nut;
		}

		// 가을
		for(auto tree : birth)
		{

			int x = tree.x;
			int y = tree.y;

			for(int index = 0; index < MAX; index++)
			{
				int nx = x + dx[index];
				int ny = y + dy[index];

				if(1 <= nx && nx <= n && 1 <= ny && ny <= n)
				{
					alive.push_back({nx, ny, 1});
				}
			}
		}


		// 겨울
		for(int y = 1; y <= n; y++)
		{
			for(int x = 1; x <= n; x++)
			{
				map[y][x] += nutrient[y][x];
			}
		}

		// 사후처리
		trees.clear();
		for(auto tree : alive)
		{
            int x = tree.x;
            int y = tree.y;
            int age = tree.age;
			trees.push_back({x, y, age});
		}
	}

}

int main(void)
{

	// 맵 입력
	cin >> n >> m >> k;
	for(int y = 1; y <= n; y++)
		for(int x = 1; x <= n; x++)
		{
			cin >> nutrient[y][x];
			map[y][x] = 5;
		}

	// 나무 위치 입력
	for(int index = 0; index < m; index++)
	{
		int tempX, tempY, tempAge;
		cin >> tempX >> tempY >> tempAge;
		trees.push_back({tempX, tempY, tempAge});
	}

	simulation();

	cout << trees.size() << "\n";

	return 0;
}