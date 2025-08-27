import { hqsLib } from "./hqslib.js"

let books = hqsLib.loadHQs()
const botaoIniciar = document.getElementById("botaoIniciar")
const botaoListar = document.getElementById("botaoListar")
const botaoAdd = document.getElementById("botaoAdd")
const botaoUpd = document.getElementById("botaoUpd")
const botaoRemove = document.getElementById("botaoRemove")
const botaoListaPorEditora = document.getElementById("botaoListaPorEditora")
const forms = document.getElementById("formularios")
const outPut = document.getElementById("saida")

const iniciar = () => {
    const lista = hqsLib.loadHQs()
    outPut.textContent = "Quadrinhos carregados com sucesso! Total: " + lista.length
}

botaoIniciar.addEventListener("click", iniciar)

const listarHQs = () => {
    const a = hqsLib.printar(books)
    outPut.innerHTML = a
}

botaoListar.addEventListener("click", listarHQs)