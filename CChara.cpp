/*--------------------------------------*/
/*@title	: RPG模倣プログラム	*/
/*@brief	: CChara		*/
/*					*/
/*@author	: 小幡翔也		*/
/*@date		: 2021/09/18		*/
/*--------------------------------------*/

#include "constantValue.h"
#include "CChara.h"


/*--------------------------------------*/
/*@brief	: コンストラクタ	*/
/*@param	: 			*/
/*@return	: なし			*/
/*					*/
/*@author	: 小幡翔也		*/
/*@date		: 2021/09/18		*/
/*--------------------------------------*/
CChara::CChara( /*検討中*/ ){

}/* end : constructor */

CChara::~CChara(void){
	/* do nothing */

}/* end : destructor */

/*--------------------------------------------------------------*/
/*@brief	: 被ダメージ処理				*/
/*@param	: short s2_damage	 : 受けるダメージ値	*/
/*@param	: unsigned char u1_param : HP/MP判定(拡張可)	*/
/*@return	: 対象パラメータの減少量			*/
/*								*/
/*@author	: 小幡翔也					*/
/*@date		: 2021/09/26					*/
/*--------------------------------------------------------------*/
short CChara::s2_damaged(short s2_damage, unsigned char u1_param){
	short s2_decParam = (short)NO_VARIATION;	/* パラメータの減少量 */

	/* ダメージ値の確認 */
	if( s2_damege < (short)LEAST_VARIATION	 ){
		s2_damage = (short)ZERO_VARIATION;
	}else{
		/* do nothing */
	}

	if( u1_param == (unsigned char)CALCULATE_HP ){
		s2_decParam = (*this).s2_hitPoint[CURR_VALUE_INDEX];	/* HPの現在値取得 */

		(*this).s2_hitPoint[CURR_VALUE_INDEX] -= s2_damage;	/* ダメージ処理 */

		/* 死亡判定 */
		if( (*this).s2_hitPoint[CURR_VALUE_INDEX] <= (*this).s2_hitPoint[LOWER_LIMIT_INDEX] ){
			(*this).s2_hitPoint[CURR_VALUE_INDEX] = (*this).s2_hitPoint[LOWER_LIMIT_INDEX];
		}else{
			/* do nothing */
		}

		s2_decParam -= (*this).s2_hitPoint[CURR_VALUE_INDEX];	/* 減少幅計算 */

	}else if( u1_param == (unsigned char)CALCULATE_MP ){
		s2_decParam = (*this).s2_magicPower[CURR_VALUE_INDEX];	/* MPの現在値取得 */

		(*this).s2_magicPower[CURR_VALUE_INDEX] -= s2_damage;	/* ダメージ処理 */

		/* 下限判定 */
		if( (*this).s2_magicPower[CURR_VALUE_INDEX] <= (*this).s2_magicPower[LOWER_LIMIT_INDEX] ){
			(*this).s2_magicPower[CURR_VALUE_INDEX] = (*this).s2_magicPower[LOWER_LIMIT_INDEX];
		}else{
			/* do nothing */
		}

		s2_decParam -= (*this).s2_magicPower[CURR_VALUE_INDEX];	/* 減少幅計算 */
	}else{
		/* do nothing : 拡張用 */
	}

	return s2_decParam;
}/* end : ダメージ処理 */

/*--------------------------------------------------------------*/
/*@brief	: 回復処理					*/
/*@param	: short s2_recover	 : 回復量		*/
/*@param	: unsigned char u1_param : HP/MP判定(拡張可)	*/
/*@return	: 対象パラメータの増加量			*/
/*								*/
/*@author	: 小幡翔也					*/
/*@date		: 2021/09/26					*/
/*--------------------------------------------------------------*/
short CChara::s2_recovered(short s2_damage, unsigned char u1_param){
	short s2_incParam = (short)NO_VARIATION;	/* パラメータの増加量 */

	/* 回復量チェック */
	if( s2_damege < (short)LEAST_VARIATION	 ){
		s2_damage = (short)ZERO_VARIATION;
	}else{
		/* do nothing */
	}

	if( u1_param == (unsigned char)CALCULATE_HP ){
		s2_incParam = (*this).s2_hitPoint[CURR_VALUE_INDEX];	/* HPの現在値取得 */

		(*this).s2_hitPoint[CURR_VALUE_INDEX] += s2_recover;	/* 回復処理 */

		/* 上限判定 */
		if( (*this).s2_hitPoint[CURR_VALUE_INDEX] > (*this).s2_hitPoint[HIGHER_LIMIT_INDEX] ){
			(*this).s2_hitPoint[CURR_VALUE_INDEX] = (*this).s2_hitPoint[HIGHER_LIMIT_INDEX];
		}else{
			/* do nothing */
		}

		s2_incParam = (*this).s2_hitPoint[CURR_VALUE_INDEX] - s2_incParam;	/* 増加幅計算 */

	}else if( u1_param == (unsigned char)CALCULATE_MP ){
		(*this).s2_incParam = (*this).s2_magicPower[CURR_VALUE_INDEX];	/* MPの現在値取得 */

		(*this).s2_magicPower[CURR_VALUE_INDEX] += s2_recover;	/* 回復処理 */

		/* 上限判定 */
		if( (*this).s2_magicPower[CURR_VALUE_INDEX] > (*this).s2_magicPower[HIGHER_LIMIT_INDEX] ){
			(*this).s2_magicPower[CURR_VALUE_INDEX] = (*this).s2_magicPower[HIGHER_LIMIT_INDEX];
		}else{
			/* do nothing */
		}

		s2_incParam = (*this).s2_magicPower[CURR_VALUE_INDEX] - s2_incParam;	/* 増加幅計算 */
	}else{
		/* do nothing : 拡張用 */
	}

	return s2_incParam;
}/* end : 回復処理 */


/*--------------------------------------------------------------*/
/*@brief	: パラメータの範囲調整				*/
/*@param	: なし						*/
/*@return	: 正常に調整が行われたか			*/
/*								*/
/*@author	: 小幡翔也					*/
/*@date		: 2021/09/26					*/
/*--------------------------------------------------------------*/
bool CChara::bl_paramAdjustSelf(void){
	void* vp_checkParamAdr[] = { 
			&((this*).s2_hitPoint),
			&((this*).s2_magicPower), 
			&((this*).u2_executerPoint), 
			&((this*).u1_level), 
			&((this*).u1_atk)
		 };										/* 調整対象パラメータ */
	unsigned char u1p_checkAdrSize[] = {
			(unsigned char)CAST_S2,
			(unsigned char)CAST_S2, 
			(unsigned char)CAST_U2, 
			(unsigned char)CAST_U1, 
			(unsigned char)CAST_U1
		 };										/* キャスト用ID */
	signed char s1_normalState = (signed char)STATE_UNCHECKED;				/* 前提条件評価変数 */
	const unsigned char u1_checkAdrSize = sizeof(u1p_checkAdrSize) / sizeof(unsigned char);	/* 対象の件数 */
	bool bl_adjustExecute = true;								/* 正常に動作したかを識別するフラグ */

	for( unsigned char u1_checkAdrIndex = (unsigned char)0; u1_checkAdrIndex < u1_checkAdrSize; u1_checkAdrIndex++ ){

		/* 型識別 */
		switch( u1p_checkAdrSize ){
			case (CAST_U1) : 
				s1_normalState |= ( *( ((unsigned char*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (unsigned char)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned char*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (unsigned char)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned char*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((unsigned char*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			case (CAST_S1) :
				s1_normalState |= ( *( ((signed char*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (signed char)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((signed char*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (signed char)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((signed char*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((signed char*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break; 
			case (CAST_U2) : 
				s1_normalState |= ( *( ((unsigned short*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (unsigned short)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned short*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (unsigned short)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned short*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((unsigned short*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			case (CAST_S2) : 
				s1_normalState |= ( *( ((short*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (short)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((short*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (short)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((short*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((short*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			case (CAST_U4) : 
				s1_normalState |= ( *( ((unsigned int*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (unsigned int)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned int*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (unsigned int)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((unsigned int*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((unsigned int*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			case (CAST_S4) : 
				s1_normalState |= ( *( ((int*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (int)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((int*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (int)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((int*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((int*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			case (CAST_FLOAT) : 
				s1_normalState |= ( *( ((float*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < (float)CEILING_HIGHER_LIMIT ? (signed char)STATE_LOWER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((float*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) <= (float)CEILING_HIGHER_LIMIT ? (signed char)STATE_HIGHER_LIMIT_OK : (signed char)STATE_NG;
				s1_normalState |= ( *( ((float*)vp_checkParamAdr[u1_checkAdrIndex]) + LOWER_LIMIT_INDEX ) < *( ((float*)vp_checkParamAdr[u1_checkAdrIndex]) + HIGHER_LIMIT_INDEX ) ? (signed char)STATE_CURR_EXISTABLE : (signed char)STATE_NG;
				break;
			default : 
				s1_normalState = (signed char)STATE_NG;
		}

		/* 異常がある場合 */
		if( s1_normalStatus != (signed char)STATE_ALL_GREEN ){
			bl_adjustExecute = false;
			break;

		}else{
			/* 評価パート */
		}

	}

	return bl_adjustExecute;
}/* end : パラメータの調整 */

/*------------------------------------------------------*/
/*@brief	: 戦闘勝利に伴うexp獲得			*/
/*@param	: cl_killedEnemy : 倒した敵の情報	*/
/*@return	: なし					*/
/*							*/
/*@author	: 小幡翔也				*/
/*@date		: 2021/09/26				*/
/*------------------------------------------------------*/
void CChara::vd_winBattle( CChara cl_killedEnemy ){

	(*this).u2_executerPoint[CURR_VALUE_INDEX] += (unsigned short)(cl_killedEnemy.u1_level[CURR_VALUE_INDEX] * 10);

}/* end : 戦闘勝利によるexp獲得 */


/*--------------------------------------*/
/*@brief	: レベルアップ処理	*/
/*@param	: なし			*/
/*@return	: LVupの発生有無	*/
/*					*/
/*@author	: 小幡翔也		*/
/*@date		: 2021/09/18		*/
/*--------------------------------------*/
bool CChara::bl_levelUp(void){
	bool bl_lvupDone = false;	/* LVupが行われたかどうかを識別するフラグ */

	/* LVの上限判定 */
	if( (*this).u1_level[HIGHER_LIMIT_INDEX] > (*this).u1_level[CURR_VALUE_INDEX] ){

		/* LVの現在値更新処理 */
		while( (*this).u2_executerPoint[HIGHER_LIMIT_INDEX] < (*this).u2_executerPoint[CURR_VALUE_INDEX] ){
			/* 各パラメータの更新 */
			(*this).s2_hitPoint[HIGHER_LIMIT_INDEX] += (short)((*this).u1_deltaHp);		/* 上昇値の変数を使う */
			(*this).s2_magicPower[HIGHER_LIMIT_INDEX] += (short)((*this).u1_deltaMp);
			(*this).s2_atk[CURR_VALUE_INDEX] += ((*this).u1_deltaAtk);

			/* EXPの現在値更新 */
			(*this).u2_executerPoint[CURR_VALUE_INDEX] -= (*this).u2_executerPoint[HIGHER_LIMIT_INDEX];

			/* LVup実行フラグを立てる */
			bl_lvupDone = true;
		}
	}else{
		/* do nothing */
	}

	return bl_lvupDone;
}/* end : レベルアップ処理 */


