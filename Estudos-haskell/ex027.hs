valorLocadora :: Int -> Int -> Double
valorLocadora dias kmTotal = custoFixo + custoExtra
  where
    custoFixo = fromIntegral dias * 90.0
    cotaPermitida = dias * 100
    
    kmExcedidos = max 0 (kmTotal - cotaPermitida)
    
    custoExtra = fromIntegral kmExcedidos * 12.0