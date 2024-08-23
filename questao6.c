#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[50];
    float n1, n2, n3;
}aluno;

float calc_media(aluno a){
    return (a.n1 + a.n2 + a.n3)/3;
}

int main() {
    aluno alunos[5];
    float mai_media = 0.0;
    int indc_mai_media = 0;

    for(int i = 0; i < 5; i++){
        printf("insira sua matricula: \n");
        scanf("%d", &alunos[i].mat);
        getchar();
        printf("insira seu nome: \n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        printf("insira a primeira nota: \n");
        scanf("%f", &alunos[i].n1); 
        printf("insira a segunda nota: \n");
        scanf("%f", &alunos[i].n2);
        printf("insira a terceira nota: \n");
        scanf("%f", &alunos[i].n3);

        float media = calc_media(alunos[i]);

        if(media > mai_media){
            mai_media = media;
            indc_mai_media = i;
        }  
    }

    printf("o aluno com a maior média geral é: %s (Matrícula: %d)\n", alunos[indc_mai_media].nome, alunos[indc_mai_media].mat);
    printf("notas: %.2f, %.2f, %.2f\n", alunos[indc_mai_media].n1, alunos[indc_mai_media].n2, alunos[indc_mai_media].n3);
    printf("média: %.2f\n", mai_media);
}