#pragma once
#include <iostream>
//#include "GameManager.h"

using namespace std;

class GameManager;

enum class Direction
{
	None,
	Up,
	Down,
	Right,
	Left,
};

class GameObject
{
private:
	float Hp;
	string Id;
	int X, Y;
	GameManager* Manager;

public:
	GameObject();
	GameObject(string Id, int X, int Y);
	~GameObject();

	string GetId();
	int GetX();
	int GetY();
	float GetHp();
	void SetHp(float Hp);
	void Move(Direction Direction);
	void Attack();
	void TakeDamage(int Damage);
	void Dead();
};