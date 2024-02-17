#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/print_board.h"
#include "util/scrabble.h"

    int main()
    {int N,x,y,d,punctaj[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int scor1[26]={0},scor2[26]={0},indice,s1=0,s2=0,valword,bonus=1;
    int ok=0,len,contor=0,gasit=0,i1,j1,s2_nou=0,i_nou,j_nou, max=0,dir=0;
    char game_board[15][15],s[5],v[50],*c,*word, xx[6],yy[6],*aparx,*apary,litera;
    char nr_task[25],w[50][50]={},*cuvant_nou, *cuv_final;
    for(int i=0;i<15;i++)//initializam matricea cu punct
             for(int j=0;j<15;j++)
                game_board[i][j]='.';
    fgets(nr_task, sizeof(nr_task), stdin);//citim numarul task-ului sub forma de caracter
    switch(atoi(nr_task))//transformam caracterul in intreg
    {case 0:
        
        print_board(game_board);//tiparire matrice
     break;
        
    case 1:
    
        fgets(s, sizeof(s), stdin);//citire si prelucrare date de intrare
        if (s[strlen(s) - 1] == '\n')   
            s[strlen(s) - 1] = '\0';
        N=atoi(s);
        for(int k=1;k<=N;k++)//citire linie cu linie a datelor de intrare
            { 
            fgets(v, sizeof(v), stdin);
            if (v[strlen(v) - 1] == '\n')   
                v[strlen(v) - 1] = '\0';
            c = strtok(v, " ");
            y=atoi(c);
            c = strtok(NULL, " ");
            x=atoi(c);
            c = strtok(NULL, " ");
            d=atoi(c);
            c = strtok(NULL, " ");
            word=c;
            
            if (d == 0)//introducere cuvinte in matrice pe orizontala
            {
                int z;
                for(z = 0; word[z] != '\0'; z++)
                {
                    game_board[y][x] = word[z];
                    x++;
                }
            }
            if (d == 1)//introducere cuvinte in matrice pe verticala
            {
                int z;
                for(z = 0; word[z] != '\0'; z++)
                {
                    game_board[y][x] = word[z];
                    y++;
                }
            }
            }
            print_board(game_board);
    break;
        
        
    case 2:
    
        fgets(s, sizeof(s), stdin);//citire si prelucrare date de intrare
        if (s[strlen(s) - 1] == '\n')   
            s[strlen(s) - 1] = '\0';
        N=atoi(s);
        for(int i=0;i<N;i++)
        { 
            fgets(v, sizeof(v), stdin);
            if (v[strlen(v) - 1] == '\n')   
                v[strlen(v) - 1] = '\0';
            c = strtok(v, " ");
            y=atoi(c);
            c = strtok(NULL, " ");
            x=atoi(c);
            c = strtok(NULL, " ");
            d=atoi(c);
            c = strtok(NULL, " ");
            word=c;
             
        
            if(i%2==0)
                for(long unsigned int j=0;j<strlen(word);j++)//calcul punctaj pe cuvant jucator 1
                    {indice=word[j]-'A';
                    scor1[indice]=scor1[indice]+punctaj[indice];
                    }
            else
                for(long unsigned int j=0;j<strlen(word);j++)//calcul punctaj pe cuvant jucator 2
                    {indice=word[j]-'A';
                    scor2[indice]=scor2[indice]+punctaj[indice];
                    }
            }
        
            for(int i=0;i<26;i++)//calcul punctaj jucator 1
            s1=s1+scor1[i];
            printf("Player 1: %d Points\n",s1);//afisare punctaj jucator 1

            for(int i=0;i<26;i++)//calcul punctaj jucator 2
            s2=s2+scor2[i];
            printf("Player 2: %d Points\n",s2);//afisare punctaj jucator 2

    
    break;
    
    
    case 3:
    
        fgets(xx, 4, stdin);//citire si prelucrare date de intrare
        if (xx[strlen(xx) - 1] == '\n')   
            xx[strlen(xx) - 1] = '\0';
        fgets(yy, 4, stdin);
        if (yy[strlen(yy) - 1] == '\n')   
            yy[strlen(yy) - 1] = '\0';
        fgets(s, 4, stdin);
        if (s[strlen(s) - 1] == '\n')  
            s[strlen(s) - 1] = '\0';
        N=atoi(s);
        for(int k=1;k<=N;k++)
            { 
            fgets(v, 25, stdin);
            if (v[strlen(v) - 1] == '\n')   
                v[strlen(v) - 1] = '\0';

            c = strtok(v, " ");
            x=atoi(c);
            c = strtok(NULL, " ");
            y=atoi(c);
            c = strtok(NULL, " ");
            d=atoi(c);
            c = strtok(NULL, " ");
            word=c;
            valword=0;
            bonus = 1;
            for(long unsigned int j=0;j<strlen(word);j++)//calcul punctaj pe cuvant
                {
                    indice=word[j]-'A';
                    valword=valword+punctaj[indice];
                }
        
            aparx=strstr(word,xx);//cautare substring xx in cuvant
            apary=strstr(word,yy);//cautare substring YY in cuvant
            if ((aparx!=NULL) || (apary!=NULL)) // daca XX sau YY apar in cuvant se calculeaza bonusul pentru cuvant
                {
                if (d==0)
                    {
                    for(long unsigned int z = 0; z < strlen(word); z++)//calcul bonus cuvant pe orizontala
                        {
                            if ((bonus_board[x][y+z]==1) && (aparx!=NULL))
                                bonus=bonus*2;
                            else
                                {    
                                if ((bonus_board[x][y+z]==2) && (apary!=NULL) && ((word[strlen(word)-2]==yy[0]) && (word[strlen(word)-1]==yy[1])))
                                    bonus=bonus*3;
                                }
                        }
                        if (k%2!=0) //adaugare punctaj(+bonus) la scor pentru fiecare jucator
                            s1= s1 + valword*bonus;
                        else
                            s2= s2 + valword*bonus;
                    }     
                else
                    {
                    for(long unsigned int z = 0; z < strlen(word); z++)//calcul bonus cuvant pe verticala
                        {
                            if ((bonus_board[x+z][y]==1) && (aparx!=NULL))
                                bonus=bonus*2;    
                            else    
                            if ((bonus_board[x+z][y]==2) && (apary!=NULL) && ((word[strlen(word)-2]==yy[0]) && (word[strlen(word)-1]==yy[1])))
                                bonus=bonus*3;
                        }
                        if (k%2!=0) //adaugare punctaj(+bonus) la scor pentru fiecare jucator
                            s1= s1 + valword*bonus;
                        else
                            s2= s2 + valword*bonus;
                    }
                }
            else
                if (k%2!=0) 
                    s1= s1 + valword*bonus;
                else
                    s2= s2 + valword*bonus;
            }      
     
        printf("Player 1: %d Points\n",s1); // afisare scor pentru fiecare jucator
        printf("Player 2: %d Points\n",s2);
    
    break;
    
    case 4:
        
        fgets(xx, 4, stdin);//citire si prelucrare date de intrare
        if (xx[strlen(xx) - 1] == '\n')   
            xx[strlen(xx) - 1] = '\0';
        fgets(yy, 4, stdin);
        if (yy[strlen(yy) - 1] == '\n')   
            yy[strlen(yy) - 1] = '\0';
        fgets(s, sizeof(s), stdin);
        if (s[strlen(s) - 1] == '\n')   
            s[strlen(s) - 1] = '\0';
        N=atoi(s);
        for(int k=1;k<=N;k++)
        { 
            fgets(v, sizeof(v), stdin);
            if (v[strlen(v)-1] == '\n')   
                v[strlen(v)-1 ] = '\0';
            c = strtok(v, " ");
            x=atoi(c);
            c = strtok(NULL, " ");
            y=atoi(c);
            c = strtok(NULL, " ");
            d=atoi(c);
            c = strtok(NULL, " ");
            word=c;
            if (d == 0)//afisare cuvinte in matrice functie de pozitie (orizontala sau verticala)
            {
                int z;
                for(z = 0; word[z] ; z++)
                {
                    game_board[x][y] = word[z];
                    y++;
                }
            }
            if (d == 1)
            {
                int z;
                for(z = 0; word[z]; z++)
                {
                    game_board[x][y] = word[z];
                    x++;
                }
            }
            strcpy(w[k-1],word);//introducere cuvinte citite intr-un nou sir
        }
    
        
        for(int i=0;i<100;i++)  // procedura de cautare cuvant nou pentru a fi plasat pe tabla de joc
        	if(gasit==0)
			{
			ok=0;
			len=strlen(words[i]);
			for(int j=0;j<N;j++)
        		if((strcmp(words[i],w[j])<0)||(strcmp(words[i],w[j])>0))//verificam sa nu avem cuvantul pe tabla
                ok=ok+1;
                if(ok==N)
						{
						litera=words[i][0]; // individualizare prima litera din cuvant
						for(i1=0;i1<15;i1++)
        					for(j1=0;j1<15;j1++)
								{
								if((game_board[i1][j1]==litera)&&(gasit==0))// comparam cu fiecare litera din matrice
									{
								    if (((j1+len)<=15) && (game_board[i1][j1+1]=='.'))//parcurgem pe orizontala 
										{contor=0;
										for(int k=j1+1;k<j1+len;k++)//verificam daca cuvantul incape in matrice
											if(game_board[i1][k]!='.')
												break;
											else
												contor=contor+1;
										if(contor==(len-1))
											{
											for(int k=j1+1;k<j1+len;k++)
												game_board[i1][k]=words[i][k-j1];//introducem cuvantul in matrice
											gasit=1;}
                                        }
									else
										
										if (((i1+len) <= 15) && (game_board[i1+1][j1]=='.'))//parcurgem pe verticala
											{
                                            contor=0;
											for(int k=i1+1;k<i1+len;k++)//verificam daca cuvantul se incadreaza in matrice
												if(game_board[k][j1]!='.')
													break;
												else
													contor=contor+1;
											if(contor==(len-1))
												{
												for(int k=i1+1;k<i1+len;k++)
									                game_board[k][j1]=words[i][k-i1];//asezam cuvantul in matrice
												gasit=1;}
											}								
									}
								}
						}
			}
		
        print_board(game_board); // tiparire matrice

    break;
    
    case 5:
    
        fgets(xx, 4, stdin);//citire si prelucrare date de intrare
            if (xx[strlen(xx) - 1] == '\n')   
                xx[strlen(xx) - 1] = '\0';
        fgets(yy, 4, stdin);
            if (yy[strlen(yy) - 1] == '\n')   
                yy[strlen(yy) - 1] = '\0';
        fgets(s, sizeof(s), stdin);
            if (s[strlen(s) - 1] == '\n')   
                s[strlen(s) - 1] = '\0';
        N=atoi(s);
        for(int k=1;k<=N;k++)
        { 
            fgets(v, sizeof(v), stdin);
            if (v[strlen(v)-1] == '\n')   
                v[strlen(v)-1 ] = '\0';
            c=strtok(v, " ");
            x=atoi(c);
            c=strtok(NULL, " ");
            y=atoi(c);
            c=strtok(NULL, " ");
            d=atoi(c);
            c=strtok(NULL, " ");
            word=c;         
            valword=0;
            bonus=1;          
            strcpy(w[k-1],word);
            for(long unsigned int j=0;j<strlen(word);j++)//calculare punctaj+bonus pentru ambii jucatori
            {
                indice=word[j]-'A';
                valword=valword+punctaj[indice];
            }
            aparx=strstr(word,xx);
            apary=strstr(word,yy);
            if ((aparx!=NULL) || (apary!=NULL))
                {
                if (d==0)
                    {
                    for(long unsigned int z = 0; z < strlen(word); z++)
                        {
                            if ((bonus_board[x][y+z]==1) && (aparx!=NULL))
                                bonus=bonus*2;
                            else
                                {    
                                if ((bonus_board[x][y+z]==2) && (apary!=NULL) && ((word[strlen(word)-2]==yy[0]) && (word[strlen(word)-1]==yy[1])))
                                    bonus=bonus*3;
                                }
                        }
                        if (k%2!=0) 
                            s1= s1 + valword*bonus;
                        else
                            s2= s2 + valword*bonus;
                    }     
                else
                    {
                    for(long unsigned int z = 0; z < strlen(word); z++)
                        {
                            if ((bonus_board[x+z][y]==1) && (aparx!=NULL))
                                bonus=bonus*2;    
                            else    
                                if ((bonus_board[x+z][y]==2) && (apary!=NULL) && ((word[strlen(word)-2]==yy[0]) && (word[strlen(word)-1]==yy[1])))
                                    bonus=bonus*3;
                        }
                        if (k%2!=0) 
                            s1= s1 + valword*bonus;
                        else
                            s2= s2 + valword*bonus;
                    }
                }
            else
                if (k%2!=0) 
                    s1= s1 + valword*bonus;
                else
                    s2= s2 + valword*bonus;
            
            if (d == 0) //afisare cuvinte  pe orizontala in matrice
                {
                int z;
                for(z = 0; word[z] ; z++)
                    {
                    game_board[x][y] = word[z];
                    y++;
                    }
                }
            
            if (d == 1) //afisare cuvinte  pe verticala in matrice
                {
                int z;
                for(z = 0; word[z]; z++)
                    {
                    game_board[x][y] = word[z];
                    x++;
                    }
                }
        }
    
        max=s2;  // initializare punctaj maxim pentru jucatorul 2
        
        for(int i=0;i<100;i++) // parcurgere tablou cuvinte noi
        	{
			ok=0;
			len=strlen(words[i]);
			for(int j=0;j<N;j++)//parcurgem fiecare cuvant citit 
        		if((strcmp(words[i],w[j])<0)||(strcmp(words[i],w[j])>0))
                    {ok=ok+1;
                    }
				
                if (ok==N)//verificam validitatea cuvantului (nu se gaseste in lista de cuvinte date)
					{
					litera=words[i][0];
                    s2_nou=0;
					for(i1=0;i1<15;i1++)
        				for(j1=0;j1<15;j1++)
						{
                            s2_nou=0;
                            if (game_board[i1][j1]==litera)
							{   if (((j1+len)<=15) && (game_board[i1][j1+1]=='.')) //verificare posibilitate de plasare cuvant nou pe orizontala
								{   contor=0;
									for(int k=j1+1;k<j1+len;k++)
										if(game_board[i1][k]!='.')//procedeul pentru orizontala
                                            break;
										else
											contor=contor+1;
                                           									
                                    if(contor==(len-1))//verificam daca putem pune cuvantul in matrice
									{
                                        cuvant_nou=words[i];
                                        
                                        s2_nou=0;
                                        gasit=1;
										valword=0;
                                        bonus = 1;
                                        for(long unsigned int j=0;j<strlen(cuvant_nou);j++)//calculam punctajul cuvantului fara bonus
                                        {
                                            indice=words[i][j]-'A';
                                            valword=valword+punctaj[indice];
                                        }
                                        aparx=strstr(cuvant_nou,xx);
                                        apary=strstr(cuvant_nou,yy);
                                        if ((aparx!=NULL) || (apary!=NULL))
                                        {   
                                            s2_nou=0;
                                            for(long unsigned int z = 0; z < strlen(cuvant_nou); z++)
                                            {
                                                if ((bonus_board[i1][j1+z]==1) && (aparx!=NULL))
                                                    bonus=bonus*2;
                                                else
                                                {    
                                                    if ((bonus_board[i1][j1+z]==2) && (apary!=NULL) && ((cuvant_nou[strlen(cuvant_nou)-2]==yy[0]) && (cuvant_nou[strlen(cuvant_nou)-1]==yy[1])))
                                                        bonus=bonus*3;
                                                }
                                            }
                                            s2_nou=s2_nou + valword*bonus;
                                            if ((s2+s2_nou) > max)//verificam daca punctajul obtinut este maxim
                                               {max = s2+s2_nou;
                                                cuv_final=cuvant_nou;
                                                i_nou=i1;
                                                j_nou=j1;
                                                dir=0;}//dir=directia
                                            if(((s2+s2_nou) == max))//2 cuvinte dau punctaje egale
                                                {
                                                if (i1<i_nou)
                                                    {i_nou=i1;  // se retine cuvantul de pe linia cea mai mica
                                                    j_nou=j1;
                                                    max = s2+s2_nou;
                                                    cuv_final=cuvant_nou;
                                                    dir=0;}
                                                if (i1==i_nou)
                                                    if(j1<j_nou)
                                                        {i_nou=i1; // se retine cuvantul de pe coloana cea mai mica (daca incep pe aceeasi linie)
                                                        j_nou=j1;
                                                        max = s2+s2_nou;
                                                        cuv_final=cuvant_nou;
                                                        dir=0;}
                                                }
                                    
                                        }                

                                        else
                                        {    
                                            s2_nou=s2_nou + valword*bonus;
                                            if ((s2+s2_nou) > max)
                                               {max = s2+s2_nou;
                                                cuv_final=cuvant_nou;
                                                i_nou=i1;
                                                j_nou=j1;
                                                dir=0;}
                                            if(((s2+s2_nou) == max))
                                                {
                                                if (i1<i_nou)
                                                    {i_nou=i1;
                                                    j_nou=j1;
                                                    max = s2+s2_nou;
                                                    cuv_final=cuvant_nou;
                                                    dir=0;}
                                                if (i1==i_nou)
                                                    if(j1<j_nou)
                                                        {i_nou=i1;
                                                        j_nou=j1;
                                                        max = s2+s2_nou;
                                                        cuv_final=cuvant_nou;
                                                        dir=0;}
                                                }
 
                                        }
                                    
                                    
                                    }    
                                    
                                
                                }
                                
							    else
									if (((i1+len) <= 15)&&(game_board[i1+1][j1]=='.')) //verificare posibilitate de plasare cuvant nou pe verticala
									{   contor=0;
                                        for(int k=i1+1;k<i1+len;k++)
											if(game_board[k][j1]!='.')
											    break;
											else
												contor=contor+1;
                                                                                               
										if(contor==(len-1))
											{   cuvant_nou=words[i];
                                                gasit=1;
                                                valword=0;
                                                bonus = 1;
                                                for(long unsigned int j=0;j<strlen(cuvant_nou);j++) // calcul punctaj fara bonus pentru cuvant
                                                {
                                                    indice=words[i][j]-'A';
                                                    valword=valword+punctaj[indice];
                                                }
                                                aparx=strstr(cuvant_nou,xx);
                                                apary=strstr(cuvant_nou,yy);
                                                if ((aparx!=NULL) || (apary!=NULL))
                                                {   
                                                    
                                                    s2_nou=0;
                                                    for(long unsigned int z = 0; z < strlen(cuvant_nou); z++)
                                                    {
                                                        if ((bonus_board[i1+z][j1]==1) && (aparx!=NULL))
                                                            bonus=bonus*2;    
                                                        else    
                                                            if ((bonus_board[i1+z][j1]==2) && (apary!=NULL) && ((cuvant_nou[strlen(cuvant_nou)-2]==yy[0]) && (cuvant_nou[strlen(cuvant_nou)-1]==yy[1])))
                                                            bonus=bonus*3;
                                                    }
                                                    s2_nou=s2_nou + valword*bonus; // calcul punctaj cu bonus pentru cuvant
                                                    if ((s2+s2_nou) > max)
                                                        {max = s2+s2_nou;
                                                        cuv_final=cuvant_nou;
                                                        i_nou=i1;
                                                        j_nou=j1;
                                                        dir=1;}
                                                    if(((s2+s2_nou) == max))
                                                    {
                                                        if (i1<i_nou)
                                                            {i_nou=i1;
                                                            j_nou=j1;
                                                            max = s2+s2_nou;
                                                            cuv_final=cuvant_nou;
                                                            dir=1;}
                                                        if (i1==i_nou)
                                                            if(j1<j_nou)
                                                                {i_nou=i1;
                                                                j_nou=j1;
                                                                max = s2+s2_nou;
                                                                cuv_final=cuvant_nou;
                                                                dir=1;}
                                                    }
                       
                                                } 
                                                                                            
                                            else
                                                {
                                                s2_nou=s2_nou + valword*bonus;
                                                if ((s2+s2_nou) > max)
                                                    {max = s2+s2_nou;
                                                    cuv_final=cuvant_nou;
                                                    i_nou=i1;
                                                    j_nou=j1;
                                                    dir=1;}
                                                if(((s2+s2_nou) == max))
                                                {
                                                if (i1<i_nou)
                                                    {i_nou=i1;
                                                    j_nou=j1;
                                                    max = s2+s2_nou;
                                                    cuv_final=cuvant_nou;
                                                    dir=1;}
                                                if (i1==i_nou)
                                                    if(j1<j_nou)
                                                        {i_nou=i1;
                                                        j_nou=j1;
                                                        max = s2+s2_nou;
                                                        cuv_final=cuvant_nou;
                                                        dir=1;}
                                                } 
                                          
                                                }
                                            }                                                
                                     
                                    }									
							}
						    
					    }
			}
    
    
    }
    
        if ((dir==0) && (max>=s1))//introducem cuvantul in matrice pe orizontala daca respecta conditia de penctaj (>s1)
            {len=strlen(cuv_final);
            for(int k=j_nou+1;k<j_nou+len;k++)
			    game_board[i_nou][k]=cuv_final[k-j_nou];}

    
        if ((dir==1) && (max>=s1))//introducem cuvantul in matrice pe verticala daca respecta conditia de penctaj (>s1)
            {len=strlen(cuv_final);
            for(int k=i_nou+1;k<i_nou+len;k++)
			    game_board[k][j_nou]=cuv_final[k-i_nou];}
    
        if(max>=s1)
            print_board(game_board);
        else
            printf("Fail!\n");
               
    break;
    
    }            
    return 0;
    }

