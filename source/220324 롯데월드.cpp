#include <stdio.h>
#include <time.h>
int choose,ticket,FrontNumber,BackNumber,orderCount,discount,prise,sum,final,next,all,totalTicketPrice,counter,ticketTimeCase,ageCase,again,todaytime;
	const int  ALL_AFTER_ADULT_PRICE = 48000, ALL_AFTER_TEEN_PRICE = 42000,ALL_AFTER_CHILD_PRICE = 36000;//종합 4after가격 
	const int  PARK_AFTER_ADULT_PRICE = 45000,  PARK_AFTER_TEEN_PRICE = 40000, PARK_AFTER_CHILD_PRICE = 35000;//파크 4after가격
	const int  BABY_PRICE =15000, ALL_DAY_ADULT_PRICE = 59000, ALL_DAY_TEEN_PRICE = 52000, ALL_DAY_CHILD_PRICE = 47000;// 종합 1day가격
	const int  PARK_DAY_ADULT_PRICE = 56000,PARK_DAY_TEEN_PRICE = 50000, PARK_DAY_CHILD_PRICE = 46000;//파크 1day가격 
	const int  OLDMAN_AGE=65, TEEN_AGE_MAX=18, TEEN_KID_AGE=13, KID_BABY_AGE=3, BABY_AGE_MIN=1;//나이 최댓값 
	int numberYear,birth,age,oldage,newage,birthMonth,birthDay,todayDate; 
	int ticketTimeCaseArr[10]={0}, ageArr[10]={0}, ticketPriceArr[10]={0}, discountArr[10]={0}, orderCountArr[10]={0};
	
	
	void selectTicket(){//권종 선택 
		do{
		printf("선택해주세요.\n1. 종합이용권(롯데월드+민속박물관)  \n2. 파크이용권\n");
		scanf("%d",&choose);
		}while(!(choose ==1 || choose ==2));
	
		do{
		printf("권종을 선택하세요.\n1. 1DAY \n2. AFTER4(오후 4시 이후 입장)\n");
		scanf("%d",&ticket);
		}while(!(ticket ==1 || ticket ==2));
		}
	void personNumber(){//주민번호 앞자리 6글자 +뒷자리 1글자 
		do{
		printf("주민번호 앞자리 6자글자와 뒷자리 1자리를 입력하세요.\n 앞자리(6글자)\n");
		scanf("%d",&FrontNumber);
		}while(!(FrontNumber>010001 && FrontNumber<999999));
	
		do{
		printf("뒷자리(1글자)\n");
		scanf("%d",&BackNumber);
		}while(!(BackNumber==1 || BackNumber==2 || BackNumber==3||BackNumber==4));
		}
	void countTicket(){	//주문갯수 
		do{
		printf("몇개를 주문하시겠습니가?(최대 10개)\n");
		scanf("%d",&orderCount);
		}while(!(orderCount>=1 && orderCount <11));
		}	
	void discountMoney(){	//우대사항
		do{
		printf("우대사항을 선택하세요.\n1. 없음(나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 다둥이 행복\n5. 임산부\n6. 휴가장병 \n");
		scanf("%d",&discount);
		}while(!(discount==1 ||discount==2 ||discount==3 ||discount==4 ||discount==5 ||discount==6));
	}	
	void monthAge(){ //만나이 계산 
			struct tm*t;
			time_t base = time(NULL);
			t = localtime(&base);
			numberYear =FrontNumber/10000; //생년 출력
			birthMonth= (FrontNumber-(numberYear * 10000))*100/10000; // 생월 출력
			birthDay= FrontNumber-(numberYear * 10000)-(birthMonth * 100); //생일 출력 
			
			 if (BackNumber == 1 || BackNumber == 2){ // 1900년생 || 2000년생 출력 
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
			}//age는 만나이
	}
	void chooseAgePrice(){ //티켓별 나이대 별 가격 
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
					printf("잘 못 입력하셨습니다. ");
		}
	}
	void discountCase(){//우대사항 별 할인 			
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
				final = prise-(prise*0.3); //종합만 할 인 
				} else if(choose == 2){
				final = prise;
				} //파크는 할인적용 제외 
				break;	
			case 5:
					if (choose == 1){
				final = prise*0.5; //종합만 할 인 
				} else if(choose == 2){
				final = prise;
				} //파크는 할인적용 제외 
				break;		
			case 6:
					if (choose == 1){
				final = (prise*0.50)+500; //종합만 할 인 
				} else if(choose == 2){
				final = prise;
				} //파크는 할인적용 제외 
				break;					
		}
	}
	void ageSelectCase(){ //나이, 권종별 케이스 정리 
			//나이 케이스 정립
			if ( age <KID_BABY_AGE && age >=BABY_AGE_MIN) { 
				ageCase=4; // 베이비 
			} else if ((age >= KID_BABY_AGE && age <TEEN_KID_AGE)) {
				ageCase = 3; // 어린이 
			} else if (age >= TEEN_KID_AGE && age <= TEEN_AGE_MAX) {
				ageCase = 2; //청소년 
			} else if ( age >= OLDMAN_AGE ) {
				ageCase = 5; //노 인  
			} else {
				ageCase = 1; // 어른 
			}
	
			
			//종합/파크&& 주간야간 선택 
			if (choose==1 && ticket==1) {
				ticketTimeCase = 1; //종합 + 1Day 
			} else if (choose==1 && ticket==2) { 
				ticketTimeCase =2; //종합 + 4시이후   
				ticketTimeCase = 3; //파크 + 1Day 
			} else {
				ticketTimeCase = 4; // 파크 + 4시후 
			} 
		
	}
	void receiptOutput(){	 //영수증 출력부 
			
}
	
int main(){
	while(1){
	int totalTicketPrice=0, counter=0;
	int ticketTimeCaseArr[10]={0}, ageArr[10]={0}, ticketPriceArr[10]={0}, discountArr[10]={0}, orderCountArr[10]={0};	
		do{//c변수 초기화
		 	selectTicket();
			personNumber();
			countTicket();
			discountMoney();
			monthAge();
			ageSelectCase();
			chooseAgePrice();
			discountCase();
			//총 합 가격 
			sum = final * orderCount;
		
			printf(" *****************************\n");
			printf(" 가격은 %d원 입니다.\n 감사합니다.\n",sum);
			printf(" *****************************\n");
			
			ticketTimeCaseArr[counter] = ticketTimeCase;
			ticketPriceArr[counter] = sum;
			discountArr[counter] = discount;
			orderCountArr[counter] = orderCount;
			ageArr[counter]=ageCase;
			totalTicketPrice += sum;
			
			//counter에 1 추가 , 초기값은 0 
			counter++;
			
			printf("계속 발권 하시겠습니까?\n 1. 티켓 발권 \n 2. 종료\n");
			scanf("%d",&next);
		}while (next ==1);
		
			printf("\n이용해주셔서 감사합니다.\n");
		
		// 영수증 출력
		printf("\n\n===================================== 롯데월드  =====================================\n") ;
		printf("%s\t\t%s\t     %s\t  %s\t\t%s\n","선택사항","연  령","매수","가격","우대사항");

		
		FILE *fp = fopen("report.csv","a");
		for (int i =0; i<counter; i++) {
			struct tm*t;
			time_t base = time(NULL);
			t = localtime(&base);
			int todayDate = (t->tm_year + 1900)*10000 +(t->tm_mon + 1)*100+(t->tm_mday);
			fprintf(fp,"%d, %d,%d,%d,%d,%d,\n",todayDate,ticketTimeCaseArr[i],ageArr[i],ticketPriceArr[i],discountArr[i],orderCountArr[i]);
			
			switch (ticketTimeCaseArr[i]) {
				case 1:
					printf("%s\t%s","종합이용권","1Day");
					break;
				case 2:
					printf("%s\t%s","종합이용권","After4");
					break;
				case 3:
					printf("%s\t%s","파크이용권","1Day");
					break;
				case 4:
					printf("%s\t%s","파크이용권","After4");
					break;
				default:
					break;
			}
			
			switch (ageArr[i]) {
				case 1:
					printf("\t%s","어  른");
					break;
				case 2:
					printf("\t%s","청소년");
					break;
				case 3:
					printf("\t%s","어린이");
					break;
				case 4:
					printf("\t%s","유  아");
					break;
				case 5:
					printf("\t%s","노  인");
					break;
				case 6:
					printf("\t%s","영  아");
					break;
				default:
					break;
			}
			
			printf("%10d%14d원\t",orderCountArr[i],ticketPriceArr[i]) ;
			
			switch (discountArr[i]) {
				case 1:
					printf("%s\n","우대사항 없음");
					break;
				case 2:
					printf("%s\n","장애인 우대");
					break;
				case 3:
					printf("%s\n","국가유공자 우대");
					break;
				case 4:
					printf("%s\n","다둥이 행복 우대");
					break;
				case 5:
					printf("%s\n","임산부 우대");
					break;
				case 6:
					printf("%s\n","휴가장병 우대");
					break;
				default:
					break;
			}
		}
	
			
			
			printf("\n입장료 총액은 %d원 입니다.", totalTicketPrice);
			printf("\n=====================================================================================\n") ;
			printf("\n계속 진행(1:새로운 주문, 2:프로그램 종료) : ");
			scanf("%d",&again);
		 
		 if(again ==1){
		 	continue;
		 }else if (again==2){
		 	break;
		 }
	}
		 
		return 0; 
	}
