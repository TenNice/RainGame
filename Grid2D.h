#pragma once
#include <iostream>
#include "GameManager.h"

class GameManager;

using namespace std;

class Grid2D
{
private:
	int SizeX, SizeY;
	char** Map; // 2차원 배열
	GameManager* Manager;

public:
	Grid2D();
	Grid2D(int X, int Y);
	~Grid2D();

	void Draw();
	int GetSizeX();
	int GetSizeY();
	char** GetMap();
	void SetGameManager(GameManager* Manager);
};