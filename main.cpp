#include <iostream>
#include "Windows.h"
#include "Grid2D.h"
#include "GameObject.h"
#include "GameManager.h"

using namespace std;

// 콘솔에서 커서 안 보이게 하기
void ShowConsoleCursor(bool Show)
{
	auto Out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(Out, &CursorInfo);
	CursorInfo.bVisible = Show;
	SetConsoleCursorInfo(Out, &CursorInfo);
}

int main()
{
	Grid2D Grid(25, 25);
	//Grid.Draw();

	//cout << (int)ObjectCategory::Player; // 이거 0나오네
	GameObject Test("P", 10, 10);

	GameManager GameManager(&Grid, &Test);



	GameManager.Update();
	Grid.Draw();

	return 0;
}