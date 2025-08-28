const quadrinhos = [
  { id: 1, titulo: "Batman: Ano Um", editora: "DC COMICS", ano: "1987", categoria: "HQ"},
  { id: 2, titulo: "Akira", editora: "Kodansha", ano: "1982", categoria: "mangá"},
  { id: 3, titulo: "Watchmen", editora: "DC COMICS", ano: "1986", categoria: "HQ"},
  { id: 4, titulo: "Solo Leveling", editora: "D&C Media", ano: "2016", categoria:"manhwa"},
  { id: 5, titulo: "Sandman", editora: "DC Vertigo", ano: "1989", categoria: "HQ"},
  { id: 6, titulo: "V de Vingança", editora: "DC Vertigo", ano: "1988", categoria: "HQ"},
  { id: 7, titulo: "Cavaleiro das Trevas", editora: "DC COMICS", ano: "1986", categoria: "HQ"},
  { id: 8, titulo: "One Piece", editora: "Shueisha", ano: "1997", categoria: "mangá"},
  { id: 9, titulo: "Naruto", editora: "Shueisha", ano: "1999", categoria: "mangá"},
  { id: 10, titulo: "Berserk", editora: "Hakusensha", ano: "1989", categoria: "mangá"},
  { id: 11, titulo: "Dragon Ball", editora: "Shueisha", ano: "1984", categoria: "mangá"},
  { id: 12, titulo: "Homem-Aranha: A Última Caçada de Kraven", editora: "Marvel", ano: "1987", categoria: "HQ"},
  { id: 13, titulo: "X-Men: Dias de um Futuro Esquecido", editora: "Marvel", ano: "1981", categoria: "HQ"},
  { id: 14, titulo: "Demolidor: A Queda de Murdock", editora: "Marvel", ano: "1986", categoria: "HQ"},
  { id: 15, titulo: "Hellboy", editora: "Dark Horse", ano: "1993", categoria: "HQ"},
  { id: 16, titulo: "Spawn", editora: "Image Comics", ano: "1992", categoria: "HQ"},
  { id: 17, titulo: "Fullmetal Alchemist", editora: "Square Enix", ano: "2001", categoria: "mangá"},
  { id: 18, titulo: "Death Note", editora: "Shueisha", ano: "2003", categoria: "mangá"},
  { id: 19, titulo: "Attack on Titan", editora: "Kodansha", ano: "2009", categoria: "mangá"},
  { id: 20, titulo: "Tokyo Ghoul", editora: "Shueisha", ano: "2011", categoria: "mangá"},
  { id: 21, titulo: "Blue Lock", editora: "Kodansha", ano: "2018", categoria: "mangá"},
  { id: 22, titulo: "Tower of God", editora: "Naver Webtoon", ano: "2010", categoria: "manhwa"},
  { id: 23, titulo: "Gantz", editora: "Shueisha", ano: "2000", categoria: "mangá"},
  { id: 24, titulo: "Bleach", editora: "Shueisha", ano: "2001", categoria: "mangá"}
]


const reset = (x) => {
  localStorage.setItem('HQs', JSON.stringify(x))
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

const reset1 = reset(quadrinhos)

const loadHQs = () => {
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

const comparar = (id,l) => {
  const [x,...xs] = l 
  if (x == undefined) { return 0 }
  
  if (id === x.id) { return 1 + comparar(id,xs) }

  return comparar(id, xs)
}

//funções ----------------------------------------

const remove = (l) => {
  localStorage.removeItem(l)
  return 'limpo!'
}

const printar = (l) => l.map(x => `ID: ${x.id} - Título: "${x.titulo}" - Editora: ${x.editora} - Ano: ${x.ano} - Categoria: ${x.categoria}`).join('<br>')

const update = (l,id,l2) => l.map(x => x.id == id ? {...x,...l2} : x )

const deletar = (l,id) => l.filter(x => x.id !== id)

const filtraEditora = (l, editora) => l.filter(x => x.editora === editora)

const filtraCategoria = (l, categoria) => l.filter(x => x.categoria === categoria)

const add = (l,l2) => [...l,...l2]

// -----------------------------------------------

const SaveHQs = (l) => {
  localStorage.setItem('HQs', JSON.stringify(l))
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

export const hqsLib = {
  loadHQs, remove, printar,
  update, deletar, add,
  SaveHQs, reset, comparar,
  reset1, filtraEditora, filtraCategoria
}