#pragma once
#include <iostream>
#include "Grid2D.h"

using namespace std;

Grid2D::Grid2D()
{
	SizeX = 20;
	SizeY = 20;
	Map = new char* [SizeX];
	for (int i = 0; i < SizeX; i++)
	{
		Map[i] = new char[SizeY];
	}
}

Grid2D::Grid2D(int X, int Y)
{
	SizeX = X;
	SizeY = Y;
	Map = new char* [SizeX];
	for (int i = 0; i < SizeX; i++)
	{
		Map[i] = new char[SizeY];
	}
}

Grid2D::~Grid2D()
{
	for (int i = 0; i < SizeX; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;
}

void Grid2D::Draw()
{
	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			cout << Map[SizeY - 1 - i][j] << " ";
		}
		cout << endl;
	}

	//for (int i = 0; i < Manager->GetCurrentPlayer(); i++)
	//{
	//	Manager->GetGameObject(ObjectCategory::Player)[i];
	//}
}

int Grid2D::GetSizeX()
{
	return SizeX;
}

int Grid2D::GetSizeY()
{
	return SizeY;
}

char** Grid2D::GetMap()
{
	return Map;
}

void Grid2D::SetGameManager(GameManager* Manager)
{
	this->Manager = Manager;
}

