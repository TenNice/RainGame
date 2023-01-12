#include <iostream>
#include "Windows.h"
#include "Grid2D.h"
#include "GameObject.h"
#include "GameManager.h"

using namespace std;

// �ֿܼ��� Ŀ�� �� ���̰� �ϱ�
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

	//cout << (int)ObjectCategory::Player; // �̰� 0������
	GameObject Test("P", 10, 10);

	GameManager GameManager(&Grid, &Test);



	GameManager.Update();
	Grid.Draw();

	return 0;
}