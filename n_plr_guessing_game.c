//n player guessing game
#include <stdio.h>
#include <stdlib.h>		// to use srand() and abs()
#include <time.h>		// to use time()

int
main ()
{
  printf("\n ________NUMBER GUESSING GAME________ \n \n");
  int rand_number, Guess, guess_count = 0,a=0,n, player,s,l,x,y,k,m,z,j1,j2,j3;
  double max = 0,temp;
  double score_card1[100];
  double rank_card[100];
  double score_card2[100];  // this is a copy of score_card1

  printf("\n      WELCOME TO THIS WONDERFUL NUMBER GUESSING GAME.   ");
  printf("\n\n      THE GOAL HERE IS TO GUESS A RAMDOMLY GENERATED NUMBER RANGING FROM 1 TO 100 IN THE LEAST NUMBER OF GUESSES. ");
  printf("\n\n      THE GAME ITSELF WOULD GUIDE YOU, BUT REMEMBER THE GUESSES ARE ADDING UP. ");
  printf("\n\n      LESSER THE THE NUMBER OF GUESSES, BETTER THE RANK YOU WILL GET. ");
  printf("\n\n      BUT IF THE GUESSES BE WILDER, IT WOULD BE COUNTED AGAINST YOU. ");
  printf("\n\n      MAY THE MOST INTUITIVE WIN. ");
  printf("\n\n\n      Enter Number Of Players = ");
  scanf("%d", &n);
  
  for(player=1; player <= n; player++)
    { srand (time (0));
      rand_number = rand () % 100 + 1;
    //printf("rand number %d = %d",player, rand_number );
      printf ("\n \n \n     #PLAYER %d  \n \n", player);
  do
	{
	  printf (" \n      Enter your Guess = ");
	  scanf ("%d", &Guess);

	  if (Guess < rand_number)
	    {
	      printf (" \n     ~Guess Higher \n");
	    }
	  else if (Guess > rand_number)
	    {
	      printf (" \n     ~Guess Lower \n");
	    }
	    
	  guess_count++;  //guess counter
	  
	  a += abs(rand_number - Guess);  //this is for tie-breaking
	}
  while (Guess != rand_number);
    
    if(guess_count == 1)
      {
       printf (" \n      You Took 1 Guess. \n \n");
      }
    else
      {
       printf (" \n      You Took %d Guesses. \n \n", guess_count);
      } 
      score_card1[player - 1] = guess_count + (a*0.0001) + (player*0.00001);  //(a*0.0001) determines how close/wild the guesses were
      score_card2[player - 1] = guess_count + (a*0.0001) + (player*0.00001);  //(player*0.00001) is when mutiple players took just 1 guess
      guess_count = 0;  //to initialise guess_count
      a = 0;  //to initialise a
      }
   
   for(l = 0; l < n; l++) 
       {
    for(x = 0; x < n; x++) //this loop finds the max element in a given array
           {
            if(score_card1[x] >= max)
              {
               max = score_card1[x];
              }
           }
        
        for(y = 0; y < n; y++) //this loop stores 0 in that element's place so that next time max is new 
           {
            if(max == score_card1[y]) 
              {
               score_card1[y] = 0; //this deletes all the elements of score_card1 after loop is completed
               break; //to handle equal numbers
              }
           }
        
        rank_card[l] = max;
        max = 0;   //to initialise 'max' 
     
       }
       
      
       for(z = 0; z < (n/2); z++) //to reverse rank_card,cuz the least guesser is the best player 
       {                      //note:had z run till n, the arr would have been reversed twice i.e. would have become the same
        temp = rank_card[z];
        rank_card[z] = rank_card[n-z-1];
        rank_card[n-z-1] = temp;
       }
    
    printf("\n      ______SCORE BOARD______      \n \n");
    
    for(m = 0; m < n; m++)   
      {
       for(k = 0; k < n; k++)
          {
           if(rank_card[m] == score_card2[k]) //as score_card1 is deleted and score_card2 is a copy of score_card1
             { 
              if((int)rank_card[m] == 1)
                {
                 printf("      %d. Player %d (1 Guess) \n \n", m+1, k+1);
                }
            else
                {
                 printf("      %d. Player %d (%d Guesses) \n \n", m+1, k+1, (int)score_card2[k] /* or (int)rank_card[m] */); 
                }
             }
          }
      }
      
    /* //for trouble-shooting purposes
     for(j1=0;j1<n;j1++)
        {  printf(" score_card1 = %f\n",score_card1[j1]);}
      
      for(j2=0;j2<n;j2++)
        {  printf(" score_card2 = %f\n",score_card2[j2]);}
      
      for(j3=0;j3<n;j3++)
        {  printf(" rank_card = %f\n", rank_card[j3]);}
    */
    printf("\n\n      PLAY AGAIN ?? ");
    return 0;
}
 