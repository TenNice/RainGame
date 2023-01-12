#include "GameObject.h"

GameObject::GameObject()
{
	Hp = 100;
	Id = "Default";
	X = 1;
	Y = 1;
}

GameObject::GameObject(string Id, int X, int Y)
{
	this->Id = Id;
	this->X = X;
	this->Y = Y;
}

GameObject::~GameObject()
{

}

string GameObject::GetId()
{
	return Id;
}

int GameObject::GetX()
{
	return X;
}

int GameObject::GetY()
{
	return Y;
}

float GameObject::GetHp()
{
	return Hp;
}

void GameObject::SetHp(float Hp)
{
	this->Hp = Hp;
}

void GameObject::Move(Direction Direction)
{
	switch (Direction)
	{
	case Direction::None:
		break;
	case Direction::Up:
		Y++;
		break;
	case Direction::Down:
		Y--;
		break;
	case Direction::Right:
		X++;
		break;
	case Direction::Left:
		X--;
		break;
	default:
		break;
	}
}

void GameObject::Attack()
{
	// �÷��̾� X,Y��ǥ�� �� X,Y��ǥ�� ��ġ�� TakeDamage()
	// -> X,Y��ǥ ��ġ�°� ã���ִ� �Լ��� �ʿ�
	TakeDamage(100);
	
}

void GameObject::TakeDamage(int Damage)
{
	Hp -= Damage;
	if (Hp <= 0)
	{
		Dead();
	}
}

void GameObject::Dead()
{
	//Manager->RemoveGameObject(this);
}

