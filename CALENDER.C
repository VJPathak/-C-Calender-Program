#include<stdio.h>
#include<conio.h>
#include<math.h>

int month_[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int weekday(int date, int impmonth, int year)
{
	   int dayWeek,count=1, yr, yd,dayno,i,j;

	   if( year % 4 == 0 )
	   {
	    month_[1]=29;
	   }
	   yr = year % 100;
	   yd = year / 100;
	 //  printf("\n The Date Given is : %d / %d / %d \n\n", date, impmonth, year);
	   dayWeek = 1.25 * yr + findm(impmonth, year) + date - 2 * (yd % 4);
	   dayWeek = dayWeek % 7;
	   switch (dayWeek)
	   {
	   case 0:  printf("\n   Day of Week of the Date is : Saturday");
		    dayno=6;
			break;
	   case 1:  printf("\n   Day of Week of the Date is : Sunday");
		    dayno=7;
			break;
	   case 2:  printf("\n   Day of Week of the Date is : Monday");
		    dayno=1;
			break;
	   case 3:  printf("\n   Day of Week of the Date is : Tuesday");
		    dayno=2;
			break;
	   case 4:  printf("\n   Day of Week of the Date is : Wednesday");
		    dayno=3;
			break;
	   case 5:  printf("\n   Day of Week of the Date is : Thursday");
		    dayno=4;
			break;
	   case 6:  printf("\n   Day of Week of the Date is : Friday");
		    dayno=5;
			break;
	   default:  printf("\n  The Given input data is wrong");
	   }

 printf("\n\n");
 printf("   MON  TUE  WED  THU  FRI  SAT");
 textcolor(RED);
 cprintf("  SUN");
 printf("\n\n");

 for(i=1;i<=6;i++)
 {
  for(j=1;j<=7;j++)
   {


    if(count<dayno)
     {
      printf("     ");
     }
    else
     {
     if(j==7)
     {
     textcolor(RED);
     cprintf("   %2d",count-(dayno-1));
     }
     else
     {
     printf("   %2d",count-(dayno-1));
     }
     }


     if(count==month_[impmonth-1]+dayno-1)
     {
     goto end;
     }
     else
     {
     count++;
     }


   }

    printf("\n");

 }

   end:
   printf(" ");

	   return 0;
	   }



    int findm(int months, int yearss)
    {
	   int findmonth, leapyr;
	   if ((yearss % 100 == 0) && (yearss % 400 != 0))
	   leapyr = 0;
	   else if (yearss % 4 == 0)
	   leapyr = 1;
	   else
	   leapyr = 0;
	   findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months))
+ (5 * months + months / 9) / 2;
	   findmonth = findmonth % 7;
	   return findmonth;
    }



void main()
 {

 int dat=1, impmonth, years;
 clrscr();

 printf("\n\n                           CALENDER APPLICATION\n\n");
 printf("................................................................................\n\n");
 printf("   Enter the year : ");
 scanf("%d", &years);
 printf("\n   Enter the month : ");
 scanf("%d", &impmonth);
 //printf("\n Enter the date : ");
 //scanf("%d", &dat);
 weekday(dat, impmonth, years);
 getch();

 }

