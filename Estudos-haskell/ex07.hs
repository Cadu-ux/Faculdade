valorVinho :: Int -> Double -> Double
valorVinho quantidade preco = 
    let pago = (quantidade  `div` 3) * 2 + (quantidade `mod` 3)
    in (fromIntegral pago) * preco
