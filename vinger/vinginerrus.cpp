//---------------------------------------------------------------------------
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        FILE *out;
        int y,x;
        char c;
        out=fopen("vinginereng.txt","w+");
        c='�';
        for(y=0; y<32; y++)
        {
           c='�'+y;
           if(c>'�') c='�';
           fprintf(out,"%d",y);
           for(x=0; x<32; x++)
           {
             fprintf(out,"\t%c",c);
             c++;
             if(c>'�') c='�';
           }
           fprintf(out,"\n");
           
        }
        fclose(out);
        return 0;
}
//---------------------------------------------------------------------------
 