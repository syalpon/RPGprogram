#ifndef EXP_H
#define EXP_H

#include "Parameter.h"

class Exp : public Parameter
{
protected:
	//���ݒl������l����������
	void Event_Process_NowExceedMax(int, int);
	void Event_NowExceedMax_Process(int ,int );

public:
	//�R���X�g���N�^
	Exp();
	Exp(void*, int, int, int);
};


#endif