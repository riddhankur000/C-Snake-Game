#include<iostream>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

void print_gameover(void);
void delay(float);
void gameover(void);
int playsnake(void);
void hidecursor(void);

int points=0;
char ch1=0,ch2;

int main(){
    int d;
    cout<<"Welcome To The Snake Game..."<<endl<<"Please Play This Game in Full Screen"<<endl<<"KEYBOARD CONTROLS :: "<<endl;
    cout<<"Move Right >> d"<<endl<<"Move Left >> a"<<endl<<"Move Up >> w"<<endl<<"Move Down >> s"<<endl;
    cout<<"Press Any Key To Start The Game"<<endl;
    getch();
    hidecursor();
    d=playsnake();
    if(d==0){
    delay(1);
    gameover();
    }

return 0;
}

int playsnake(void){
    int k=0;
    int x=rand()%120;
        if(x%2==1){
            x++;
        }
    int y=rand()%30;
    int dir=rand()%4;
    int ball[2]={(rand()%120),(rand()%30)};
    int length=0;
    int start[2]={x,y};
    int mid[2];
    int end[2];
    // int body[900][2];
    // body[0][0]=start[0];
    // body[0][1]=start[1];
    struct point{
        int x;
        int y;
        int direction;
    };
    struct point body[1800];
    body[0].x=start[0];
    body[0].y=start[1];
    body[0].direction=dir;

    // struct node{
    //     int xy[2];
    //     struct node* next;
    // };
    // struct node* head=NULL;
    // struct node* ptr=NULL;
    // ptr=(struct node*)malloc(sizeof(struct node));
    // ptr->next=NULL;
    // ptr->xy[0]=start[0];
    // ptr->xy[1]=start[1];
    // head->next=ptr;

    ch2=ch1;
    while(1){
        system("cls");
        hidecursor();
        if(ball[0]%2==1){
            ball[0]++;
        }
        // if(ball[1]%2==1){
        //     ball[1]++;
        // }
        if(dir==0){
            start[0]+=2;
            ch2='d';
            if(start[0]>120){
                start[0]-=120;
              
            }
        }
        if(dir==1){
            start[1]--;
            ch2='w';            
            if(start[1]<0){
                start[1]+=30;
                
            }
        }
        if(dir==2){
            start[0]-=2;
            ch2='a';
            if(start[0]<0){
                start[0]+=120;
                
            }
        }
        if(dir==3){
            start[1]++;
            ch2='s';            
            if(start[1]>30){
                start[1]-=30;
                
            }
        }

        for(int j=length;j>0;j--){
            body[j].x=body[j-1].x;
            body[j].y=body[j-1].y;
            // if(body[j].direction==0){
            // body[j].x+=2;
    
              
            // }
            // if(body[j].direction==1){
            // body[j].y--;
    
                
            // }
            // if(body[j].direction==2){
            // body[j].x-=2;
                
            // }
            // if(body[j].direction==3){
            // body[j].y++;
        
                
            // }
        }
    body[0].x=start[0];
    body[0].y=start[1];
    cout<<"TOTAL SCORE  =  "<<points<<endl;
    for(int j=0;j<=210;j++){
        cout<<'_';
    }
    int b;
    for(int i=0;i<=30;i++){
    for(int j=0;j<=120;j++){
        b=0;

        if((j==start[0]&&i==start[1])||(j==ball[0]&&i==ball[1])){
            cout<<"*";
            b=1;
        }
        if(b==0){
            for(int k=1;k<=length;k++){
            if((body[k].x==j)&&(body[k].y==i)){
                cout<<"*";
                b=1;
            }
        }
        }
        if(b==0)
        {
            cout<<" ";
        }
    }
    cout<<"|";
    cout<<endl;
    }

    for(int j=0;j<=120;j++){
        cout<<'_';
    }
    cout<<"|";
    if((start[0]==ball[0])&&(start[1]==ball[1])){
        ball[0]=rand()%120;
        ball[1]=rand()%30;
        points++;
        length++;
        
    }
    
    cout<<endl;
    if(kbhit()==1){
        // int a=0;
        ch1=getch();
        if(ch2=='a'||ch2=='d'){
        if(ch1=='w'){
            dir=1;
            ch2=ch1;
        }
        }
        if(ch2=='w'||ch2=='s'){
        if(ch1=='a'){
            dir=2;
            ch2=ch1;
        }
        }
        if(ch2=='a'||ch2=='d'){
        if(ch1=='s'){
            dir=3;
            ch2=ch1;
        }
        }
        if(ch2=='w'||ch2=='s'){
        if(ch1=='d'){
            dir=0;
            ch2=ch1;
        }
        }
    }
    // for(int j=length;j>0;j--){
    //     body[j].direction=body[j-1].direction;
    // }
    // body[0].direction=dir;
    int c=0;
    for(int k=1;k<=length;k++){
        if((body[k].x==start[0])&&(body[k].y==start[1])){
            c=1;
            break;
        }
    }
    if(c==1){
        return 0;
    }
    delay(0.002);
    // k++;
    }
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void print_gameover(void){
    cout<<"Your Final Score Is "<<points<<endl<<"Thanks For Playing...."<<endl;
    for(int i=0;i<=30;i++){
    for(int j=0;j<=60;j++){
        if(i==1){
            if((j>=5&&j<15)||(j>=20&&j<=30)||(j>=35&&j<=45)||(j>=50&&j<60))
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if((i>=2&&i<5)){
            if(j==5||j==20||j==30||j==35||j==40||j==45||j==50) 
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if(i==5){
            if(j==5||(j>7&&j<15)||(j>=20&&j<=30)||j==35||j==45||(j>=50&&j<=55)) 
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if(i>5&&i<10){
            if(j==5||j==10||j==14||j==20||j==30||j==35||j==45||j==50)
            cout<<"* ";
            else
            cout<<"  ";
            // continue;  
        }
        else if(i==10){
            if((j>=5&&j<=10)||j==14||j==20||j==30||j==35||j==45||(j>=50&&j<60))  
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        } 
        else if(i==15){
            if((j>=5&&j<15)||(j==20||j==30)||(j>=35&&j<=45)||(j>=50&&j<60))
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if((i>=16&&i<20)){
            if(j==5||j==14||j==20||j==30||(j==35)||j==50||j==59) 
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if(i==20){
            if(j==5||j==14||j==20||j==30||(j>=35&&j<=40)||(j>=50&&j<=59)) 
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        }
        else if(i>20&&i<25){
            if(j==5||j==14||j==i||j==(50-i)||j==35||j==50||j==(34+i))
            cout<<"* ";
            else
            cout<<"  ";
            // continue;  
        }
        else if(i==25){
            if((j>=5&&j<=14)||j==25||(j>=35&&j<=45)||j==50||j==59)  
            cout<<"* ";
            else
            cout<<"  ";
            // continue;
        } 
        else{
            cout<<"  ";
        }
        
        }
    cout<<"|";
    cout<<endl;
    }
    for(int j=0;j<=60;j++){
            cout<<"__";
        }
        cout<<"|"<<endl;
    cout<<"Press q Key To Exit...";
}

void delay( float seconds){
    clock_t ms=(seconds*1000) + clock();
    while(ms>clock()){}

}

void gameover(void){
        int i=0;
    while(1){
        system("cls");
        if(i%2==0){
            print_gameover();
        }
        else{
        cout<<"Your Final Score Is "<<points<<endl<<"Thanks For Playing...."<<endl;
            for(int i=0;i<=30;i++){
            for(int j=0;j<=60;j++){
                cout<<"  ";
        }
        cout<<"|";
        cout<<endl;
        }
        for(int j=0;j<=60;j++){
            cout<<"__";
        }
        cout<<"|"<<endl;
        cout<<"Press q Key To Exit...";
        }
        delay(0.4);
        i++;
        if(kbhit()==1){
            ch1=getch();
        }
        if(ch1=='q'){
            exit(1);
        }
    }
}