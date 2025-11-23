areaTriangulo :: Double -> Double -> Double -> Double
areaTriangulo a b c
  | ehTriangulo = sqrt (s * (s - a) * (s - b) * (s - c))
  | otherwise   = 0.0
  where
    s = (a + b + c) / 2
    
    ehTriangulo = (a + b > c) && (a + c > b) && (b + c > a)