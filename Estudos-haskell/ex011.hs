tipo :: Int -> String
tipo numero = if numero>0
              then "Positivo " ++ show numero
              else if numero<0 then "Negativo " ++ show (numero * (-1))
              else "Nulo"