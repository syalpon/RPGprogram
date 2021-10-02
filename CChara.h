/*--------------------------------------*/
/*@title	: RPG模倣プログラム	*/
/*@brief	: CChara		*/
/*					*/
/*@author	: 小幡翔也		*/
/*@date		: 2021/09/18		*/
/*--------------------------------------*/

class CChara{
	/* コンストラクタ */
	public : 
		CChara( /*検討中*/ );

	/* デストラクタ */
	public : 
		~CChara(void);

	/* クラス関数 */
	public : 
		short s2_damaged( short, unsigned char );
		short s2_recovered( short, unsigned char );
		bool bl_paramAdjustSelf(void);
		bool bl_levelUp(void);
		void vd_winBattle( CChara );


	/* クラス変数 */
	private : 
		short s2_hitPoint[PALAM_SIZE];			/* HP(体力) */
		short s2_magicPower[PALAM_SIZE];		/* MP(魔力) */
		unsigned short u2_executerPoint[PALAM_SIZE];	/* EXP(経験値) */

		unsigned char u1_nameArray[ NAME_LENG + 1 ];	/* 名前格納配列 */
		unsigned char u1_partyIdentifier;		/* 陣営識別符号 */
		unsigned char u1_level[PALAM_SIZE];		/* LV(レベル) */
		unsigned char u1_atk[PALAM_SIZE];		/* ATK(攻撃力) */

		unsigned char u1_deltaHp;			/* HP変化量(lvup用) */
		unsigned char u1_deltaMp;			/* MP変化量(lvup用) */
		unsigned char u1_deltaAtk;			/* 攻撃力変化量(lvup用) */

}
