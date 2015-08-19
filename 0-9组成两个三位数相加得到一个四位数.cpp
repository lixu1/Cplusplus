#include "stdio.h"
int main()
{
    int a[10];
    for(a[0]=0;a[0]<10;a[0]++)
    {
        for(a[1]=0;a[1]<10;a[1]++)
        {
            if(a[1]==a[0]) continue;
            for(a[2]=0;a[2]<10;a[2]++)
            {
                if(a[2]==a[0])continue;
                if(a[2]==a[1])continue;
                for(a[3]=0;a[3]<10;a[3]++)
                {
                    if(a[3]==a[0])continue;
                    if(a[3]==a[1])continue;
                    if(a[3]==a[2])continue;
                    for(a[4]=0;a[4]<10;a[4]++)
                    {
                        if(a[4]==a[0])continue;
                        if(a[4]==a[1])continue;
                        if(a[4]==a[2])continue;
                        if(a[4]==a[3])continue;
                        for(a[5]=0;a[5]<10;a[5]++)
                        {
                            if(a[5]==a[0])continue;
                            if(a[5]==a[1])continue;
                            if(a[5]==a[2])continue;
                            if(a[5]==a[3])continue;
                            if(a[5]==a[4])continue;
                            for(a[6]=0;a[6]<10;a[6]++)
                            {
                                if(a[6]==a[0])continue;
                                if(a[6]==a[1])continue;
                                if(a[6]==a[2])continue;
                                if(a[6]==a[3])continue;
                                if(a[6]==a[4])continue;
                                if(a[6]==a[5])continue;
                                for(a[7]=0;a[7]<10;a[7]++)
                                {
                                    if(a[7]==a[0])continue;
                                    if(a[7]==a[1])continue;
                                    if(a[7]==a[2])continue;
                                    if(a[7]==a[3])continue;
                                    if(a[7]==a[4])continue;
                                    if(a[7]==a[5])continue;
                                    if(a[7]==a[6]) continue;
                                    for(a[8]=0;a[8]<10;a[8]++)
                                    {
                                        if(a[8]==a[0])continue;
                                        if(a[8]==a[1])continue;
                                        if(a[8]==a[2])continue;
                                        if(a[8]==a[3])continue;
                                        if(a[8]==a[4])continue;
                                        if(a[8]==a[5])continue;
                                        if(a[8]==a[6])continue;
                                        if(a[8]==a[7])continue;
                                        for(a[9]=0;a[9]<10;a[9]++)
                                        {
                                            if(a[9]==a[0])continue;
                                            if(a[9]==a[1])continue;
                                            if(a[9]==a[2])continue;
                                            if(a[9]==a[3])continue;
                                            if(a[9]==a[4])continue;
                                            if(a[9]==a[5])continue;
                                            if(a[9]==a[6])continue;
                                            if(a[9]==a[7])continue;
                                            if(a[9]==a[8])continue;
                                            if((a[0]*100+a[1]*10+a[2]+a[3]*100+a[4]*10
                                               +a[5])==(a[6]*1000+a[7]*100+a[8]*10+a[9])&&a[6]!=0)
                                               {
                                                   for(int i=0;i<3;i++)
                                                   printf("%d",a[i]);
                                                   printf(" + ");
                                                   for(int i=3;i<6;i++)
                                                   printf("%d",a[i]);
                                                   printf(" = ");
                                                   for(int i=6;i<10;i++)
                                                   printf("%d",a[i]);
                                                   printf("\n");
                                               }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
