#include <stdio.h>
#include <time.h>
int choose,ticket,FrontNumber,BackNumber,orderCount,discount,prise,sum,final,next,all,totalTicketPrice,counter,ticketTimeCase,ageCase,again,todaytime;
	const int  ALL_AFTER_ADULT_PRICE = 48000, ALL_AFTER_TEEN_PRICE = 42000,ALL_AFTER_CHILD_PRICE = 36000;//���� 4after���� 
	const int  PARK_AFTER_ADULT_PRICE = 45000,  PARK_AFTER_TEEN_PRICE = 40000, PARK_AFTER_CHILD_PRICE = 35000;//��ũ 4after����
	const int  BABY_PRICE =15000, ALL_DAY_ADULT_PRICE = 59000, ALL_DAY_TEEN_PRICE = 52000, ALL_DAY_CHILD_PRICE = 47000;// ���� 1day����
	const int  PARK_DAY_ADULT_PRICE = 56000,PARK_DAY_TEEN_PRICE = 50000, PARK_DAY_CHILD_PRICE = 46000;//��ũ 1day���� 
	const int  OLDMAN_AGE=65, TEEN_AGE_MAX=18, TEEN_KID_AGE=13, KID_BABY_AGE=3, BABY_AGE_MIN=1;//���� �ִ� 
	int numberYear,birth,age,oldage,newage,birthMonth,birthDay,todayDate; 
	int ticketTimeCaseArr[10]={0}, ageArr[10]={0}, ticketPriceArr[10]={0}, discountArr[10]={0}, orderCountArr[10]={0};
	
	
	void selectTicket(){//���� ���� 
		do{
		printf("�������ּ���.\n1. �����̿��(�Ե�����+�μӹڹ���)  \n2. ��ũ�̿��\n");
		scanf("%d",&choose);
		}while(!(choose ==1 || choose ==2));
	
		do{
		printf("������ �����ϼ���.\n1. 1DAY \n2. AFTER4(���� 4�� ���� ����)\n");
		scanf("%d",&ticket);
		}while(!(ticket ==1 || ticket ==2));
		}
	void personNumber(){//�ֹι�ȣ ���ڸ� 6���� +���ڸ� 1���� 
		do{
		printf("�ֹι�ȣ ���ڸ� 6�ڱ��ڿ� ���ڸ� 1�ڸ��� �Է��ϼ���.\n ���ڸ�(6����)\n");
		scanf("%d",&FrontNumber);
		}while(!(FrontNumber>010001 && FrontNumber<999999));
	
		do{
		printf("���ڸ�(1����)\n");
		scanf("%d",&BackNumber);
		}while(!(BackNumber==1 || BackNumber==2 || BackNumber==3||BackNumber==4));
		}
	void countTicket(){	//�ֹ����� 
		do{
		printf("��� �ֹ��Ͻðڽ��ϰ�?(�ִ� 10��)\n");
		scanf("%d",&orderCount);
		}while(!(orderCount>=1 && orderCount <11));
		}	
	void discountMoney(){	//������
		do{
		printf("�������� �����ϼ���.\n1. ����(���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ٵ��� �ູ\n5. �ӻ��\n6. �ް��庴 \n");
		scanf("%d",&discount);
		}while(!(discount==1 ||discount==2 ||discount==3 ||discount==4 ||discount==5 ||discount==6));
	}	
	void monthAge(){ //������ ��� 
			struct tm*t;
			time_t base = time(NULL);
			t = localtime(&base);
			numberYear =FrontNumber/10000; //���� ���
			birthMonth= (FrontNumber-(numberYear * 10000))*100/10000; // ���� ���
			birthDay= FrontNumber-(numberYear * 10000)-(birthMonth * 100); //���� ��� 
			
			 if (BackNumber == 1 || BackNumber == 2){ // 1900��� || 2000��� ��� 
			 	oldage = numberYear + 1900;
			 } else if (BackNumber == 3 || BackNumber == 4){  
			 	newage = numberYear + 2000;
			 }
	
			if (oldage < 2000){
				if(birthMonth <= t->tm_mon + 1 && birthDay <= t->tm_mday){
					age = (t->tm_year + 1900) - oldage;
				} else if(birthMonth > t->tm_mon + 1 ){
					age= (t->tm_year + 1900) - oldage -1;
				}else if(birthDay > t->tm_mday ){
					age= (t->tm_year + 1900) - oldage -1;
				}
			}
			if(newage >=2000){
				if(birthMonth <= t->tm_mon + 1 && birthDay <= t->tm_mday){
					age = (t->tm_year + 1900) - newage;
				} else if(birthMonth > t->tm_mon + 1 ){
					age= ((t->tm_year + 1900) - newage) -1;
				}else if(birthDay > t->tm_mday){
					age= ((t->tm_year + 1900) - newage)-1;
				}
			}//age�� ������
	}
	void chooseAgePrice(){ //Ƽ�Ϻ� ���̴� �� ���� 
			switch(choose){
				case 1 :
					switch(ticket){
					case 1:

					if ( age <=3 ){
						BABY_PRICE;
						}	else if ( age >3 && age <= 12){
						prise = ALL_DAY_CHILD_PRICE;
						}	else if ( age >12 && age <= 18){
						prise = ALL_DAY_TEEN_PRICE;
						}	else if ( age >=19 && age <= 64){
						prise = ALL_DAY_ADULT_PRICE;
						}	else if ( age >= 65){
						prise = ALL_DAY_CHILD_PRICE;
						}
						break;

					case 2:
					if ( age <=3 ){
						BABY_PRICE;
						}	else if ( age >3 && age <= 12){
						prise = ALL_AFTER_CHILD_PRICE;
						}	else if ( age >12 && age <= 18){
						prise = ALL_AFTER_TEEN_PRICE;
						}	else if ( age >=19 && age <= 64){
						prise = ALL_AFTER_ADULT_PRICE;
						}	else if ( age >= 65){
						prise = ALL_AFTER_CHILD_PRICE;
						}
						break;
					}
				break;
				case 2 :
					switch(ticket){
					case 1:
						if ( age <=3 ){
						BABY_PRICE;
						}	else if ( age >3 && age <= 12){
						prise = PARK_DAY_CHILD_PRICE;
						}	else if ( age >12 && age <= 18){
						prise = PARK_DAY_TEEN_PRICE;
						}	else if ( age >=19 && age <= 64){
						prise = PARK_DAY_ADULT_PRICE;
						}	else if ( age >= 65){
						prise = PARK_DAY_CHILD_PRICE;
						}
					break;
					case 2:
						if ( age <=3 ){
						prise = BABY_PRICE;
						}	else if ( age >3 && age <= 12){
						prise = PARK_AFTER_CHILD_PRICE;
						}	else if ( age >12 && age <= 18){
						prise = PARK_AFTER_TEEN_PRICE;
						}	else if ( age >=19 && age <= 64){
						prise = PARK_AFTER_ADULT_PRICE;
						}	else if ( age >= 65){
						prise = PARK_AFTER_CHILD_PRICE;
						}
					break;
					}
					break;
				default:
					printf("�� �� �Է��ϼ̽��ϴ�. ");
		}
	}
	void discountCase(){//������ �� ���� 			
		switch(discount){
			case 1:
				final = prise; 
				break;
			case 2:
				final = prise*0.5;
				break;
			case 3:
				final = prise*0.5;
				break;	
			case 4:
				if (choose == 1){
				final = prise-(prise*0.3); //���ո� �� �� 
				} else if(choose == 2){
				final = prise;
				} //��ũ�� �������� ���� 
				break;	
			case 5:
					if (choose == 1){
				final = prise*0.5; //���ո� �� �� 
				} else if(choose == 2){
				final = prise;
				} //��ũ�� �������� ���� 
				break;		
			case 6:
					if (choose == 1){
				final = (prise*0.50)+500; //���ո� �� �� 
				} else if(choose == 2){
				final = prise;
				} //��ũ�� �������� ���� 
				break;					
		}
	}
	void ageSelectCase(){ //����, ������ ���̽� ���� 
			//���� ���̽� ����
			if ( age <KID_BABY_AGE && age >=BABY_AGE_MIN) { 
				ageCase=4; // ���̺� 
			} else if ((age >= KID_BABY_AGE && age <TEEN_KID_AGE)) {
				ageCase = 3; // ��� 
			} else if (age >= TEEN_KID_AGE && age <= TEEN_AGE_MAX) {
				ageCase = 2; //û�ҳ� 
			} else if ( age >= OLDMAN_AGE ) {
				ageCase = 5; //�� ��  
			} else {
				ageCase = 1; // � 
			}
	
			
			//����/��ũ&& �ְ��߰� ���� 
			if (choose==1 && ticket==1) {
				ticketTimeCase = 1; //���� + 1Day 
			} else if (choose==1 && ticket==2) { 
				ticketTimeCase =2; //���� + 4������   
				ticketTimeCase = 3; //��ũ + 1Day 
			} else {
				ticketTimeCase = 4; // ��ũ + 4���� 
			} 
		
	}
	void receiptOutput(){	 //������ ��º� 
			
}
	
int main(){
	while(1){
	int totalTicketPrice=0, counter=0;
	int ticketTimeCaseArr[10]={0}, ageArr[10]={0}, ticketPriceArr[10]={0}, discountArr[10]={0}, orderCountArr[10]={0};	
		do{//c���� �ʱ�ȭ
		 	selectTicket();
			personNumber();
			countTicket();
			discountMoney();
			monthAge();
			ageSelectCase();
			chooseAgePrice();
			discountCase();
			//�� �� ���� 
			sum = final * orderCount;
		
			printf(" *****************************\n");
			printf(" ������ %d�� �Դϴ�.\n �����մϴ�.\n",sum);
			printf(" *****************************\n");
			
			ticketTimeCaseArr[counter] = ticketTimeCase;
			ticketPriceArr[counter] = sum;
			discountArr[counter] = discount;
			orderCountArr[counter] = orderCount;
			ageArr[counter]=ageCase;
			totalTicketPrice += sum;
			
			//counter�� 1 �߰� , �ʱⰪ�� 0 
			counter++;
			
			printf("��� �߱� �Ͻðڽ��ϱ�?\n 1. Ƽ�� �߱� \n 2. ����\n");
			scanf("%d",&next);
		}while (next ==1);
		
			printf("\n�̿����ּż� �����մϴ�.\n");
		
		// ������ ���
		printf("\n\n===================================== �Ե�����  =====================================\n") ;
		printf("%s\t\t%s\t     %s\t  %s\t\t%s\n","���û���","��  ��","�ż�","����","������");

		
		FILE *fp = fopen("report.csv","a");
		for (int i =0; i<counter; i++) {
			struct tm*t;
			time_t base = time(NULL);
			t = localtime(&base);
			int todayDate = (t->tm_year + 1900)*10000 +(t->tm_mon + 1)*100+(t->tm_mday);
			fprintf(fp,"%d, %d,%d,%d,%d,%d,\n",todayDate,ticketTimeCaseArr[i],ageArr[i],ticketPriceArr[i],discountArr[i],orderCountArr[i]);
			
			switch (ticketTimeCaseArr[i]) {
				case 1:
					printf("%s\t%s","�����̿��","1Day");
					break;
				case 2:
					printf("%s\t%s","�����̿��","After4");
					break;
				case 3:
					printf("%s\t%s","��ũ�̿��","1Day");
					break;
				case 4:
					printf("%s\t%s","��ũ�̿��","After4");
					break;
				default:
					break;
			}
			
			switch (ageArr[i]) {
				case 1:
					printf("\t%s","��  ��");
					break;
				case 2:
					printf("\t%s","û�ҳ�");
					break;
				case 3:
					printf("\t%s","���");
					break;
				case 4:
					printf("\t%s","��  ��");
					break;
				case 5:
					printf("\t%s","��  ��");
					break;
				case 6:
					printf("\t%s","��  ��");
					break;
				default:
					break;
			}
			
			printf("%10d%14d��\t",orderCountArr[i],ticketPriceArr[i]) ;
			
			switch (discountArr[i]) {
				case 1:
					printf("%s\n","������ ����");
					break;
				case 2:
					printf("%s\n","����� ���");
					break;
				case 3:
					printf("%s\n","���������� ���");
					break;
				case 4:
					printf("%s\n","�ٵ��� �ູ ���");
					break;
				case 5:
					printf("%s\n","�ӻ�� ���");
					break;
				case 6:
					printf("%s\n","�ް��庴 ���");
					break;
				default:
					break;
			}
		}
	
			
			
			printf("\n����� �Ѿ��� %d�� �Դϴ�.", totalTicketPrice);
			printf("\n=====================================================================================\n") ;
			printf("\n��� ����(1:���ο� �ֹ�, 2:���α׷� ����) : ");
			scanf("%d",&again);
		 
		 if(again ==1){
		 	continue;
		 }else if (again==2){
		 	break;
		 }
	}
		 
		return 0; 
	}
