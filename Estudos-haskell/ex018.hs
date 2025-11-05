mediaTres :: Double -> Double -> Double -> Double
mediaTres a b c = soma / 3.0
  where
    soma = a + b + c

precoVinhos :: Int -> Double -> Double
precoVinhos quantidade precoUnitario = fromIntegral garrafasAPagar * precoUnitario
  where
    garrafasGratis = quantidade `div` 3
    
    garrafasAPagar = quantidade - garrafasGratis

precoCirco :: Int -> Double -> Double
precoCirco idade precoNormal = precoNormal * (1.0 - taxaDesconto)
  where
    taxaDesconto = if idade <= 18 || idade >= 60
                   then 0.5  -- 50% de desconto
                   else 0.1  -- 10% de desconto


fahrenheitParaCentigrados :: Double -> Double
fahrenheitParaCentigrados f = (f - offset) * fator
  where
    offset = 32.0
    fator  = 5.0 / 9.0

centigradosParaFahrenheit :: Double -> Double
centigradosParaFahrenheit c =
    let fator = 9.0 / 5.0
        offset = 32.0
    in (c * fator) + offset

