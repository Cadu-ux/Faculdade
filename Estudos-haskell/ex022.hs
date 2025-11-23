conceitoMEC :: Int -> Int -> Char
conceitoMEC livros alunos
  | relacao <= 8   = 'A'
  | relacao <= 12  = 'B'
  | relacao <= 18  = 'C'
  | otherwise      = 'D'
  where
    relacao = (fromIntegral alunos) / (fromIntegral livros)