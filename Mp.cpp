#include "Mp.h"
#include "Character.h"

//---------------------------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------------------------
Mp::Mp():Parameter(this, 0, 100, 100){}
Mp::Mp(void* p, int _min, int _now, int _max):Parameter(p, _min, _now, _max){}

//---------------------------------------------------------------------
//�I�[�o�[���C�h�FMP�ő�l���������ݒl���ő�l�ɍ��킷
//---------------------------------------------------------------------
void Mp::Event_MaxIncrease_Process(int now_value, int update_value)
{
	SetNow(update_value);
}
