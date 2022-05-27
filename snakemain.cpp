
#include <conio.h>
#pragma hdrstop

#pragma argsused
const int length     = 5;  
const int width      = 10; 
const int height     = 10; 
const int color      = 10;  

int main(int argc, char* argv[])
{
  int SnakePoint[length];  
  int SnakeNaprav[length];
  int key;                 
  for(int i=0; i<length;i++){
    SnakePoint[i]=i;       
    SnakeNaprav[i]=1;      
  }
  SnakeNaprav[length-1]=0;
  for(int i=0; i<height;i++)
    for(int j=0;j<width;j++)

  do {
    int x,y;
    clrscr();              
    for(int i=0; i<length;i++){
      x=SnakePoint[i]/10;
      y=SnakePoint[i]%10;
      gotoxy(x+1,y+1);
      textcolor(color);    
      cprintf("*");        
    }
    
    key=getch();

    switch(key){
    case 75:               
      SnakeNaprav[length-1]=-10; 
      break;
    case 77:             
      SnakeNaprav[length-1]=10; 
      break;
    case 72:              
      SnakeNaprav[length-1]=-1; 
      break;
    case 80:               
      SnakeNaprav[length-1]=1; 
      break;
    }
    int pol=1; 
    for(int i=length-1; i>=0;i--){
      for(int j=0; j<length; j++)             
        if((SnakePoint[i]+SnakeNaprav[i]==SnakePoint[j]+SnakeNaprav[j])&&
           (i!=j)) {pol=0;break;}
      x=(SnakePoint[i]+SnakeNaprav[i])/10+1;  
      y=(SnakePoint[i]+SnakeNaprav[i])%10+1;  
      if((x<=0)||(x>=width)||(y<=0)||(y>=height))
          pol=0;   
      if(pol==0) break;   
    }
    if(pol==1){
      //��������!
      for(int i=length-1; i>=0;i--)
        SnakePoint[i]+=SnakeNaprav[i];  
      for(int i=0; i<length-1;i++)
        SnakeNaprav[i]=SnakeNaprav[i+1]; 
    }

  }while(key!=27);         
  return 0;
}
//---------------------------------------------------------------------------

