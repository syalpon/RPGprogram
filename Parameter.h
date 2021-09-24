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

    virtual void Event_MaxIncrement(); //上限値が増えた時
    virtual void Event_MaxDecrement(); //上限値が減った時
    virtual void Event_NowIncrement(); //現在値が増えた時
    virtual void Event_NowDecrement(); //現在値が減った時
    virtual void Event_MinIncrement(); //下限値が増えた時
    virtual void Event_MinDecrement(); //下限値が減った時
    virtual void Event_NowExceedMax(); //現在値が上限値を上回った時
    virtual void Event_NowBelowMin();  //現在値が下限値を下回った時

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

    //演算子のオーバーライド
    virtual int operator+(T);
    virtual T& operator+=(int);
    virtual T& operator+=(T);
    virtual T& operator++(int);
    virtual int operator-(T);
    virtual T& operator-=(T);
    virtual T& operator-=(int);
    virtual T& operator=(int);

    //表示関数
    virtual void Show();
    virtual void Show(const char *);
};


#endif