#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void named();
void savename(char);

int main(void)
{
    srand(time(NULL));
    printf("[Aü<1ČšÉČĐöŪ]\n");
    named();
}

void named(){
    int i, j; //įp
    int ran_V, ran_C; //ŠÉp
    int num, num_real=0; //ž·xäoÛ·x
    char *nme, *nme_real; //įŽ@ķŽžäoÛž
    char NME_V[5] = {'a','e','i','o','u'};
    char NME_C[22] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z',NULL};
    while(1){
        printf("žßÉ:");
        scanf("%d",&num);
        num*=2;
        if(num<1)
            break;
        else{
            nme=(char *) malloc(num*sizeof(char));
            for(i=0;i<num;i++){
                ran_V=(rand()%5);
                ran_C=(rand()%22);
                /*ķŽįŽ@ž*/
                if(i%2==0)
                    *(nme+i)=NME_C[ran_C];
                else
                    *(nme+i)=NME_V[ran_V];
                if(*(nme+i)!=NULL)
                    num_real++;
            }
            num_real+=1;
            nme_real=(char *) malloc(num_real*sizeof(char));
            for(i=0,j=0;j<num_real;i++){
                if(*(nme+i)!=NULL){
                    if(j==0)
                        *(nme_real+j)=*(nme+i)-('a'-'A');
                    else if(j==(num_real-1))
                        *(nme_real+j)='\n';
                    else
                        *(nme_real+j)=*(nme+i);
                    printf("%c",*(nme_real+j));
                    savename(*(nme_real+j));
                    j++;
                }
            }
            num_real=0;
            free(nme);
            free(nme_real);
        }
    }
}
void savename(char str){
    FILE *fnme;
    fnme = fopen("D:\\c_randomname.txt","a");
    if(fnme!=NULL){
        while((getc(fnme))!=EOF);
        putc(str,fnme);
        fclose(fnme);
    }
    else
        printf("FAIL");
}
