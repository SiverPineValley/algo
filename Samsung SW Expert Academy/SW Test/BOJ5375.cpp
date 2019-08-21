// 큐빙 미완성
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

#define CLOCK 1
#define COUNTER_CLOCK 3

#define CUBELINE 3

// 위, 아래, 앞, 뒤, 왼, 오
enum FACE{U,D,F,B,L,R,SIZE}; // enum 예시 코드
int cube[SIZE][3][3];

void rotSameFace(int face)
{
	int tempRot[3];
	tempRot[0] = cube[face][0][0]; tempRot[1] = cube[face][0][1]; tempRot[2] = cube[face][0][2];
	cube[face][0][2] = cube[face][0][0];
	cube[face][0][1] = cube[face][1][0];
	cube[face][0][0] = cube[face][2][0];

	cube[face][1][0] = cube[face][2][1];
	cube[face][2][0] = cube[face][2][2];

	cube[face][2][1] = cube[face][1][2];
	cube[face][2][2] = tempRot[2];
	cube[face][1][2] = tempRot[1];
}

void rotSameFace_DOWN()
{
	int tempRot[3];
	tempRot[0] = cube[D][0][2]; tempRot[1] = cube[D][0][1]; tempRot[2] = cube[D][0][0];
	cube[D][0][0] = cube[D][0][2];
	cube[D][0][1] = cube[D][1][2];
	cube[D][0][2] = cube[D][2][2];

	cube[D][1][2] = cube[D][2][1];
	cube[D][2][2] = cube[D][2][0];

	cube[D][2][1] = cube[D][1][0];
	cube[D][2][0] = tempRot[2];
	cube[D][1][0] = tempRot[1];
}

void rotUp(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[F][0][0]; tempRot[1] = cube[F][0][1]; tempRot[2] = cube[F][0][2];
		cube[F][0][0] = cube[R][2][0]; cube[F][0][1] = cube[R][1][0]; cube[F][0][0] = cube[R][2][0];
		cube[R][2][0] = cube[B][2][2]; cube[R][1][0] = cube[B][2][1]; cube[R][0][0] = cube[B][2][0];
		cube[B][2][2] = cube[L][0][2]; cube[B][2][1] = cube[L][1][2]; cube[B][2][0] = cube[L][2][2];
		cube[L][0][2] = tempRot[0]; cube[L][1][2] = tempRot[1]; cube[L][2][2] = tempRot[2];
		rotSameFace(U);
	}
}

void rotDown(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[F][2][0]; tempRot[1] = cube[F][2][1]; tempRot[2] = cube[F][2][2];
		cube[F][2][0] = cube[L][0][0]; cube[F][2][1] = cube[L][1][0]; cube[F][2][2] = cube[L][2][0];
		cube[L][2][0] = cube[B][0][0]; cube[L][1][0] = cube[B][0][1]; cube[L][0][0] = cube[B][0][2];
		cube[B][0][0] = cube[R][0][2]; cube[B][0][1] = cube[R][1][2]; cube[B][0][2] = cube[R][2][2];
		cube[R][2][2] = tempRot[0]; cube[R][1][2] = tempRot[1]; cube[R][0][2] = tempRot[2];
		rotSameFace_DOWN();
	}
}

void rotFront(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[U][2][0]; tempRot[1] = cube[U][2][1]; tempRot[2] = cube[U][2][2];
		cube[U][2][0] = cube[L][2][0]; cube[U][2][1] = cube[L][2][1]; cube[U][2][2] = cube[L][2][2];
		cube[L][2][0] = cube[D][2][0]; cube[L][2][1] = cube[D][2][1]; cube[L][2][2] = cube[D][2][2];
		cube[D][2][0] = cube[R][2][0]; cube[D][2][1] = cube[R][2][1]; cube[D][2][2] = cube[R][2][2];
		cube[R][2][0] = tempRot[0]; cube[R][2][1] = tempRot[1]; cube[R][2][2] = tempRot[2];
		rotSameFace(F);
	}
}

void rotBack(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[L][0][0]; tempRot[1] = cube[L][0][1]; tempRot[2] = cube[L][0][2];
		cube[L][0][0] = cube[U][0][0]; cube[L][0][1] = cube[U][0][1]; cube[L][0][2] = cube[U][0][2];
		cube[U][0][0] = cube[R][0][0]; cube[U][0][1] = cube[R][0][1]; cube[U][0][2] = cube[R][0][2];
		cube[R][0][0] = cube[D][0][0]; cube[R][0][1] = cube[D][0][1]; cube[R][0][2] = cube[D][0][2];
		cube[D][0][0] = tempRot[0]; cube[D][0][1] = tempRot[1]; cube[D][0][2] = tempRot[2];
		rotSameFace(B);
	}
}

void rotRight(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[U][0][2]; tempRot[1] = cube[U][1][2]; tempRot[2] = cube[U][2][2];
		cube[U][0][2] = cube[F][0][2]; cube[U][1][2] = cube[F][1][2]; cube[U][2][2] = cube[F][2][2];
		cube[F][0][2] = cube[D][0][0]; cube[F][1][2] = cube[D][1][0]; cube[F][2][2] = cube[D][2][0];
		cube[D][0][0] = cube[B][0][2]; cube[D][1][0] = cube[B][1][2]; cube[D][2][0] = cube[B][2][2];
		cube[B][0][2] = tempRot[0]; cube[B][1][2] = tempRot[1]; cube[B][2][2] = tempRot[2];
		rotSameFace(R);
	}
}

void rotLeft(int isClock)
{
	for(int rot = 0; rot < isClock; rot++)
	{
		int tempRot[3];
		tempRot[0] = cube[U][0][0]; tempRot[1] = cube[U][1][0]; tempRot[2] = cube[U][2][0];
		cube[U][2][0] = cube[B][2][0]; cube[U][1][0] = cube[B][1][0]; cube[U][0][0] = cube[B][0][0];
		cube[B][0][0] = cube[D][0][2]; cube[B][1][0] = cube[D][1][2]; cube[B][2][0] = cube[D][2][2];
		cube[D][0][2] = cube[F][0][0]; cube[D][1][2] = cube[F][1][0]; cube[D][2][2] = cube[F][2][0];
		cube[F][0][0] = tempRot[0]; cube[F][1][0] = tempRot[1]; cube[F][2][0] = tempRot[2];
		rotSameFace(L);
	}
}

int main(void)
{
	int testCase;

	cin >> testCase;

	while(testCase--)
	{
		// 입력
		int n;
		cin >> n;
		vector<string> rotation;
		for(int index = 0; index < n; index++)
		{
			string tempString;
			cin >> tempString;
			rotation.push_back(tempString);		
		}

		// Cube 초기화
		for(int face = 0; face < SIZE; face++)
			for(int y = 0; y < CUBELINE; y++)
				for(int x = 0; x < CUBELINE; x++)
					cube[face][y][x] = face;

		for(auto rotCase : rotation)
		{
			if(rotCase.compare("U+") == 0)
				rotUp(CLOCK);
			else if(rotCase.compare("U-") == 0)
				rotUp(COUNTER_CLOCK);
			else if(rotCase.compare("D+") == 0)
				rotDown(CLOCK);
			else if(rotCase.compare("D-") == 0)
				rotDown(COUNTER_CLOCK);
			else if(rotCase.compare("F+") == 0)
				rotFront(CLOCK);
			else if(rotCase.compare("F-") == 0)
				rotFront(COUNTER_CLOCK);
			else if(rotCase.compare("B+") == 0)
				rotBack(CLOCK);
			else if(rotCase.compare("B-") == 0)
				rotBack(COUNTER_CLOCK);
			else if(rotCase.compare("R+") == 0)
				rotRight(CLOCK);
			else if(rotCase.compare("R-") == 0)
				rotRight(COUNTER_CLOCK);
			else if(rotCase.compare("L+") == 0)
				rotLeft(CLOCK);
			else if(rotCase.compare("L-") == 0)
				rotLeft(COUNTER_CLOCK);
		}

		for(int y = 0; y < CUBELINE; y++)
		{
			for(int x = 0; x < CUBELINE; x++)
			{
				int cubeComponent = cube[U][y][x];
				if(cubeComponent == 0) cout << "w";			// 위
				else if(cubeComponent == 1) cout << "y";	// 아래
				else if(cubeComponent == 2) cout << "r";	// 앞
				else if(cubeComponent == 3) cout << "o";	// 뒤
				else if(cubeComponent == 4) cout << "g";	// 왼
				else if(cubeComponent == 5) cout << "b";	// 오
			}
			cout << "\n";
		}
	}

	return 0;
}