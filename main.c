#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//FUNCTIONS-------------------
int terminate(char option[4]);
void sign_up();
void login_user();
void calculate_cost();
void payment();
void get_receipt();
int exit_user(char choice_inside_login);
int logout(int choice,int admin_or_user);
void login_root();
int exit_root(int choice);
void change_cost();
//---------------------------

//VARIABLES------------------
char name[20],surname[20],address[20],username[20],password[6],c_c_number[16];
int age,engine_cc,days, login_successful = 0 , pay_with_credit;
float ins_cost_18_22 = 0.00052 , ins_cost_23_30=0.00043 , ins_cost_over30 = 0.00028 , selected_cost, amount , total_amount , discount ;
//---------------------------


int main(int argc, char *argv[]) {
	char option[4];
	int admin_or_user;
	
	do{
		
		int sign_up_done = 0;
		int choice_user,choice_admin;
		system("cls");
		
		printf("\t\t\t\t***********************HOME SCREEN**********************\n");
		
		printf("\nType 'root' if you are admin or type 'user' if you are a user or type '0' to end the program: ");
		
		scanf("%s",option);    //GETS THE INPUT FROM THE USER
		while(strcmp(option,"user")!=0 && strcmp(option,"root")!=0 && strcmp(option,"0")!=0){   //CHECKING IF THE INPUT IS CORRECT
			printf("\nWrong input.Please try again: ");
			gets(option);
		}
		
		if(strcmp(option,"user")==0){
			admin_or_user = 2;
			do{ //USER SCREEN AND FUNCTIONS------------------------
				
				int end_of_login=0;
				
				system("cls");
				
				printf("\n\n\t\t\t\t***********************USER SCREEN**********************\n"); 
				
				printf("\n\t\t\t\t 1.SIGN UP\n\t\t\t\t 2.LOGIN\n\t\t\t\t 3.LOGOUT\n"); //PRINTING THE MENU
				
				printf("\n\nSelect one number of the option above:");
				scanf("%d",&choice_user);
			 	
			 	int ex_choice;
			 	
				if(sign_up_done == 0 && choice_user != 1){
					ex_choice = choice_user;
					choice_user = 4 ; 
				}
				while(choice_user != 1 && choice_user != 2 && choice_user != 3 ){  //CHECKING IF THE INPUT IS CORRECT
					
					if(sign_up_done==0 && ex_choice == 2){
						printf("You have to sign up first!");
					}
					else if(sign_up_done == 0 && ex_choice == 3){
						printf("You have to sign up before leaving");
					}
					printf("\nWrong input.Please try again: ");
					scanf("%d",&choice_user);
					
					if(sign_up_done == 0 && choice_user != 1){
					ex_choice = choice_user;
					choice_user = 4 ; 
					}
				}
				
				if(choice_user == 1){
					sign_up(sign_up);
					sign_up_done = 1;
					login_successful = 0;
					continue;
					
				}
				
				
				if(choice_user == 2){
					
					login_user();
					continue;
				}
				
				
			}while(logout(choice_user,admin_or_user)); //Using the function logout to check if the user want to log out to the main screen.
			
		}//End of the USER SCREEN.
		
	else if(strcmp(option,"root")==0){ //Start of the ADMIN SCREEN.
		admin_or_user = 1;
		do{
			system("cls");
				
			printf("\n\n\t\t\t\t***********************ADMIN SCREEN**********************\n");
			printf("\n\t\t\t\t 1.LOGIN\n\t\t\t\t 2.LOGOUT\n"); //PRINTING THE MENU
			
			printf("\n\nSelect one number of the option above:");
			scanf("%d",&choice_admin);
				
			if(choice_admin != 1 && choice_admin != 2){
				printf("Wrong input.Try again.\n");
				continue;
			}
			if(choice_admin == 1){
				
				login_root();
					
			}
			
		}while(logout(choice_admin,admin_or_user));
		
		
	}//End of the ADMIN SCREEN.
	
	
		
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
	int flag_a = 0 ,flag_b = 0;
	
	system("cls");
	
		
		
		
		do{
			
			if(login_successful == 0){   //Checking if he has logged in before.
				printf("\n\n\t\t\t\t***********************USER LOGIN PAGE**********************\n");
				do{
				
					printf("\nType your username: ");
					scanf("%s",givenUsername);
					printf("Type your password: ");
					scanf("%s",givenPassword);
					if (strcmp(givenUsername,username)!=0 || strcmp(givenPassword,password)!=0){
						printf("Wrong password or username.Try again.\n");
						continue;
					}
					break;
				}while(1);
				
				
				login_successful = 1;  //flag that shows the user has logged in once.
				printf("\nLogged in succesfully!");
				printf("\n\t\t\t\t\t\t------MENU------\n");
				printf("\n\t\t\t\t a.Calculate Cost\n\t\t\t\t b.Payment\n\t\t\t\t c.Receipt\n\t\t\t\t d.Exit\n\n");
				
				do{
					printf("What action do you select: ");
					scanf(" %c",&choice_inside_login);
					if(choice_inside_login != 'a' && choice_inside_login != 'b' &&choice_inside_login != 'c' && choice_inside_login != 'd'){
						printf("\nWrong input!Try again.");
						continue;
					}
					else{
						
						if(choice_inside_login != 'a' && flag_a == 0 && choice_inside_login != 'd'){    //Checking if user calculated the cost before paying or receiving the receipt.
							
							if(choice_inside_login == 'b' || choice_inside_login == 'c'){
								printf("\nYou have to Calculate the Cost before payment and receipt.Try again.");
								continue;
							}
						
						}
						else if(choice_inside_login != 'b' && flag_b == 0 && choice_inside_login != 'd'){    //Checking if user paid before receiving the receipt.
							if(choice_inside_login == 'c'){
								printf("You have to pay before receiving the receipt.Try again.");
								continue;
							}
						}
						break;
					}
						
				}while(1);
				
				
			}
			else{     //If logged in previously does't ask for username and password.
				printf("\n\n\t\t\t\t***********************LOGIN PAGE**********************\n");
				printf("\n\t\t\t\t\t\t------MENU------\n");
				printf("\n\t\t\t\t a.Calculate Cost\n\t\t\t\t b.Payment\n\t\t\t\t c.Receipt\n\t\t\t\t d.Exit\n\n");
					do{
						printf("What action do you select: ");
						scanf(" %c",&choice_inside_login);
						if(choice_inside_login != 'a' && choice_inside_login != 'b' && choice_inside_login != 'c' && choice_inside_login != 'd'){
							printf("\nWrong input!Try again:");
							continue;
						}
						else{
							
							if(choice_inside_login != 'a' && flag_a == 0 && choice_inside_login != 'd'){    //Checking if user calculated the cost before paying or receiving the receipt.
								
								if(choice_inside_login == 'b' || choice_inside_login == 'c'){
									printf("\nYou have to Calculate the Cost before payment or receipt.Try again.");
									continue;
								}
							
							}
							else if(choice_inside_login != 'b' && flag_b == 0 && choice_inside_login != 'd'){ //Checking if user paid before receiving the receipt.
								if(choice_inside_login == 'c'){
									printf("You have to pay before receiving the receipt.Try again.");
									continue;
								}
							}
							
							break;
						}
						
					}while(1);
			}
		
		
			
			
			
			if(choice_inside_login == 'a'){	  // if the user selected 'calculate cost'
				flag_a = 1;
				calculate_cost();
					
			}
			else if(choice_inside_login == 'b'){    // if the user selected 'payment'
				flag_b = 1;
				payment();
				
			}
			else if(choice_inside_login == 'c'){   // if the user selected 'receipt'
				get_receipt();
			}
			
				
		
			
		}while(exit_user(choice_inside_login));	 //If choice is 'd' then exits to the user main page by calling the function exit_user.
		
		
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
		selected_cost = ins_cost_18_22;
	}
	else if( age <31){
		ins_cost = ins_cost_23_30 * engine_cc;
		selected_cost = ins_cost_23_30;
	}
	else{
		ins_cost = ins_cost_over30 * engine_cc;
		selected_cost = ins_cost_over30;
	}
	
	amount = ins_cost + rent_cost;
	

	
}
//END OF THE FUNCTION 'CALCULATE_COST'---------------------------	


//START OF THE FUNCTION 'PAYMENT'---------------------------
void payment(){
	
	system("cls");
	int option,len;
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
			scanf("%s",c_c_number);
			
			len = strlen(c_c_number);  //Holding how many digit have been given by the user
		
			if(len != 16){
				printf("\nWrong input.Try again.");
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


//START OF THE FUNCTION 'GET_RECEIPT'---------------------------
void get_receipt(){
	system("cls");
	
	printf("*********************************************************************\n*\t\t\t   CarRental S.A.\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n");
	printf("*   - Days: \t\t\t %d\t(%.2f EUR / day)           *\n",days,amount/days);
	printf("*   - Driver Age: \t\t %d\t(%f EUR / CC)         *\n",age,selected_cost);
	printf("*   - Engine CC: \t\t %d\t\t\t            *\n",engine_cc);
	printf("*\t\t\t\t\t\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n");
	printf("*\t\t\t   PAYMENT DETAILS\t\t\t    *\n");
	printf("*\t\t\t\t\t\t\t\t    *\n");
	printf("*   - AMOUNT: \t\t\t %.2f EUR\t\t\t    *\n",amount);
	
	if(pay_with_credit == 1){
		printf("*   - Pay with Credit Card? \t\tY\t\t\t    *\n*   - Discount (15%%): \t\t %.2f EUR\t\t\t    *\n",discount);
		printf("*   - TOTAL AMOUNT: \t\t %.2f EUR\t\t\t    *\n",total_amount);
		printf("*\t\t\t\t\t\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n");
		printf("*\t\t\t   CREDIT CARD\t\t\t\t    *\n");
		printf("*   - Credit card number:\t\t\t\t\t    *\n");
		printf("*\t     %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c \t\t\t\t    *\n",c_c_number[0],c_c_number[1],c_c_number[2],c_c_number[3],c_c_number[4],c_c_number[5],c_c_number[6],c_c_number[7],c_c_number[8],c_c_number[9],c_c_number[10],c_c_number[11],c_c_number[12],c_c_number[13],c_c_number[14],c_c_number[15]);
		printf("*\t\t\t\t\t\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n");
		printf("*********************************************************************\n");
	}
	else{
		printf("*   - Pay with Credit Card? \t\tN\t\t\t    *\n*   - Discount (0%%): \t\t 0 EUR\t\t\t\t    *\n");
		printf("*   - TOTAL AMOUNT: \t\t %.2f EUR\t\t\t    *\n",total_amount);
		printf("*\t\t\t\t\t\t\t\t    *\n*\t\t\t\t\t\t\t\t    *\n");
		printf("*********************************************************************\n");
	}
	
	
}
//END OF THE FUNCTION 'GET_RECEIPT'---------------------------

//START OF THE FUNCTION 'EXIT_USER'---------------------------
int exit_user(char choice_inside_login){
	int output;
	
	if (choice_inside_login == 'd' ){
		output = 0;
	}
	else{
		output = 1;
	}
	
	
	return output;
}
//END OF THE FUNCTION 'EXIT_USER'---------------------------

//START OF THE FUNCTION 'LOGOUT'---------------------------
int logout(int choice,int admin_or_user){
	int output;
	
	if (admin_or_user == 2 ){
	
		if(choice == 3){
			output = 0;
		}
		else{
			output = 1;
		}
	}
	else{
		if(choice == 2){
			output = 0;
		}
		else{
			output = 1;
		}
	}
	return output;
}
//END OF THE FUNCTION 'LOGOUT'---------------------------

//START OF THE FUNCTION 'LOGIN_ROOT'---------------------------
void login_root(){
	
	char adminUsername[20],adminPassword[20],choice_inside_admin_login;
	
	system("cls");
	
	printf("\n\n\t\t\t\t***********************ADMIN LOGIN PAGE**********************\n");
	
		
		do{
			printf("\nType your username: ");
			scanf("%s",adminUsername);
			printf("Type your password: ");
			scanf("%s",adminPassword);
			
			if(strcmp(adminUsername,"root")!=0 || strcmp(adminPassword,"Root123")!=0){  //Checking if the username is correct.
				printf("Wrong input.Try again.\n");
				continue;
			}
			break;
		}while(1);
		
		printf("\nLogged in succesfully!");
		
		do{
		
			printf("\n\t\t\t\t\t\t------MENU------\n");
			printf("\n\t\t\t\t a.Change Cost\n\t\t\t\t b.Exit\n");
			
			
			do{
				printf("What action do you select: ");
				scanf(" %c",&choice_inside_admin_login);
				if (choice_inside_admin_login != 'a' && choice_inside_admin_login != 'b' ){ //Checking if input is correct
					printf("\nWrong input.Try again.");
					continue;
				}
				break;
			}while(1);
			
			if(choice_inside_admin_login == 'a'){
				change_cost();
			}
		}while(exit_root(choice_inside_admin_login));
		
		
	
	
}
//END OF THE FUNCTION 'LOGIN_ROOT'---------------------------

//START OF THE FUNCTION 'EXIT_ROOT'---------------------------
int exit_root(int choice){
	if(choice == 'b'){
		return 0;
	}
	return 1;
}
//END OF THE FUNCTION 'EXIT_ROOT'---------------------------

//START OF THE FUNCTION 'CHANGE_COST'---------------------------
void change_cost(){
	
	float new_ins_cost_18_22,new_ins_cost_23_30,new_ins_cost_over30;
	int choice_of_category;
	
	system("cls");

	printf("\n------------------Change Cost------------------\n");
	printf("What category from 1-3 do you want to change:");
	do{
		scanf("%d",&choice_of_category);
		if(choice_of_category != 1 && choice_of_category != 2 && choice_of_category != 3 ){
			printf("Wrong input.Try again:");
			continue;
		}
		break;
	}while(1);
	
	printf("Give the new cost: ");
	if(choice_of_category == 1){
		
		do{
			scanf("%f",&new_ins_cost_18_22);
			if( (abs( 1 - (new_ins_cost_18_22 / ins_cost_18_22) ) * 100 ) > 0.10  ){
				printf("Wrong input.The diffence is greater than 10%%.Try again: ");
				continue;
			}
			break;
		}while(1);
		
		ins_cost_18_22 = new_ins_cost_18_22; 
		
	}
	else if(choice_of_category == 2){
		do{
			scanf("%f",&new_ins_cost_23_30);
			if( (abs( 1 - (new_ins_cost_23_30 / ins_cost_23_30) ) * 100 ) > 0.10  ){
				printf("Wrong input.The diffence is greater than 10%%.Try again: ");
				continue;
			}
			break;
		}while(1);
		ins_cost_23_30 = new_ins_cost_23_30;
	}
	else{
		do{
			scanf("%f",&new_ins_cost_over30);
			if( (abs( 1 - (new_ins_cost_over30 / ins_cost_over30) ) * 100 ) > 0.10  ){
				printf("Wrong input.The diffence is greater than 10%%.Try again: ");
				continue;
			}
			break;
		}while(1);
		ins_cost_over30 = new_ins_cost_over30;
	}
}
//END OF THE FUNCTION 'CHANGE_COST'---------------------------
