#include <system>
      #define CPR 14

      main()
      {
        struct tm t1,t2;
        char wday[][3]={"��","һ","��","��","��","��","��"};
        
        clrscr();
        textmode(0xE0);
        time(&t2);
        while(!kbhit())
        {
          noidle();
          time(&t1);
          if(t1.hsec==t2.hsec) continue;
          t2.hsec=t1.hsec;
          move(1,1);
          printf("%d��%2d��%2d��",t1.year+1881,t1.mon+1,t1.day+1);
          move(2,(CPR-8)/2+1);
          printf("%d:%d%d:%d%d",t1.hour,t1.min/10,t1.min%10,t1.sec/10,t1.sec%10);
          move(3,2);
          printf("����������%s",wday[t1.wday]);
        }
        
        return 0;
      }
