equacaoSegundoGrau :: Double -> Double -> Double -> String
equacaoSegundoGrau a b c
  | a == 0    = "Nao e equacao de segundo grau"
  | delta < 0 = "Nao tem solucao real"
  | delta == 0 = "A unica solucao real e " ++ show r
  | otherwise = "As solucoes reais sao " ++ show r1 ++ " e " ++ show r2
  where
    delta = b*b - 4*a*c
    r  = -b / (2*a)
    r1 = (-b - sqrt delta) / (2*a)
    r2 = (-b + sqrt delta) / (2*a)