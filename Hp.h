#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter
{
protected:
	//�I�[�o�[���C�h
	void Event_MaxIncrease_Process(int, int); //����l����������
	void Event_NowIncrease_Process(int, int); //���ݒl����������
	void Event_NowDecrease_Process(int, int);  //�_���[�W���󂯂���
	void Event_NowBelowMin_Process(int ,int);	//���S��
	
public:
	//�R���X�g���N�^
	Hp();
	Hp(void *,int,int,int);
};


#endif