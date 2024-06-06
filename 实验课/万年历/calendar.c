#include<stdio.h>
int judgemonth(int month,int year);
void output(int week,int month,int day,int century,int yearofcen,int year);//声明
//主函数，输入年份，输出日历
int main(){
        int year;
        int month;
        int day;
        int week;
        int century;
        int yearofcen;

        printf("please enter the year:\n");
        scanf("%d",&year);

        for(month=1;month<=12; month++){
                output(week,month,day,century,yearofcen,year);
                printf("\n");
        }
return 0;
}
// 输出日历函数
void output(int week,int month,int day,int century,int yearofcen,int year){
         // 处理1月和2月的情况，因为它们在算法中属于上一年
        if (month == 1 || month == 2) {
                month += 12;
                year--;
                century = year/100;
                yearofcen = year%100;
                printf("MONTH %d\nSUN MON WED TUE THU FRI SAT \n",month-12);
                week=(yearofcen + yearofcen/4 + century/4 - 2*century + 26*(month+1)/10) %7;
                if(week <0) week+= 7;
                else if(week >7) week= 7;
                for(int i = 0; i < week;i++){
                        printf("    ");
                }
                year++;
                month -= 12;
        }
        // 其他月份直接输出
        else{
                printf("MONTH %d\nSUN MON WED TUE THU FRI SAT \n",month);
                century = year/100;
                yearofcen = year%100;
                week=(yearofcen + yearofcen/4 + century/4 - 2*century + 26*(month+1)/10) %7;
                if(week <0) week+= 7;
                else if(week >7) week= 7;
                for(int i = 0; i < week;i++){
                        printf("    ");
                }
        }

        for(day = 1; day <= judgemonth(month,year);day++){
                printf("%3d ",day);
                if(++week >6){
                        printf("\n");
                        week=0;
                }
        }
}
//判断二月是否为闰月以及其他月是大月还是小月
int judgemonth(int month,int year){
        int daymax;
        if(((year%4 == 0 && year%100 != 0) || (year%400 ==  0)) && (month == 2)) daymax = 29;
        else if( month == 2) daymax = 28;
        else if((month%2 == 0 && month <= 7) || (month%2 != 0 && month >= 8)){
                daymax = 30;
        }
        else{
                daymax = 31;
        }
        return daymax;
}

