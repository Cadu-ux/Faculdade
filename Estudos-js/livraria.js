// ---------------------------------------------------------------------
// Manipulação funcional de uma LIVRARIA
// ---------------------------------------------------------------------

// Exemplo de estado inicial:
const books = [
  { id: 1, title: "Dom Casmurro", author: "Machado de Assis", year: 1899 },
  { id: 2, title: "Capitães da Areia", author: "Jorge Amado", year: 1937 },
  { id: 3, title: "A Hora da Estrela", author: "Clarice Lispector", year: 1977 }
]

// ---------------------------------------------------------------------
// 0. listBooks
// Versão básica da função de listagem de livros (Read do CRUD)
// Usa formatação padrão como string por linha
// ---------------------------------------------------------------------
const listBooks = books =>
  books.map(book =>
    `${book.id} - "${book.title}" (${book.author}, ${book.year})`
  )

console.log(`== listBooks ==`)
console.log(listBooks(books).join('\n'))


// ---------------------------------------------------------------------
// 1. formatBooks
// Aplica uma função de formatação em cada livro da lista
// ---------------------------------------------------------------------
const formatBooks = (books, formatFn) =>
  books.map((book, index) => formatFn(book, index))

// Exemplos de funções de formatação:
const shortFormat = (book, i) => `${i + 1}. ${book.title}`
const fullFormat = book =>
  `${book.id} - "${book.title}" (${book.author}, ${book.year})`

console.log(`== formatBooks ==`)
console.log(formatBooks(books, shortFormat).join('\n'))

// ---------------------------------------------------------------------
// 2. markOldBooks
// Adiciona um campo "old" se o livro for anterior ao ano indicado
// ---------------------------------------------------------------------
const markOldBooks = (books, cutoffYear) =>
  books.map(book => ({
    ...book,
    old: book.year < cutoffYear
  }))

console.log(`== markOldBooks ==`)
console.log(markOldBooks(books, 1950))

// ---------------------------------------------------------------------
// 3. addCategoryByAuthor
// Usa uma função para classificar cada autor como "clássico", "moderno", etc
// ---------------------------------------------------------------------
const addCategoryByAuthor = (books, classifyAuthorFn) =>
  books.map(book => ({
    ...book,
    category: classifyAuthorFn(book.author)
  }))

// Exemplo:
const classicOrModern = author =>
  author === "Machado de Assis" ? "clássico" : "moderno"

console.log(`== addCategoryByAuthor ==`)
console.log(addCategoryByAuthor(books, classicOrModern))

// ---------------------------------------------------------------------
// 4. updateTitles
// Aplica uma função sobre o título de cada livro (ex: adicionar prefixo)
// ---------------------------------------------------------------------
const updateTitles = (books, transformFn) =>
  books.map(book => ({
    ...book,
    title: transformFn(book.title)
  }))

// Exemplo:
const addPrefix = title => `[Livro] ${title}`

console.log(`== updateTitles ==`)
console.log(updateTitles(books, addPrefix))

// ---------------------------------------------------------------------
// 5. renameFields
// Transforma a estrutura do livro (ex: traduz campos para português)
// ---------------------------------------------------------------------
const renameFields = (books, renamerFn) =>
  books.map(book => renamerFn(book))

// Exemplo de renomeação:
const renomear = ({ id, title, author, year }) => ({
  codigo: id,
  titulo: title,
  autor: author,
  ano: year
})

console.log(`== renameFields ==`)
console.log(renameFields(books, renomear))