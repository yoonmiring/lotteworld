#include <stdio.h>

int main(){
	FILE*fp =fopen("report.csv","r");
	const int MAX=10000;
	int count = 0;
	int date_Y[MAX],date_M[MAX],date_D[MAX],ticketTimeCaseArr[MAX],ageArr[MAX],ticketPriceArr[MAX],discountArr[MAX],orderCountArr[MAX];
	
	
	while(fscanf(fp, "%d %d %d ,%d,%d,%d,%d,%d",&date_Y[count],&date_M[count],&date_D[count],&ticketTimeCaseArr[count],&ageArr[count],&ticketPriceArr[count],&discountArr[count],&orderCountArr[count]) != -1){
		count++;
	}
	fclose(fp);
	
	for(int i=0; i<count; i++){
	printf("%d %d %d,%d,%d,%d,%d,%d\n",date_Y[i],date_M[i],date_D[i],ticketTimeCaseArr[i],ageArr[i],ticketPriceArr[i],discountArr[i],orderCountArr[i]);
	}

return 0;
}

