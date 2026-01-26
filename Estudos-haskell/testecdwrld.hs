import CodeWorld

-- Definição da figura composta
figura :: Picture
figura = pictures [retanguloVermelho, retanguloAmarelo, retanguloAzul]
  where
    -- Quadrado azul de lado 4 [cite: 35]
    retanguloAzul = colored blue (solidRectangle 4 4)
    
    -- Quadrado amarelo de lado 3 [cite: 36]
    -- Transladado 0.5 em Y para alinhar o topo com o quadrado azul
    -- (Opcional: se não transladar, fica centralizado, mas o visual da prova sugere alinhamento no topo)
    retanguloAmarelo = translated 0 0.5 (colored yellow (solidRectangle 3 3))
    
    -- Quadrado vermelho de lado 2, inclinado [cite: 37]
    -- Mantemos o centro relativo ao amarelo
    retanguloVermelho = translated 0 0.5 (colored red (rotated (pi/4) (solidRectangle 2 2)))

-- Função Main desenhando as 3 instâncias [cite: 24]
main :: IO ()
main = drawingOf (pictures [
        translated 0 4 figura,   -- Figura de cima
        figura,                  -- Figura do meio
        translated 0 (-4) figura -- Figura de baixo
    ])