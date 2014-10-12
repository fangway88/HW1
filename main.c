#include<stdio.h>

struct team {
	char *name;
	char *conference;
	int wins;
};	

struct team NBA[4];

void swap(struct team *team1, struct team *team2) {
	struct team temp = *team1;
	*team1 = *team2;
	*team2 = temp;
}

int count_letters(char *team) {
	int number_of_letters = 0;
	for (;*team != '\0';team++) {
		number_of_letters++;
		printf("%c, letter number %d\n",*team, number_of_letters);
	}
	return number_of_letters;
}

int main()
{
	struct team Heat;
	Heat.name = "Heat";
	Heat.conference = "East";
	Heat.wins = 68;

	struct team Pacers;
	Pacers.name = "Pacers";
	Pacers.conference = "East";
	Pacers.wins = 52;

	struct team Lakers;
	Lakers.name = "Lakers";
	Lakers.conference = "West";
	Lakers.wins = 30;

	struct team Thunder;
	Thunder.name = "Thunder";
	Thunder.conference = "West";
	Thunder.wins = 70;

	NBA[0] = Heat;
	NBA[1] = Pacers;
	NBA[2] = Lakers;
	NBA[3] = Thunder;

	int total_wins = 0;
	int i;
	int wins_by_conference[2] = {0,0};
	for (i = 0; i < 4; i++) {
		total_wins  += (NBA + i)->wins;
		if (strcmp((NBA + i)->conference, "East") == 0) {
			wins_by_conference[0] += (NBA + i)->wins;
		} else {
			wins_by_conference[1] += (NBA + i)->wins;
		}
	}

	printf("The total wins is: %d\n", total_wins);
	printf("Eastern Conference has %d wins\n", wins_by_conference[0]);
	printf("Western Conference has %d wins\n\n", wins_by_conference[1]);
	printf("The teams used in these statistics are the following: %s, %s, %s, %s\n", NBA->name, (NBA + 1)->name, (NBA + 2)->name, (NBA + 3)->name);
	
	swap((NBA + 1), (NBA + 2));
	printf("The teams in alphabetical order are the following: %s, %s, %s, %s\n\n", NBA->name, (NBA + 1)->name, (NBA + 2)->name, (NBA + 3)->name);	
	
	printf("Breakdown of the Heat name\n");
	int number = count_letters("Heat");
	printf("The number of letters in Heat is %d\n", number);

	return(0);
}
