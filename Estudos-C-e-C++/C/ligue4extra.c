// (coloque logo antes do iniciar_partida e depois do inserir_ficha)


// Retorna 1 se o turno foi consumido 
int usar_ficha_portal(struct partida *jogo, int coluna) {
    // Validação básica
    if (coluna < 0 || coluna >= COLUNAS) return 0;

    printf("\n[PORTAL] Ativando portal na coluna %d...\n", coluna + 1);
    delay_visual(500);

    // Percorre de cima pra baixo ao inves do habitual (baixo pra cima)
    for (int i = 0; i < LINHAS; i++) {
        // Se encontrar QUALQUER coisa que não seja vazio 
        if (jogo->matriz[i][coluna].ocupante != VAZIO) {
            
            // A ficha que estava lá some
            jogo->matriz[i][coluna].ocupante = VAZIO;
            jogo->matriz[i][coluna].tipo_ficha = 0;
            strcpy(jogo->matriz[i][coluna].simbolo, " ");

            printf("%s>>> O Portal absorveu a ficha da linha %d! <<<%s\n", cor_atencao, i+1, cor_reset);
            delay_visual(1000);
            return 1; // Sucesso, gastou a ficha
        }
    }

    // Se percorreu tudo e não achou nada (coluna vazia)
    printf("%s>>> O Portal caiu no vazio e desapareceu! <<<%s\n", cor_atencao, cor_reset);
    delay_visual(1000);
    return 1; // Também retorna 1, pois a ficha foi gasta mesmo sem efeito
}




// (coloque logo depois do if else que define coluna e tipo_f) 

    int jogada_realizada = 0; // variavel de controle

    // logica especial pra ficha portal
    if (tipo_f == FICHA_PORTAL) {
        // O portal não usa validar nem inserir_ficha, ele tem função própria
        jogada_realizada = usar_ficha_portal(jogo, coluna);
        
        // Se deu certo , desconta do inventário
        if (jogada_realizada) {
             jogador_vez->fichas_portal--;
        }
    }
    
    // pra fichas que empilham (normal e explosiva)
    else {
        int linha = validar(coluna, *jogo);

        if (linha != -1) {
            inserir_ficha(jogo, linha, coluna, jogo->jogador_atual, tipo_f);
            
            // Desconta do inventário correspondente
            if(tipo_f == FICHA_COMUM) jogador_vez->fichas_comuns--;
            else if(tipo_f == FICHA_EXPLOSIVA) jogador_vez->fichas_explosivas--;
            
            // logica da ficha explosiva aqui
            
            jogada_realizada = 1;
        } else {
            // Coluna cheia para fichas normais
            if (jogador_vez->tipo == 0) {
                 printf("\n%sCOLUNA CHEIA! Escolha outra.%s\n", cor_atencao, cor_reset);
                 delay_visual(1000);
            }
        }
    }

    // finaliza o turno se houve jogada
    if (jogada_realizada) {
        
        // Verifica vitória apenas se nao foi portal 
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
            
            // Lógica do Bônus a cada 10 turnos (Mantida igual)
            if(jogo->turno > 1 && (jogo->turno - 1) % 10 == 0) {
                jogo->j1.fichas_explosivas++; jogo->j1.fichas_portal++;
                jogo->j2.fichas_explosivas++; jogo->j2.fichas_portal++;
                printf("\n%s[BÔNUS] 5 Rodadas se passaram! Fichas especiais recebidas.%s\n", cor_atencao, cor_reset);
                delay_visual(1500);
            }
        }
    } 
    // Se for humano e a jogada falhou (ex: coluna invalida), o loop volta sem trocar turno