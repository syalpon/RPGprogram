/*--------------------------------------*/
/*@title	: RPG模倣プログラム	*/
/*@brief	: 定数値定義		*/
/*					*/
/*@author	: 小幡翔也		*/
/*@date		: 2021/09/18		*/
/*--------------------------------------*/

#define LEAST_VARIATION	(1)		/* 最小の変化量 */
#define ZERO_VARIATION	(0)		/* 変化量0 */

#define CAST_U1		(0x01)		/* キャストID */
#define CAST_S1		(0x81)
#define CAST_U2		(0x02)
#define CAST_S2		(0x82)
#define CAST_U4		(0x04)
#define CAST_S4		(0x84)
#define CAST_FLOAT	(0xC4))


#define NAME_LENG	(8)		/* 名前の文字数 */
#define PALAM_SIZE	(3)		/* 1パラメータあたりの変数使用量 */

#define LOWER_LIMIT_INDEX	(0)	/* 下限値のインデックス */
#define CURR_VALUE_INDEX	(1)	/* 現在値のインデックス */
#define HIGHER_LIMIT_INDEX	(2)	/* 上限値のインデックス */

#define CALCULATE_HP	(1)		/* 演算対象 : HP */
#define CALCULATE_MP	(2)		/* 演算対象 : MP */

#define CEILING_DAMAGE	(999)		/* ダメージ上限(拡張用) */
#define LEAST_DAMAGE	(1)		/* ダメージ下限(拡張用) */
#define NO_DAMAGE	(0)		/* 攻撃を無効化(拡張用) */

#define CEILING_HIGHER_LIMIT	(999)		/* 上限値の上限 */

#define STATE_UNCHECKED		(0x00)	/* 評価前 */
#define STATE_LOWER_LIMIT_OK	(0x01)	/* 下限が前提を満たす */
#define STATE_HIGHER_LIMIT_OK	(0x02)  /* 上限が前提を満たす */
#define STATE_CURR_EXISTABLE	(0x04)	/* 現在値が存在可能 */
#define STATE_ALL_GREEN		(0x07)	/* 上記 3 条件を満たす */
#define STATE_NG		(0x00)	/* 条件を満たさない */

#define ERR_BROKEN_LIMIT	(-1)	/* エラー : パラメータの上限・下限が異常な値 */

