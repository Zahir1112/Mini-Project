#include<stdio.h>
#include<conio.h>


//Prototyping
void verify ();
void inventory ();
void password ();
void error ();
void billcal();


//Global arrays
int stock[6];
float price[6];
float cost[6];
int pick[6];
float bill[6];
char usrnm[10];
char pass[10];
int key[2];


//Global Variables
int i,j;



/*Title - Menu*/
void title () {
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=13;j++) {
		
		if ((i==1||i==2||i==3)&&(j==1))
		printf("\t\t\t      ");
		if ((i==1||i==3)&&(j>=1&&j<=13))
		printf("=");
		if ((i==2)&&(j==2||j==12))
		printf(" ");
		if (i==2&&j==2)
		printf("MAIN MENU");
		if ((i==2)&&(j==1||j==13))
		printf("=");
		}
		printf("\n");
		}
	}//Title Function End



/*Error function*/
void error () {
	printf("\n");
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=35;j++) {
		
		if ((i==1||i==2||i==3)&&(j==1))
		printf("\t\t  ");	
		if ((i==1||i==3)&&(j>=1&&j<=35))
		printf("-");
		if ((i==2)&&(j==2||j==34))
		printf(" ");
		if (i==2&&j==2)
		printf("Invalid Selection! Enter Again!");
		if ((i==2)&&(j==1||j==35))
		printf("|");
		}
		printf("\n");
		}
	printf("\n\n");

}//Error Function End




/*Main Menu Function*/
void menu () {
		int op;
		
		printf("\n");
		title();

		//Options
		printf("\n\n1. INVENTORY MANAGEMENT\n");
		printf("2. BILL CALCULATION\n");
		printf("3. ENCRYPT YOUR DATA\n");
		printf("4. EXIT\n\n");
	
		printf("=> CHOOSE THE OPTION : ");
		scanf("%d",&op);
	
		
		//switch
		switch (op) {
		
			//01
			case 1:
			if(key[0]==1){
			system("cls");
			verify(op);
			}
		
			else {
			system("cls");
			printf("\a");
			inventory();
			}
			break;
		
			
			//02
			case 2:
			if(key[0]==1){
			system("cls");
			verify(op);
			}
		
			else {
			system("cls");
			printf("\a");
			billcal();
			}
			break;
			
			
			//03
			case 3:
			system("cls");
			printf("\a");
			password ();
			break;
			
			case 4:
			break;
			
			default:
			error();
			printf("\a\a");
			menu ();
		}
	
	}//Main Menu Function End




/*verify Function*/ 
void verify (int op) {
	char userpass[10];
	char userusrnm[10];
	
		printf("\n\t\t\tPLEASE LOGIN TO CONTONUE !");
		printf("\a\a");
		
		printf("\n\n\n=> ENTER YOUR USERNAME : ");
		scanf("%s",&userusrnm);
		
		printf("\n=> ENTER YOUR PASSWORD : ");
		scanf("%s",&userpass);
		
		//Option After Password Protection
		if((strcmp(userusrnm, usrnm))==0&&(strcmp(pass, userpass)==0)) {
		system("cls");
		
			if(op==1) {
			printf("\a");
			system("COLOR 0B");
			inventory ();
			}
		
			else {
			printf("\a");
			system("COLOR 0B");
			billcal();
			}
		
		}//If end
		
		
		else {
		system("COLOR 0C");
		printf("\n");
		
		for (i=1;i<=3;i++) {
			for (j=1;j<=34;j++) {
			if ((i==1||i==2||i==3)&&(j==1))
			printf("\t\t    ");
			
			if ((i==1||i==3)&&(j>=1&&j<=34))
			printf("-");
			if ((i==2)&&(j==2||j==33))
			printf(" ");
			if (i==2&&j==2)
			printf("Invalid Password! Enter Again!");
			if ((i==2)&&(j==1||j==34))
			printf("|");
		}
		printf("\n");
		}
	
		printf("\a\a");
	
		printf("\n");
		
		verify(op);
	
	}

}//Verify Function End



/*Inventory Function*/
void inventory () {
	int op;
	system("COLOR 0B");
	
	FILE *fptr;
	
	//Title
	printf("\n");
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=24;j++) {
			if ((i==1||i==2||i==3)&&(j==1))
			printf("\t\t\t");
			if ((i==1||i==3)&&(j>=1&&j<=24))
			printf("=");
			if ((i==2)&&(j==2||j==23))
			printf(" ");
			if (i==2&&j==2)
			printf("INVENTORY MANAGEMENT");
			if ((i==2)&&(j==1||j==24))
			printf("=");
		}
		printf("\n");
	}
	
	
	//Options
	printf("\n\n1. ENTER INVENTORY UNITS\n");
	printf("2. DISPLAY INVENTORY UNITS\n");
	printf("3. MAIN MENU\n\n");
	
	printf("=> CHOOSE THE OPTION : ");
	scanf("%d",&op);
	
	
	//Enter Inventory Units
	if (op==1)
	{
		printf("\a");
	
		printf("\n\n     UNITS\t NO\tPRICE (RS.)");
		printf("\n-------------   ----\t-----------");
		
		printf("\n* HEAD LIGHTS : ");
		scanf("%d\t%f",&stock[0], &price[0]);
	
		printf("\n* BUMPERS     : ");
		scanf("%d\t%f",&stock[1], &price[1]);
	
		printf("\n* MIRRORS     : ");
		scanf("%d\t%f",&stock[2], &price[2]);
	
		printf("\n* DOORS       : ");
		scanf("%d\t%f",&stock[3], &price[3]);
	
		printf("\n* TYRES       : ");
		scanf("%d\t%f",&stock[4], &price[4]);
	
		printf("\n* TRUNKIDS    : ");
		scanf("%d\t%f",&stock[5], &price[5]);
		
		
		//File Handling
		fptr=fopen("C:\\Users\\User\\File\\data.txt","w");
		
		for (i=0;i<6;i++) {
			fprintf(fptr,"%d\t%.2f\n",stock[i],price[i]);
		}
		
		fclose(fptr);
	
		system("cls");
		printf("\a");
		inventory ();
	}
	
	
	//Display Inventory Units
	else if (op==2)
	{	
		float sum;
		
		for (i=0;i<6;i++) {
		cost[i]=(float)stock[i]*price[i];
		sum=sum+cost[i];
		}
	
		printf("\n\n     UNITS\t    NO\t\t PRICE\t\t  TOTAL (RS.)");
		printf("\n-------------      -----\t-------\t\t--------------");
		printf("\n\n* HEAD LIGHTS :    %d\t     %10.2f\t\t   %11.2f",stock[0], price[0], cost[0]);
		printf("\n\n* BUMPERS     :    %d\t     %10.2f\t\t   %11.2f",stock[1], price[1], cost[1]);
		printf("\n\n* MIRRORS     :    %d\t     %10.2f\t\t   %11.2f",stock[2], price[2], cost[2]);
		printf("\n\n* DOORS       :    %d\t     %10.2f\t\t   %11.2f",stock[3], price[3], cost[3]);
		printf("\n\n* TYRES       :    %d\t     %10.2f\t\t   %11.2f",stock[4], price[4], cost[4]);
		printf("\n\n* TRUNKIDS    :    %d\t     %10.2f\t\t   %11.2f\n\n",stock[5], price[5], cost[5]);
		
		printf("\n=> TOTAL (RS.) : %.2f\n\n\n",sum);
		
		printf("\a");
		
		inventory ();
	}
	
	
	//Main Menu
	else if (op==3){
	system("cls");
	printf("\a");
	menu();
	}
	
	//Error
	else {
	error();
	printf("\a\a");
	inventory ();
	}

}//Inventory Function End



/*Bill Calculation Function*/
void billcal () {
	int op;
	
	//Title
	printf("\n");
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=20;j++) {
			if ((i==1||i==2||i==3)&&(j==1))
			printf("\t\t\t   ");
			if ((i==1||i==3)&&(j>=1&&j<=20))
			printf("=");
			if ((i==2)&&(j==2||j==19))
			printf(" ");
			if (i==2&&j==2)
			printf("BILL CALCULATION");
			if ((i==2)&&(j==1||j==20))
			printf("=");
		}
		printf("\n");
	}
	
	
	//Options
	printf("\n\n1. PICK ITEMS\n");
	printf("2. GENERATE THE BILL\n");
	printf("3. DISPLAY NEW INVENTORY\n");
	printf("4. MAIN MENU\n\n");
	
	printf("=> CHOOSE THE OPTION : ");
	scanf("%d",&op);
	
	
	//Pick Items
	if (op==1) {
	
	printf("\n\n     UNITS\t NO");
	printf("\n-------------   ----");
		
	printf("\n* HEAD LIGHTS : ");
	scanf("%d",&pick[0]);
	
	printf("\n* BUMPERS     : ");
	scanf("%d",&pick[1]);
	
	printf("\n* MIRRORS     : ");
	scanf("%d",&pick[2]);
	
	printf("\n* DOORS       : ");
	scanf("%d",&pick[3]);
	
	printf("\n* TYRES       : ");
	scanf("%d",&pick[4]);
	
	printf("\n* TRUNKIDS    : ");
	scanf("%d",&pick[5]);
	
	system("cls");
	printf("\a");
	billcal();
		
	}
	
	
	//Generate Bill
	else if (op==2) {
		float sum;
		
		//Sum & Each Total
		for (i=0;i<6;i++) {
		bill[i]=pick[i]*price[i];
		sum=sum+bill[i];
		}
		
		
		//Displaying
		printf("\n\n     UNITS\t    NO\t\t PRICE\t\t  TOTAL (RS.)");
		printf("\n-------------      -----\t-------\t\t--------------");
		printf("\n\n* HEAD LIGHTS :    %d\t     %10.2f\t\t   %11.2f",pick[0], price[0], bill[0]);
		printf("\n\n* BUMPERS     :    %d\t     %10.2f\t\t   %11.2f",pick[1], price[1], bill[1]);
		printf("\n\n* MIRRORS     :    %d\t     %10.2f\t\t   %11.2f",pick[2], price[2], bill[2]);
		printf("\n\n* DOORS       :    %d\t     %10.2f\t\t   %11.2f",pick[3], price[3], bill[3]);
		printf("\n\n* TYRES       :    %d\t     %10.2f\t\t   %11.2f",pick[4], price[4], bill[4]);
		printf("\n\n* TRUNKIDS    :    %d\t     %10.2f\t\t   %11.2f\n\n",pick[5], price[5], bill[5]);
		printf("\n=> BILL COST : %.2f\n\n",sum);
		
		printf("\a");
		billcal();
	}
	
	
	//Display New Inventory
	else if (op==3) {
		float sum2=0;
		for (i=0;i<6;i++) {
		sum2=(float)sum2+(cost[i]-bill[i]);
		}
	
		printf("\n\n     UNITS\t    NO\t\t PRICE\t\t  TOTAL (RS.)");
		printf("\n-------------      -----\t-------\t\t--------------");
		printf("\n\n* HEAD LIGHTS :    %d\t     %10.2f\t\t   %11.2f",stock[0]-pick[0], price[0], cost[0]-bill[0]);
		printf("\n\n* BUMPERS     :    %d\t     %10.2f\t\t   %11.2f",stock[1]-pick[1], price[1], cost[1]-bill[1]);
		printf("\n\n* MIRRORS     :    %d\t     %10.2f\t\t   %11.2f",stock[2]-pick[2], price[2], cost[2]-bill[2]);
		printf("\n\n* DOORS       :    %d\t     %10.2f\t\t   %11.2f",stock[3]-pick[3], price[3], cost[3]-bill[3]);
		printf("\n\n* TYRES       :    %d\t     %10.2f\t\t   %11.2f",stock[4]-pick[4], price[4], cost[4]-bill[4]);
		printf("\n\n* TRUNKIDS    :    %d\t     %10.2f\t\t   %11.2f\n\n",stock[5]-pick[5], price[5], cost[5]-bill[5]);
		
		printf("\n=> TOTAL (RS.) : %.2f\n\n",sum2);
		
		printf("\a");
		
		billcal();
	}

	
	//Main Menu
	else if (op==4) {
	system("cls");
	printf("\a");
	menu();
	}
	
	else {
	error();
	printf("\a\a");
	billcal();
	}
	
		
}//Bill Calculation Function - End




//Password Function
void password () {
	int op;
	char usrnm1[10];
	char pass1[10];
	
	//Title
	printf("\n");
	
	for (i=1;i<=3;i++) {
		for (j=1;j<=19;j++) {
			if ((i==1||i==2||i==3)&&(j==1))
			printf("\t\t\t   ");
			if ((i==1||i==3)&&(j>=1&&j<=19))
			printf("=");
			if ((i==2)&&(j==2||j==16))
			printf(" ");
			if (i==2&&j==2)
			printf("ENCRYPTION MENU");
			if ((i==2)&&(j==1||j==19))
			printf("=");
		}
		printf("\n");
	}
	
	
	//Options
	printf("\n\n1. CREATE YOUR PASSWORD\n");
	printf("2. RESET YOUR PASSWORD\n");
	printf("3. MAIN MENU\n\n");
	
	printf("=> CHOOSE THE OPTION : ");
	scanf("%d",&op);
	
	
	if (op==1) {
		
		if(key[1]==0) {
			
			printf("\n* ENTER USERNAME : ");
			scanf("%s",&usrnm);
			printf("\a");
		
			printf("\n* ENTER PASSWORD : ");
			scanf("%s",&pass);
			printf("\a");
		
			key[0]=1;
			key[1]=1;
		
			system("cls");
			password ();
		}
		
		else {
			printf("\n\n\t\t\t| REST YOUR PASSWORD !!! |\n\n\n");
			printf("\a\a");
			password ();
		}
	}
	
	
	else if (op==2) {
		
		printf("\n* ENTER USERNAME : ");
		scanf("%s",&usrnm1);
		printf("\a");
		
		printf("\n* ENTER PASSWORD : ");
		scanf("%s",&pass1);
		printf("\a");
		
		if (strcmp(usrnm,usrnm1)==0&&strcmp(pass,pass1)==0) {
			key[0]=0;
			printf("\n\n\t  ^-^ YOUR PASSWORD HAS BEEN RESET SUCCESSFULLY !! ^-^\n\n\n");
			printf("\a");	
			key[1]=0;
			
			password ();
		}
		
		
		else {
			
			printf("\n");
			for (i=1;i<=3;i++) {
			for (j=1;j<=41;j++) {
			
			//Error Message
			if ((i==1||i==2||i==3)&&(j==1))
			printf("\t\t  ");
			if ((i==1||i==3)&&(j>=1&&j<=41))
			printf("-");
			if ((i==2)&&(j==2||j==40))
			printf(" ");
			if (i==2&&j==2)
			printf("PASSWORD RESET WAS NOT SUCCESSFUL !!!");
			if ((i==2)&&(j==1||j==41))
			printf("|");
			}
		printf("\n");
			}
	
		printf("\a\a");
	
		printf("\n");
		
		password ();
		}
		
	}
		
		
	else {
		system("cls");
		printf("\a");
		menu ();
	}
		
}//Password Function - End




/*Main Function*/
int main () {
	
	char op[3];
	key[1]=0;
	char yes[3]="YES";
	system("COLOR 0B");
	printf("\n");
	
	//Title
	for (i=1;i<=5;i++) {
		for (j=1;j<=75;j++) {
			if((i>=1&&i<=5)&&j==1)
			printf("   ");
			
			if ((i==1)&&((j==2||j==3||j==4||j==9||j==13||j==17||j==18||j==19||j==20||j==21||j==26||j==27||j==28||j==37||j==41||j==45||j==46||j==47||j==48||j==49||j==53||j==54||j==55||j==56||j==62||j==63||j==64||j==69||j==70||j==71||j==72||j==73)))
			printf("*");
			else if ((i==2)&&(j==1||j==5||j==9||j==13||j==19||j==25||j==29||j==37||j==38||j==40||j==41||j==47||j==53||j==57||j==61||j==65||j==71))
			printf("*");
			else if ((i==3)&&(j==1||j==2||j==3||j==4||j==5||j==9||j==13||j==19||j==25||j==29||j==37||j==39||j==41||j==47||j==53||j==54||j==55||j==56||j==61||j==62||j==63||j==64||j==65||j==71))
			printf("*");
			else if ((i==4)&&((j==1||j==5||j==9||j==13||j==19||j==25||j==29||j==37||j==41||j==47||j==53||j==57||j==61||j==65||j==69||j==71)))
			printf("*");
			else if ((i==5)&&((j==1||j==5||j==10||j==11||j==12||j==19||j==26||j==27||j==28||j==37||j==41||j==45||j==46||j==47||j==48||j==49||j==53||j==57||j==61||j==65||j==70)))
			printf("*");
			else
			printf(" ");
		}
	
		printf("\n");
	}
	
	printf("\n\n\n");
	
	
	//Instuctions
	printf("=> ABOUT OUR PRODUCT ! <=\n");
	printf("-------------------------\n");
	printf("\n * THIS PRODUCT IS SPECIALLY DESIGNED FOR AUTO-MOBILE INVENTORY MANAGEMENT.\n");
	printf("\n * BEING A STARTUP COMPANY, AUTO-MIRAJ HAS DEVELOPED THIS TOOL IN ORDER TO\n");
	printf("   MEET WITH YOUR MOST OF THE EXPECTATIONS.\n");
	printf("\n * IF YOU ENCOUNTER ANY BUGS, PLEASE REPORT US !");
	printf("\n   ( SUPPORT : AUTOMIRAJ2019@GMAIL.COM )\n\n\n");
	printf(" ^-^ DEVELOPER : M.ZAHIR (CYBER TEAM) ^-^\n\n");
	
	
	printf("\n\n\n=> FUNCTIONS OF OUR PRODUCT : <=\n");
	printf("----------------------------------\n");
	printf("\n 1. INVENTORY MANAGEMENT :\n");
	printf("\n    1.1. ENTER INVENTORY UNITS   : (YOU CAN ADD YOUR INVENTORY DATA)\n");
	printf("\n    1.2. DISPLAY INVENTORY UNITS : (INVENTORY DATA WITH TOTAL CALCULATIONS)\n\n");
	
	
	printf("\n\n 2. BILL CALCULATIONS :\n");
	printf("\n    2.1. PICK ITEMS	       : (SELECT THE DESIRED ITEMS FROM INVENTORY)\n");
	printf("\n    2.2. GENERATE THE BILL     : (BILL WILL BE CALCULATED FOR SELECTED ITEMS)\n");
	printf("\n    2.3. DISPLAY NEW INVENTORY : (NEW INVENTORY DATA, AFTER YOU PICK ITEMS)\n\n");
	
	
	printf("\n\n 3. ENCRYPT YOUR DATA : (OPTIONAL)\n");
	printf("\n   => HIGHLY RECOMMENDED TO PROTECT YOUR DATA FROM UN-AUTHORIZED ACCESS <=\n");
	printf("\n   => EVERY MAIN OPTIONS WILL BE ENCRYPTED <=\n");
	printf("\n   3.1. CREATE YOUR PASSWORD : (CREATE A USERNAME & PASSWORD)\n");
	printf("\n   3.2. RESET YOUR PASSWORD  : (RESET PASSWORD BY PROVIDING PREVIOUS PASSWORD)\n\n");
	
	
	printf("\n\n * IF YOU READ ALL THE INSTRUCTIONS, ENTER 'YES' TO START USING THE SOFTWARE");
	printf("\n   OR PRESS ANY KEY TO EXIT !\n");
	printf("\n => ENTER : ");
	scanf("%s",&op);
	
	
	//Starting software
	if (strcmp(op,yes)==0) {
		system("cls");
		printf("\a\a");
		menu();
	}
	
	else {
		printf("\n\n\t\t\t       | THANK YOU !!! |\n\n\n");
		printf("\a\a");
	}
	
	
	getch();
}
