

-- Idade somente em anos
idadeEmAnos :: (Int, Int, Int) -> (Int, Int, Int) -> Int
idadeEmAnos (diaN, mesN, anoN) (diaA, mesA, anoA)
  | (mesA < mesN) || (mesA == mesN && diaA < diaN) = anoA - anoN - 1
  | otherwise                                      = anoA - anoN

-- Idade em anos e meses
idadeEmAnosEMeses :: (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int)
idadeEmAnosEMeses (diaN, mesN, anoN) (diaA, mesA, anoA)
  | mesA < mesN = (anos - 1, mesA - mesN + 12) -- Empresta 1 ano
  | otherwise   = (anos, mesA - mesN)
  where
    anos = idadeEmAnos (diaN, mesN, anoN) (diaA, mesA, anoA)
    
-- Idade completa
idadeCompleta :: (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int, Int)
idadeCompleta (diaN, mesN, anoN) (diaA, mesA, anoA)
  | diaA >= diaN && mesA >= mesN = (anoA - anoN, mesA - mesN, diaA - diaN)
  | diaA >= diaN && mesA < mesN  = idadeCompleta (diaN, mesN, anoN) (diaA, mesA + 12, anoA - 1)
  | diaA < diaN = idadeCompleta (diaN, mesN, anoN) (diaA + diasMesAnterior, mesA - 1, anoA)
  
  where
    mesAnterior = if mesA == 1 then 12 else mesA - 1
    anoDoMesAnterior = if mesA == 1 then anoA - 1 else anoA
    diasMesAnterior = diasNoMes mesAnterior anoDoMesAnterior