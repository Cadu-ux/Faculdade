ehBissexto :: Int -> Bool
ehBissexto ano = (ano `mod` 4 == 0) && (ano `mod` 100 /= 0 || ano `mod` 400 == 0)