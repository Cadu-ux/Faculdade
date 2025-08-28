import { hqsLib } from "./hqsLib.js"
let books = hqsLib.loadHQs()
const botaoIniciar = document.getElementById("botaoIniciar")
const botaoListar = document.getElementById("botaoListar")
const botaoAdd = document.getElementById("botaoAdd")
const botaoUpd = document.getElementById("botaoUpd")
const botaoRemove = document.getElementById("botaoRemove")
const botaoListaPorEditora = document.getElementById("botaoListaPorEditora")
const forms = document.getElementById("formularios")
const outPut = document.getElementById("saida")
const botaoListaPorCategoria = document.getElementById("botaoListaPorCategoria")

const iniciar = () => {
    const lista = hqsLib.reset1
    books = lista
    outPut.textContent = "Quadrinhos carregados com sucesso! Total: " + lista.length
}

botaoIniciar.addEventListener("click", iniciar)

const listarHQs = () => {
    outPut.innerHTML = hqsLib.printar(books)
}

botaoListar.addEventListener("click", listarHQs)

const saidaAdicionaHQ = () => {
    outPut.innerHTML = `
        ID: <input type="number" id="idIN"></input>
        Título: <input type="text" id="tituloIN"></input><br>
        Editora: <input type="text" id="editoraIN"></input>
        Ano: <input type="number" id="anoIN"></input><br>
        Categoria: <input type="text" id="categoriaIN"></input>
        <button id="adicionarButtonC">Adicionar</button>
        `
    const adicionaFunc = () => {
        const id_ = Number(document.getElementById("idIN").value)
        if (hqsLib.comparar(id_, books) !== 0) {return outPut.innerHTML = "Já existe esse ID!"}
        const l = [{ 
             id: id_,
             titulo: document.getElementById("tituloIN").value,
             editora: document.getElementById("editoraIN").value, 
             ano: Number(document.getElementById("anoIN").value), 
             categoria: document.getElementById("categoriaIN").value
            }]
        const novaLista = hqsLib.add(books, l)
        books = hqsLib.SaveHQs(novaLista)
    outPut.innerHTML = "HQ ADICIONADA!"
    }
    document.getElementById("adicionarButtonC").addEventListener("click", adicionaFunc)
}

botaoAdd.addEventListener("click", saidaAdicionaHQ)

const saidaAtualizaHQ = () => {
    outPut.innerHTML = `
        ID: <input type="number" id="idIN"></input>
        Novo título: <input type="text" id="tituloIN"></input><br>
        Nova editora: <input type="text" id="editoraIN"></input>
        Novo ano: <input type="number" id="anoIN"></input><br>
        Nova categoria: <input type="text" id="categoriaIN"></input>
        <button id="atualizarButtonC">Atualizar</button>
        `
    const atualizaFunc = () => {
        const id_ = Number(document.getElementById("idIN").value)
        if (hqsLib.comparar(id_, books) === 0) {return outPut.innerHTML = "Não existe esse ID!"}
        const l = { 
             id: id_,
             titulo: document.getElementById("tituloIN").value,
             editora: document.getElementById("editoraIN").value, 
             ano: Number(document.getElementById("anoIN").value), 
             categoria: document.getElementById("categoriaIN").value
            }
        const listaAtualizada = hqsLib.update(books, id_, l)
        books = hqsLib.SaveHQs(listaAtualizada)
        outPut.innerHTML = "LISTA ATUALIZADA!"
    }
    document.getElementById("atualizarButtonC").addEventListener("click", atualizaFunc)
}

botaoUpd.addEventListener("click", saidaAtualizaHQ)

const saidaRemoveHQ = () => {
    outPut.innerHTML = `
    ID: <input type="number" id="idIN"></input>
    <button id="removeButtonC">Remover</button>`
    const removeFunc = () => {
        const id_ = Number(document.getElementById("idIN").value)
        if (hqsLib.comparar(id_, books) === 0) {return outPut.innerHTML = "Não existe esse ID!"}
        const listaRemovida = hqsLib.deletar(books, id_)
        books = hqsLib.SaveHQs(listaRemovida)
        outPut.innerHTML = "HQ REMOVIDA!"
    }
    document.getElementById("removeButtonC").addEventListener("click", removeFunc)
}

botaoRemove.addEventListener("click", saidaRemoveHQ)

const listaPorEditora = () => {
    outPut.innerHTML = `
    Editora: <input type="text" id="editoraINPUT"></input>
    <button id="pesquisaButtonC">Pesquisar</button>`
    const listaFunc = () => {
        const editora_ = document.getElementById("editoraINPUT").value
        const listaPesquisada = hqsLib.filtraEditora(books, editora_)
        outPut.innerHTML = hqsLib.printar(listaPesquisada)
    }
    document.getElementById("pesquisaButtonC").addEventListener("click", listaFunc)
}

botaoListaPorEditora.addEventListener("click", listaPorEditora)

const listaPorCategoria = () => {
    outPut.innerHTML = `
    Categoria: <input type="text" id="categoriaINPUT"></input>
    <button id="pesquisaButtonC">Pesquisar</button>`
    const listaFunc = () => {
        const categoria_ = document.getElementById("categoriaINPUT").value
        const listaPesquisada = hqsLib.filtraCategoria(books, categoria_)
        outPut.innerHTML = hqsLib.printar(listaPesquisada)
    }
    document.getElementById("pesquisaButtonC").addEventListener("click", listaFunc)
}

botaoListaPorCategoria.addEventListener("click", listaPorCategoria)