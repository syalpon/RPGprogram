#ifndef EXP_H
#define EXP_H

#include "Parameter.h"

class Exp : public Parameter<Exp>
{
protected:
	//���ݒl������l����������
	void Event_NowExceedMax(int ,int );

public:
	//�R���X�g���N�^
	Exp();
	Exp(void*, int, int, int);
};


#endif