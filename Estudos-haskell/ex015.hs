sinalString :: Int -> String
sinalString x
    | x > 0     = "Positivo " ++ show x
    | x < 0     = "Negativo " ++ show (abs x)
    | otherwise = "Nulo"