/*
	Problem Code: MeetingPoint

	There is a girl called Maya who is a big fan of Deepika .(The heroine).
	Maya always wanted to meet her and go on a tour of cities with her.
	She has been dreaming about this from childhood.

	At last Maya got to know that, Deepika is going to tour india and she stops in several cities.
	Ie KanyaKumari->Kochi->Ooty->Mysore->Bangalore->Hyderabad->Bhopal
	At the same time even Maya is travelling with her family, 
	and her family not being much travelled before, Only knows how to travel from some cities to another.
	So Maya's family planned their trip in a different route from what Deepika is going .
	Ie Tirupati->Bhimvaram->Vijayawada->Vizag->Hyd->Bhopal 


	Maya later came to know that her route will intersect with Deepika's Route and 
	after the intersection point they are going to travel along the same route.

	Ie if Deepika Route is A->B->C->D->E->F->G->H
	Maya Route is Z->Y->E->F->G->H

	Both Maya and Deepika meet at 'E' city.And travel remaining cities F, G, H together.


	But Maya being not that into problem solving, She wants you to help to know in 
	which city she can meet her star, given the 2 routes she and Deepika are going 
	to travel and also how many cities she had to travel to meet Deepika.
	
	Can you write a program which will fulfill her dream ?


	Struct CityNode{
	Char * city[20];
	Sturct node * nextCity;
}

CityNode will have a city name and address of the next city.
Two CityNode's can have same name but will have different address.

*/

/**
Return the meeting city node if maya can meet deepika, or else NULL.
*/
#include<stdio.h>
#include<string.h>


struct CityNode{
	char city[20];
	struct CityNode * nextCity;
};

int compare(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (s1[i]!='\0' && s2[j]!='\0')
	{
		if (s1[i] != s2[j])
			return 0;
		++i;
		++j;
	}
	if (i == j)
		return 1;
	else
		return 0;
}
struct CityNode * meetingPoint(struct CityNode * deepikaStartCity, struct CityNode *mayaStartCity, int *numberOfCitiesMayaShouldTravel) {
	if (deepikaStartCity == NULL || mayaStartCity == NULL)
	{
		numberOfCitiesMayaShouldTravel = 0;
		return NULL;
	}
	CityNode *common = NULL;
	int i=0;
	CityNode *temp = deepikaStartCity;
	while (mayaStartCity != NULL)
	{
		while (deepikaStartCity != NULL)
		{
			if (compare(deepikaStartCity->city, mayaStartCity->city))
			{
				common = mayaStartCity;
				return common;
			}
			deepikaStartCity = deepikaStartCity->nextCity;
		}
		(*numberOfCitiesMayaShouldTravel)++;
		deepikaStartCity = temp;
		mayaStartCity = mayaStartCity->nextCity;
	}
	return common;
}