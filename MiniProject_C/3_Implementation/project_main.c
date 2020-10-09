#include <stdio.h>
#include <time.h>

/*check given year is leap year or not*/
int isLeapYear(int year, int mon)
{
    int flag = 0;
    if (year % 100 == 0)
    {
            if (year % 400 == 0)
            {
                    if (mon == 2)
                    {
                            flag = 1;
                    }
            }
    }
    else if (year % 4 == 0)
    {
            if (mon == 2)
            {
                    flag = 1;
            }
    }
    return (flag);
}


int main()
{

    int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;

    /* enter date of birth */
    printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&days,&month, &year);

    /*get current date.*/
    ts = time(NULL);
    ct = localtime(&ts);

    printf("Current Date: %d/%d/%d\n",
            ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

    days = DaysInMon[month - 1] - days + 1;

    /* leap year checking*/
    if (isLeapYear(year, month))
    {
            days = days + 1;
    }

    /* calculating age in no of days, years and months */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;

    /* checking for leap year feb - 29 days */
    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1)))
    {
            if (days >= (DaysInMon[ct->tm_mon] + 1))
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    }
    else if (days >= DaysInMon[ct->tm_mon])
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }

    if (month >= 12)
    {
            year = year + 1;
            month = month - 12;
    }

    /* print age */
    printf("\n## Hey you are  %d years %d months and %d days old. ##\n", year, month, days);
    /* print life period */
    printf("The Life Period based on the generated age is : ");
    if(year>=0 && year<=11)
    {
        printf("Childhood");
        if(year==0 && days<=42 && month<=1)
        {
           printf("(Newborn Child)");
        }
        else if(year==1 && days>42 && month>=1)
        {
            printf("(Suckling)");
        }
        else if(year>=1 && year<=3)
        {
            printf("(Early Childhood)");
        }
        else if(year>=4 && year<=7)
        {
            printf("(Pre-school Childhood)");
        }
        else
        {
            printf("(School Childhood)");
        }
    }
    else if(year>=12 && year<=20)
    {
        printf("Adolescence");
        if(year>=12 && year<=15)
        {
            printf("(Puberty)");
        }
        else
        {
            printf("(Adolescence)");
        }
    }
    else if(year>=21 && year<=60)
    {
        printf("Adulthood");
        if(year>=21 && year<=30)
        {
            printf("(Early Adulthood)");
        }
        else if(year>=31 && year<=45)
        {
            printf("(Middle Adulthood)");
        }
        else
        {
            printf("(Late Adulthood)");
        }
    }
    else
    {
        printf("Old Age");
        if(year>=61 && year<=75)
        {
            printf("(Early Old Age)");
        }
        else if(year>=76 && year<=90)
        {
            printf("(Middle Old Age)");
        }
        else
        {
            printf("(Late Old Age)");
        }
    }
    return 0;
}
