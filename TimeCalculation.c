/*
 C言語による時計算
 https://neguse-atama.hatenablog.com
*/
#include <stdio.h>
int main(void){
    int nanzi,nanfun,tuzuki;
    double tyoukaku,tankaku,sanokaku,motomerukaku;
    do{
        printf("時計の長針と短針のなす角度を求めます。任意の時刻を入力してください。\n(ただし、入力できる時間は0から11、分は0から59までの整数値に限ります)\n");
        printf("何時:");  scanf("%d",&nanzi);
        printf("何分:");  scanf("%d",&nanfun);
        if((nanzi>=0 && nanzi<=11) && nanfun>=60){
            printf("「何分:」に60以上の整数(整数以外の値)を入力しないでください。\n");
            goto yarinaosikeisan;
        }else if(nanzi>=12 && nanfun>=60){
            printf("「何時:」に12以上の整数(整数以外の値)を、「何分:」に60以上の整数(整数以外の値)を入力しないでください。\n");
            goto yarinaosikeisan;
        }else if(nanzi>=12 && (nanfun>=0 && nanfun<=59)){
            printf("「何時:」に12以上の整数(整数以外の値)を入力しないでください。\n");
            goto yarinaosikeisan;
        }
        tyoukaku=6*nanfun;
        tankaku=0.5*(60*nanzi+nanfun);
        if(nanzi<0 && nanfun>0){
            printf("「何時:」に負の数を入力しないでください。\n");
        }else if(nanzi>0 && nanfun<0){
            printf("「何分:」に負の数を入力しないでください。\n");
        }else if(nanzi<0 && nanfun<0){
            printf("「何時:」,「何分:」に負の数を入力しないでください。\n");
        }else if(tankaku<tyoukaku){
            sanokaku=tyoukaku-tankaku;
            if(sanokaku>180 && sanokaku!=360){
                motomerukaku=360-sanokaku;
                printf("求める小さい方の角度は%lf度です。\n",motomerukaku);
                printf("求める大きい方の角度は%lf度です。\n",sanokaku);
            }else if(sanokaku<=180){
                motomerukaku=360-sanokaku;
                printf("求める小さい方の角度は%lf度です。\n",sanokaku);
                printf("求める大きい方の角度は%lf度です。\n",motomerukaku);
            }
        }else if(tankaku>tyoukaku){
            sanokaku=tankaku-tyoukaku;
            if(sanokaku>180 && sanokaku!=360){
                motomerukaku=360-sanokaku;
                printf("求める小さい方の角度は%lf度です。\n",motomerukaku);
                printf("求める大きい方の角度は%lf度です。\n",sanokaku);
            }else if(sanokaku<=180){
                motomerukaku=360-sanokaku;
                printf("求める小さい方の角度は%lf度です。\n",sanokaku);
                printf("求める大きい方の角度は%lf度です。\n",motomerukaku);
            }
        }else if((tyoukaku==tankaku)||(tyoukaku==0&&tankaku==360)){
            printf("求める角度は0度です。\n");
        }
    yarinaosikeisan:
        printf("計算をやり直しますか。・・・(0)はい (1)いいえ:");
        scanf("%d",&tuzuki);
        printf("これで計算を終了します。\n");
    }while(tuzuki==0);
    return (0);
}