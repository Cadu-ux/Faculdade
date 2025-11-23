contaEletricaProgressiva :: Int -> Double
contaEletricaProgressiva consumo
  | valorComTaxa < 35.0 = 35.0
  | otherwise           = valorComTaxa
  where
    consumoD = fromIntegral consumo

    -- Faixa 1 (0-99): 99 kWh
    faixa1 = (min consumoD 99) * 1.35
    -- Faixa 2 (100-299): 200 kWh
    faixa2 = (max 0 (min (consumoD - 99) 200)) * 1.55
    -- Faixa 3 (300-574): 275 kWh
    faixa3 = (max 0 (min (consumoD - 299) 275)) * 1.75
    -- Faixa 4 (acima de 574)
    faixa4 = (max 0 (consumoD - 574)) * 2.15

    valorBruto = faixa1 + faixa2 + faixa3 + faixa4
    
    taxa = if consumo > 300 then valorBruto * 0.10 else 0.0
    valorComTaxa = valorBruto + taxa