#pragma once

#include "Grid2D.h"
#include "GameObject.h"

class Grid2D;

enum class ObjectCategory
{
	Player,
	Enemy,
};

class GameManager
{
private:
	Grid2D* Grid;
	GameObject*** GameObjects;
	int MaxGameObjectCategory;
	int CurrentPlayer;
	int MaxPlayer;
	int CurrentEnemy;
	int MaxEnemy;

public:
	GameManager();
	GameManager(Grid2D* Grid);
	GameManager(Grid2D* Grid, GameObject* Object);
	~GameManager();

	void AddGameObject(GameObject* GameObject, ObjectCategory ObjectCategory);
	void RemoveGameObject(GameObject* GameObject);
	void Update();
	GameObject** GetGameObject(ObjectCategory ObjectCategory);
	int GetCurrentPlayer();
};