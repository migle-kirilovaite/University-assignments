#include <stdio.h>
#include <stdlib.h>

#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values

// input: 
//    user enters 10 non-negative integers
// output: 
//    report how many times each unique value occured,
//    display values and occurence times in ascending order

int main() {
   
   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;

   printf("Programa isveda ivestu sekos nariu pasikartojimo dazni. \n"); // report what the program does

   printf("Iveskite seka is 10 nariu(-io) \n"); // ask to enter 10 numbers 

   while(counter < SIZE){
      printf("Iveskite %d sekos elementa:", counter+1); // ask to enter the following number
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            printf("Sekos narys ivestas sekmingai! \n"); // report that number entered successfully
         } else {
            printf("Virsyti masyvo reziai [0;%d]! \n", FREQ_SIZE-1);
         }
      } else {
         printf("Netinkama ivestis! Iveskite sveika, neneigiama skaiciu! \n"); // report that value exceeds bounds and has to belong to [0; FREQ-SIZE]
         while(getchar() != '\n')
            ;
      }
   }
   
   printf("Seka ivesta sekminkai! \n");// report that data has been entered correctly
   
   // proceeding to computations...
   
   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }

   int flag;
   int diffNumsCounter = 0;

   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }        
      }       
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }

   int temp;

   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }

   printf("Skaicius        Pasikartojimo daznis \n");// report that results will be reported
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         printf("%8d.......................... %d \n", diffNums[i], frequency[diffNums[i]]);// report the value of diffNums[i] and the value of frequency[diffNums[i]]
      }
   }

   return 0;
}