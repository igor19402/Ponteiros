#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int dia;
    int mes;
    int ano;
}data;


typedef struct{
    int codigo;
    char nome[30];
    float salario;
    data admiti;
}funcionario;

void exibetab(funcionario f[],int n){
    int i;
    //Lendo os dados do usuario
    for(i=0;i<n;i++){
        printf("digite o codigo do funcionario:");
        scanf("%d",&f[i].codigo);
        fflush(stdin);
        printf("nome do funcionario:");
        gets(f[i].nome);
        printf("salario:");
        scanf("%f",&f[i].salario);
        printf("dia de admissão:");
        scanf("%d",&f[i].admiti.dia);
        printf("mes de admissão:");
        scanf("%d",&f[i].admiti.mes);
        printf("ano de admissão:");
        scanf("%d",&f[i].admiti.ano);
    }
    ordenatab(f,n);

}

void ordenatab(funcionario f[],int n){
    int aux,i,j;
    char aux2[30];

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(f[j].codigo>f[j+1].codigo){
                aux = f[j].codigo;
                f[j].codigo= f[j+1].codigo;
                f[j+1].codigo = aux;
                strcpy(aux2,f[j].nome);
                strcpy(f[j].nome,f[j+1].nome);
                strcpy(f[j+1].nome,aux2);
                aux = f[j].salario;
                f[j].salario = f[j+1].salario;
                f[j+1].salario = aux;
                aux = f[j].admiti.dia;
                f[j].admiti.dia = f[j+1].admiti.dia;
                f[j+1].admiti.dia = aux;
                aux = f[j].admiti.mes;
                f[j].admiti.mes = f[j+1].admiti.mes;
                f[j+1].admiti.mes = aux;
                aux = f[j].admiti.ano;
                f[j].admiti.ano = f[j+1].admiti.ano;
                f[j+1].admiti.ano = aux;}}

    //exibindo os dados do usuario
        printf("Codigo     nome              salario   admissao\n");
        printf("                                        dia mes ano\n");

    for(i=0;i<n;i++){
        printf("%d   %s                    %.2f     %d   %d   %d \n",f[i].codigo,f[i].nome,f[i].salario,f[i].admiti.dia,f[i].admiti.mes,f[i].admiti.ano);
    }
}
    }

float total_salarios(funcionario f[],int n){
    float soma=0;
    int i;
    for(i=0;i<n;i++){
        soma+=f[i].salario;
    }
    return soma;
}
int main(){
    int n;
    printf("quantos funcionarios:");
    scanf("%d",&n);
    funcionario f[n];
    exibetab(f,n);
    printf("%.2f",total_salarios(f,n));

}
