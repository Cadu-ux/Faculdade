limpa :: Eq a => [a] -> [a]
limpa [] = []
limpa [x] = [x]
limpa (x:xs)
  | x == cabeca = resto
  | otherwise   = x : resto
  where
    resto = limpa xs
    cabeca = head resto