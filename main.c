#include <time.h>
#include <stdio.h>
#include <stdlib.h>                       /*funkcja atof()*/

void tabela(int tabela[82][10])
{
	int a=0,b=9;
	printf("_____________");
	printf("\n");
	int c=0;
	int d=81;
	for (b=0;b<3;b++)
	{
		for (a=0; a<3;a++)
		{
				printf ("|%d%d%d|%d%d%d|%d%d%d|\n", tabela[++c-8][0],tabela[++c-6][0],tabela[++c-4][0],tabela[++c-2][0],tabela[++c][0],tabela[++c+2][0],tabela[++c+4][0],tabela[++c+6][0],tabela[++c+8][0]);
				//printf ("|%d%d%d|%d%d%d|%d%d%d|\n",tabela[--d],tabela[--d],tabela[--d],tabela[--d],tabela[--d],tabela[--d],tabela[--d],tabela[--d],tabela[--d]);

		}

	printf("_____________\n");
	//a=0;
	}
}


int lok(int a)
{
	int e,h,g;
		e=a%9;

		if(e==0)h=2;
		if(e==0)h=2;
		if(e==1)h=0;
		if(e==2)h=0;
		if(e==3)h=0;
		if(e==4)h=1;
		if(e==5)h=1;
		if(e==6)h=1;
		if(e==7)h=2;
		if(e==8)h=2;

		g=a/27;
		if (a==27) g=0;
		if (a==54) g=1;
		if (a==81) g=2;
		if (g==1) h=h+3;
		if (g==2) h=h+6;
		return h;

}
	void dop (int pole [82][10],int dane[28][10])
	{
		int a=1,b=1,c=1,d=1,e,f,g,h;


			while (c<=27)
			{
				d=1;
				while (d<=9)
				{
					dane[c][d]=d;
					//printf("%d",dane[c][d]=d);
					d++;

				}
			c++;
			}
			while(a<=81)
			{
				if(pole[a][0]!=0)
				{
					//printf("%d",a);
					f=pole[a][0];

					e=(a)%9;//kolumny
					if(e==0) e=9;
					dane[9+e][f]=0;
					//printf("c%dc",dane[18][9]);
					e=a/9;
					if (a%9==0) e=e-1;
					dane[1+e][f]=0;

					h=lok(a);
					dane[19+h][f]=0;
					//printf("s%ds",h);



				}
				a++;

			}

	}


void porownaj (int pole [82][10],int dane[28][10])
{
	int a=1,b=1,c,d,e,f;
	while (a<=81)
	{


		if(pole[a][0]==0)
		{
			b=1;
			while (b<=9)
			{
				e=a/9;
				if (a%9==0) e=e-1;
				c=dane[1+e][b];
				//printf("%d",dane[1+e][b]);
				//printf("%d",e);

				e=a%9;
				//printf("%d",e);
				if(e==0) e=9;
				//printf("%d",e);
				d=dane[9+e][b];
				//printf("%d",dane[9+e][b]);
					//printf("%d",e);
				e=lok(a);
				f=dane[19+e][b];
				//printf("%d",dane[9+e][b]);
				if ((c==d)&(c==f))
				{
				//printf("%da",c);
				pole[a][b]=c;
				//printf("aa%daa",pole[54][8]);
					//if (a==5)printf("tu dobrze%d",c);
					b++;
				}
				else
				{
					pole[a][b]=0;
					b++;
				}

			}
		}
			//printf("qqqqqqqqq");
		b=1;
		a++;
	}
	//printf("qqqqqqqqq");
}
void zliczwiersze(int pole[82][10])
{
	int zlicz[11][10];
	int a=1,b=1,c=1,d=1,e,f,g,h;
	while (c<=10)
			{
				d=1;
				while (d<=9)
				{
					zlicz[c][d]=0;
					//printf("d");
					d++;

				}
			c++;
			}
			a=1;
			//printf("\nqqqssssssssd\n");
	while (a<=81)
	{
		if (pole[a][0]==0)
		{
			//printf("ea%dae",a);
			e=a/9;
			if (a%9==0) e=e-1;
			//printf("%d",pole[a][1]);
			//if (e==0)printf("tu dobrze%d",a);
			b=1;
			while (b<=9)
			{	//printf("%dc",pole[a][b]);
				if (pole[a][b]==b)  zlicz[1+e][b]=zlicz[1+e][b]+1;
				//printf("a%db%dz%d ",a,b,zlicz[1+e][b]);
				b++;

			}
		}
		//b=1;
		//printf("\n");
		a++;
	}

	c=1;
	while (c<=27)
			{
				d=1;
				while (d<=9)
				{
					//zlicz[c][d]=0;
				//printf("a%da",zlicz[c][d]);
					d++;

				}
			c++;
			}

	//printf("tu dobrze%d",zlicz[1][5]);
	b=1;
	c=1;
	d=1;





	e=1;

	while(e<9)
	{
		b=1;
		while (b<=9)
	{
		if (zlicz[e][b]==1)
		{
			//printf("\n%da%d",e,b);
			h=1;
			while(h<=81)
			{
				d=h/9;
				if (h%9==0) d=d-1;
				if ((d+1)==e)
				{
					if (pole[h][0]==0)
					{
						if( pole[h][b]==b)
						{
							pole[h][0]=b;
							//	printf("\ntutajwiersz%daa%d\n",h,b);
						}
					}
				}
				h++;
			}
			b++;
		}

		else b++;

	}
	e++;
	}








}

void zliczkolumny( int pole[82][10])
{
	int zlicz[11][10];
	int a=1,b=1,c=1,d,e,f,g,h;
	while (c<=10)
			{
				d=1;
				while (d<=9)
				{
					zlicz[c][d]=0;
					//printf("%d",dane[c][d]=d);
					d++;

				}
			c++;
			}
			a=1;


	h=1;
	while (h<=81)
	{
		if (pole[h][0]==0)
		{
			e=h%9;
			if (e==0)e=9;
			b=1;
			//printf("qa%daq",e);
			while(b<=9)
			{
				if(pole[h][b]==b) zlicz[e][b]++;
				//printf("a%db%dz%d ",h,b,zlicz[e][b]);
				b++;
			}
		//printf("\n");
		}
		h++;
	}




	c=1;
	while (c<=9)
			{
				d=1;
				while (d<=9)
				{
					//zlicz[c][d]=0;
					//printf("a%da",zlicz[c][d]);
					d++;

				}
			c++;
			}



	b=1;
	c=1;
	d=1;





	e=1;
	while(e<=9)
	{
		b=1;
		while (b<=9)
	{
		if (zlicz[e][b]==1)
		{
			h=1;
			while(h<=81)
			{
				d=h%9;
				if (d==0)d=9;
				if (d==e)
				{
					if (pole[h][0]==0)
					{
						if( pole[h][b]==b)
						{
							pole[h][0]=b;
							//	printf("\ntutajkolumna%daa%d\n",h,b);
						}
					}
				}
				h++;
			}
			b++;
		}

		else b++;

	}
	e++;
	}








}
void zliczzbiory (int zlicz[28][10], int pole[82][10])
{
	int a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1;
	while (c<=27)
			{
				d=1;
				while (d<=9)
				{
					zlicz[c][d]=0;
					//printf("%d",dane[c][d]=d);
					d++;

				}
			c++;
			}

	while (h<=81)
	{
		if (pole[h][0]==0)
		{
			e=lok(h);
			b=1;
			//printf("qa%daq",e);
			while(b<=9)
			{
				if(pole[h][b]==b) zlicz[e][b]++;
				b++;
			}

		}
		h++;
	}
	b=1;
	e=0;


	while(e<9)
	{
		b=1;
		while (b<=9)
	{
		if (zlicz[e][b]==1)
		{
			h=1;
			while(h<=81)
			{
				d=lok(h);
				if (d==e)
				{
					if (pole[h][0]==0)
					{
						if( pole[h][b]==b)
						{
							pole[h][0]=b;
							//	printf("\ntutajzbior%d\n",h);
						}
					}
				}
				h++;
			}
			b++;
		}

		else b++;

	}
	e++;
	}


}

int oczywiste (int pole[82][10],int dane[28][10],int zlicz[28][10])
{
	static int a=1;
	int c=1;
	//printf("%d",a);
	dop(pole,dane);
	porownaj(pole,dane);
	zliczkolumny(pole);
	dop(pole,dane);
	porownaj(pole,dane);
	zliczzbiory(zlicz,pole);
	dop(pole,dane);
	porownaj(pole,dane);
	zliczwiersze(pole);
	while (a<=81)
	{
		if (pole[a][0]==0)
		{
		a++;
		//c++;
		return oczywiste (pole,dane,zlicz);
		//break;
		}
		else a++;

	}
	a=1;
	while (a<=81)
	{
		if (pole[a][0]==0)
		{
		a++;
		c++;
		break;
		}
		else a++;

	}
	a=1;
	return c;

}

int zagadka (int pole[82][10],int dane[28][10],int zlicz[28][10])
{
	int t[82];
	int pom [82][10];
	 int a=1;
	 int c=1,p=1,r=1,g=81;
	int b=1;
	int e=1;

	int i, zarodek;
    time_t tt;
    zarodek = time(&tt);
    srand(zarodek);
    a=1;
   // printf("\n%d  %d %d   %d\n",rand()%4+1,rand()%4+1,rand()%4+1,rand()%4+1);
    while(a<=81)
	{
		pom[a][0]=pole[a][0];
		t[a]=0;
		a++;
	}
    a=1;
    //tabela(pom);
	//printf("aaaaaddddddassss%d\n",a);
	while(a<=81)
	{	//printf("aaaaaddddddassss%d\n",a);
	//tabela(pom);
		r=1;
		dop(pom,dane);
		porownaj (pom,dane);
		//zliczkolumny (pom);
		//zliczwiersze (pom);
		if (pom[a][0]==0)
		{//	printf("aaaaaddddddassss%d\n",a);
			b=1;
			while (b<=9) t[b++]=0;
			b=1;
			while (b<=9)
			{
				//repozytoria kodu
				//subversion, git

				if (pom[a][b]==b)
				{
				//	printf("%daaaaaddddddassss%d\n",a,b);
					t[r]=b;
					r++;
				}
				b++	;
			}
			g=(rand()%r);
			if (g==0) g=r;
		//	printf ("%d  %d\n",t[g],a);
			pom[a][0]=t[g];

			oczywiste(pom,dane,zlicz);
		}
		//oczywiste(pom,dane,zlicz);
		a++;
	}
	//tabela (pom);
		g=1;
		c=1;
		while (g<=81)
		{
			if (pom[g][0]==0)
			{
			g++;
			c++;
			break;
			}
			else g++;
		}
		if (c==1)
		{
		a=1;
   			// printf("\n%d  %d %d   %d\n",rand()%4+1,rand()%4+1,rand()%4+1,rand()%4+1);
    		while(a<=81)
			{
			pole[a][0]=pom[a][0];
			a++;

			}

			return 0;
		}
	if (c==2) return zagadka(pole,dane, zlicz);
}


int main ()
{
	int pole[82][10];

    int a;
	for (a=0; a<=81; a++) pole[a][0]=0;
	/*pole[3][0]=1;
	pole[4][0]=8;
	pole[7][0]=9;
	pole[10][0]=5;
	pole[12][0]=9;
	pole[14][0]=1;
	pole[18][0]=4;
	pole[20][0]=4;
	pole[24][0]=5;
	pole[33][0]=2;
	pole[35][0]=3;
	pole[40][0]=3;
	pole[43][0]=5;
	pole[45][0]=8;
	pole[46][0]=9;
	pole[50][0]=6;
	pole[52][0]=1;
	pole[53][0]=4;
	pole[55][0]=1;
	pole[58][0]=6;
	pole[66][0]=2;
	pole[67][0]=9;
	pole[70][0]=4;
	pole[72][0]=5;
	pole[79][0]=8;
	pole[80][0]=2;*/

	/*pole[11][0]=1;
	pole[12][0]=8;
	pole[13][0]=9;
	pole[14][0]=5;
	pole[16][0]=3;
	pole[17][0]=2;
	pole[18][0]=7;
	pole[10][0]=4;*/

	/*pole[2][0]=4;
	pole[11][0]=6;
	pole[20][0]=8;
	//pole[29][0]=;
	pole[38][0]=1;
	pole[47][0]=3;
	pole[56][0]=5;
	pole[65][0]=9;
	pole[74][0]=2;*/

	/*pole[31][0]=1;
	pole[32][0]=3;
	pole[33][0]=6;
	pole[40][0]=9;
	pole[42][0]=2;
	pole[49][0]=4;
	pole[50][0]=7;
	pole[51][0]=8;*/

	/*pole[4][0]=9;
	pole[6][0]=2;
	pole[10][0]=4;
	pole[14][0]=5;
	pole[15][0]=3;
	pole[16][0]=7;
	pole[17][0]=6;
	pole[19][0]=1;
	pole[20][0]=2;
	pole[21][0]=7;
	pole[22][0]=4;
	pole[23][0]=8;
	pole[26][0]=9;
	pole[28][0]=3;
	pole[29][0]=4;
	pole[30][0]=1;
	pole[31][0]=8;
	pole[34][0]=6;
	pole[39][0]=9;
	pole[40][0]=6;
	pole[45][0]=1;
	pole[46][0]=2;
	pole[47][0]=7;
	pole[48][0]=6;
	pole[49][0]=3;
	pole[50][0]=1;
	pole[51][0]=4;
	pole[53][0]=5;
	pole[55][0]=9;
	pole[57][0]=5;
	pole[60][0]=1;
	pole[62][0]=8;
	pole[63][0]=6;
	pole[77][0]=3;
	pole[79][0]=4;
	pole[81][0]=9;*/

/*
	pole[7][0]=3;
	pole[11][0]=1;
	pole[13][0]=8;
	pole[14][0]=2;
	pole[17][0]=6;
	pole[18][0]=4;
	pole[19][0]=5;
	pole[21][0]=8;
	pole[25][0]=9;
	pole[28][0]=3;
	pole[34][0]=6;
	pole[39][0]=1;
	pole[40][0]=5;
	pole[42][0]=9;
	pole[43][0]=2;
	pole[48][0]=2;
	pole[54][0]=7;
	pole[57][0]=9;
	pole[61][0]=7;
	pole[63][0]=2;
	pole[64][0]=6;
	pole[65][0]=2;
	pole[68][0]=4;
	pole[69][0]=1;
	pole[71][0]=5;
	pole[75][0]=5;*/



	tabela(pole);
	 int dane[28][10];
	 int zlicz[28][10];

	printf ("\n");
	int q=1;


	oczywiste(pole,dane,zlicz);
	printf("\n");
	tabela (pole);

	zagadka(pole,dane,zlicz);

	tabela(pole);



	return 0;
}


