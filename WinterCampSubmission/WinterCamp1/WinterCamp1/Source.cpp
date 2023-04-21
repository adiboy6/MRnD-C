#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<specstrings.h>

typedef struct marks {
	int roll;
	char name[20];
	int m1, m2, m3, m4;
	float avg, cgpa;
}marks;

typedef struct info
{
	int r;
	char phno[10];
	char addr[100];
	char city[30];
	char pin[15];
}info;

typedef struct global_info {
	info **obj1 = (info **)malloc(sizeof(info *) * 10);
	int itotal = 0;
} global_info;

typedef struct global_marks {
	marks **obj = (marks **)malloc(sizeof(marks *) * 10);
	int  total = 0, re = 0, fl = 0, cfl = 0,q=0,qn;
}global_marks;

typedef struct global {
	int op, so,count=0;
	char flag = NULL;
	char str[100], queries[100], key[100], value[100], cmd[3][100] = {"SELECT","*FROM","FROM"};
}global;

typedef struct hash {
	hash * next = NULL;
	char *key, *value;
}hash;

typedef struct token {
	int tot=0;
	char **str = (char **)malloc(1*sizeof(char *));
}token;

token t;
global_marks m;
global_info in;
global g;
hash *temp, *hobj[16];

void iload()
{
	FILE *fp;
	char s[100] = "C:\\Users\\adity\\Desktop\\Winter Camp\\";
	strcat(s, g.str);
	fp = fopen(s, "r");
	char c,head[50];
	fgets(head, 50, fp);
	int i = 0,l,j=0,flag=0,k=in.itotal,flag1=0,option;
	in.itotal = 0;
	while ((c = getc(fp)) != EOF)
	{
		if (c == ',')
		{
			for (l = 0; l <k && i == 0 && (flag1==0||flag1==2); l++)
			{
				if ((in.obj1)[k]->r == (in.obj1)[l]->r)
				{
					if (flag1 == 0)
					{
						printf("Duplicates found.\n1.Update\n2.Drop\n");
						scanf("%d", &option);
						switch (option)
						{
						case 1:
							flag1 = 1;
							break;
						case 2:
							flag1 = 2;
							break;
						default:
							break;
						}
					}
					--k;
					continue;
				}
			}
			if (i == 1)
			{
				(in.obj1)[k]->phno[--j] = '\0';
				j = 0;
			}
			if (i == 2)
			{
				in.obj1[k]->addr[j] = '\0';
				j = 0;
			}
			if (i == 3)
			{
				in.obj1[k]->city[j] = '\0';
				j = 0;
			}
			++i;
			continue;
		}
		if (c == '\n')
		{
			if (i == 4)
			{
				in.obj1[k]->pin[j] = '\0';
				j = 0;
			}
		}
		if (c == '\n' || flag == 0)
		{
			if (c == '\n')
			{
				i = 0;
				++k;
				flag = 0;
			}
			if (k % 10 == 9)
				(in.obj1) = (info **)realloc(in.obj1, sizeof(info*)*(k + 10));
			(in.obj1)[k] = (info *)malloc(sizeof(info));
			if (flag == 0)
			{
				(in.obj1)[k]->r = 0;
				flag = 1;
			}
		}
		if (c >= '0'&&c <= '9' && i == 0 )
		{
			if (i == 0)
				(in.obj1)[k]->r = (in.obj1)[k]->r * 10 + c - '0';
		}
		if (i > 0)
		{
			if( i == 1)
				(in.obj1)[k]->phno[j++] = c;
			if (i == 2)
				(in.obj1)[k]->addr[j++] = c;
			if (i == 3)
				(in.obj1)[k]->city[j++] = c;
			if (i == 4)
				(in.obj1)[k]->pin[j++] = c;
		}
	}
	in.itotal=in.itotal+k;
	fclose(fp);
}

void load()
{
	FILE *fp;
	char s[100]= "C:\\Users\\adity\\Desktop\\Winter Camp\\";
	strcat(s, g.str);
	fp = fopen(s,"r");
	int j = 0, i = 0, k = m.total,l,flag1=0,option;
	m.total = 0;
	char c, head[100];
	fgets(head, 100, fp);
	int flag = 0, count = 0, num = 0;
		while ((c = getc(fp)) != EOF)
		{
			if (c == ',')
			{
				if (i == 1)
				{
					(m.obj)[k]->name[j] = '\0';
					j = 0;
				}
				for (l = 0; l <k && i==0 && (flag1==0||flag1==2); l++)
				{
					if ((m.obj)[k]->roll == (m.obj)[l]->roll)
					{
						if (flag1 == 0)
						{
							printf("Duplicates found.\n1.Update\n2.Drop\n");
							scanf("%d", &option);
							switch (option)
							{
							case 1:
								printf("%d", m.obj[k]->roll);
								k = 1;
								(m.obj)[k-1]->m1 = 0, (m.obj)[k-1]->m2 = 0, (m.obj)[k-1]->m3 = 0, (m.obj)[k-1]->m4 = 0;
								m.obj[k-1]->name[0] = '\0';
								flag1 = 1;
								break;
							case 2:
								flag1 = 2;
								break;
							default:
								break;
							}
						}
						--k;
						continue;
					}
				}
				++i;
				continue;
			}
			if (c == '\n' || flag == 0)
			{
				if (c == '\n')
				{
					i = 0;
					++k;
				}
				if (k % 10 == 9)
					m.obj = (marks **)realloc(m.obj,sizeof(marks*)*(k+10));
				(m.obj)[k] = (marks *)malloc(sizeof(marks));
				(m.obj)[k]->roll = 0, (m.obj)[k]->m1 = 0, (m.obj)[k]->m2 = 0, (m.obj)[k]->m3 = 0, (m.obj)[k]->m4 = 0;
				if (flag == 0)
				{
					(m.obj)[k]->roll = 0;
					flag = 1;
				}
			}
			if (c >= '0'&&c <= '9' && (i == 0 || i == 2 || i == 3 || i == 4 || i == 5))
			{
				if (i == 0)
					(m.obj)[k]->roll = (m.obj)[k]->roll * 10 + c - '0';
				if (i == 2)
					(m.obj)[k]->m1 = (m.obj)[k]->m1 * 10 + c - '0';
				if (i == 3)
					(m.obj)[k]->m2 = (m.obj)[k]->m2 * 10 + c - '0';
				if (i == 4)
					(m.obj)[k]->m3 = (m.obj)[k]->m3 * 10 + c - '0';
				if (i == 5)
					(m.obj)[k]->m4 = (m.obj)[k]->m4 * 10 + c - '0';
			}
			if ((c >= 'a' || c >= 'A') && (c <= 'z' || c <= 'Z') && i == 1)
				(m.obj)[k]->name[j++] = c;
		}
		m.total =m.total+ k;
		fclose(fp);
}

void ishow()
{
	int i = 0;
	printf("RollNo\tPhone No\tAddress\t\t\t\tCity\t\tPincode\n");
	for (i = 0; i < in.itotal; i++)
	{
		if (i%10 <10)
		{
			printf("%d\t", (in.obj1)[i]->r);
			printf("%s\t", (in.obj1)[i]->phno);
			printf("%s\t\t", (in.obj1)[i]->addr);
			printf("%s\t", (in.obj1)[i]->city);
			printf("%s\t", (in.obj1)[i]->pin);
			printf("\n\n");
		}
		if (i%10 == 9)
		{
			while (1)
			{
				printf("Press enter key...\n");
				if (_getch() == '\r')
				{
					system("cls");
					printf("RollNo\tPhone No\tAddress\t\t\t\tCity\t\tPincode\n");
					break;
				}
			}
		}
	}
	printf("Press enter to exit..");
	_getch();
}

void show()
{
	int i = 0;
	FILE *fp;
	printf("RollNo\tName\t\tM1\tM2\tM3\tM4\t");
	if (m.fl > 0)
		printf("Average\t");
	if (m.cfl > 0)
		printf("CGPA\t");
	printf("\n");
	for (i = 0; i < m.total; i++)
	{
		printf("\n");
		if (i % 10 < 10)
		{
			printf("%d\t", (m.obj)[i]->roll);
			printf("%s\t\t", (m.obj)[i]->name);
			printf("%d\t", (m.obj)[i]->m1);
			printf("%d\t", (m.obj)[i]->m2);
			printf("%d\t", (m.obj)[i]->m3);
			printf("%d\t", (m.obj)[i]->m4);
			if (m.fl>0)
			{
				if (m.fl > i)
					printf("%.2f	", (m.obj)[i]->avg);
				else
					printf("NA\t");
			}
			if (m.cfl>0)
			{
				if (m.cfl > i)
					printf("%.2f	", (m.obj)[i]->cgpa);
				else
					printf("NA\t");
			}
			printf("\n");
		}
		if (i % 10 == 9)
		{
			while (1)
			{
				printf("Press enter key...\n");
				if (_getch() == '\r')
				{
					system("cls");
					printf("RollNo\tName\t\tM1\tM2\tM3\tM4\t");
					if (m.fl != 0)
						printf("Average\t");
					if (m.cfl != 0)
						printf("CGPA\t");
					printf("\n");
					break;
				}
			}
		}
	}
	printf("Press enter to exit..");
	_getch();
}

void avg()
{
	g.flag = 'a';
	int i;
	if (m.fl == m.total)
	{
		printf("Lines over\n");
		printf("Press enter to exit..\n");
		_getch();
		return;
	}
	m.fl += 1;
	for (i = 0; i < m.fl; i++)
			(m.obj)[i]->avg = (float)((m.obj)[i]->m1 + (m.obj)[i]->m2 + (m.obj)[i]->m3 + (m.obj)[i]->m4) / 4;
}

int grade(int n)
{
	if (n > 90)
		return 10;
	else if (n < 90 && n >= 80)
		return 9;
	else if (n < 80 && n >= 70)
		return 8;
	else if (n < 70 && n >= 60)
		return 7;
	else if (n < 60 && n >= 50)
		return 6;
	else if (n < 50 && n >= 60)
		return 5;
	else
		return 0;
}

void cgpa()
{
	g.flag = 'c';
	if (m.cfl == m.total)
	{
		printf("Lines over\n");
		printf("Press enter to exit..\n");
		_getch();
		return;
	}
	m.cfl += 1;
	for (int i = 0; i < m.cfl; i++)
		(m.obj)[i]->cgpa =(float) (grade((m.obj)[i]->m1) + grade((m.obj)[i]->m2) + grade((m.obj)[i]->m3) + grade((m.obj)[i]->m4))/4;
}

void save()
{
	FILE *fp;
	fp = fopen(g.str, "w");
	fprintf(fp, "RollNo,Name,M1,M2,M3,M4\n");
	for (int i = 0; i < m.total; i++)
	{
		fprintf(fp,"%d",(m.obj)[i]->roll);
		fprintf(fp, ",%s", (m.obj)[i]->name);
		fprintf(fp, ",%d", (m.obj)[i]->m1);
		fprintf(fp, ",%d", (m.obj)[i]->m2);
		fprintf(fp, ",%d", (m.obj)[i]->m3);
		fprintf(fp, ",%d", (m.obj)[i]->m4);
		if (g.flag == 'a')
			fprintf(fp, ",%0.2f", (m.obj)[i]->avg);
		if (g.flag == 'c')
			fprintf(fp, ",%0.2f", (m.obj)[i]->cgpa);
		putc('\n', fp);
	}
	fclose(fp);
}

void isave()
{
	FILE *fp;
	fp = fopen(g.str, "w");
	fprintf(fp, "RollNo,PhoneNo,Address,City,Pincode\n");
	for (int i = 0; i < in.itotal; i++)
	{
		fprintf(fp, "%d", (in.obj1)[i]->r);
		fprintf(fp, ",%s", (in.obj1)[i]->phno);
		fprintf(fp, ",%s", (in.obj1)[i]->addr);
		fprintf(fp, ",%s", (in.obj1)[i]->city);
		fprintf(fp, ",%s", (in.obj1)[i]->pin);
		putc('\n', fp);
	}
	fclose(fp);
}

void join()
{
	int i,j,flag;
	system("cls");
	printf("RollNo\tName\t\tM1\tM2\tM3\tM4\t");
	if (m.fl > 0)
		printf("Average\t\t");
	if (m.cfl > 0)
		printf("CGPA\t\t");
	printf("Phone No\tAddress\t\t\tCity\t\tPincode\n");
	printf("\n");
	for (i = 0; i <m.total-1;i++)
	{
		if (i % 10 < 10)
		{
			flag = 0;
			for ( j = 0; j < in.itotal; j++)
			{
				if ((m.obj)[i]->roll == (in.obj1)[j]->r)
				{
					printf("%d\t%s\t\t%d\t%d\t%d\t%d\t", (m.obj)[i]->roll, (m.obj)[i]->name, (m.obj)[i]->m1, (m.obj)[i]->m2, (m.obj)[i]->m3, (m.obj)[i]->m4);
					if (m.fl>0)
					{
						if (m.fl >= i)
							printf("%.2f\t\t", (m.obj)[i]->avg);
						else
							printf("NA\t\t");
					}
					if (m.cfl>0)
					{
						if (m.cfl > i)
							printf("%.2f\t\t", (m.obj)[i]->cgpa);
						else
							printf("NA\t\t");
					}
					printf("%s\t%s\t\t%s\t%s", (in.obj1)[j]->phno, (in.obj1)[j]->addr, (in.obj1)[j]->city, (in.obj1)[j]->pin);
					printf("\n\n");
					flag = 1;
				}
				
			}
			if (flag == 0)
				printf("%d\t%s\t\t%d\t%d\t%d\t%d\tNA\t\tNA\t\t\tNA\t\tNA\n\n", (m.obj)[i]->roll, (m.obj)[i]->name, (m.obj)[i]->m1, (m.obj)[i]->m2, (m.obj)[i]->m3, (m.obj)[i]->m4);
		}
		if(i%10==9)
		{
			while (1)
			{
				printf("Press enter key...\n");
				if (_getch() == '\r')
				{
					system("cls");
					printf("RollNo\tName\t\tM1\tM2\tM3\tM4\tPhone No\tAddress\t\t\tCity\t\tPincode\n");
					break;
				}
			}
		}
	}
	printf("Press enter to exit..");
	_getch();
}

void strtok()
{
	char str[100];
	int i = 0,j=0,k=0,l=0;
	t.str[t.tot] = (char *)malloc(sizeof(char *) * 1);
	while (g.queries[i] != '\0')
	{
		if (g.queries[i] ==' ' || g.queries[i] == '\n')
		{
			t.str[t.tot][j] = '\0';
			if(g.queries[i] != '\n')
				t.str[++t.tot] = (char *)malloc(sizeof(char *) * 1);
			if (g.queries[i + 1] != '\0')
				++i;
			if (g.queries[i + 1] == '\0')
			{
				++t.tot;
				break;
			}j = 0;
		}
		t.str[t.tot][j++] = g.queries[i++];
	}
}

int strtoascii(char *s)
{
	int num = 0, i = 0;
	while (s[i] != '\0')
		num += (int)s[i++];
	return num;
}

int hashfunc(char *s)
{
	return strtoascii(s) % 16;
}

void hash_put()
{
	int key = hashfunc(g.key);
	temp = hobj[key];
	if (hobj[key] == NULL)
	{
		hobj[key] = (hash *)malloc(sizeof(hash));
		temp = hobj[key];
		temp->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = (hash *)malloc(sizeof(hash));
		temp = temp->next;
	}
	temp->key = (char *)malloc(sizeof(char) * 30);
	strcpy(temp->key, g.key);
	temp->next = NULL;
}

void find(char *s)
{
	while (hobj[hashfunc(s)] !=NULL)
	{
		++g.count;
	//	if(_getch()=='\r')
			hobj[hashfunc(s)] = hobj[hashfunc(s)]->next;
	}
}

void query()
{
	strtok();
	int i;
	for (i = 0; i < t.tot; i++)
		find(t.str[i]);
	if (g.count != 0)
	{
		strcpy(g.str,t.str[i - 1]);
		load();
		system("cls");
		show();
	}
}

void main()
{
	for (int i = 0; i < 3; i++)
	{
		strcpy(g.key, g.cmd[i]);
		hash_put();
	}
	while (1)
	{
		printf("1.Load\n2.Show\n3.Average\n4.CGPA\n5.Save\n6.Join\n7.Queries\n8.Exit\n");
		scanf("%d", &(g.op));
		switch (g.op)
		{
		case 1:
			printf("1.Marks\n2.Info\n");
			scanf("%d", &(g.so));
				switch (g.so)
				{
				case 1:
					printf("Enter the file name:\n");
					scanf("%s",g.str);
					load();
					break;
				case 2:
					printf("Enter the file name:\n");
					scanf("%s", g.str);
					iload();
					break;
				default:
					break;
				}
			break;
		case 2:
				printf("1.Marks\n2.Info\n");
				scanf("%d", &(g.so));
				switch (g.so)
				{
				case 1:
					system("cls");
					show();
					break;
				case 2:
					system("cls");
					ishow();
					break;
				default:
					break;
				}
			break;
		case 3:
			avg();
			break;
		case 4:
			cgpa();
			break;
		case 5:
			printf("1.Marks\n2.Info\n");
			scanf("%d", &(g.so));
			switch (g.so)
			{
			case 1:
				printf("Enter the file name:\n");
				scanf("%s", g.str);
				save();
				break;
			case 2:
				printf("Enter the file name:\n");
				scanf("%s", g.str);
				isave();
				break;
			default:
				break;
			}
			break;
		case 6:
			join();
			break;
		case 7:
			printf("enter your query");
			fgets(g.queries, 100, stdin);
			fflush(stdin);
			fgets(g.queries, 100, stdin);
			query();
			break;
		case 8:
			exit(0);
	
		default:
			break;
		}
		system("cls");
	}
}