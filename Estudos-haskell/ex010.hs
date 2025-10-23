maior :: Char -> Char
maior c = if c >= 'A' && c <= 'Z'
          then toEnum (fromEnum c + offset)
          else c
    where
      offset = fromEnum 'a' - fromEnum 'A'