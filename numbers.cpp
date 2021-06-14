#include<iostream>
#include<cstdlib>
#include <stdlib.h>
#include <time.h> 
using namespace std;

//Jakub Drożdż 2021

bool check_unique(int arr[],int size,int x){
    for(int i=0;i<size;i++){
        if(arr[i]==x) return false;
    }
    return true;
}

void rand_tab(int arr[],int size){
    int cur_size=0;
    for(int i=0;i<size;i++){
        int x=1+rand()%(24+1-1);
        cur_size++;
        if(check_unique(arr,cur_size,x)==true){
            arr[i]=x;
        }
        else{
            i--;
            cur_size--;
        }
    }
}

void show_tab(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void allocate(int arr_24[],int arr[],int amount,int j,int counter){
    for(int i=0;i<amount;i++){
        arr[i]=arr_24[j];
        j+=counter;
    }
}

int* divide_arr(int arr_24[],int amount,int array_n){
    static int t1[12],t2[12],t3[12],t4[12];
    int counter=(24/amount);
    int j=0;
    if(array_n==1){
        allocate(arr_24,t1,amount,j,counter);
        return t1;
    }
    if(array_n==2){
        j=1;
        allocate(arr_24,t2,amount,j,counter);
        return t2;
    }
    if(array_n==3){
        j=2;
        allocate(arr_24,t3,amount,j,counter);
        return t3;
    }
    if(array_n==4){
        j=3;
        allocate(arr_24,t4,amount,j,counter);
        return t4;
    }
}

void reverse_array(int arr[],int size){
    int x=size-1;
    for(int i=0;i<size;i++){
        if(i!=x){
            int temp=arr[i];
            arr[i]=arr[x];
            arr[x]=temp;
            x--;
        }
        if(i==x||i==x-1) break;
    }
}

bool first_check(int arr[],int size){
    cout<<"Czy twoja liczbe znajduje się tutaj (y/n): \n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    char digit;
    cin>>digit;
    if(digit!='y') return false;
    return true;
}

int piece(int t1[],int t2[],int t3[],int t4[],int amount){
    bool state=false;
    int size = 24/amount;
    state=first_check(t1,size);
    if(state==false){
        state=first_check(t2,size);
        if(state==false&&amount>=3){
            state=first_check(t3,size);
            if(state==false&&amount>=4){
                state=first_check(t4,size);
                return 4;
            }
            return 3;
        }
        return 2;
    }
    return 1;
}
void stack_tabs(int arr_24[],int arr[],int size,int beg){
    int j=0;
    for(int i=beg;i<beg+size;i++){
        arr_24[i]=arr[j];
        j++;
    }
}

int main(){
    srand(time(NULL));
    int arr_24[24];
    rand_tab(arr_24,24);
    cout<<"Wybierz swoją liczbę"<<endl;
    show_tab(arr_24,24);

    //POINTERS TO ARRAYS
    int* t1=divide_arr(arr_24,6,1);int* t2=divide_arr(arr_24,6,2);int* t3=divide_arr(arr_24,6,3);int* t4=divide_arr(arr_24,6,4);

    //REVERSE ARRAYS
    reverse_array(t1,6);reverse_array(t2,6);reverse_array(t3,6);reverse_array(t4,6);

    int num=1;
    num=piece(t1,t2,t3,t4,4);

    if(num==1){
        stack_tabs(arr_24,t1,6,0);stack_tabs(arr_24,t2,6,6);stack_tabs(arr_24,t3,6,12);stack_tabs(arr_24,t4,6,18);
    }
    if(num==2){
        stack_tabs(arr_24,t2,6,0);stack_tabs(arr_24,t3,6,6);stack_tabs(arr_24,t4,6,12);stack_tabs(arr_24,t1,6,18);
    }
    if(num==3){
        stack_tabs(arr_24,t3,6,0);stack_tabs(arr_24,t4,6,6);stack_tabs(arr_24,t1,6,12);stack_tabs(arr_24,t2,6,18);
    }
    if(num==4){
        stack_tabs(arr_24,t4,6,0);stack_tabs(arr_24,t1,6,6);stack_tabs(arr_24,t2,6,12);stack_tabs(arr_24,t3,6,18);
    }

    cout<<endl;

    t1=divide_arr(arr_24,8,1);t2=divide_arr(arr_24,8,2);t3=divide_arr(arr_24,8,3);
    reverse_array(t1,8);reverse_array(t2,8);reverse_array(t3,8);

    num=piece(t1,t2,t3,t4,3);

    if(num==1){
        stack_tabs(arr_24,t1,8,0);stack_tabs(arr_24,t2,8,8);stack_tabs(arr_24,t3,8,16);
    }
    if(num==2){
        stack_tabs(arr_24,t2,8,0);stack_tabs(arr_24,t3,8,8);stack_tabs(arr_24,t1,8,16);
    }
    if(num==3){
        stack_tabs(arr_24,t3,8,0);stack_tabs(arr_24,t1,8,8);stack_tabs(arr_24,t2,8,16);
    }

    cout<<endl;

    t1=divide_arr(arr_24,12,1);t2=divide_arr(arr_24,12,2);
    reverse_array(t1,12);reverse_array(t2,12);

    num=piece(t1,t2,t3,t4,2);

    if(num==1){
        stack_tabs(arr_24,t1,12,0);stack_tabs(arr_24,t2,12,12);
    }
    if(num==2){
        stack_tabs(arr_24,t2,12,0);stack_tabs(arr_24,t1,12,12);
    }
    
    cout<<"Twoja liczba to: "<<arr_24[8]<<endl;
    return 0;
}