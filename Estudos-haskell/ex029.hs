contaEletrica :: Int -> Double
contaEletrica consumo
  | valorComTaxa < 35.0 = 35.0
  | otherwise           = valorComTaxa
  where
    consumoD = fromIntegral consumo -- Consumo em Double
    
    valorBruto
      | consumo <= 99   = consumoD * 1.35
      | consumo <= 299  = consumoD * 1.55
      | consumo <= 574  = consumoD * 1.75
      | otherwise       = consumoD * 2.15
      
    taxa = if consumo > 300 then valorBruto * 0.10 else 0.0
    
    valorComTaxa = valorBruto + taxa