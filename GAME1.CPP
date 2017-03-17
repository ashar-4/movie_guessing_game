
/*		This is a program in which the system chooses a
		random movie and the user then has to guess it		*/

#include<iostream>
#include"movie.cpp"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	char ch, opt, user[20];
	int n, i, m, slen, ctr, tri;
	time_t x, y;

	do
	{
		srand(time(&x));
		n = rand() % 169 + 1;
		slen = strlen(mov[n]);               	            //copy string length in slen
		strcpy(user, mov[n]);                			    //copy the name of the movie in user array
		for(i = 0; mov[n][i] != '\0'; ++i)					//loop to show some characters of the user array
		{
			if(i == 1 || i == 4 || i == 8 || i == 12 || user[i] == ' ')
				user[i] = mov[n][i];
			else
				user[i] = '*';
		}
		cout << "\t\tguess the name of the movie : ";
		puts(user);
		cout << "total no. of tries = 5";				    //the user has 5 tries in total in case he makes a mistake
		tri = 0;

		do
		{
			ctr=0 ;
			cout << endl << "enter any letter : ";
			cin >> ch;                               		//the user enters his choice
			for(i=0; mov[n][i] != '\0'; ++i)	   			//loop to check the presence or non-presence of the character
			{
				if(mov[n][i] == ch)
					user[i] = ch;
				else
					ctr++;
			}
			if(ctr == slen)
			{
				tri++;
				cout << "WRONG INPUT !!!!" << endl;
				cout << "no.of tries left = " << 5 - tri;
			}
			m = strcmp(mov[n], user);		                //checks whether the user has completed the game
			if(!m)							                //if the user has completed the game within 5 tries then he/she wins
			{
				cout << endl;
				puts(user);
				cout << "\t\t\tCONGRATS !!!! YOU WIN" << endl;
				break;
			}
			if(tri == 5)                                    //if the user has input 5 wrong inputs, then he/she loses
			{
				cout << endl;
				puts(user);
				cout << "\t\t\tSORRY !!!! YOU LOSE" << endl;
				cout << "\t\t\tcorrect answer : ";
				puts(mov[n]);
			}
			cout << endl;
			if(tri != 5)
				puts(user);
		}
		while(tri < 5);
		cout << "\t\t\twanna try again (y/n) : ";
		cin >> opt;
	}
	while(opt == 'y') ;
	return 0;
}
