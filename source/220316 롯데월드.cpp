#include <stdio.h>
#include <time.h>
int main(){
	int choose,ticket,FrontNumber,BackNumber,orderCount,discount,prise,sum,final;
	const int  ALL_AFTER_ADULT_PRICE = 48000, ALL_AFTER_TEEN_PRICE = 42000,ALL_AFTER_CHILD_PRICE = 36000;//종합 4after가격 
	const int  PARK_AFTER_ADULT_PRICE = 45000,  PARK_AFTER_TEEN_PRICE = 40000, PARK_AFTER_CHILD_PRICE = 35000;//파크 4after가격
	const int  BABY_PRICE =15000, ALL_DAY_ADULT_PRICE = 59000, ALL_DAY_TEEN_PRICE = 52000, ALL_DAY_CHILD_PRICE = 47000;// 종합 1day가격
	const int  PARK_DAY_ADULT_PRICE = 56000,PARK_DAY_TEEN_PRICE = 50000, PARK_DAY_CHILD_PRICE = 46000;//파크 1day가격 
	int numberYear,birth,age,oldage,newage; 

	while (1){
	printf("선택해주세요.\n1. 종합이용권(롯데월드+민속박물관)  \n2. 파크이용권\n");
	scanf("%d",&choose);
	
	if (choose ==1 || choose ==2){
		break;
	}else{
	continue;
	}
}
	while (1){
	printf("권종을 선택하세요.\n1. 1DAY \n2. AFTER4(오후 4시 이후 입장)\n");
	scanf("%d",&ticket);
	
	if (ticket ==1 || ticket ==2){
		break;
	}else{
		continue;
	}
}
	while(1){
	printf("주민번호 앞자리 6자글자와 뒷자리 1자리를 입력하세요.\n 앞자리(6글자)\n");
	scanf("%d",&FrontNumber);
	
	if (FrontNumber>000001 && FrontNumber<999999){
		break;
	}else{
		continue;
	}
}
	while(1){
	printf("뒷자리(1글자)\n");
	scanf("%1d",&BackNumber);
	if (BackNumber==1 || BackNumber==2 || BackNumber==3||BackNumber==4){
		break;
	}else{
		continue;
	}
}	
	while(1){
	printf("몇개를 주문하시겠습니가?(최대 10개)\n");
	scanf("%d",&orderCount);
	if (orderCount>=1 && orderCount <11){
		break;
	}else{
		continue;
	}
}	
	while(1){
	printf("우대사항을 선택하세요.\n1. 없음(나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 다둥이 행복\n5. 임산부\n6. 휴가장병 \n");
	scanf("%d",&discount);
	if(discount==1 ||discount==2 ||discount==3 ||discount==4 ||discount==5 ||discount==6){
		break;
	}else{
		continue;
	}
	}
/*
		struct tm*t;
		time_t base = time(NULL);
		t = localtime(&base);
		printf("%d %d %d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
*/ //시간값 설정		
		
		numberYear =FrontNumber/10000; //생년 출력
		birth= FrontNumber-(numberYear * 10000); // 생일 출력
		
		 if (BackNumber == 1 || BackNumber == 2){ // 1900년생 || 2000년생 출력 
		 	oldage = numberYear + 1900;
		 } else if (BackNumber == 3 || BackNumber == 4){  //해결안됨  
		 	newage = numberYear + 2000;
		 }



		if( birth > 316 && oldage < 2000){  //만나이
			age= 2022 - oldage -1;
			}
			else if (birth <= 316 && oldage < 2000){
			age = 2022 - oldage;
			}
			
		 if (birth > 316 && newage >= 2000){
			age = 2022 - newage-1;
			}
			else if (birth <= 316 && newage >= 2000){
			age = 2022 - newage;
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
					}	else if ( age >19 && age <= 64){
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
					}	else if ( age >19 && age <= 64){
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
					}	else if ( age >19 && age <= 64){
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
					}	else if ( age >19 && age <= 64){
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

	sum = final * orderCount;
	printf(" 가격은 %d원 입니다.\n 감사합니다.",sum);

	
return 0 ;  
}


