#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um agendamento
typedef struct {
    int dia;
    int duracao;
} Agendamento;

// Função para determinar se um ano é bissexto
// Parâmetro:
// - ano: O ano a ser verificado
// Retorna:
// - 1 se o ano é bissexto, 0 caso contrário
int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função para obter o dia da semana do primeiro dia do ano
// Parâmetros:
// - diaDoAno: O dia do ano (1 a 366)
// - primeiroDia: O dia da semana do primeiro dia do ano (0 a 6, onde 0 é Domingo)
// Retorna:
// - O dia da semana do primeiro dia do ano (0 a 6, onde 0 é Domingo)
int obterDiaDaSemana(int diaDoAno, int primeiroDia) {
    return (diaDoAno + primeiroDia - 1) % 7; // 0 é Domingo, 1 é Segunda, ..., 6 é Sábado
}

// Função para exibir o calendário de um mês
// Parâmetros:
// - diasNoMes: O número de dias no mês
// - primeiroDia: O dia da semana do primeiro dia do mês (0 a 6, onde 0 é Domingo)
void exibirCalendario(int diasNoMes, int primeiroDia) {
    printf("Dom Seg Ter Qua Qui Sex Sab\n");

    // Preencher os espaços vazios até o primeiro dia do mês
    for (int i = 0; i < primeiroDia; i++) {
        printf("    ");
    }

    // Exibir os dias do mês
    for (int dia = 1; dia <= diasNoMes; dia++) {
        printf("%3d ", dia);
        if ((dia + primeiroDia) % 7 == 0 || dia == diasNoMes) {
            printf("\n");
        }
    }
}

//coloque a sua parte aqui Pedro <<<<<<---------------------

////////////////////Main_Início//////////////////////
int main() {
    int ano, primeiroDiaDoAno, diasNoMes[13], primeiroDiaDoMes[13];
    int agenda[366] = {0}; // Supondo que o ano tem no máximo 366 dias

    // Solicitar ao usuário o ano e o primeiro dia da semana
    printf("Digite o ano: ");
    scanf("%d", &ano);
    printf("---------------------------------------------\n");
    printf("Digite o primeiro dia da semana.\nEx.: (0)Domingo, (1)Segunda, ..., (6)Sábado.\n");
    printf("---------------------------------------------\n");
    scanf("%d", &primeiroDiaDoAno);
    system("clear");
