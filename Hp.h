#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter<Hp>
{
protected:
	//�I�[�o�[���C�h
	void Event_MaxIncrement(int, int); //����l����������
	void Event_NowIncrement(int, int); //���ݒl����������
	void Event_NowDecrement(int, int);  //�_���[�W���󂯂���
	void Event_NowBelowMin(int ,int);	//���S��
	
public:
	//�R���X�g���N�^
	Hp();
	Hp(void *,int,int,int);
};


#endif