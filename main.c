#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int terminate(char option[4]);
void sign_up();
void login_user();
void calculate_cost();

char name[20],surname[20],address[20],username[20],password[6];
int age,engine_cc;
float final_cost;

int main(int argc, char *argv[]) {
	char option[4];
	
	
	do{
		float flag = 1 ;
		int sign_up_done = 0;
		
		printf("\t\t\t\t***********************HOME SCREEN**********************\n");
		
		printf("Type 'root' if you are admin or type 'user' if you are a user or type '0' to end the program: ");
		
		gets(option);    //GETS THE INPUT FROM THE USER
		while(strcmp(option,"user")!=0 && strcmp(option,"root")!=0 && strcmp(option,"0")!=0){   //CHECKING IF THE INPUT IS CORRECT
			printf("\nWrong input.Please try again: ");
			gets(option);
		}
		
		
		while(strcmp(option,"user")==0 && flag==1){ //USER SCREEN AND FUNCTIONS------------------------
			
			int choice,end_of_login=0;
			
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
	
	printf("\n\n\t\t\t\t***********************SIGN UP PAGE**********************\n");
	
	printf("\n---------Give us your Name: ");
	scanf("%s",name);
	
	printf("---------Give us your Surname: ");	
	scanf("%s",surname);
	
	printf("---------Give us your Username: ");	
	scanf("%s",username);
	
	printf("---------Give us your Address: ");
	scanf("%s",address);
	
	printf("---------Give us your Password: ");
	scanf("%s",password);

}
//END OF THE FUNCTION 'SING_UP'------------------------------



void login_user(){
	
		char choice_inside_login;
	
		char givenUsername[20],givenPassword[6];
		
		printf("\n\n\t\t\t\t***********************LOGIN PAGE**********************\n");
		
		do{
			
			printf("\nType your username: ");
			scanf("%s",givenUsername);
			printf("Type your password: ");
			scanf("%s",givenPassword);
			
			if(strcmp(givenUsername,username)!=0 || strcmp(givenPassword,password)!=0){
				printf("Wrong input.Try again\n");
				continue;
			}	
			else{
				
				printf("\nLogged in succesfully!");
				printf("\n\t\t\t\t\t\t------MENU------\n");
				printf("\n\t\t\t\t a.Calculate Cost\n\t\t\t\t b.Payment\n\t\t\t\t c.Receipt\n\t\t\t\t d.Exit\n\n");
				do{
					scanf(" %c",&choice_inside_login);
					if(choice_inside_login!= 'a' && choice_inside_login!= 'b' && choice_inside_login!= 'c' && choice_inside_login!= 'd' ){
						printf("\nWrong input.Try again:");
						continue;
					}
					else{
						break;
					}
				}while(1);
			}
			
			if(choice_inside_login == 'a'){
				calculate_cost();
				printf("\n------------------Cost Calculation------------------");
				printf("")
				
			}
				
		
			
		}while(strcmp(givenUsername,username)!=0 || strcmp(givenPassword,password)!=0);	
	
	
}


void calculate_cost(){
	printf("\n------------------Cost Calculation------------------\n");
	
	do{
	
		printf("\nGive us your age:");
		scanf("%d",&age);
		printf("Give us the Engine CC:");
		scanf("%d",&engine_cc);
		
		if(age<18 || engine_cc <0  ){
			printf("Wrong input.Try again");
			continue;
		}
		else{
			break;
		}
	
	}while(1);
	
	
	
	
}