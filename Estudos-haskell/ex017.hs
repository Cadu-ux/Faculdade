xorIf :: Bool -> Bool -> Bool
xorIf a b = if a then (not b) else b

xorCasa :: Bool -> Bool -> Bool
xorCasa True  True  = False
xorCasa True  False = True
xorCasa False True  = True
xorCasa False False = False

xorOp :: Bool -> Bool -> Bool
xorOp a b = (a || b) && (not (a && b))

xorIgual :: Bool -> Bool -> Bool
xorIgual a b = a /= b