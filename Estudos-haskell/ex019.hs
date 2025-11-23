acimaDaMedia :: Double -> Double -> Double -> Int
acimaDaMedia a b c = contaMaior a + contaMaior b + contaMaior c
  where
    media = (a + b + c) / 3

    contaMaior x = if x > media then 1 else 0