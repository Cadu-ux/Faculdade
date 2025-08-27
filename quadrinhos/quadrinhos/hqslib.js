const quadrinhos = [
  { id: 1, titulo: "Batman: Ano Um", editora: "DC COMICS", ano: "1987", categoria: "HQ"},
  { id: 2, titulo: "Akira", editora: "Kodansha", ano: "1982", categoria: "mangá"},
  { id: 3, titulo: "Watchmen", editora: "DC COMICS", ano: "1986", categoria: "HQ"},
  { id: 4, titulo: "Solo Leveling", editora: "D&C Media", ano: "2016", categoria:"manhwa"},
]

localStorage.setItem('HQs', JSON.stringify(quadrinhos))

const reset = (x) => {
  localStorage.setItem('HQs', JSON.stringify(x))
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

const loadHQs = () => {
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

//funções ----------------------------------------

const remove = (l) => {
  localStorage.removeItem(l)
  return 'limpo!'
}

const printar = (l) => l.map(x => `id: ${x.id} título: ${x.titulo} editora: ${x.editora}`).join('<br>')

const update = (l,id,l2) => l.map(x => x.id == id ? {...x,...l2} : x )

const deletar = (l,id) => l.filter(x => x.id !== id)

const add = (l,l2) => [...l,...l2]

// -----------------------------------------------

const SaveHQs = (l) => {
  localStorage.setItem('HQs', JSON.stringify(l))
  const books = localStorage.getItem('HQs')
  return books ? JSON.parse(books) : []
}

export const hqsLib = {
  loadHQs, remove, printar, update, deletar, add, SaveHQs, reset
}