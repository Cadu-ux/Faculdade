circo :: Int -> Double -> Double
circo idade preco = if idade <= 18 then (preco * 0.5) else if idade >= 60 then (preco * 0.5) else (preco * 0.9)