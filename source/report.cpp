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
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","��¥","�̿�� ����","���ɴ�","���� �ݾ�","��� ����","�߱� ����");


	while(fscanf(fp, "%10d\t,%10d\t,%10d\t,%10d\t,%10d\t,%10d",&date[count],&ticketTimeCaseArr[count],
												&ageArr[count],&ticketPriceArr[count],&discountArr[count],&orderCountArr[count]) != -1){
		count++;
	}

	fclose(fp);
	
	for(int i=0; i<count; i++){
	printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[i],ticketTimeCaseArr[i],ageArr[i],ticketPriceArr[i],discountArr[i],orderCountArr[i]);
	}
	
	printf("==========================================������ �Ǹ� ��Ȳ===============================================\n") ;
	
	
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
	printf("\n\t\t\t���� �̿��(1DAy): �� %d��\t / ���� %d��\n",countAllDay,incomeAllDay);
	printf("\n\t\t\t���� �̿��(AFTER4): �� %d��\t / ���� %d��\n",countAllAfter,incomeAllAfter);
	printf("\n\t\t\t��ũ �̿��(1DAy): �� %d��\t / ���� %d��\n",countParkDay,incomeParkDay);
	printf("\n\t\t\t��ũ �̿��(AFTER4): �� %d��\t / ���� %d��\n",countParkAfter,incomeParkAfter);
	
	printf("\n==========================================�����׺�  �Ǹ� ��Ȳ===============================================\n") ;
	
	
	int countNo = 0, countDis = 0 ,countHonor = 0, countBaby = 0, countMore = 0, countArmy = 0;
	int incomeNo = 0, incomeDis = 0 ,incomeHonor = 0, incomeBaby = 0, incomeMore = 0, incomeArmy = 0;
	
	for (int i=0; i< count; i++){
		if ( discountArr[i] == 1) {
			countNo += orderCountArr[i];
			incomeNo += ticketPriceArr[i];		 
		} 
		else if ( discountArr[i] == 2) {
			countDis += orderCountArr[i];	
			incomeDis += ticketPriceArr[i];		 
		} 
		else if ( discountArr[i] == 3) {
			countHonor += orderCountArr[i];
			incomeHonor += ticketPriceArr[i];	
		}
		else if ( discountArr[i] == 4) {
			countBaby += orderCountArr[i];	
			incomeBaby += ticketPriceArr[i];		 
		} 
		else if ( discountArr[i] == 5) {
			countMore += orderCountArr[i];
			incomeMore += ticketPriceArr[i];			 
		}
		else if ( discountArr[i] == 6) {
			countArmy += orderCountArr[i];	
			incomeArmy += ticketPriceArr[i];		 
		} 
	}
	printf("\n\t\t\t������ ���� : �� %d��\t\t / ���� %d��\n",countNo,incomeNo);
	printf("\n\t\t\t����� ������ : �� %d��\t / ���� %d��\n",countDis,incomeDis);
	printf("\n\t\t\t���������� ������: �� %d��\t / ���� %d��\n",countHonor,incomeHonor);
	printf("\n\t\t\t�ӻ�� ������: �� %d��\t / ���� %d��\n",countBaby,incomeBaby);
	printf("\n\t\t\t�ٵ��� ������: �� %d��\t / ���� %d��\n",countMore,incomeMore);
	printf("\n\t\t\t�ް��庴  ������: �� %d��\t / ���� %d��\n",countArmy,incomeArmy);

	
	
	

return 0;
}

