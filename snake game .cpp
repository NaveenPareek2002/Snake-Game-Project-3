#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width =40;
const int height =20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;
enum edirection {stop=0,p,q,up,down};
edirection dir;
void setup()
{
gameover = false;
dir =stop;
x=width/2;
y=height/2;
fruitx =rand()%width;
fruity =rand()%height;
score =0;

}
void draw()
{//Sleep(10);
system("cls");
for( int i=0;i<=width;i++)
    {cout<<"#";}
cout<<endl;
for(int i=0;i<=height;i++)
{
    for(int j=0;j<=width;j++)
     {
         if( j==0||j==width)
         {
             cout<<"#";
         }
         else if(j==fruitx && i==fruity)
        {
         cout<<"*";
        }

        else if(j==x && i==y)
        {
         cout<<"O";}


        else if(x>width)
        {
            x=0;
        }
        else if(y<0)
        {
            y=height;
        }
        else if(x<0)
        {
            x=width;
        }
        else if(y>height)
        {
            y=0;
        }
        else
        {bool print=false;
            for(int k=0;k<ntail;k++)
            {
                if(tailx[k]==j&&taily[k]==i)
                {
                cout<<"o";
                print=true;
                }
            }
         if(!print)
            cout<<" ";}
     }
    cout<<endl;
    }
for(int i=0;i<=width;i++)
    cout<<"#";
    cout<<endl;
}
void input()
{
    if (kbhit())
{switch( getch())

 {case's':
dir= up;
 break;
 case'a':
  dir = p;
 break;
  case'w':
 dir =down;
 break;
 case'd':
dir = q;
 break;
 case'x':
    gameover=true;
    break;
}}}
void logic()
{int px=tailx[0],py=taily[0],X,Y;

for(int i=ntail;i>0;i--)
{
   tailx[i]=tailx[i-1];
    taily[i]=taily[i-1];
}
tailx[0]=x;
taily[0]=y;
switch(dir)
{case up:
y++;
 break;
 case down:
 y--;
 break;
  case p:
 x--;
 break;
 case q:
x++;
 break;
 default:
    break;
}
for(int i=0;i<ntail;i++)
{
    if(tailx[i]==x&&taily[i]==y)
    {
        gameover=true;
    }
}
if(x==fruitx&&y==fruity)
{
    score+=10;
    fruitx =rand()%width;
fruity =rand()%height;
ntail++;
}
}
int main()
{
setup();
while (!gameover)
{ draw();
  if(dir==p||dir==q)
{
    Sleep(5);
}Sleep(100);
 if(dir==up||dir==down)
{
    Sleep(60);
}
  input();
  logic();
 cout<<"score= "<<score;
 // Sleep(50);
}
return 0;
}
