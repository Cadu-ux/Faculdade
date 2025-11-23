ehBissexto :: Int -> Bool
ehBissexto ano = (ano `mod` 4 == 0) && (ano `mod` 100 /= 0 || ano `mod` 400 == 0)
diasNoMes :: Int -> Int -> Int
diasNoMes mes ano
  | mes == 2  = if ehBissexto ano then 29 else 28
  | mes `elem` [4, 6, 9, 11] = 30
  | otherwise = 31

somaDiasMesesAnteriores :: Int -> Int -> Int
somaDiasMesesAnteriores mes ano
  | mes == 1  = 0
  | otherwise = diasNoMes (mes - 1) ano + somaDiasMesesAnteriores (mes - 1) ano

diaDoAno :: Int -> Int -> Int -> Int
diaDoAno dia mes ano = somaDiasMesesAnteriores mes ano + dia

diasParaSaoJoao :: Int -> Int -> Int -> Int
diasParaSaoJoao dia mes ano
  | diaAtual <= diaSJ = diaSJ - diaAtual
  | otherwise         = (diasTotaisEsteAno - diaAtual) + diaSJProximoAno
  where
    diaAtual = diaDoAno dia mes ano
    diaSJ    = diaDoAno 24 6 ano
    
    diasTotaisEsteAno = if ehBissexto ano then 366 else 365
    diaSJProximoAno   = diaDoAno 24 6 (ano + 1)