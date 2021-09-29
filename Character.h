#ifndef CHARACTER_H
#define CHARACTER_H

#include "Side.h"
#include "Parameter.h"
#include "Hp.h"
#include "Mp.h"
#include "Exp.h"
#include "Lv.h"
#include "Atk.h"

#define NAME_SIZE 8 //���O�̍ő啶����

//�L�����N�^�[�N���X
class Character
{
private:
	//�t�B�[���h
	char name[NAME_SIZE];	//���O
	Side side;				//�w�c
	Hp   hp;				//�̗�
	Mp   mp;				//����
	Exp  exp;				//�o���l
	Lv   lv;				//���x��
	Atk  atk;				//�U����

public :
	//�R���X�g���N�^
	Character();
	Character(const char *);
	Character(
		const char *,
		Side ,
		int,int,int,	//HP
		int,int,int,	//MP
		int,int,int,	//EXP
		int,int,int,	//LV
		int,int,int		//ATK
	);
	//�Q�b�^�[
	char* GetName();



	//�U������
	void Atack(Character &);

	//���x���A�b�v����
	void LevelUp();

	//���S����
	void Dead();

	//�X�e�[�^�X�\��
	void Show();


	//�f�o�b�O
	void Test();
};

#endif