#include <iostream>
#include<cstring>
using namespace std;

int minlen(string *p,int n);

int main()
{
    int i;
    int min;
    int num;

    cout << "please" ;
    cin>>num;

    string *p;
    p=new string[num];

    cout<<"ok";
    for(i=0;i<num;++i){
        cin>>*(p+i);
    }

    min=minlen(p,num);
    cout<<min;
    delete [] p;

    return 0;
}

int minlen(string *p,int num){
    int *lengthOfString;
    lengthOfString=new int[num];
    int minimun;
    int i;

    for(i=0;i<num;++i){
        cout<<(p+i)->length()<<endl;
        *(lengthOfString+i)=(p+i)->length();
    }

    for(i=0;i<num-1;++i){
        if(*(lengthOfString+i)<*(lengthOfString+i+1)){
            minimun=*(lengthOfString+i);
        }
    }
    delete [] lengthOfString;
    return minimun;
}