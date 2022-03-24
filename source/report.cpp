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

return 0;
}

