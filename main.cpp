#include "Side.h"
#include "Character.h"

static bool AllyAtack(Character*, Character[], int);
static bool EnemyAtack( Character *, Character [] ,int );

int main()
{
	//—EÒ
	Character Brave(
		"Brave",
		ALLY,
		0,100,100,
		0,100,100,
		0,  0,100,
		1,  1, 99,
		0, 10,100
	);

	//ím
	Character Warriar(
		"Warriar",
		ALLY,
		0, 200, 200,
		0,   0,   0,
		0,   0, 100,
		1,   1,  99,
		0,  20, 200
	);

	//–‚–@g‚¢
	Character Wizard(
		"Wizard",
		ALLY,
		0, 100, 100,
		0, 200, 200,
		0,   0,  50,
		1,   1,  99,
		0,  10, 100
	);

	//‰öb
	Character Monster(
		"Monster",
		ENEMY,
		0, 100, 100,
		0,   0,   0,
		0,   0, 100,
		1,  10,  99,
		0,  20, 200
	);

	//ƒ{ƒX
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


	//í“¬1
	while (true) 
	{
		//Œ©•û‚ÌUŒ‚:“G‚ª€–S‚µ‚½ê‡I—¹
		if ( AllyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}

		//“G‚ÌUŒ‚:Œ©•û‚ª€–S‚µ‚½ê‡I—¹
		if (EnemyAtack(&Monster, Ally, AllyNum) == false)
		{
			break;
		}
	}




	//ƒfƒoƒbƒO
	Brave.Test();

	return 0;
}

//Œ©•û‚ÌUŒ‚F“G‚ª€‚Ê‚Ü‚Å‡”Ô‚ÉUŒ‚
//‘SˆõUŒ‚‚ªI—¹‚µ‚Ä“G‚ª¶‚«c‚Á‚Ä‚¢‚éê‡true‚ğ•Ô‚·B“r’†‚Ü‚½‚ÍÅŒã‚É“G‚ª€–S‚µ‚½ê‡‚Ífalse‚ğ•Ô‚·
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

//“G‚ÌUŒ‚FÅŒã‚©‚ç¶‘¶‚µ‚Ä‚¢‚éƒLƒƒƒ‰ƒNƒ^[‚ÉŒü‚¯‚Ä‚P‰ñUŒ‚
static bool EnemyAtack(Character *Enemy, Character Ally[],int AllyNum )
{
	bool alive = true;
	//¶‘¶Ò‚Ì’†‚Å”z—ñ‚ÌŒã‚ë‚É‚¢‚éƒLƒƒƒ‰ƒNƒ^[‚ğZo
	for (int i = AllyNum-1 ; 0 <= i ; i-- )
	{
		if (Ally[i].GetAlive() == true)
		{
			Enemy->Atack(Ally[i]);
			break;
		}
	}

	//—EÒ‚ª€–S‚µ‚½ê‡Œ©•ûw‰c‚Ì”s–k
	if (Ally[0].GetAlive() == false)
	{
		alive = false;
	}

	return alive;
}