#include "Side.h"
#include "Character.h"

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

	//�{�X
	Character Boss(
		"Boss",
		ENEMY,
		0,999,999,
		0,999,999,
		0,100,999,
		1,999,999,
		0,999,999
	);

	//�s��
	Brave.Atack(Boss);
	Brave.Atack(Boss);
	Brave.Atack(Boss);
	Brave.Atack(Boss);
	Brave.Test();

	return 0;
}