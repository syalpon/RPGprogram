#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter<Hp>
{
protected:
	//�I�[�o�[���C�h
	void Event_NowBelowMin();


public:
	//�R���X�g���N�^
	Hp();
	Hp(void *,int,int,int);
};


#endif