import { hqsLib } from "./hqsLib.js"
let books = hqsLib.loadHQs()


const botaoIniciar = document.getElementById("botaoIniciar")
const botaoListar = document.getElementById("botaoListar")
const botaoAdd = document.getElementById("botaoAdd")
const botaoUpd = document.getElementById("botaoUpd")
const botaoRemove = document.getElementById("botaoRemove")
const botaoListaPorEditora = document.getElementById("botaoListaPorEditora")
const botaoListaPorCategoria = document.getElementById("botaoListaPorCategoria")
const outPut = document.getElementById("saida")


const limparSaida = () => outPut.innerHTML = '';


const iniciar = () => {
    limparSaida();
    books = hqsLib.reset1
    outPut.innerHTML = `<p class="aviso-sucesso">Quadrinhos carregados com sucesso! Total: ${books.length}</p>`
}

const listarHQs = () => {
    limparSaida();
    outPut.innerHTML = hqsLib.printar(books)
}

const saidaAdicionaHQ = () => {
    limparSaida();
    outPut.innerHTML = `
        <div class="form-container">
            <h3>Adicionar Nova HQ</h3>
            <div class="form-group">
                <label for="idIN">ID:</label>
                <input type="number" id="idIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="tituloIN">Título:</label>
                <input type="text" id="tituloIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="editoraIN">Editora:</label>
                <input type="text" id="editoraIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="anoIN">Ano:</label>
                <input type="number" id="anoIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="categoriaIN">Categoria:</label>
                <input type="text" id="categoriaIN" class="form-input">
            </div>
            <button id="adicionarButtonC" class="form-button">Adicionar</button>
        </div>
    `;
    document.getElementById("adicionarButtonC").addEventListener("click", () => {
        const id_ = Number(document.getElementById("idIN").value);
        if (hqsLib.comparar(id_, books) !== 0) {
            outPut.innerHTML = `<p class="aviso-erro">Já existe uma HQ com esse ID!</p>`;
            return;
        }
        const novaHQ = [{
            id: id_,
            titulo: document.getElementById("tituloIN").value,
            editora: document.getElementById("editoraIN").value,
            ano: Number(document.getElementById("anoIN").value),
            categoria: document.getElementById("categoriaIN").value
        }];
        books = hqsLib.SaveHQs(hqsLib.add(books, novaHQ));
        outPut.innerHTML = `<p class="aviso-sucesso">HQ Adicionada!</p>`;
    });
}

const saidaAtualizaHQ = () => {
    limparSaida();
    outPut.innerHTML = `
        <div class="form-container">
            <h3>Atualizar HQ</h3>
            <div class="form-group">
                <label for="idIN">ID da HQ para atualizar:</label>
                <input type="number" id="idIN" class="form-input">
            </div>
            <p class="form-hint">Preencha apenas os campos que deseja alterar:</p>
            <div class="form-group">
                <label for="tituloIN">Novo Título:</label>
                <input type="text" id="tituloIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="editoraIN">Nova Editora:</label>
                <input type="text" id="editoraIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="anoIN">Novo Ano:</label>
                <input type="number" id="anoIN" class="form-input">
            </div>
            <div class="form-group">
                <label for="categoriaIN">Nova Categoria:</label>
                <input type="text" id="categoriaIN" class="form-input">
            </div>
            <button id="atualizarButtonC" class="form-button">Atualizar</button>
        </div>
    `;
    document.getElementById("atualizarButtonC").addEventListener("click", () => {
        const id_ = Number(document.getElementById("idIN").value);
        if (hqsLib.comparar(id_, books) === 0) {
            outPut.innerHTML = `<p class="aviso-erro">Não existe HQ com esse ID!</p>`;
            return;
        }
        const hqExistente = books.find(hq => hq.id === id_);
        const dadosAtualizados = {
            titulo: document.getElementById("tituloIN").value || hqExistente.titulo,
            editora: document.getElementById("editoraIN").value || hqExistente.editora,
            ano: Number(document.getElementById("anoIN").value) || hqExistente.ano,
            categoria: document.getElementById("categoriaIN").value || hqExistente.categoria,
        };
        books = hqsLib.SaveHQs(hqsLib.update(books, id_, dadosAtualizados));
        outPut.innerHTML = `<p class="aviso-sucesso">HQ Atualizada!</p>`;
    });
}

const saidaRemoveHQ = () => {
    limparSaida();
    outPut.innerHTML = `
        <div class="form-container">
            <h3>Remover HQ</h3>
            <div class="form-group">
                <label for="idIN">ID da HQ a ser removida:</label>
                <input type="number" id="idIN" class="form-input">
            </div>
            <button id="removeButtonC" class="form-button">Remover</button>
        </div>
    `;
    document.getElementById("removeButtonC").addEventListener("click", () => {
        const id_ = Number(document.getElementById("idIN").value);
        if (hqsLib.comparar(id_, books) === 0) {
            outPut.innerHTML = `<p class="aviso-erro">Não existe HQ com esse ID!</p>`;
            return;
        }
        books = hqsLib.SaveHQs(hqsLib.deletar(books, id_));
        outPut.innerHTML = `<p class="aviso-sucesso">HQ Removida!</p>`;
    });
}

const criarFormularioPesquisa = (tipo) => {
    limparSaida();
    const labelTexto = tipo === 'editora' ? 'Editora' : 'Categoria';
    outPut.innerHTML = `
        <div class="form-container">
            <h3>Listar por ${labelTexto}</h3>
            <div class="form-group">
                <label for="pesquisaInput">${labelTexto}:</label>
                <input type="text" id="pesquisaInput" class="form-input">
            </div>
            <button id="pesquisaButtonC" class="form-button">Pesquisar</button>
        </div>
        <div id="resultado-pesquisa"></div>
    `;
    document.getElementById("pesquisaButtonC").addEventListener("click", () => {
        const valorPesquisa = document.getElementById("pesquisaInput").value;
        const funcaoFiltro = tipo === 'editora' ? hqsLib.filtraEditora : hqsLib.filtraCategoria;
        const resultado = funcaoFiltro(books, valorPesquisa);
        document.getElementById("resultado-pesquisa").innerHTML = hqsLib.printar(resultado);
    });
}

botaoIniciar.addEventListener("click", iniciar);
botaoListar.addEventListener("click", listarHQs);
botaoAdd.addEventListener("click", saidaAdicionaHQ);
botaoUpd.addEventListener("click", saidaAtualizaHQ);
botaoRemove.addEventListener("click", saidaRemoveHQ);
botaoListaPorEditora.addEventListener("click", () => criarFormularioPesquisa('editora'));
botaoListaPorCategoria.addEventListener("click", () => criarFormularioPesquisa('categoria'));