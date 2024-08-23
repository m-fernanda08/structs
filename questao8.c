#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct {
    char nome[50];
    int day;
    int month;
    int year;
} pessoa;

int comparar_datas(pessoa p1, pessoa p2) {
    if (p1.year > p2.year) return 1;
    if (p1.year < p2.year) return -1;
    if (p1.month > p2.month) return 1;
    if (p1.month < p2.month) return -1;
    if (p1.day > p2.day) return 1;
    if (p1.day < p2.day) return -1;
    return 0;
}

int main() {
    pessoa pessoas[6];
    pessoa m_novo, m_velho;
    
    m_velho.year = INT_MAX;
    m_novo.year = INT_MIN;

    for (int i = 0; i < 6; i++) {
        printf("Nome da pessoa %d:\n", i + 1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);

        printf("Dia de nascimento da pessoa %d:\n", i + 1);
        scanf("%d", &pessoas[i].day);

        printf("Mês de nascimento da pessoa %d:\n", i + 1);
        scanf("%d", &pessoas[i].month);

        printf("Ano de nascimento da pessoa %d:\n", i + 1);
        scanf("%d", &pessoas[i].year);

        getchar();

        if (comparar_datas(pessoas[i], m_novo) > 0) {
            m_novo = pessoas[i];
        }
        
        if (comparar_datas(pessoas[i], m_velho) < 0) {
            m_velho = pessoas[i];
        }
    }


    printf("Pessoa mais nova %s (Data de nascimento: %02d/%02d/%04d)\n",
           m_novo.nome, m_novo.day, m_novo.month, m_novo.year);
    printf("Pessoa mais velha %s (Data de nascimento: %02d/%02d/%04d)\n",
           m_velho.nome, m_velho.day, m_velho.month, m_velho.year);

    return 0;
}