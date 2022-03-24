#include <stdio.h>
#include <string.h>
int main(){
//	char list[1024],*list1,*list2,*list3,*list4,*list5,*list6;
	FILE*fp =fopen("report.csv","r");
//	char *ptr = strtok(list,",");
	const int MAX=10000;
	int count = 0;
	int date[MAX],ticketTimeCaseArr[MAX],ageArr[MAX],ticketPriceArr[MAX],discountArr[MAX],orderCountArr[MAX];
/*	
	list1 = strtok(list,",");
	list2 = strtok(NULL,",");
	list3 = strtok(NULL,",");
	list4 = strtok(NULL,",");
	list5 = strtok(NULL,",");
	list6 = strtok(NULL,",");
*/	
	printf("==========================================report.csv================================================\n") ;
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","날짜","이용권 종류","연령대","결제 금액","우대 구분","발권 수량");


	while(fscanf(fp, "%10d\t,%10d\t,%10d\t,%10d\t,%10d\t,%10d",&date[count],&ticketTimeCaseArr[count],
												&ageArr[count],&ticketPriceArr[count],&discountArr[count],&orderCountArr[count]) != -1){
		count++;
	}

	fclose(fp);
	
	for(int i=0; i<count; i++){
	printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[i],ticketTimeCaseArr[i],ageArr[i],ticketPriceArr[i],discountArr[i],orderCountArr[i]);
	}
	
	printf("==========================================권종별 판매 현황===============================================\n") ;
	
	
	int countAllDay = 0 , countAllAfter=0, countParkDay=0, countParkAfter = 0, incomeAllDay = 0,incomeAllAfter = 0, incomeParkDay = 0, incomeParkAfter = 0;
	
	for (int i=0; i< count; i++){
		if ( ticketTimeCaseArr[i] == 1) {
			countAllDay += orderCountArr[i];
			incomeAllDay += ticketPriceArr[i];
		} else if ( ticketTimeCaseArr[i] == 2){
			countAllAfter += orderCountArr[i];
			incomeAllAfter += ticketPriceArr[i];
		}else if ( ticketTimeCaseArr[i] == 3){
			countParkDay += orderCountArr[i];
			incomeParkDay += ticketPriceArr[i];
		}else if ( ticketTimeCaseArr[i] == 4){
			countParkAfter += orderCountArr[i];
			incomeParkAfter += ticketPriceArr[i];
		}
	}
	printf("\n\t\t\t종합 이용권(1DAy): 총 %d매\t / 매출 %d원\n",countAllDay,incomeAllDay);
	printf("\n\t\t\t종합 이용권(AFTER4): 총 %d매\t / 매출 %d원\n",countAllAfter,incomeAllAfter);
	printf("\n\t\t\t파크 이용권(1DAy): 총 %d매\t / 매출 %d원\n",countParkDay,incomeParkDay);
	printf("\n\t\t\t파크 이용권(AFTER4): 총 %d매\t / 매출 %d원\n",countParkAfter,incomeParkAfter);
	
	

return 0;
}

