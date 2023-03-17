#include <stdio.h>

int main(){
	int n;
	int user,pswd;
			FILE * flog;
	do{
		printf("2.login\n");
		printf("1.register\n");
		printf("0.exit\n");
		scanf("%d",&n);
	}while(n!=2&&n!=1&&n!=0);
	switch(n){
		case 0:
			printf("Thanks any way .");
			break;
		case 1:
			printf("enter the username number:  ");
			scanf("%d",&user);
			printf("enter the password number : ");
			scanf("%d",&pswd);
			FILE * freg = fopen("form.dat","w");
			fwrite(&user,sizeof(int),1,freg);
			fwrite(&pswd,sizeof(int),1,freg);
			fclose(freg);
			break;
		case 2:

			flog = fopen("form.dat","r");
			if(flog==NULL){
				printf("Unable to find the database .\n");	
			}
			fread(&user,sizeof(int),1,flog);
			printf("the user : %d\n",user);
			fread(&pswd,sizeof(int),1,flog);
			printf("the password : %d\n",pswd);	
			fclose(flog);
			break;		
	}
	return 0;
}
