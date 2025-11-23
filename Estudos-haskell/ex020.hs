todosDiferentes :: (Eq a) => a -> a -> a -> Bool
todosDiferentes a b c = (a /= b) && (a /= c) && (b /= c)