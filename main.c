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

// Função para verificar se é possível agendar no dia especificado

// Parâmetros: 

// - agenda: Array representando os agendamentos de cada dia do ano 
// - dia: O dia do ano para verificar agendamento 
// - duracao: A duração do agendamento em dias

// Retorna: 
// - 1 se é possível agendar, 0 caso contrário
int verificarAgendamento(int *agenda, int dia, int duracao) { 
int pacientes = 0; for (int i = dia; i < dia + duracao; i++) 
{ if (agenda[i] >= 5) {
return 0; 
// Não é possível agendar neste dia 
} 
 pacientes += agenda[i]; 
} 
return pacientes < 5; 
// Retorna 1 se o número total de pacientes for menor que 5 
} 
// Função para inserir um agendamento 
// Parâmetros: 
// - agenda: Array representando os agendamentos de cada dia do ano 
// - dia: O dia do ano para inserir o agendamento 
// - duracao: A duração do agendamento em dias void inserirAgendamento
(int *agenda, int dia, int duracao) { 
    for (int i = dia; i < dia + duracao; i++) { 
agenda[i]++; }
} 

// Função para exibir o calendário com agendamentos 
// Parâmetros: // - diasNoMes: O número de dias no mês 
// - primeiroDia: O dia da semana do primeiro dia do mês (0 a 6, onde 0 é Domingo) 
// - agenda: Array representando os agendamentos de cada dia do ano void exibirCalendarioComAgendamentos

(int diasNoMes, int primeiroDia, int *agenda) { 
printf("Dom Seg Ter Qua Qui Sex Sab\n"); 

// Preencher os espaços vazios até o primeiro dia do mês 
for (int i = 0; i < primeiroDia; i++) { printf(" "); } 

// Exibir os dias do mês com os agendamentos 
for (int dia = 1; dia <= diasNoMes; dia++) { 
    printf("%3d ", agenda[dia]); if ((dia + primeiroDia) % 7 == 0 || dia == diasNoMes) { 
        printf("\n"); } 
} 
}

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

    // Definir o número de dias em cada mês
    diasNoMes[1] = 31;
    diasNoMes[2] = ehBissexto(ano) ? 29 : 28;
    diasNoMes[3] = 31;
    diasNoMes[4] = 30;
    diasNoMes[5] = 31;
    diasNoMes[6] = 30;
    diasNoMes[7] = 31;
    diasNoMes[8] = 31;
    diasNoMes[9] = 30;
    diasNoMes[10] = 31;
    diasNoMes[11] = 30;
    diasNoMes[12] = 31;

     // Definir o primeiro dia da semana de cada mês
    primeiroDiaDoMes[1] = primeiroDiaDoAno;
    for (int mes = 2; mes <= 12; mes++) {
        primeiroDiaDoMes[mes] = (primeiroDiaDoMes[mes - 1] + diasNoMes[mes - 1]) % 7;
    }

     int opcao;
    do {
       // Menu de opções
              printf("\n\n------------MENU------------\n");
              printf("1. Mostrar o calendário\n");
              printf("2. Inserir agendamento\n");
              printf("3. Mostrar o calendário com agendamentos\n");
              printf("4. Sair\n");
              printf("----------------------------\n");
              printf("Escolha uma opção: ");
              scanf("%d", &opcao);
              printf("----------------------------\n");
              system("clear");
        //Definindo a lógica de cada opção do Menu
              switch (opcao) {
                  case 1:
                      // Opção 1: Mostrar o calendário
                      printf("\n\tCalendário de %d\n", ano);
                      printf("============================");
                      for (int mes = 1; mes <= 12; mes++) {
                          printf("\n\t\t\t%d / %d\n", mes, ano);
                          printf("----------------------------\n");
                          exibirCalendario(diasNoMes[mes], primeiroDiaDoMes[mes]);
                          printf("============================");
                      }
                        break;
                    case 2:
                      // Opção 2: Inserir agendamento
                      {
                          int mes, dia, duracao;
                          printf("Digite o mês do agendamento: ");
                          scanf("%d", &mes);
                          printf("------------------------------\n");
                          printf("Digite o dia do agendamento: ");
                          scanf("%d", &dia);
                          printf("------------------------------\n");
                          printf("Digite a duração do agendamento em dias: ");
                          scanf("%d", &duracao);
                          system("clear");

                          if (verificarAgendamento(agenda, dia, duracao)) {
                              inserirAgendamento(agenda, dia, duracao);
                              printf("Agendamento inserido com sucesso.\n");
                          } else {
                              printf("Não é possível agendar neste dia.\n");
                          }
                      }
                         break;
                     case 3:
                      // Opção 3: Mostrar o calendário com agendamentos
                      printf("\n\tCalendário de %d\n\tcom agendamentos\n", ano);
                      printf("============================");
                      for (int mes = 1; mes <= 12; mes++) {
                          printf("\n\t\t%d / %d\n", mes, ano);
                          printf("----------------------------\n");

                          exibirCalendarioComAgendamentos(diasNoMes[mes], primeiroDiaDoMes[mes], agenda);
                          printf("============================");
                      }
                          break;
                      case 4:
                      // Opção 4: Sair
                      printf("Saindo...\n");
                      break;
                  default:
                      // Opção inválida
                      printf("Opção inválida. Tente novamente.\n");
              }
          } while (opcao != 4);

          return 0;
      }
