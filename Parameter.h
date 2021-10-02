#ifndef PARAMETER_H
#define PARAMETER_H

template <class T>
class Parameter
{
private:
    //フィールド
    int max;
    int now;
    int min;

protected:
    //自クラスを持つオブジェクトのポインタ
    void* owner;
    //閾値を超えた場合のイベントハンドラ
    //第一引数は更新前の値、第二引数は更新しようとしている値を受け取る
    virtual void Event_MaxIncrement(int ,int ); //上限値が増えた時
    virtual void Event_MaxDecrement(int ,int ); //上限値が減った時
    virtual void Event_NowIncrement(int ,int ); //現在値が増えた時
    virtual void Event_NowDecrement(int ,int ); //現在値が減った時
    virtual void Event_MinIncrement(int ,int ); //下限値が増えた時
    virtual void Event_MinDecrement(int ,int ); //下限値が減った時
    virtual void Event_NowExceedMax(int ,int ); //現在値が上限値を上回った時
    virtual void Event_NowBelowMin (int ,int ); //現在値が下限値を下回った時

public :
    //コンストラクタ
    Parameter();
    Parameter(void *,int ,int ,int );

    //ゲッター
    virtual int Max();
    virtual int Now();
    virtual int Min();
    //セッター
    virtual void Max(int);
    virtual void Now(int);
    virtual void Min(int);

    //表示関数
    virtual void Show();
    virtual void Show(const char *);
};

#endif