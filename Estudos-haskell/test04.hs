naMedia :: Double -> Double -> Double -> Int
naMedia a b c 
              | (a > media) && (b > media) ||
                (a > media) && (c > media)    = 2
              | (b > media) && (c > media)    = 2
              | otherwise                     = 1
  where
    media = (a + b + c) / 3