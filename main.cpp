#include "Side.h"
#include "Character.h"

static bool AllyAtack(Character*, Character[], int);
static bool EnemyAtack( Character *, Character [] ,int );

int main()
{
	//勇者
	Character Brave(
		"Brave",
		ALLY,
		0,100,100,
		0,100,100,
		0,  0,100,
		1,  1, 99,
		0, 10,100
	);

	//戦士
	Character Warriar(
		"Warriar",
		ALLY,
		0, 200, 200,
		0,   0,   0,
		0,   0, 100,
		1,   1,  99,
		0,  20, 200
	);

	//魔法使い
	Character Wizard(
		"Wizard",
		ALLY,
		0, 100, 100,
		0, 200, 200,
		0,   0,  50,
		1,   1,  99,
		0,  10, 100
	);

	//怪獣
	Character Monster(
		"Monster",
		ENEMY,
		0, 100, 100,
		0,   0,   0,
		0,   0, 100,
		1,  10,  99,
		0,  20, 200
	);

	//ボス
	Character Boss(
		"Boss",
		ENEMY,
		0, 999, 999,
		0, 999, 999,
		0, 100, 999,
		1, 999, 999,
		0, 999, 999
	);

	Character Ally[]  = { Brave ,Warriar ,Wizard };

	int AllyNum = sizeof(Ally) / sizeof(Ally[0]);


	//戦闘1
	while (true) 
	{
		//見方の攻撃:敵が死亡した場合終了
		if ( AllyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}

		//敵の攻撃:見方が死亡した場合終了
		if (EnemyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}
	}




	//デバッグ
	Brave.Test();

	return 0;
}

//見方の攻撃：敵が死ぬまで順番に攻撃
//全員攻撃が終了して敵が生き残っている場合trueを返す。途中または最後に敵が死亡した場合はfalseを返す
static bool AllyAtack(Character* Enemy, Character Ally[], int AllyNum)
{
	bool alive = true;;
	for (int i = 0; i < AllyNum; i++)
	{
		Ally[i].Atack(*Enemy);

		if (Enemy->GetAlive() == false)
		{
			alive = false;
			break;
		}
	}

	return alive;
}

//敵の攻撃：最後から生存しているキャラクターに向けて１回攻撃
static bool EnemyAtack(Character *Enemy, Character Ally[],int AllyNum )
{
	bool alive = true;
	//生存者の中で配列の後ろにいるキャラクターを算出
	for (int i = AllyNum-1 ; 0 <= i ; i-- )
	{
		if (Ally[i].GetAlive() == true)
		{
			Enemy->Atack(Ally[i]);
			break;
		}
	}

	//勇者が死亡した場合見方陣営の敗北
	if (Ally[0].GetAlive() == false)
	{
		alive = false;
	}

	return alive;
}