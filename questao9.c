#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char esporte[50];
    int idade;
    float alt;
} atleta;

int comparar_alturas(atleta a1, atleta a2) {
    if (a1.alt > a2.alt) return 1;
    if (a1.alt < a2.alt) return -1;
    return 0;
}

int comparar_idades(atleta a1, atleta a2) {
    if (a1.idade > a2.idade) return 1;
    if (a1.idade < a2.idade) return -1;
    return 0;
}

int main() {
    atleta atletas[5];
    atleta m_alto, m_velho;
    
    m_alto.alt = 0.0;
    m_velho.idade = 0;

    for (int i = 0; i < 5; i++) {
        printf("Nome do atleta %d:\n", i + 1);
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
        
        printf("Esporte do atleta %d:\n", i + 1);
        fgets(atletas[i].esporte, sizeof(atletas[i].esporte), stdin);
        
        printf("Idade do atleta %d:\n", i + 1);
        scanf("%d", &atletas[i].idade);
        
        printf("Altura do atleta %d (em metros):\n", i + 1);
        scanf("%f", &atletas[i].alt);
        
        getchar(); 


        if (comparar_alturas(atletas[i], m_alto) > 0) {
            m_alto = atletas[i];
        }
        
        if (comparar_idades(atletas[i], m_velho) > 0) {
            m_velho = atletas[i];
        }
    }

    printf("Atleta mais alto: %s (Altura: %.2f metros)\n",
           m_alto.nome, m_alto.alt);
    printf("Atleta mais velho: %s (Idade: %d anos)\n",
           m_velho.nome, m_velho.idade);

    return 0;
}