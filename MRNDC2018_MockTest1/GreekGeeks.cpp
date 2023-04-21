/*
Problem Code : GREEK_GEEKS

	There lived 2 mathematicians named Alice and Bob, they love geometry so they went for a walk on x-axis.
	When they are on a coordinate (xi , 0) on x-axis they can observe a star which is straight up at 90 degrees 
	at some point (xi , INFINITY).

	There exists excatly 1-star for each ( xi , 0 ) except for a point ( p , 0) it has 0-stars. 
	
	Now Alice and Bob are started their journey and they count the stars along the path which they go.
	Alice starts his journey from start1 and ends at end1 [ representing (start1,0) and (end1,0) ]
	Bob   starts his journey from start2 and ends at end2 [ representing (start2,0) and (end2,0) ]

	They wanted to know how many stars they both counted in "COMMON",so they approached you for your help.

	given the integers start1,end1,start2,end2 and p.
	You need to return the number of stars they counted in common. 
	 
	Example : Alice [1 3], Bob [6 10] , p = 4 
	Result  : 0 [Reason : No common stars counted]

	Example : Alice [3 1] Bob [10 2] , p = 10
	Result  : 2 [Reason : at (2,0) and (3,0) ]

	Example : Alice [1 5] Bob [5 6] , p = 5
	Result  : 0 [Reason : at (5,0) there is no star ]  
*/


long long countCommonStars(long long start1, long long end1,long long start2, long long end2,long long p){
	int temp;
	long long res = 0;
	if (start1 > end1)
	{
		temp = end1;
		end1 = start1;
		start1 = temp;
	}
	if (start2 > end2)
	{
		temp = end2;
		end2 = start2;
		start2 = temp;
	}
	if (start2 > start1&&start2 < end1)
	{
		if (end2 < end1)
		{
			while (start2 <= end2)
			{
				if (start2 == p)
					--res;
				else
					++res;
				++start2;
			}
		}
		else
		{
			while (start2 <= end1)
			{
				if (start2 == p)
					--res;
				else
					++res;
				++start2;
			}
		}
		return res;
	}
	else if (start1 > start2&&start1 < end2)
	{
		if (end1 < end2)
		{
			while (start1 <= end1)
			{
				if (start1 == p)
					--res;
				else
					++res;
				++start1;
			}
		}
		else
		{
			while (start2 <= end2)
			{
				if (start1 == p)
					--res;
				else
					++res;
				++start1;
			}
		}
		return res;
	}
	else
		return res;
}