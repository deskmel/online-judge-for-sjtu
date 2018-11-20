#include <iostream>//求加密的字符串

using namespace std;

char encrypt(char* ,int i);//声明加密函数
//char decrypt(char);

int main()
{
    char plainText[100]={'\0'};
    int i;
    char encryptText[100]={'\0'};
    char *p;
    //char decryptText[100]={'\0'};

    cout<<"Please input the plain text:";//输入原来的未加密的字符串
    for(i=0;i<10;++i){
        cin>>plainText[i];
    }

    p=plainText;

    for(i=0;i<10;++i){//对字符串进行加密
        encryptText[i]=encrypt((p+i),i);
    }
    //for(i=0;i<100;++i){
        //decryptText[i]=decrypt(encryptText[i],i);
   // }

    cout<<encryptText[100]<<endl;
    //cout<<decryptText[100]<<endl;


    return 0;
}

char encrypt(char *p,int i){//加密程序
    int j;
    char encryptText=0;

    j=i%7;//j用来看每个单独的字符串要加哪个数
    switch(j){
    case 0:
        if(*p+8>122||*p+8<32){
            encryptText=(*p+8)%122+32;
        }
        else{
            encryptText=*p+8;
        }
        break;
    case 1:
        if(*p+7>122||*p+7<32){
            encryptText=(*p+7)%122+32;
        }
        else{
            encryptText=*p+7;
        }
        break;
    case 2:
        if(*p+3>122||*p+3<32){
            encryptText=(*p+3)%122+32;
        }
        else{
            encryptText=*p+3;
        }
        break;
    case 3:
        if(*p+4>122||*p+4<32){
            encryptText=(*p+4)%122+32;
        }
        else{
            encryptText=*p+4;
        }
        break;
    case 4:
        if(*p+9>122||*p+9<32){
            encryptText=(*p+9)%122+32;
        }
        else{
            encryptText=*p+9;
        }
        break;
    case 5:
        if(*p+6>122||*p+6<32){
            encryptText=(*p+6)%122+32;
        }
        else{
            encryptText=*p+6;
        }
        break;
    case 6:
        if(*p+2>122||*p+2<32){
            encryptText=(*p+2)%122+32;
        }
        else{
            encryptText=*p+2;
        }
        break;
        }
return encryptText;
}