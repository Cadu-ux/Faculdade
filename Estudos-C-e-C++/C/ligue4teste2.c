#include <stdio.h>
#include <string.h>
#include <stdlib.h> // pra encerrar o jogo e configurar ambiente no terminal
#include <time.h>   // Necessário para o rand() funcionar bem

// definição para tratar pausa visual tanto para win quanto para linux
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

//constantes globais
#define LINHAS 6 
#define COLUNAS 7 
#define VAZIO 0 
#define PLAYER_1 1 
#define PLAYER_2 2 

#define FICHA_COMUM 1 
#define FICHA_EXPLOSIVA 2 
#define FICHA_PORTAL 3 

#define PVP 1 
#define PVC 2 
#define CVC 3

// ESTRUTURAS
struct celula{
    int ocupante; //quem ocupa a celula vazio, p1 ou p2
    int tipo_ficha; //vai ser util pra implementar outras fihcas
    char simbolo[5]; // simbolo ou vazio
};

struct jogador{
    char nome[50]; 
    int id;
    int tipo; // se e humano ou cpu
    int jogadas; 
    int vitorias; 
    char cor_code[10]; 
    
    // Inventário
    int fichas_comuns;
    int fichas_explosivas;
    int fichas_portal;
};

struct partida{
    struct celula matriz[LINHAS][COLUNAS]; 
    struct jogador j1;
    struct jogador j2;
    int jogador_atual; 
    int turno; 
    int modo_jogo;
    int venceu; 
    int game_on; 
};

//== PARTE VISUAL ==//
const char cor_reset[] = "\033[0m"; 
const char cor_p1[] = "\033[1;34m"; // Azul
const char cor_p2[] = "\033[1;31m"; // Vermelho
const char cor_atencao[] = "\x1b[33m"; // Amarelo
const char ficha[] = "█";          
const char ficha_exp[] = "⛞";    
const char ficha_por[] = "U";    
const char tabuleiro_vazio[] = " ";

void limpar_tela(){
    #ifdef _WIN32 
        system("cls");
    #elif linux 
        system("clear");
    #endif
}

void configurar_ambiente_win(){ 
    #ifdef _WIN32
        system("chcp 65001");
    #endif
}

void delay_visual(int ms){ 
    SLEEP_MS(ms);
}

// MENU
int mostar_menu_principal(){
    int opcao;
    int resultado;
    do {
        limpar_tela(); 
        printf("====== LIGUE 4 ======\n");
        printf("1. Iniciar novo jogo\n");
        printf("2. Hall da fama\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");

        resultado = scanf("%d", &opcao); 

        if (resultado != 1 || opcao < 1 || opcao > 3) { 
            printf("%sEntrada inválida! Digite um número entre 1 e 3.%s\n", cor_atencao, cor_reset);
            while (getchar() != '\n'); 
            printf("Pressione Enter para tentar novamente...");
            getchar();
        } else {
            break; 
        }
    } while (1); 
    return opcao;
}

void solicitar_nomes(struct jogador *p1, struct jogador *p2, int modo) {
    p1->id = 1; 
    p2->id = 2;

    // Inicializa fichas
    p1->fichas_comuns = 21; p1->fichas_explosivas = 0; p1->fichas_portal = 5;
    p2->fichas_comuns = 21; p2->fichas_explosivas = 0; p2->fichas_portal = 5;

    limpar_tela(); 
    printf("=== CONFIGURACAO DOS JOGADORES ===\n\n");

    if (modo == 1) { // PvP
        p1->tipo = 0; 
        printf("Digite o nome do Jogador 1: ");
        scanf(" %[^\n]", p1->nome); 
        p1->nome[strcspn(p1->nome, "\n")] = 0; 

        p2->tipo = 0; 
        printf("Digite o nome do Jogador 2: ");
        scanf(" %[^\n]", p2->nome);
        p2->nome[strcspn(p2->nome, "\n")] = 0; 
    }
    else if (modo == 2) { // PvC
        p1->tipo = 0; 
        printf("Digite o nome do Jogador 1: ");
        scanf(" %[^\n]", p1->nome);
        p1->nome[strcspn(p1->nome, "\n")] = 0; 

        p2->tipo = 1; 
        strcpy(p2->nome, "Computador"); 
        printf("\nSeu adversario sera o: %s\n", p2->nome);
        printf("Pressione Enter para continuar...");
        getchar(); getchar(); 
    }
    else if (modo == 3) { // CvC
        p1->tipo = 1; 
        strcpy(p1->nome, "PC Azul");
        p2->tipo = 1; 
        strcpy(p2->nome, "PC Vermelho");

        printf("Modo Simulacao selecionado.\n");
        printf("Partida: %s vs %s\n", p1->nome, p2->nome);
        printf("Pressione Enter para iniciar a simulacao...");
        getchar(); getchar(); 
    }
}

void exibir_cabecalho(){
    printf("         LIGUE 4++   \n");
    printf("   1   2   3   4   5   6   7  \n");
}

void desenhar_tabuleiro(struct partida jogo){
    limpar_tela();
    exibir_cabecalho();
    printf("+---+---+---+---+---+---+---+\n");

    for(int i=0; i<LINHAS; i++){
        printf("|"); 
        for(int j=0; j<COLUNAS; j++){
            int valor = jogo.matriz[i][j].ocupante; 
            int tipo = jogo.matriz[i][j].tipo_ficha; 

            if(valor == VAZIO){
                printf(" %s |", tabuleiro_vazio); 
            } 
            else {
                const char *cor = (valor == PLAYER_1) ? cor_p1 : cor_p2;
                const char *simbolo_peca;

                if (tipo == FICHA_EXPLOSIVA) simbolo_peca = ficha_exp;
                else if (tipo == FICHA_PORTAL) simbolo_peca = ficha_por;
                else simbolo_peca = ficha;

                printf(" %s%s%s |", cor, simbolo_peca, cor_reset);
            }
        }
        printf("\n+---+---+---+---+---+---+---+\n"); 
    }
}

//== Lógica ==//
void iniciar_tabuleiro(struct partida *jogo){
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            jogo->matriz[i][j].ocupante = VAZIO; 
            jogo->matriz[i][j].tipo_ficha = FICHA_COMUM; 
            strcpy(jogo->matriz[i][j].simbolo, " "); 
        }
    }       
}

int validar(int coluna, struct partida jogo){
    int altura = -1; 
    if((coluna < 0) || (coluna > 6)){ 
        return altura;
    }
    // Percorre de baixo pra cima
    for(int i = LINHAS - 1; i >= 0; i--){ 
        if(jogo.matriz[i][coluna].ocupante == VAZIO){
            altura = i; 
            return altura; 
        }
    }
    return altura; 
}

void inserir_ficha(struct partida *jogo, int linha, int coluna, int id_jogador, int tipo) {
    jogo->matriz[linha][coluna].ocupante = id_jogador;
    jogo->matriz[linha][coluna].tipo_ficha = tipo;
}

// === IMPLEMENTAÇÃO DO PORTAL ===
// Retorna 1 se a jogada foi feita (gastou a ficha), 0 se a coluna é inválida
int usar_ficha_portal(struct partida *jogo, int coluna) {
    if (coluna < 0 || coluna >= COLUNAS) return 0; // Coluna inválida

    printf("\n%s[PORTAL] Ativando portal na coluna %d...%s\n", cor_atencao, coluna + 1, cor_reset);
    delay_visual(500);

    // Percorre de CIMA para BAIXO (contrário da gravidade normal)
    // Procura a primeira peça ocupada para absorver
    for (int i = 0; i < LINHAS; i++) {
        if (jogo->matriz[i][coluna].ocupante != VAZIO) {
            
            // Absorve (apaga) a ficha encontrada
            jogo->matriz[i][coluna].ocupante = VAZIO;
            jogo->matriz[i][coluna].tipo_ficha = 0;
            strcpy(jogo->matriz[i][coluna].simbolo, " ");

            printf("%s>>> ZWOOSH! O Portal absorveu a ficha da linha %d! <<<%s\n", cor_atencao, i+1, cor_reset);
            delay_visual(1000);
            return 1; // Sucesso
        }
    }

    // Se a coluna estiver vazia, o portal desaparece
    printf("%s>>> O Portal caiu no vazio e desapareceu sem efeito! <<<%s\n", cor_atencao, cor_reset);
    delay_visual(1000);
    return 1; // Consome a ficha mesmo assim
}

int verificar_vitoria(struct partida jogo, int jogador) {
    int cont;
    // Horizontal
    for (int i = 0; i < LINHAS; i++) {
        cont = 0;
        for (int j = 0; j < COLUNAS; j++) {
            if (jogo.matriz[i][j].ocupante == jogador) {
                cont++;
                if (cont == 4) return 1;
            } else {
                cont = 0;
            }
        }
    }
    // Vertical
    for (int j = 0; j < COLUNAS; j++) {
        cont = 0;
        for (int i = 0; i < LINHAS; i++) {
            if (jogo.matriz[i][j].ocupante == jogador) {
                cont++;
                if (cont == 4) return 1;
            } else {
                cont = 0;
            }
        }
    }
    // Diagonal Princ.
    for (int i = 0; i < LINHAS - 3; i++) {
        for (int j = 0; j < COLUNAS - 3; j++) {
            if (jogo.matriz[i][j].ocupante == jogador &&
                jogo.matriz[i+1][j+1].ocupante == jogador &&
                jogo.matriz[i+2][j+2].ocupante == jogador &&
                jogo.matriz[i+3][j+3].ocupante == jogador) {
                return 1;}
        }
    }
    // Diagonal Sec.
    for (int i = 3; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS - 3; j++) {
            if (jogo.matriz[i][j].ocupante == jogador &&
                jogo.matriz[i-1][j+1].ocupante == jogador &&
                jogo.matriz[i-2][j+2].ocupante == jogador &&
                jogo.matriz[i-3][j+3].ocupante == jogador) {
                return 1;}
        }
    }
    return 0;
}

void trocar_turno(struct partida *jogo) {
    if (jogo->jogador_atual == PLAYER_1) { 
        jogo->jogador_atual = PLAYER_2;
    } else {
        jogo->jogador_atual = PLAYER_1;
    } 
    jogo->turno++; 
}

void verificar_empate(struct partida *jogo){
    if (jogo->turno > LINHAS * COLUNAS) {
        printf("EMPATE! O tabuleiro está cheio.\n");
        jogo->game_on = 0;
    }
}

int selecionar_modo(){
    int modo;
    do {
        limpar_tela();
        printf("=== SELECIONE O MODO DE JOGO ===\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs CPU\n");
        printf("3. CPU vs CPU\n");
        printf("Escolha: ");

        if (scanf("%d", &modo) != 1 || modo < 1 || modo > 3) { 
            printf("%sEntrada inválida!%s\n", cor_atencao, cor_reset);
            while (getchar() != '\n');
            getchar(); 
        } else {
            while (getchar() != '\n'); 
            break;
        }
    } while (1);
    return modo; 
}

// == CORE DO JOGO ==
void iniciar_partida(struct partida *jogo){
    iniciar_tabuleiro(jogo); 
    jogo->jogador_atual = PLAYER_1; 
    jogo->turno = 1; 
    jogo->game_on = 1; 

    while (jogo->game_on) {
        desenhar_tabuleiro(*jogo);

        struct jogador *jogador_vez = (jogo->jogador_atual == PLAYER_1) ? &jogo->j1 : &jogo->j2;
        const char *cor_v = (jogo->jogador_atual == PLAYER_1) ? cor_p1 : cor_p2;

        printf("\n%s--- Turno: %d ---%s\n", cor_atencao, jogo->turno, cor_reset);
        printf("%sVez de: %s%s\n", cor_v, jogador_vez->nome, cor_reset);

        int coluna = -1; 
        int tipo_f = FICHA_COMUM; 

        // == INPUT DO JOGADOR ==
        if (jogador_vez->tipo == 0) { // Humano
            int escolha_valida = 0;
            
            while (!escolha_valida) {  
                printf("Inventário: [c] Comum:%d | [e] Explosiva:%d | [p] Portal:%d\n", 
                        jogador_vez->fichas_comuns, jogador_vez->fichas_explosivas, jogador_vez->fichas_portal);
                printf("Escolha o tipo de ficha: ");
                char input;
                scanf(" %c", &input);

                if (input == 'c' || input == 'C') tipo_f = FICHA_COMUM;
                else if (input == 'e' || input == 'E') tipo_f = FICHA_EXPLOSIVA;
                else if (input == 'p' || input == 'P') tipo_f = FICHA_PORTAL;
                else {
                    printf("\n%sOpção inválida!%s\n", cor_atencao, cor_reset);
                    continue; 
                }

                // Verifica estoque
                if (tipo_f == FICHA_COMUM && jogador_vez->fichas_comuns > 0) escolha_valida = 1;
                else if (tipo_f == FICHA_EXPLOSIVA && jogador_vez->fichas_explosivas > 0) escolha_valida = 1;
                else if (tipo_f == FICHA_PORTAL && jogador_vez->fichas_portal > 0) escolha_valida = 1;
                else printf("\n%sVocê não tem essa ficha! Escolha novamente.%s\n", cor_atencao, cor_reset);
            }

            printf("Escolha uma coluna (1-7): ");
            scanf("%d", &coluna);
            coluna--; 
        
        } else { // CPU
            printf("Computador pensando...\n");
            delay_visual(1500);
            coluna = rand() % COLUNAS;
            // CPU simples: Se tiver portal e a coluna estiver quase cheia, usa portal (logica basica)
            // Se tiver explosiva, usa aleatoriamente
            // Aqui mantivemos simples usando COMUM para a CPU nao bugar
            tipo_f = FICHA_COMUM; 
        }

        // == PROCESSAMENTO DA JOGADA ==
        int jogada_realizada = 0;

        // SE FOR FICHA PORTAL:
        if (tipo_f == FICHA_PORTAL) {
            // Tenta usar o portal na coluna (ele retorna 1 se a coluna for valida)
            if (usar_ficha_portal(jogo, coluna)) {
                jogador_vez->fichas_portal--; // Gasta ficha
                jogada_realizada = 1;
            } else {
                // Coluna invalida (fora do range)
                if (jogador_vez->tipo == 0) {
                    printf("\n%sCOLUNA INVALIDA!%s\n", cor_atencao, cor_reset);
                    delay_visual(1000);
                }
            }
        }
        // SE FOR FICHA COMUM OU EXPLOSIVA:
        else {
            int linha = validar(coluna, *jogo); 

            if (linha != -1) { 
                inserir_ficha(jogo, linha, coluna, jogo->jogador_atual, tipo_f);
                
                if(tipo_f == FICHA_COMUM) jogador_vez->fichas_comuns--;
                else if(tipo_f == FICHA_EXPLOSIVA) jogador_vez->fichas_explosivas--;

                jogada_realizada = 1;
            } else {
                if (jogador_vez->tipo == 0) {
                    printf("\n%sJOGADA INVÁLIDA! Coluna cheia ou inexistente.%s\n", cor_atencao, cor_reset);
                    printf("Pressione Enter...");
                    while (getchar() != '\n'); getchar();
                }
            }
        }

        // == FINALIZA TURNO SE DEU CERTO ==
        if (jogada_realizada) {
            // Verifica vitoria apenas se nao for portal (portal nao faz 4 em linha ao ser jogado)
            int venceu = 0;
            if (tipo_f != FICHA_PORTAL) {
                venceu = verificar_vitoria(*jogo, jogo->jogador_atual);
            }
            
            if (venceu) { 
                desenhar_tabuleiro(*jogo);
                printf("\n%s %s VENCEU O JOGO! %s\n", cor_v, jogador_vez->nome, cor_reset);
                jogo->game_on = 0;
            } else {
                trocar_turno(jogo);
                
                // BÔNUS a cada 10 rodadas
                if(jogo->turno > 1 && (jogo->turno - 1) % 10 == 0) {
                    jogo->j1.fichas_explosivas++; jogo->j1.fichas_portal++;
                    jogo->j2.fichas_explosivas++; jogo->j2.fichas_portal++;
                    printf("\n%s[BÔNUS] Rodadas avançaram! Fichas especiais recebidas.%s\n", cor_atencao, cor_reset);
                    delay_visual(1500);
                }
            }
        }
    }
}

int pos_jogo(){
    int opcao;
    int resultado;
    do{
        printf("\n============================\n");
        printf("1. Jogar Novamente\n");
        printf("2. Voltar ao Menu Principal\n");
        printf("3. Sair do Jogo\n");
        printf("Escolha uma opção: ");
        resultado = scanf("%d", &opcao); 

        if (resultado != 1 || opcao < 1 || opcao > 3) { 
            printf("%sEntrada inválida!%s\n", cor_atencao, cor_reset);
            while (getchar() != '\n'); 
            getchar();
        } else {
            break; 
        }
    } while (1); 
    return opcao;
}

//==Main==//
int main() {
    struct partida jogo; 
    int opcao_menu;
    srand(time(NULL)); 
    configurar_ambiente_win();

    while (1) {
        opcao_menu = mostar_menu_principal();

        if (opcao_menu == 1) { 
            jogo.modo_jogo = selecionar_modo(); 
            solicitar_nomes(&jogo.j1, &jogo.j2, jogo.modo_jogo); 

            int jogar_de_novo = 1; 
            while (jogar_de_novo == 1) {
                iniciar_partida(&jogo);

                int acao = pos_jogo(); 
                if (acao == 1) jogar_de_novo = 1;
                else if (acao == 3) exit(0);
                else jogar_de_novo = 0; 
            }
        } 
        else if (opcao_menu == 2)  {
            limpar_tela();
            printf("%sCalma, jovem padawan! Hall da fama em breve.%s\n", cor_atencao, cor_reset);
            printf("Pressione Enter para voltar...");
            while (getchar() != '\n'); 
            getchar();
        } 
        else if (opcao_menu == 3) {
            printf("Que a força esteja com você!\n");
            break;
        }
    }
    return 0;
}