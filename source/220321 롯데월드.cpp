#include <stdio.h>
#include <time.h>
int main(){
	int choose,ticket,FrontNumber,BackNumber,orderCount,discount,prise,sum,final;
	const int  ALL_AFTER_ADULT_PRICE = 48000, ALL_AFTER_TEEN_PRICE = 42000,ALL_AFTER_CHILD_PRICE = 36000;//���� 4after���� 
	const int  PARK_AFTER_ADULT_PRICE = 45000,  PARK_AFTER_TEEN_PRICE = 40000, PARK_AFTER_CHILD_PRICE = 35000;//��ũ 4after����
	const int  BABY_PRICE =15000, ALL_DAY_ADULT_PRICE = 59000, ALL_DAY_TEEN_PRICE = 52000, ALL_DAY_CHILD_PRICE = 47000;// ���� 1day����
	const int  PARK_DAY_ADULT_PRICE = 56000,PARK_DAY_TEEN_PRICE = 50000, PARK_DAY_CHILD_PRICE = 46000;//��ũ 1day���� 
	int numberYear,birth,age,oldage,newage,birthMonth,birthDay; 

	do{
	printf("�������ּ���.\n1. �����̿��(�Ե�����+�μӹڹ���)  \n2. ��ũ�̿��\n");
	scanf("%d",&choose);
	}while(!(choose ==1 || choose ==2));
	
	do{
	printf("������ �����ϼ���.\n1. 1DAY \n2. AFTER4(���� 4�� ���� ����)\n");
	scanf("%d",&ticket);
	}while(!(ticket ==1 || ticket ==2));
	
	do{
	printf("�ֹι�ȣ ���ڸ� 6�ڱ��ڿ� ���ڸ� 1�ڸ��� �Է��ϼ���.\n ���ڸ�(6����)\n");
	scanf("%d",&FrontNumber);
	}while(!(FrontNumber>000001 && FrontNumber<999999));
	
	do{
	printf("���ڸ�(1����)\n");
	scanf("%d",&BackNumber);
	}while(!(BackNumber==1 || BackNumber==2 || BackNumber==3||BackNumber==4));
	
	do{
	printf("��� �ֹ��Ͻðڽ��ϰ�?(�ִ� 10��)\n");
	scanf("%d",&orderCount);
	}while(!(orderCount>=1 && orderCount <11));
	
	do{
	printf("�������� �����ϼ���.\n1. ����(���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ٵ��� �ູ\n5. �ӻ��\n6. �ް��庴 \n");
	scanf("%d",&discount);
	}while(!(discount==1 ||discount==2 ||discount==3 ||discount==4 ||discount==5 ||discount==6));
	


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
		}

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

	sum = final * orderCount;
	printf(" *****************************\n");
	printf(" ������ %d�� �Դϴ�.\n �����մϴ�.\n",sum);
	printf(" *****************************\n");
	
return 0 ;  
}


