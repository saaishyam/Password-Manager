#include<stdio.h>
#include<string.h>

#define MAX_CHAR 1000

int count = 0;

struct Data 
{
    char namep[MAX_CHAR];
    char password[MAX_CHAR];
};

struct Data pass[100];

void Addpass(){

    FILE *fptr = fopen("accdata.txt","a");

    if(fptr == NULL){
        printf("The File is not opened\n");
        return;
    }

    
    printf("Enter the name of account/website:");
    fgets(pass[count].namep,MAX_CHAR,stdin);
    pass[count].namep[strcspn(pass[count].namep,"\n")] = '\0';

    printf("Enter Password: ");
    fgets(pass[count].password,MAX_CHAR,stdin);
    pass[count].password[strcspn(pass[count].password,"\n")] = '\0';

    fprintf(fptr, "%s:%s\n", pass[count].namep,pass[count].password);

    if(count <=100){
        count++;
    }
    else{
        printf("ARRAY OUTOF BOUNDS!!\n");
    }

    fclose(fptr);
}

void Viewpass(){

    int found=0;
    FILE *fptr = fopen("accdata.txt","r");

    char acc[MAX_CHAR]; //Stores Input data
    char line[MAX_CHAR]; // Stores the data in the file

    printf("Enter the account/website name to search for: ");

    fgets(acc,MAX_CHAR,stdin);

    acc[strcspn(acc,"\n")] = '\0';

    if(count == 0){
        printf("No Data found Input data to view\n");
        return;
    }


    if (fptr == NULL){
        printf("File not opened\n");
        return;
    }
    else{
    
        while(fgets(line,MAX_CHAR,fptr)){
            line[strcspn(line,"\n")] = '\0';

            char *name =strtok(line, ":");
            char *password = strtok(NULL, ":");

            if(name == NULL || password == NULL)
            {
              continue;   // skip malformed line
            }

            if (strcmp(acc,name) == 0){
                printf("==================================\n");
                printf("password : %s\n", password);
                printf("==================================\n");
                found = 1;
                break;
            }
        }

    }


    if(found == 0){
        printf("account not found!\n");
        return;
    }

    fclose(fptr);
}

void Updatepass(){

    int found=0;

    FILE *fptr = fopen("accdata.txt","r");
    FILE *temp = fopen("temp.txt","w");
    
    char acc[MAX_CHAR];
    char line[MAX_CHAR];
    char _pass[MAX_CHAR];

    printf("Enter the account/website name to Update: ");
    fgets(acc,MAX_CHAR,stdin);

    printf("Enter password to be updated: ");
    fgets(_pass,MAX_CHAR,stdin);

    _pass[strcspn(_pass,"\n")] = '\0';
    acc[strcspn(acc,"\n")] = '\0';

    printf("==================================\n");

    if (fptr == NULL){
        printf("File not opened\n");
        return;
        fclose(temp);
        remove("temp.txt");
    }

    while(fgets(line,MAX_CHAR,fptr)){
        line[strcspn(line,"\n")] = '\0';

        char *name = strtok(line,":");
        char *password = strtok(NULL,":");

        if(name == NULL || password == NULL)
        {
            continue;
        }

        if(strcmp(acc,name) == 0){
            printf("Account found...\n");
            found = 1;
            fprintf(temp,"%s:%s\n",acc,_pass);

            printf("==================================\n");
        }
        else{
            fprintf(temp, "%s:%s\n", name, password);
        }

    }

    printf("Password Updation succesfull\n");


    if (found == 0){
        printf("Account not found\n");
    }

    fclose(temp);
    fclose(fptr);

    remove("accdata.txt");
    rename("temp.txt", "accdata.txt");
}

int main(){

    while (1){

    
    int choice;

    printf("#######PASSWORD MANAGER############\n");
    printf("1.ADD PASSWORD\n");
    printf("2.VIEW PASSWORD\n");
    printf("3.UPDATE PASSWORD\n");
    printf("4.EXIT\n");

    printf("Enter your choice:");
    scanf("%d",&choice);
    getchar();

    if(choice == 1){
        Addpass();
    }
    else if(choice == 2){
        Viewpass();
    }
    else if(choice == 3){
        Updatepass();
    }
    else if(choice == 4){
        break;
    }
    else{
        printf("Wrong choice\n");
    }
}

    return 0;

}