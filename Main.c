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
    
    printf("Enter the name of account/website:");
    fgets(pass[count].namep,MAX_CHAR,stdin);
    pass[count].namep[strcspn(pass[count].namep,"\n")] = '\0';

    printf("Enter Password: ");
    fgets(pass[count].password,MAX_CHAR,stdin);
    pass[count].password[strcspn(pass[count].password,"\n")] = '\0';

    if(count <=100){
        count++;
    }
    else{
        printf("ARRAY OUTOF BOUNDS!!\n");
    }

}

void Viewpass(){

    int found=0;
    char acc[MAX_CHAR];
    printf("Enter the account/website name to search for: ");
    fgets(acc,MAX_CHAR,stdin);

    acc[strcspn(acc,"\n")] = '\0';

    for (int i = 0; i < count; i++){

        if(strcmp(acc,pass[i].namep) == 0){
            printf("Match Found!!\n");
            printf("%s : %s\n",pass[i].namep,pass[i].password);
            found = 1;
            break;
        }
    }

    if(found == 0){
        printf("account not found!\n");
    }

}

void Updatepass(){

    int found=0;
    char acc[MAX_CHAR];
    printf("Enter the account/website name to Update: ");
    fgets(acc,MAX_CHAR,stdin);

    acc[strcspn(acc,"\n")] = '\0';

    for (int i = 0; i < count; i++){

        if(strcmp(acc,pass[i].namep) == 0){
            
            printf("Enter pass to update:");
            fgets(pass[i].password,MAX_CHAR,stdin);
            pass[i].password[strcspn(pass[i].password,"\n")] = '\0';

            printf("Password Updated succesfully!\n");
            
            found = 1;
        }
    }

    if(found == 0){
        printf("account not found\n");
    }

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