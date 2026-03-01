

 1. Função shift
   Explicação: A função aceita uma tupla aninhada onde os elementos podem ser 
   de qualquer tipo (a, b, c são variáveis de tipo livres)



 2. Função zip

   Ela combina (zip) duas listas criando uma lista de pares, mas alterna a ordem 
   das listas de origem a cada passo recursivo
   
 Como a chamada recursiva inverte os argumentos,o tipo da primeira lista deve ser igual ao tipo da segunda lista. Se fossem 
   diferentes, a recursão falharia ao tentar passar um Bool onde se espera um Int



 3. Função ocorrencias
ocorrencias :: Eq a => a -> [a] -> Int
ocorrencias x xs = length [k | k <- xs, k == x]
ocorrencias :: Eq a => a -> [a] -> Int
Para verificar se o item `x` ocorre em `xs`, precisamos comparar os valores, o que exige a restrição de classe (type constraint) `Eq`



 4. Função oneLookupFirst

oneLookupFirst :: Eq a => [(a, b)] -> a -> b
oneLookupFirst [] _ = error "Item não encontrado"
oneLookupFirst ((k, v):xs) item
    | k == item = v
    | otherwise = oneLookupFirst xs item

   oneLookupFirst :: Eq a => [(a, b)] -> a -> b
   
   Exige `Eq a` para comparar a chave (primeira componente) com o item. 
   O retorno é do tipo `b` (segunda componente)




 5. Função oneLookupSecond

oneLookupSecond :: Eq b => [(a, b)] -> b -> a
oneLookupSecond [] _ = error "Item não encontrado"
oneLookupSecond ((k, v):xs) item
    | v == item = k
    | otherwise = oneLookupSecond xs item

   oneLookupSecond :: Eq b => [(a, b)] -> b -> a
   
   E Agora a comparação é feita com a segunda componente (valor),assim a restrição `Eq` deve ser aplicada ao tipo `b`




 6. Função misterio

misterio :: (Eq a, Show a) => [a] -> [a] -> [String]
misterio y x = [ show z | z <- x, elem z y ]


   misterio :: (Eq a, Show a) => [a] -> [a] -> [String]
   
   
   1. `z <- x`: Infere que `x` é uma lista de algum tipo `[a]`.
   2. `elem z y`: Infere que `y` também é uma lista do mesmo tipo `[a]` e, 
      para usar `elem`, o tipo `a` deve ter a instância de `Eq`.
   3. `show z`: Para converter `z` em String, o tipo `a` deve ter a instância de `Show`.
   4. O retorno é uma lista de Strings
