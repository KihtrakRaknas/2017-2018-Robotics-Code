
#include "main.h"

void operatorControl() {
		FILE *fptr;

		char string[99];
			delay(5000);
			fptr = fopen("emp.txt", "r");
			delay(5000);
			printf("Opening file\n");
			if (fptr == NULL)
			{
					printf("File does not exists \n");
					//return;
			}else{
			printf("Printing contents of the file\n");
			while(fgets(string, 99,fptr)!=NULL){
				printf("%s", string);
			}
			fclose(fptr);
			}

    fptr = fopen("emp.txt", "w");
		delay(300);
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("Writing to file\n-\n-\n");
		for(int i = 0; i!=5;i++)
    fprintf(fptr, "Test # %d\n", i);
		char Cha;
		while(Cha!='\n'){
			Cha = fgetc(stdin);
			fprintf(fptr,"%c",Cha);
		}
		printf("Input Recorded\nClosing File\n");
		 fclose(fptr);

		// char string[99];
		//
		// 	fptr = fopen("emp.txt", "r");
		// 	printf("Opening file\n");
		// 	if (fptr == NULL)
		// 	{
		// 			printf("File does not exists \n");
		// 			return;
		// 	}
		// 	printf("Printing contents of the file\n");
		// 	while(fgets(string, 99,fptr)!=NULL){
		// 		printf("%s", string);
		// 	}
		// 	fclose(fptr);

}
