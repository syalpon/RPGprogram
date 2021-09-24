#include "Character.h"
#include <cstdio>
#include <cstring>

//---------------------------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------------------------
Character::Character()
	:Character("No Name")
{
	/* �����t���R���X�g���N�^�ɈϏ� */
}

Character::Character(const char* _name)
	: hp(this, 0, 100, 100),
	mp(this, 0, 100, 100),
	exp(this, 0, 0, 100),
	lv(this,1,1,99),
	atk(this,0,10,100)

{
	strcpy(name, _name);
	side = OTHER;
}

Character::Character(
	const char* _name,
	Side _side,
	int _hp_min, int _hp_now, int _hp_max,
	int _mp_min, int _mp_now, int _mp_max,
	int _exp_min, int _exp_now, int _exp_max,
	int _lv_min, int _lv_now, int _lv_max,
	int _atk_min, int _atk_now, int _atk_max
)
	: hp( this, _hp_min , _hp_now , _hp_max ),
	  mp( this, _mp_min , _mp_now , _mp_max ),
	  exp(this, _exp_min, _exp_now, _exp_max),
	  lv( this, _lv_min , _lv_now , _lv_max ),
	  atk(this, _atk_min, _atk_now, _atk_max)
{
	strcpy(name, _name);
	side = _side;
}

//---------------------------------------------------------------------
//�L�����N�^�[�U������
//---------------------------------------------------------------------
void Character::Atack(Character &character)
{
	character.hp -= this->hp;//TODO:hp��atk
}

//---------------------------------------------------------------------
//�L�����N�^�[���x���A�b�v����
//---------------------------------------------------------------------
void Character::LevelUp()
{
	printf("%s�̓��x���A�b�v����\n", name);
	lv++;
	atk+=50;
	Show();
}

//---------------------------------------------------------------------
//�L�����N�^�[���S����
//---------------------------------------------------------------------
void Character::Dead()
{
	printf("%s�͎��S����\n",name);
}

//---------------------------------------------------------------------
//�L�����N�^�[�X�e�[�^�X�\��
//---------------------------------------------------------------------
void Character::Show()
{
	printf("-----------------------------------\n");
	printf("[���O]:%s\n", name);
	switch (side)
	{
	case ALLY:
		printf("[�w�c]:%s\n", "����");
		break;

	case ENEMY:
		printf("[�w�c]:%s\n", "�G");
		break;

	case OTHER :
		printf("[�w�c]:%s\n", "���̑�");
		break;
		
	default :
		printf("ERROR : Character::Show \n");
		break;
	}
	
	hp.Show("HP");
	mp.Show("MP");
	exp.Show("EXP");
	lv.Show("LV");
	atk.Show("ATK");

	printf("-----------------------------------\n");
}



void Character::Test()
{
	exp += 350;
}