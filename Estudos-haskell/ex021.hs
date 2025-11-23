mediana :: (Ord a) => a -> a -> a -> a
mediana a b c
  | (a <= b && a >= c) || (a >= b && a <= c) = a
  | (b <= a && b >= c) || (b >= a && b <= c) = b
  | otherwise                                = c