#include "Side.h"
#include "Character.h"

static bool AllyAtack(Character*, Character[], int);
static bool EnemyAtack( Character *, Character [] ,int );

int main()
{
	//�E��
	Character Brave(
		"Brave",
		ALLY,
		0,100,100,
		0,100,100,
		0,  0,100,
		1,  1, 99,
		0, 10,100
	);

	//��m
	Character Warriar(
		"Warriar",
		ALLY,
		0, 200, 200,
		0,   0,   0,
		0,   0, 100,
		1,   1,  99,
		0,  20, 200
	);

	//���@�g��
	Character Wizard(
		"Wizard",
		ALLY,
		0, 100, 100,
		0, 200, 200,
		0,   0,  50,
		1,   1,  99,
		0,  10, 100
	);

	//���b
	Character Monster(
		"Monster",
		ENEMY,
		0, 100, 100,
		0,   0,   0,
		0,   0, 100,
		1,  10,  99,
		0,  20, 200
	);

	//�{�X
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


	//�퓬1
	while (true) 
	{
		//�����̍U��:�G�����S�����ꍇ�I��
		if ( AllyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}

		//�G�̍U��:���������S�����ꍇ�I��
		if (EnemyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}
	}




	//�f�o�b�O
	Brave.Test();

	return 0;
}

//�����̍U���F�G�����ʂ܂ŏ��ԂɍU��
//�S���U�����I�����ēG�������c���Ă���ꍇtrue��Ԃ��B�r���܂��͍Ō�ɓG�����S�����ꍇ��false��Ԃ�
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

//�G�̍U���F�Ōォ�琶�����Ă���L�����N�^�[�Ɍ����ĂP��U��
static bool EnemyAtack(Character *Enemy, Character Ally[],int AllyNum )
{
	bool alive = true;
	//�����҂̒��Ŕz��̌��ɂ���L�����N�^�[���Z�o
	for (int i = AllyNum-1 ; 0 <= i ; i-- )
	{
		if (Ally[i].GetAlive() == true)
		{
			Enemy->Atack(Ally[i]);
			break;
		}
	}

	//�E�҂����S�����ꍇ�����w�c�̔s�k
	if (Ally[0].GetAlive() == false)
	{
		alive = false;
	}

	return alive;
}