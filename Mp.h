#ifndef MP_H
#define MP_H

#include "Parameter.h"

class Mp : public Parameter<Mp>
{
protected:
	//�I�[�o�[���C�h
	void Event_MaxIncrement(int, int); //����l����������
public:
	//�R���X�g���N�^
	Mp();
	Mp(void*, int, int, int);
};



#endif