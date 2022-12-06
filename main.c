#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int terminate(char option[4]);
void sign_up();
void login_user();
void calculate_cost();
void payment();

char name[20],surname[20],address[20],username[20],password[6],credit_card_number[16];
int age,engine_cc,days, login_successful = 0 , pay_with_credit;
float ins_cost_18_22 = 0.00052 , ins_cost_23_30=0.00043 , ins_cost_over30 = 0.00028 , amount , total_amount , discount ;

int main(int argc, char *argv[]) {
	char option[4];
	
	
	do{
		float flag = 1 ;
		int sign_up_done = 0;
		
		system("cls");
		
		printf("\t\t\t\t***********************HOME SCREEN**********************\n");
		
		printf("Type 'root' if you are admin or type 'user' if you are a user or type '0' to end the program: ");
		
		gets(option);    //GETS THE INPUT FROM THE USER
		while(strcmp(option,"user")!=0 && strcmp(option,"root")!=0 && strcmp(option,"0")!=0){   //CHECKING IF THE INPUT IS CORRECT
			printf("\nWrong input.Please try again: ");
			gets(option);
		}
		
		
		while(strcmp(option,"user")==0 && flag==1){ //USER SCREEN AND FUNCTIONS------------------------
			
			int choice,end_of_login=0;
			
			system("cls");
			
			printf("\n\n\t\t\t\t***********************USER SCREEN**********************\n"); 
			
			printf("\n\t\t\t\t 1.SIGN UP\n\t\t\t\t 2.LOGIN\n\t\t\t\t 3.LOGOUT\n"); //PRINTING THE MENU
			
			printf("\n\nSelect one number of the option above:");
			scanf("%d",&choice);
		 	
		 	int ex_choice;
		 	
			if(sign_up_done == 0 && choice != 1){
				ex_choice = choice;
				choice = 4 ; 
			}
			while(choice != 1 && choice != 2 && choice != 3 ){  //CHECKING IF THE INPUT IS CORRECT
				
				if(sign_up_done==0 && ex_choice == 2){
					printf("You have to sign up first!");
				}
				else if(sign_up_done == 0 && ex_choice == 3){
					printf("You have to sign up before leaving");
				}
				printf("\nWrong input.Please try again: ");
				scanf("%d",&choice);
				
				if(sign_up_done == 0 && choice != 1){
				ex_choice = choice;
				choice = 4 ; 
				}
			}
			
			if(choice == 1){
				sign_up(sign_up);
				sign_up_done = 1;
				continue;
				
			}
			
			
			while(choice == 2 && end_of_login == 0){
				
				login_user();
				
				
				
				
				
				
			}
		}
		
		
		
	}while(terminate(option) == 0);  //CALLS THE FUNCTION 'TERMINATE' AND IF IT'S TRUE THEN EXITS THE LOOP AND ENDS PROGRAM
	
	return 0;
}

//START OF THE FUNCTION 'TERMINATE'--------------------------
int terminate(char option[4]){
	
	if (strcmp(option,"0") == 0){ 
		return 1;
	}
	else{
		return 0;
	}
}
//END OF THE FUNCTION 'TERMINATE'----------------------------


//START OF THE FUNCTION 'SING_UP'----------------------------
void sign_up(){
	
	system("cls");
	
	printf("\n\n\t\t\t\t***********************SIGN UP PAGE**********************\n");
	
	printf("\n---------Give us your Name: ");
	scanf("%s",name);
	
	printf("---------Give us your Surname: ");	
	scanf("%s",surname);
	
	printf("---------Give us your Username: ");	
	scanf("%s",username);
	
	printf("---------Give us your Address: ");
	scanf("%s",address);
	do{
	
		printf("---------Give us your Password: ");
		scanf("%s",password);
		if(strlen(password) > 6){
			printf("Password with more than 6 characters!Try again.\n");
			continue;
		}
		else{
			break;
		}
		
	}while(1);
	

}
//END OF THE FUNCTION 'SING_UP'------------------------------


//START OF THE FUNCTION 'LOGIN_USER'---------------------------
void login_user(){
	char choice_inside_login, givenUsername[20],givenPassword[6];
	int flag_a = 0 ;
	system("cls");
	
		
		printf("\n\n\t\t\t\t***********************LOGIN PAGE**********************\n");
		
		do{
			if(login_successful == 0){   //Checking if he has logged in before.
			
				printf("\nType your username: ");
				scanf("%s",givenUsername);
				printf("Type your password: ");
				scanf("%s",givenPassword);
				
				if(strcmp(givenUsername,username)!=0 || strcmp(givenPassword,password)!=0){
					printf("Wrong input.Try again\n");
					continue;
				}	
				else{
					
					login_successful = 1;
					printf("\nLogged in succesfully!");
					printf("\n\t\t\t\t\t\t------MENU------\n");
					printf("\n\t\t\t\t a.Calculate Cost\n\t\t\t\t b.Payment\n\t\t\t\t c.Receipt\n\t\t\t\t d.Exit\n\n");
					do{
						printf("What action do you select: ");
						scanf(" %c",&choice_inside_login);
						if(choice_inside_login != 'a' && choice_inside_login != 'b' &&choice_inside_login != 'c'){
							printf("\nWrong input!Try again:");
							continue;
						}
						else{
							
							if(choice_inside_login != 'a' && flag_a == 0 && choice_inside_login != 'd'){
								printf("flag_a = %d", flag_a);
								if(choice_inside_login == 'b' || choice_inside_login == 'c'){
									printf("\nYou have to Calculate the Cost before payment and receipt.Try again:");
									continue;
								}
							
							}
							break;
						}
						
					}while(1);
				}
				
			}
			else{     //If logged in previously does't ask for username and password.
				
				printf("\n\t\t\t\t\t\t------MENU------\n");
				printf("\n\t\t\t\t a.Calculate Cost\n\t\t\t\t b.Payment\n\t\t\t\t c.Receipt\n\t\t\t\t d.Exit\n\n");
					do{
						printf("What action do you select: ");
						scanf(" %c",&choice_inside_login);
						if(choice_inside_login != 'a' && choice_inside_login != 'b' &&choice_inside_login != 'c'){
							printf("\nWrong input!Try again:");
							continue;
						}
						else{
							
							if(choice_inside_login != 'a' && flag_a == 0 && choice_inside_login != 'd'){
								
								if(choice_inside_login == 'b' || choice_inside_login == 'c'){
									printf("\nYou have to Calculate the Cost before payment and receipt.Try again.");
									continue;
								}
							
							}
							break;
						}
						
					}while(1);
			}
		
		
			
			
			
			if(choice_inside_login == 'a'){	
					flag_a = 1;
					printf("in choice a flag_a = %d", flag_a);
					calculate_cost();
					
			}
			else if(choice_inside_login == 'b'){
				payment();
				
				
			}
				
		
			
		}while(1);	
		
		
}
//END OF THE FUNCTION 'LOGIN_USER'---------------------------


//START OF THE FUNCTION 'CALCULATE_COST'---------------------------
void calculate_cost(){
	
	system("cls");
	float rent_cost=0,ins_cost=0;
	
	printf("\n------------------Cost Calculation------------------\n");
	
	do{
		printf("\nHow many days do you want to rent the vehicle: ");
		scanf("%d",&days);
		printf("Give us your age:");
		scanf("%d",&age);
		printf("Give us the Engine CC:");
		scanf("%d",&engine_cc);
		
		if(age <18 || engine_cc <0 || days <0 ){
			printf("Wrong input.Try again.");
			printf("wrong");
			continue;
		}
		else{
			break;
		}
	}while(1);
	
	if(days<6){
		
		if(engine_cc < 1601){
			rent_cost = 11.42*days;
		}
		else if(engine_cc < 2001){
			rent_cost = 13.82*days;
		}
		else{
			rent_cost =16.22 * days; 
		}
	}
	else if(days<11){
			if (engine_cc < 1601){
			rent_cost = 10.22*days;
		}
		else if(engine_cc < 2001){
			rent_cost = 12.16*days;
		}
		else{
			rent_cost = 15.10*days; 
		}
	}
	else{
			if (engine_cc < 1601){
			rent_cost = 9.15 * days;
		}
		else if(engine_cc < 2001){
			rent_cost = 10.62 * days;
		}
		else{
			rent_cost = 13.80 * days; 
		}
	}
	
	if(age<23){
		ins_cost = ins_cost_18_22 * engine_cc;
	}
	else if( age <31){
		ins_cost = ins_cost_23_30 * engine_cc;
	}
	else{
		ins_cost = ins_cost_over30 * engine_cc;
	}
	
	amount = ins_cost + rent_cost;
	

	
}
//END OF THE FUNCTION 'CALCULATE_COST'---------------------------	


//START OF THE FUNCTION 'PAYMENT'---------------------------
void payment(){
	
	system("cls");
	int option;
	float total_confirm;
	
	printf("\n------------------Payment------------------\n");
	printf("Pay with: 1.Card\n\t  2.Cash");
	printf("\n\nWhat do you select: ");
	
	do{
		scanf("%d",&option);
		if(option != 1 && option!=2){
			printf("\nWrong input.Try again: ");
		}
		
	
	}while (option != 1 && option!=2);
	
	if (option == 1){
		discount = amount * 15/100;
		total_amount = amount - discount;
		pay_with_credit = 1;
		do{
			printf("\nGive the credit card number: ");
			scanf("%s",credit_card_number);
			if(strlen(credit_card_number) != 16){
				printf("\nMore than 16 digits.Try again.");
				continue;
			}
			break;
		}while(1);
		
		printf("Your total amount is: %f",total_amount);
		
		do{
		
			printf("\nPlease confirm by typing the total amount here:");
			scanf("%f",&total_confirm);
			
			if(total_confirm != total_amount){
				printf("Wrong input.Try again.");
				continue;
			}		
			break;
		}while(1);
		
	}
	else {
		discount = 0;
		total_amount = amount;
		pay_with_credit = 0;
		
		printf("Your total amount is: %f",total_amount);
		
		do{
		
			printf("\nPlease confirm by typing the total amount here:");
			scanf("%f",&total_confirm);
			
			if(total_confirm != total_amount){
				printf("Wrong input.Try again.");
				continue;
			}		
			break;
		}while(1);
		
		
	}
	
	
	
	
}
//END OF THE FUNCTION 'PAYMENT'---------------------------