#include "GameManager.h"

GameManager::GameManager()
{
	Grid = nullptr;
	MaxGameObjectCategory = 10;
	CurrentPlayer = 0;
	MaxPlayer = 2;
	CurrentEnemy = 0;
	MaxEnemy = 100;
	GameObjects = new GameObject * *[MaxGameObjectCategory];
	GameObjects[(int)ObjectCategory::Player] = new GameObject * [MaxPlayer];
	GameObjects[(int)ObjectCategory::Enemy] = new GameObject * [MaxEnemy];
}

GameManager::GameManager(Grid2D* Grid)
{
	this->Grid = Grid;
	Grid->SetGameManager(this);
	MaxGameObjectCategory = 10;
	CurrentPlayer = 0;
	MaxPlayer = 2;
	CurrentEnemy = 0;
	MaxEnemy = 100;
	GameObjects = new GameObject * *[MaxGameObjectCategory];
	GameObjects[(int)ObjectCategory::Player] = new GameObject * [MaxPlayer];
	GameObjects[(int)ObjectCategory::Enemy] = new GameObject * [MaxEnemy];
}

GameManager::GameManager(Grid2D* Grid, GameObject* Object)
{
	this->Grid = Grid;
	Grid->SetGameManager(this);
	MaxGameObjectCategory = 10;
	CurrentPlayer = 0;
	MaxPlayer = 2;
	CurrentEnemy = 0;
	MaxEnemy = 100;
	GameObjects = new GameObject ** [MaxGameObjectCategory];
	GameObjects[(int)ObjectCategory::Player] = new GameObject * [MaxPlayer];
	GameObjects[(int)ObjectCategory::Enemy] = new GameObject * [MaxEnemy];
	AddGameObject(Object, ObjectCategory::Player);
}

GameManager::~GameManager()
{
	// delete[] GameObject;
	delete[] GameObjects[(int)ObjectCategory::Player];
	delete[] GameObjects[(int)ObjectCategory::Enemy];
	delete[] GameObjects;
}

void GameManager::AddGameObject(GameObject* GameObject, ObjectCategory ObjectCategory)
{
	if (ObjectCategory == ObjectCategory::Player)
	{
		GameObjects[(int)ObjectCategory::Player][CurrentPlayer++] = GameObject;
	}
	else if (ObjectCategory == ObjectCategory::Enemy)
	{
		GameObjects[(int)ObjectCategory::Enemy][CurrentEnemy++] = GameObject;
	}
}

void GameManager::RemoveGameObject(GameObject* GameObject)
{
	// �� ã�Ƽ� ���ֱ�
	for (int i = 0; i < MaxEnemy; i++)
	{
		if (GameObjects[(int)ObjectCategory::Enemy][i]->GetId() == GameObject->GetId())
		{
			cout << GameObjects[(int)ObjectCategory::Enemy][i]->GetId() << "��(��) �Ҹ�Ǿ����ϴ�." << endl;
			GameObjects[(int)ObjectCategory::Enemy][i] = nullptr;
		}
	}

	// �����ؼ� �����ϴ°� �ڵ� �ʿ�
	CurrentEnemy--;
}

void GameManager::Update()
{
	// �⺻Map����
	for (int i = 0; i < Grid->GetSizeX(); i++)
	{
		for (int j = 0; j < Grid->GetSizeY(); j++)
		{
			if (i == 0 || i == Grid->GetSizeX() - 1 || j == 0 || j == Grid->GetSizeY() - 1)
			{
				Grid->GetMap()[i][j] = '#';
			}
			else
			{
				Grid->GetMap()[i][j] = ' ';
			}
		}
	}

	// �÷��̾�
	int PlayerX = GameObjects[(int)ObjectCategory::Player][0]->GetX();
	int PlayerY = GameObjects[(int)ObjectCategory::Player][0]->GetY();
	Grid->GetMap()[PlayerX][PlayerY] = GameObjects[(int)ObjectCategory::Player][0]->GetId()[0];

}

GameObject** GameManager::GetGameObject(ObjectCategory Category)
{
	if (Category == ObjectCategory::Player)
	{
		return GameObjects[(int)ObjectCategory::Player];
	}
	else if (Category == ObjectCategory::Enemy)
	{
		return GameObjects[(int)ObjectCategory::Enemy];
	}

	return nullptr;
}

int GameManager::GetCurrentPlayer()
{
	return CurrentPlayer;
}
