#include <stdio.h>
#include <stdlib.h>

int prompt();
int new_account();
int econimic_flight();
int business_flight();
int menu();
int bill();

int option, seat, number, account, menu_index, flight_type;
char first_name[20], last_name[20], f_response, response;
float f_tax, price = 0;

char items[20][50] = { "Chicken Alfredo", "Spaghetti and Meatballs", "Pizza Margherita", "Cheeseburger", "Grilled Chicken Sandwich", "Fish and Chips", "Steak Frites", "Caesar Salad", "Greek Salad", "Mushroom Risotto", "Chicken Tenders", "Fried Chicken Sandwich", "BBQ Ribs", "French Onion Soup", "Clam Chowder", "Garlic Bread", "Mashed Potatoes", "Sweet Potato Fries", "Onion Rings", "Cheesecake" };
float prices[20] = { 12.99, 11.99, 10.99, 9.99, 8.99, 13.99, 16.99, 7.99, 8.99, 14.99, 7.99, 9.99, 15.99, 5.99, 6.99, 3.99, 4.99, 5.99, 4.99, 6.99 };
int quantity = 0, choice, order[20] = { 0 };
float subtotal = 0.0, tax, total;

int main()
{
	prompt();
	return 0;
}

int prompt()
{
	printf("\t=================================================\n");
	printf("\t      Welcome to Airline Reservation System\n");
	printf("\t=================================================\n");
	printf("\n\t\t    Please Create Your Account!\n");
	new_account();
}

int new_account()
{
	printf("\n\t=================================================\n");
	printf("\n\t\t\tCreate New Account\n");
	printf("\n\tEnter your first name: ");
	scanf("%s", &first_name);
	printf("\n\tEnter your last name: ");
	scanf("%s", &last_name);
	printf("\n\tEnter your PayPal number: ");
	scanf("%d", &number);
	printf("\n\t-------------------------------------------------\n");
	printf("\t\t\tWelcome %s %s", first_name, last_name);
	printf("\n\t   You Have Successfully Created Your Account!");
	printf("\n\t-------------------------------------------------\n");
	printf("\n\tChoose an option\n");
	printf("\t\t\t   1. Economy Class\n");
	printf("\t\t\t   2. Business/First Class\n");
	printf("\t\t\t   3. Exit\n");
	printf("\n\tYour choice (1-3): ");
	scanf("%d", &option);
	switch (option)
	{
		case 1:
			flight_type = 1;
			econimic_flight();
			break;
		case 2:
			flight_type = 0;
			business_flight();
			break;
		case 3:
			printf("\n\n\t-------------------------------------------------\n");
			printf("\n\t\t    See You Again...Goodbye!");
			printf("\n\n\t-------------------------------------------------\n");
			exit(0);
			break;
		default:
			printf("\n\n\t-------------------------------------------------\n");
			printf("\n\t\tInvalid Option...Please Try Again!");
			printf("\n\n\t-------------------------------------------------\n");
			exit(0);
			break;
	}
}

int econimic_flight()
{
	printf("\n\t=================================================\n");
	printf("\t            Welcome to Economy Class\n");
	printf("\t=================================================\n");
	printf("\n\tAvaialbe seats:- ");
	for (int i = 101; i <= 160; i++)
	{
		printf("E-%d", i);
		if (i % 4 == 0 && i != 160)
		{
			printf(",\n\t\t\t ");
		}
		else if (i != 160)
		{
			printf(", ");
		}
	}

	printf("\n\n\tEnter seat number (E-101 to E-160): E-");
	scanf("%d", &seat);
	printf("\n\n\t-------------------------------------------------\n");
	printf("\n\t   | Seat Number E - %d Successfully Booked |", seat);
	printf("\n\n\t-------------------------------------------------\n");
	printf("\n\tWould you like to have food on your trip (y/n)");
	printf("\n\n\t\t\tYour Response:- ");
	scanf(" %c", &f_response);
	if (f_response == 'y')
	{
		menu();
	}

	bill();
}

int business_flight()
{
	printf("\n\t=================================================\n");
	printf("\t      Welcome to Business/First Class\n");
	printf("\t=================================================\n");
	printf("\n\tAvaialbe seats:- ");
	for (int i = 201; i <= 240; i++)
	{
		printf("B-%d", i);
		if (i % 4 == 0 && i != 160)
		{
			printf(",\n\t\t\t ");
		}
		else if (i != 160)
		{
			printf(", ");
		}
	}

	printf("\n\tEnter seat number (B-201 to E-240): ");
	scanf("%d", &seat);
	printf("\n\n\t-------------------------------------------------\n");
	printf("\n\t   | Seat Number B - %d Successfully Booked |", seat);
	printf("\n\n\t-------------------------------------------------\n");
	printf("\n\tWould you like to have food on your trip (y/n)");
	printf("\n\n\t\t\tYour Response:- ");
	scanf(" %c", &f_response);
	if (f_response == 'y')
	{
		menu();
	}

	bill();
}

int menu()
{
	menu_index = 1;
	printf("\n\t=================================================\n");
	printf("\t\t\t    MENU");
	printf("\n\t=================================================\n\n");
	for (int i = 0; i < 20; i++)
	{
		printf("\t\t%d. %s - \t$%.2f\n", i + 1, items[i], prices[i]);
	}

	printf("\n\t=================================================\n");
	printf("\n\tEnter code of the food item (1-20): ");
	scanf("%d", &choice);
	while (choice >= 1 && choice <= 20)
	{
		printf("\tEnter quantity: ");
		scanf("%d", &quantity);
		order[choice - 1] += quantity;
		printf("\tEnter code of the food item (1-20) or 0 to finish ordering: ");
		scanf("%d", &choice);
	}
}

int bill()
{
	printf("\n\t=================================================");
	printf("\n\n\t\t\tINVOICE DETAILS\n");
	printf("\n\t=================================================\n");
	printf("\n\tCustomer name:              %s %s\n", first_name, last_name);
	if (flight_type == 1)
	{
		price = 542.00;
		tax = price *0.05;
		printf("\tClass:                      Economic\n");
		printf("\tSeat number:                E-%d\n", seat);
	}
	else if (flight_type == 0)
	{
		price = 921.00;
		tax = price *0.12;
		printf("\tClass:                      Business/First\n");
		printf("\tSeat number:                B-%d\n", seat);
	}

	printf("\tTicket Price:               $%.2f\n", price);
	printf("\tTaxable amount:             $%.2f\n", price);
	printf("\tTax:                        $%.2f\n", tax);
	if (menu_index == 1)
	{
		printf("\t-------------------------------------------------\n");
		printf("\tFood Bill\n");
		for (int i = 0; i < 20; i++)
		{
			if (order[i] != 0)
			{
				subtotal += order[i] *prices[i];
				printf("\t%d x %s                   $%.2f\n", order[i], items[i], order[i] *prices[i]);
			}
		}

		printf("\tSubtotal:                     $%.2f\n", subtotal);
		printf("\tTax:                          $%.2f\n", subtotal *0.07);
		total = subtotal *1.07;
		printf("\tTotal:                        $%.2f\n", total);
		printf("\t=================================================\n");
		printf("\tGrand total:                  $%.2f\n", price + tax + total);
	}
	else
	{
		printf("\t=================================================\n");
		printf("\tGrand total: \t\t           $%.2f\n", price + tax + total);
	}

	printf("\t=================================================\n");
	printf("\n\tYou Will Recevie Payment Request On Your Device");
	printf("\n\n\t\t   Payment Confirmed (y/n)?");
	printf("\n\n\t\t      Your Response:- ");
	scanf("%s", &response);
	if (response == 'y')
	{
		printf("\n\n\t-------------------------------------------------\n");
		printf("\n\tThank You %s %s For Travelling With Us!", first_name, last_name);
		printf("\n\n\t-------------------------------------------------\n");
		printf("\n\t\t\t   Bon Voyage ^_^");
		printf("\n\n\t-------------------------------------------------\n");
	}
	else
	{
		printf("\n\tPayment Not Completed...Please Try Again!\n");
	}
}
