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
        c='A';
        for(y=0; y<26; y++)
        {
           c='A'+y;
           if(c>'Z') c='A';
           fprintf(out,"%d",y);
           for(x=0; x<26; x++)
           {
             fprintf(out,"\t%c",c);
             c++;
             if(c>'Z') c='A';
           }
           fprintf(out,"\n");
           
        }
        fclose(out);
        return 0;
}
//---------------------------------------------------------------------------
 