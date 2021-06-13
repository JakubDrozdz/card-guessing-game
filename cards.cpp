#include<iostream>
#include<cstdlib>
#include <stdlib.h>
#include <time.h> 
using namespace std;
bool check_unique(int tab[],int rozm,int x){
    for(int i=0;i<rozm;i++){
        if(tab[i]==x) return false;
    }
    return true;
}
void rand_tab(int tab[]){
    int rozm=0;
    for(int i=0;i<24;i++){
        int x=1+rand()%(24+1-1);
        rozm++;
        if(check_unique(tab,rozm,x)==true){
            tab[i]=x;
        }
        else{
            i--;
            rozm--;
        }
    }
}
void show_tab(int tab[],int rozm){
    for(int i=0;i<rozm;i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}
void div_four(int tab_24[],int tab_1[],int tab_2[],int tab_3[],int tab_4[]){
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<24;i++){
        if(i==0||i==4||i==8||i==12||i==16||i==20){
            tab_1[a]=tab_24[i];
            a++;
        }
        if(i==1||i==5||i==9||i==13||i==17||i==21){
            tab_2[b]=tab_24[i];
            b++;
        }
        if(i==2||i==6||i==10||i==14||i==18||i==22){
            tab_3[c]=tab_24[i];
            c++;
        }
        if(i==3||i==7||i==11||i==15||i==19||i==23){
            tab_4[d]=tab_24[i];
            d++;
        }
    }
}
void div_three(int tab_24[],int t_1[],int t_2[],int t_3[]){
    int a=0,b=0,c=0;
    for(int i=0;i<24;i++){
        if(i==0||i==3||i==6||i==9||i==12||i==15||i==18||i==21){
            t_1[a]=tab_24[i];
            a++;
        }
        if(i==1||i==4||i==7||i==10||i==13||i==16||i==19||i==22){
            t_2[b]=tab_24[i];
            b++;
        }
        if(i==2||i==5||i==8||i==11||i==14||i==17||i==20||i==23){
            t_3[c]=tab_24[i];
            c++;
        }
    }
}
void div_two(int tab_24[],int t1[],int t2[]){
    int a=0,b=0;
    for(int i=0;i<24;i++){
        if(i==0||i==2||i==4||i==6||i==8||i==10||i==12||i==14||i==16||i==18||i==20||i==22){
            t1[a]=tab_24[i];
            a++;
        }
        if(i==1||i==3||i==5||i==7||i==9||i==11||i==13||i==15||i==17||i==19||i==21||i==23){
            t2[b]=tab_24[i];
            b++;
        }
    }
}
void reverse_tab(int tab[],int rozm){
    int x=rozm-1;
    for(int i=0;i<rozm;i++){
        if(i!=x){
            int temp=tab[i];
            tab[i]=tab[x];
            tab[x]=temp;
            x--;
        }
        if(i==x||i==x-1) break;
    }
}
bool first_check(int tab[],int rozm){
    cout<<"Czy jest w: \n";
    for(int i=0;i<rozm;i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
    char znak;
    cin>>znak;
    if(znak!='y') return false;
    return true;
}
void stack_tabs(int tab_24[],int tab[],int rozm,int pocz){
    int j=0;
    for(int i=pocz;i<pocz+rozm;i++){
        tab_24[i]=tab[j];
        j++;
    }
}

int main(){
    srand(time(NULL));
    int tab_24[24];
    rand_tab(tab_24);
    cout<<"Wybierz swoją liczbę"<<endl;
    show_tab(tab_24,24);
    int tab_1[6],tab_2[6],tab_3[6],tab_4[6];
    div_four(tab_24,tab_1,tab_2,tab_3,tab_4);
    reverse_tab(tab_1,6);
    reverse_tab(tab_2,6);
    reverse_tab(tab_3,6);
    reverse_tab(tab_4,6);
    int num=1;
    bool state=false;
    state=first_check(tab_1,6);
    if(state==false){
        state=first_check(tab_2,6);
        num=2;
        if(state==false){
            state=first_check(tab_3,6);
            num=3;
            if(state==false){
                num=4;
                state=first_check(tab_4,6);
            }
        }
    }

    if(num==1){
        stack_tabs(tab_24,tab_1,6,0);
        stack_tabs(tab_24,tab_2,6,6);
        stack_tabs(tab_24,tab_3,6,12);
        stack_tabs(tab_24,tab_4,6,18);
    }
    if(num==2){
        stack_tabs(tab_24,tab_2,6,0);
        stack_tabs(tab_24,tab_3,6,6);
        stack_tabs(tab_24,tab_4,6,12);
        stack_tabs(tab_24,tab_1,6,18);
    }
    if(num==3){
        stack_tabs(tab_24,tab_3,6,0);
        stack_tabs(tab_24,tab_4,6,6);
        stack_tabs(tab_24,tab_1,6,12);
        stack_tabs(tab_24,tab_2,6,18);
    }
    if(num==4){
        stack_tabs(tab_24,tab_4,6,0);
        stack_tabs(tab_24,tab_1,6,6);
        stack_tabs(tab_24,tab_2,6,12);
        stack_tabs(tab_24,tab_3,6,18);
    }

    cout<<endl;
    int t_1[8],t_2[8],t_3[8];
    div_three(tab_24,t_1,t_2,t_3);
    reverse_tab(t_1,8);
    reverse_tab(t_2,8);
    reverse_tab(t_3,8);
    num=1;
    state=false;
    state=first_check(t_1,8);
    if(state==false){
        state=first_check(t_2,8);
        num=2;
        if(state==false){
            num=3;
            state=first_check(t_3,8);
        }
    }

    if(num==1){
        stack_tabs(tab_24,t_1,8,0);
        stack_tabs(tab_24,t_2,8,8);
        stack_tabs(tab_24,t_3,8,16);
    }
    if(num==2){
        stack_tabs(tab_24,t_2,8,0);
        stack_tabs(tab_24,t_3,8,8);
        stack_tabs(tab_24,t_1,8,16);
    }
    if(num==3){
        stack_tabs(tab_24,t_3,8,0);
        stack_tabs(tab_24,t_1,8,8);
        stack_tabs(tab_24,t_2,8,16);
    }

    cout<<endl;
    int t1[12],t2[12];
    div_two(tab_24,t1,t2);
    reverse_tab(t1,12);
    reverse_tab(t2,12);
    num=1;
    state=false;
    state=first_check(t1,12);
    if(state==false){
        num=2;
        state=first_check(t2,12);
    }

    if(num==1){
        stack_tabs(tab_24,t1,12,0);
        stack_tabs(tab_24,t2,12,12);
    }
    if(num==2){
        stack_tabs(tab_24,t2,12,0);
        stack_tabs(tab_24,t1,12,12);
    }
    cout<<"Twoja liczba to: "<<tab_24[8]<<endl;
    return 0;
}