mediaAluno :: Float -> Float -> Float -> String
mediaAluno n1 n2 n3
    | media >= 7.0 = "Aprovado"
    | media < 5.0  = "Reprovado"
    | otherwise    = "Vai para a Final"
  where
    media = (n1 + n2 + n3) / 3