#ifndef MP_H
#define MP_H

#include "Parameter.h"

class Mp : public Parameter
{
protected:
	//����l����������
	void Event_MaxIncrease_Process(int, int); 

public:
	//�R���X�g���N�^
	Mp();
	Mp(void*, int, int, int);
};



#endif