#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct Player
{
	int jerseyNo;
	char name[50];
	int runs;
	int wickets;
	int matches;

}Player;

//=================== Hardcoded Player Data ===================

Player p[MAX] =
{
	{18,"Virat",14000,5,300},
	{45,"Rohit",11000,10,270},
	{7,"Dhoni",10500,1,350},
	{63,"Suryakumar",4500,2,120},
	{1,"KLRahul",8000,0,180}
};

int count = 5;

//================ Function Prototypes =================

void addPlayer();
void removePlayer();
void searchPlayer();
void searchByJersey();
void searchByName();
void updatePlayer();
void displayPlayers();
void sortPlayers();
void sortByRuns(int);
void sortByWickets(int);
void top3Runs();
void top3Wickets();
void playerStatistics();
void filterPlayers();

void toLower(char str[]);

void toLower(char str[])
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
	int choice;

	do
	{
		printf("\n");
		printf("=============================================\n");
		printf("      PLAYER MANAGEMENT SYSTEM\n");
		printf("=============================================\n");

		printf("\n1. Add Player");
		printf("\n2. Remove Player");
		printf("\n3. Search Player");
		printf("\n4. Update Player");
		printf("\n5. Display All Players");
		printf("\n6. Sort Players");
		printf("\n7. Top 3 Run Scorers");
		printf("\n8. Top 3 Wicket Takers");
		printf("\n9. Player Statistics");
		printf("\n10. Filter Players");
		printf("\n11. Exit");

		printf("\n\nEnter Your Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				addPlayer();
				break;

			case 2:
				removePlayer();
				break;

			case 3:
				searchPlayer();
				break;

			case 4:
				updatePlayer();
				break;

			case 5:
				displayPlayers();
				break;

			case 6:
				sortPlayers();
				break;

			case 7:
				top3Runs();
				break;

			case 8:
				top3Wickets();
				break;

			case 9:
				playerStatistics();
				break;

			case 10:
				filterPlayers();
				break;

			case 11:
				printf("\nThank You...\n");
				exit(0);

			default:
				printf("\nInvalid Choice...");
		}

	}while(choice != 11);

	return 0;
}

void addPlayer()
{
    int i, valid;
    int duplicate;

    if(count >= MAX)
    {
        printf("\nPlayer List Is Full...\n");
        return;
    }

    // Jersey Validation
    do
    {
        duplicate = 0;

        printf("\nEnter Jersey Number : ");
        scanf("%d",&p[count].jerseyNo);

        if(p[count].jerseyNo <= 0)
        {
            printf("\nJersey Number Must Be Greater Than 0.\n");
            continue;
        }

        for(i=0;i<count;i++)
        {
            if(p[i].jerseyNo == p[count].jerseyNo)
            {
                printf("\nJersey Number Already Exists...");
                printf("\nPlease Enter Another Jersey Number.\n");
                duplicate = 1;
                break;
            }
        }

    }while(p[count].jerseyNo <= 0 || duplicate == 1);

    // Name Validation
    while(getchar()!='\n');

    do
    {
        valid = 1;

        printf("Enter Player Name : ");
        fgets(p[count].name,sizeof(p[count].name),stdin);

        p[count].name[strcspn(p[count].name,"\n")] = '\0';

        if(strlen(p[count].name)==0)
        {
            printf("\nName Cannot Be Empty...\n");
            valid = 0;
            continue;
        }

        for(i=0;p[count].name[i]!='\0';i++)
        {
            if(!(isalpha((unsigned char)p[count].name[i]) || p[count].name[i]==' '))
            {
                valid = 0;
                break;
            }
        }

        if(valid==0)
        {
            printf("\nName Should Contain Only Alphabets And Spaces.\n");
        }

    }while(valid==0);

    // Matches Validation
    do
    {
        printf("Enter Matches : ");
        scanf("%d",&p[count].matches);

        if(p[count].matches<0)
        {
            printf("\nMatches Cannot Be Negative...\n");
        }

    }while(p[count].matches<0);

    // Runs & Wickets Validation
    if(p[count].matches==0)
    {
        p[count].runs=0;
        p[count].wickets=0;
    }
    else
    {
        do
        {
            printf("Enter Runs : ");
            scanf("%d",&p[count].runs);

            if(p[count].runs<0)
            {
                printf("\nRuns Cannot Be Negative...\n");
            }

        }while(p[count].runs<0);

        do
        {
            printf("Enter Wickets : ");
            scanf("%d",&p[count].wickets);

            if(p[count].wickets<0)
            {
                printf("\nWickets Cannot Be Negative...\n");
            }

        }while(p[count].wickets<0);
    }

    count++;

    printf("\n====================================");
    printf("\nPlayer Added Successfully...");
    printf("\n====================================\n");
}
void displayPlayers()
{
	int i;

	if(count == 0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	printf("\n====================================================================================================\n");
	printf("Sr\tJNo\tName\t\tRuns\tWickets\tMatches\t\tStatus\n");
	printf("====================================================================================================\n");

	for(i = 0; i < count; i++)
	{
		printf("%d\t%d\t%-15s%d\t%d\t%d\t\t",
		i + 1,
		p[i].jerseyNo,
		p[i].name,
		p[i].runs,
		p[i].wickets,
		p[i].matches);

		if(p[i].matches == 0)
		{
			if(p[i].runs == 0 && p[i].wickets == 0)
				printf("Not Played");
			else
				printf("Invalid Data");
		}
		else
		{
			printf("Played");
		}

		printf("\n");
	}

	printf("====================================================================================================\n");
}

void searchPlayer()
{
    int choice;

   printf("\n========== Search Player ==========");
    printf("\n1. Search By Jersey");
    printf("\n2. Search By Name");
    printf("\n3.back");
    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            searchByJersey();
            break;

        case 2:
            searchByName();
            break;

        case 3:
          return;
        default:
            printf("\nInvalid Choice...");
    }
}

void searchByJersey()
{
	int jerseyNo;
	int i;

	if(count==0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	do
	{
		printf("\nEnter Jersey Number : ");
		scanf("%d",&jerseyNo);

		if(jerseyNo<=0)
			printf("\nInvalid Jersey Number...\n");

	}while(jerseyNo<=0);

	for(i=0;i<count;i++)
	{
		if(p[i].jerseyNo==jerseyNo)
		{
			printf("\n========== Player Details ==========\n");

			printf("\nJersey Number : %d",p[i].jerseyNo);
			printf("\nPlayer Name   : %s",p[i].name);
			printf("\nRuns          : %d",p[i].runs);
			printf("\nWickets       : %d",p[i].wickets);
			printf("\nMatches       : %d",p[i].matches);

			if(p[i].matches==0)
				printf("\nStatus        : Not Played");
			else
				printf("\nStatus        : Played");

			return;
		}
	}

	printf("\nPlayer Not Found...\n");
}

void searchByName()
{
    char name[50];
    char temp[50];
    int i, found = 0;

    if(count == 0)
    {
        printf("\nNo Players Available...\n");
        return;
    }

    printf("\nEnter Player Name or Starting Letter : ");
    scanf(" %49[^\n]", name);

    // Convert input to lowercase
    toLower(name);

    for(i = 0; i < count; i++)
    {
        strcpy(temp, p[i].name);

        // Convert player name to lowercase
        toLower(temp);

        // Compare starting characters
        if(strncmp(temp, name, strlen(name)) == 0)
        {
            printf("\n========== Player Details ==========\n");

            printf("\nJersey Number : %d", p[i].jerseyNo);
            printf("\nPlayer Name   : %s", p[i].name);
            printf("\nRuns          : %d", p[i].runs);
            printf("\nWickets       : %d", p[i].wickets);
            printf("\nMatches       : %d", p[i].matches);

            if(p[i].matches == 0)
                printf("\nStatus        : Not Played");
            else
                printf("\nStatus        : Played");

            printf("\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nPlayer Not Found...\n");
    }
}

void updatePlayer()
{
    int jersey;
    int i, choice;
    int found = 0;
    int addRuns, addWickets, addMatches;

    if(count == 0)
    {
        printf("\nNo Players Available...\n");
        return;
    }

    // Find Valid Jersey Number
    do
    {
        found = 0;

        printf("\nEnter Jersey Number : ");
        scanf("%d",&jersey);

        if(jersey <= 0)
        {
            printf("\nInvalid Jersey Number...");
            printf("\nPlease Enter Valid Jersey Number.\n");
            continue;
        }

        for(i=0;i<count;i++)
        {
            if(p[i].jerseyNo == jersey)
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            printf("\nPlayer Not Found...");
            printf("\nPlease Enter Existing Jersey Number.\n");
        }

    }while(found == 0);

    // Show Current Details Only Once
    printf("\n=========================================");
    printf("\nCurrent Player Details");
    printf("\n=========================================");

    printf("\nJersey Number : %d",p[i].jerseyNo);
    printf("\nPlayer Name   : %s",p[i].name);
    printf("\nRuns          : %d",p[i].runs);
    printf("\nWickets       : %d",p[i].wickets);
    printf("\nMatches       : %d",p[i].matches);

    while(1)
    {
        printf("\n\n========== UPDATE MENU ==========");
        printf("\n1. Update Name");
        printf("\n2. Add Runs");
        printf("\n3. Add Wickets");
        printf("\n4. Add Matches");
        printf("\n5. Update All");
        printf("\n6. Back");

        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                while(getchar()!='\n');

                printf("\nEnter New Name : ");
                scanf("%49[^\n]",p[i].name);

                printf("\nName Updated Successfully...\n");
                break;

            case 2:

                do
                {
                    printf("\nEnter Runs To Add : ");
                    scanf("%d",&addRuns);

                    if(addRuns < 0)
                        printf("\nRuns Cannot Be Negative.\n");

                }while(addRuns < 0);

                p[i].runs += addRuns;

                printf("\nRuns Updated Successfully...\n");
                break;

            case 3:

                do
                {
                    printf("\nEnter Wickets To Add : ");
                    scanf("%d",&addWickets);

                    if(addWickets < 0)
                        printf("\nWickets Cannot Be Negative.\n");

                }while(addWickets < 0);

                p[i].wickets += addWickets;

                printf("\nWickets Updated Successfully...\n");
                break;

            case 4:

                do
                {
                    printf("\nEnter Matches To Add : ");
                    scanf("%d",&addMatches);

                    if(addMatches < 0)
                        printf("\nMatches Cannot Be Negative.\n");

                }while(addMatches < 0);

                p[i].matches += addMatches;

                printf("\nMatches Updated Successfully...\n");
                break;

            case 5:

                while(getchar()!='\n');

                printf("\nEnter New Name : ");
                scanf("%49[^\n]",p[i].name);

                do
                {
                    printf("Enter Runs To Add : ");
                    scanf("%d",&addRuns);

                    if(addRuns < 0)
                        printf("\nRuns Cannot Be Negative.\n");

                }while(addRuns < 0);

                do
                {
                    printf("Enter Wickets To Add : ");
                    scanf("%d",&addWickets);

                    if(addWickets < 0)
                        printf("\nWickets Cannot Be Negative.\n");

                }while(addWickets < 0);

                do
                {
                    printf("Enter Matches To Add : ");
                    scanf("%d",&addMatches);

                    if(addMatches < 0)
                        printf("\nMatches Cannot Be Negative.\n");

                }while(addMatches < 0);

                p[i].runs += addRuns;
                p[i].wickets += addWickets;
                p[i].matches += addMatches;

                printf("\nPlayer Updated Successfully...\n");
                break;

            case 6:
                printf("\nReturning To Main Menu...\n");
                return;

            default:
                printf("\nInvalid Choice...");
                continue;
        }

        // Updated Details
        printf("\n=========================================");
        printf("\nUpdated Player Details");
        printf("\n=========================================");

        printf("\nJersey Number : %d",p[i].jerseyNo);
        printf("\nPlayer Name   : %s",p[i].name);
        printf("\nRuns          : %d",p[i].runs);
        printf("\nWickets       : %d",p[i].wickets);
        printf("\nMatches       : %d",p[i].matches);
    }
}
void removePlayer()
{
	int jerseyNo;
	int i, j;
	char ch;

	if(count == 0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	// Jersey Number Validation
	do
	{
		printf("\nEnter Jersey Number To Remove : ");
		scanf("%d",&jerseyNo);

		if(jerseyNo <= 0)
		{
			printf("\nInvalid Jersey Number...");
			printf("\nJersey Number Must Be Greater Than 0.\n");
		}

	}while(jerseyNo <= 0);

	for(i=0; i<count; i++)
	{
		if(p[i].jerseyNo == jerseyNo)
		{
			printf("\n========== Player Details ==========\n");

			printf("\nJersey Number : %d",p[i].jerseyNo);
			printf("\nPlayer Name   : %s",p[i].name);
			printf("\nRuns          : %d",p[i].runs);
			printf("\nWickets       : %d",p[i].wickets);
			printf("\nMatches       : %d",p[i].matches);

			if(p[i].matches==0)
				printf("\nStatus        : Not Played");
			else
				printf("\nStatus        : Played");

			printf("\n\nDo You Want To Remove This Player? (Y/N) : ");
			scanf(" %c",&ch);

			if(ch=='Y' || ch=='y')
			{
				for(j=i; j<count-1; j++)
				{
					p[j] = p[j+1];
				}

				count--;

				printf("\nPlayer Removed Successfully...\n");
			}
			else
			{
				printf("\nDelete Cancelled...\n");
			}

			return;
		}
	}

	printf("\nPlayer Not Found...\n");
}

void sortPlayers()
{
	int choice;

	if(count == 0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	if(count == 1)
	{
		printf("\nOnly One Player Available. Sorting Not Required...\n");
		return;
	}

	do
	{
		printf("\n====================================");
		printf("\n         SORT PLAYERS");
		printf("\n====================================");

		printf("\n1. Sort By Maximum Runs");
		printf("\n2. Sort By Minimum Runs");
		printf("\n3. Sort By Maximum Wickets");
		printf("\n4. Sort By Minimum Wickets");
		printf("\n5. Back");

		printf("\n\nEnter Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				sortByRuns(1);
				break;

			case 2:
				sortByRuns(2);
				break;

			case 3:
				sortByWickets(1);
				break;

			case 4:
				sortByWickets(2);
				break;

			case 5:
				printf("\nReturning To Main Menu...\n");
				break;

			default:
				printf("\nInvalid Choice...");
				printf("\nPlease Enter Between 1 To 5.\n");
		}

	}while(choice != 5);
}

void sortByRuns(int choice)
{
	Player temp[MAX];
	Player t;

	int i,j;

	for(i=0;i<count;i++)
		temp[i]=p[i];

	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if((choice==1 && temp[j].runs<temp[j+1].runs) ||
			   (choice==2 && temp[j].runs>temp[j+1].runs))
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	printf("\n==========================================================================\n");
	printf("Sr\tJNo\tName\t\tRuns\tWickets\tMatches\n");
	printf("==========================================================================\n");

	for(i=0;i<count;i++)
	{
		printf("%d\t%d\t%-15s%d\t%d\t%d\n",
		i+1,
		temp[i].jerseyNo,
		temp[i].name,
		temp[i].runs,
		temp[i].wickets,
		temp[i].matches);
	}
}

void sortByWickets(int choice)
{
	Player temp[MAX];
	Player t;

	int i,j;

	for(i=0;i<count;i++)
		temp[i]=p[i];

	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if((choice==1 && temp[j].wickets<temp[j+1].wickets) ||
			   (choice==2 && temp[j].wickets>temp[j+1].wickets))
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	printf("\n==========================================================================\n");
	printf("Sr\tJNo\tName\t\tRuns\tWickets\tMatches\n");
	printf("==========================================================================\n");

	for(i=0;i<count;i++)
	{
		printf("%d\t%d\t%-15s%d\t%d\t%d\n",
		i+1,
		temp[i].jerseyNo,
		temp[i].name,
		temp[i].runs,
		temp[i].wickets,
		temp[i].matches);
	}
}

void top3Runs()
{
	Player temp[MAX];
	Player t;
	int i,j;

	if(count==0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	// Copy Original Array
	for(i=0;i<count;i++)
	{
		temp[i]=p[i];
	}

	// Bubble Sort (Descending Runs)
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(temp[j].runs < temp[j+1].runs)
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	printf("\n=====================================================================================\n");
	printf("Rank\tJNo\tName\t\tRuns\tWickets\tMatches\tStatus\n");
	printf("=====================================================================================\n");

	for(i=0;i<count && i<3;i++)
	{
		printf("%d\t%d\t%-15s%d\t%d\t%d\t\t",
		i+1,
		temp[i].jerseyNo,
		temp[i].name,
		temp[i].runs,
		temp[i].wickets,
		temp[i].matches);

		if(temp[i].matches==0)
			printf("Not Played");
		else
			printf("Played");

		printf("\n");
	}
}

void top3Wickets()
{
	Player temp[MAX];
	Player t;
	int i,j;

	if(count==0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	// Copy Original Array
	for(i=0;i<count;i++)
	{
		temp[i]=p[i];
	}

	// Bubble Sort (Descending Wickets)
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(temp[j].wickets < temp[j+1].wickets)
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	printf("\n=====================================================================================\n");
	printf("Rank\tJNo\tName\t\tRuns\tWickets\tMatches\tStatus\n");
	printf("=====================================================================================\n");

	for(i=0;i<count && i<3;i++)
	{
		printf("%d\t%d\t%-15s%d\t%d\t%d\t\t",
		i+1,
		temp[i].jerseyNo,
		temp[i].name,
		temp[i].runs,
		temp[i].wickets,
		temp[i].matches);

		if(temp[i].matches==0)
			printf("Not Played");
		else
			printf("Played");

		printf("\n");
	}
}

void playerStatistics()
{
	int i;
	int totalRuns = 0;
	int totalWickets = 0;
	int totalMatches = 0;

	float avgRuns = 0;
	float avgWickets = 0;
	float avgMatches = 0;

	int maxRuns = 0;
	int maxWickets = 0;

	char maxRunPlayer[50];
	char maxWicketPlayer[50];

	if(count==0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	maxRuns = p[0].runs;
	maxWickets = p[0].wickets;

	strcpy(maxRunPlayer,p[0].name);
	strcpy(maxWicketPlayer,p[0].name);

	for(i=0;i<count;i++)
	{
		totalRuns += p[i].runs;
		totalWickets += p[i].wickets;
		totalMatches += p[i].matches;

		if(p[i].runs > maxRuns)
		{
			maxRuns = p[i].runs;
			strcpy(maxRunPlayer,p[i].name);
		}

		if(p[i].wickets > maxWickets)
		{
			maxWickets = p[i].wickets;
			strcpy(maxWicketPlayer,p[i].name);
		}
	}

	avgRuns = (float)totalRuns/count;
	avgWickets = (float)totalWickets/count;
	avgMatches = (float)totalMatches/count;

	printf("\n===========================================");
	printf("\n        PLAYER STATISTICS");
	printf("\n===========================================");

	printf("\nTotal Players        : %d",count);
	printf("\nTotal Runs           : %d",totalRuns);
	printf("\nTotal Wickets        : %d",totalWickets);
	printf("\nTotal Matches        : %d",totalMatches);

	printf("\nAverage Runs         : %.2f",avgRuns);
	printf("\nAverage Wickets      : %.2f",avgWickets);
	printf("\nAverage Matches      : %.2f",avgMatches);

	printf("\nHighest Run Scorer   : %s",maxRunPlayer);
	printf("\nHighest Runs         : %d",maxRuns);

	printf("\nHighest Wicket Taker : %s",maxWicketPlayer);
	printf("\nHighest Wickets      : %d",maxWickets);

	printf("\n===========================================\n");
}

void filterPlayers()
{
	int choice;
	int value;
	int i;
	int flag;
	int sr;

	if(count==0)
	{
		printf("\nNo Players Available...\n");
		return;
	}

	do
	{
		flag=0;
		sr=1;

		printf("\n====================================");
		printf("\n        FILTER PLAYERS");
		printf("\n====================================");

		printf("\n1. Runs Greater Than");
		printf("\n2. Wickets Greater Than");
		printf("\n3. Matches Greater Than");
		printf("\n4. Back");

		printf("\n\nEnter Choice : ");
		scanf("%d",&choice);

		if(choice==4)
		{
			printf("\nReturning To Main Menu...\n");
			break;
		}

		if(choice<1 || choice>4)
		{
			printf("\nInvalid Choice...");
			printf("\nPlease Enter Between 1 To 4.\n");
			continue;
		}

		do
		{
			printf("\nEnter Value : ");
			scanf("%d",&value);

			if(value<0)
			{
				printf("\nValue Cannot Be Negative...\n");
			}

		}while(value<0);

		printf("\n================================================================================\n");
		printf("Sr\tJNo\tName\t\tRuns\tWickets\tMatches\n");
		printf("================================================================================\n");

		for(i=0;i<count;i++)
		{
			if((choice==1 && p[i].runs>value) ||
			   (choice==2 && p[i].wickets>value) ||
			   (choice==3 && p[i].matches>value))
			{
				printf("%d\t%d\t%-15s%d\t%d\t%d\n",
				sr++,
				p[i].jerseyNo,
				p[i].name,
				p[i].runs,
				p[i].wickets,
				p[i].matches);

				flag=1;
			}
		}

		if(flag==0)
		{
			printf("\nNo Matching Players Found...");
			printf("\nTry Another Value.\n");
		}

	}while(choice!=4);
}